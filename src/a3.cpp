// @William Le
// #260239181

#include <iostream>
#include <new>
#include <string>
using namespace std;

// ----------------------------------------------------------------------------
// Question 1 (15 pts)

/*
 * Smart pointers:
 * - auto_ptr: smart pointer that automatically cleans up/deallocates memory unpon exiting its scope, has problems if it is copied and can cause unwanted premature deletion
 * - unique_ptr: smart poiter that cannot be copied, but relies on owndership transfer to pass between functions -> the sole owner causes memory memory cleanup and pointer deletion upon going out of scope
 * - scoped_ptr: same as unique_ptr but cannot have its ownership transfered
 * - shared_ptr: pointer with reference count semantics that allows multiple pointers to point to the same object and causes cleanup if the reference count drops to zero
 * - weak_ptr: since shared_ptr does not cleanup memory on cycles, weak_ptr can be used as the loop-creating edge, but will trigger proper cleanup even in cycles
 */

// ----------------------------------------------------------------------------
// SmartPointer for integers

template <typename T>
class SmartPointer
{
    public:
        SmartPointer();
        SmartPointer(T value);
        ~SmartPointer();
        T getValue();
        void setValue(T value);
    private:
        T *ptr = 0;
        void allocate();
        void allocate(T value);
        void assertPositive(T value);
};

template <typename T>
SmartPointer<T>::SmartPointer()
{
    allocate();
}

template <typename T>
SmartPointer<T>::SmartPointer(T value)
{
    assertPositive(value);
    allocate(value);
}

template <typename T>
SmartPointer<T>::~SmartPointer()
{
    delete ptr;
    ptr = NULL;
}

template <typename T>
T SmartPointer<T>::getValue()
{
    return *ptr;
}

template <typename T>
void SmartPointer<T>::setValue(T value)
{
    assertPositive(value);
    if (ptr) delete ptr;
    allocate(value);
}

template <typename T>
void SmartPointer<T>::allocate()
{
    try
    {
        ptr = new T;
    }
    catch (bad_alloc& err)
    {
        string msg;
        msg += "Not enough memory for SmartPointer to allocate a new: ";
        msg += err.what();
        throw(msg);
    }
}

template <typename T>
void SmartPointer<T>::allocate(T value)
{
    try
    {
        ptr = new T(value);
    }
    catch (bad_alloc& err)
    {
        string msg;
        msg += "Not enough memory for SmartPointer to allocate a new: ";
        msg += err.what();
        throw(msg);
    }
}

template <typename T>
void SmartPointer<T>::assertPositive(T value)
{
    if (value < 0)
    {
        string msg;
        msg += "Cannot assign postive value "; 
        msg += to_string(value);
        msg += " to SmartPointer";
        throw(msg);
    }
}

// ----------------------------------------------------------------------------
// Tests

// Test for Question 2
int t1()
{
    const int value = 11;
    int result;
    SmartPointer<int> sPointer(value);
    result = sPointer.getValue();
    if (result != value)
    {
        cout << "Error: (t1) got " << result << ", want " << value << endl;
        return 0;
    }
    return 1;
}

// Test for Question 2
int t2()
{
    const int value = 133;
    int result;
    SmartPointer<int> sPointer;
    sPointer.setValue(value);
    result = sPointer.getValue();
    if (result != value)
    {
        cout << "Error: (t2) got " << result << ", want " << value << endl;
        return 0;
    }
    return 1;
}

// Test for Question 3
int t3()
{
    SmartPointer<int> sPointer;
    try
    {
        sPointer.setValue(-1);
    }
    catch (string &message)
    {
        return 1;
    }
    cerr << "Error: (t3) no exception thrown for negative value -1" << endl;
    return 0;
}

// Test for Question 4
int t4()
{
    const float value = 13.31;
    float result;
    SmartPointer<float> sPointer;
    sPointer.setValue(value);
    result = sPointer.getValue();
    if (result != value)
    {
        cout << "Error: (t4) got " << result << ", want " << value << endl;
        return 0;
    }
    return 1;
}

// ----------------------------------------------------------------------------
// Test each question

typedef int (*UnitTest) ();

int main()
{
    UnitTest tests[] =
    {
        t1,
        t2,
        t3,
        t4
    };

    bool success = true;
    for (int i = 0; i < 4; i++)
    {
        if (!tests[i]())
        {
            success = false;
            break;
        }
    }

    if (success) cout << "Success" << endl;
}
