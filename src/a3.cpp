// @William Le
// #260239181

#include <iostream>
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
// Question 2 (15 pts)

class SmartPointer
{
    public:
        SmartPointer();
        SmartPointer(int value);
        ~SmartPointer();
        int getValue();
        void setValue(int value);
    private:
        int *ptr = 0;
};

SmartPointer::SmartPointer()
{
    ptr = new int;
}

SmartPointer::SmartPointer(int value)
{
    ptr = new int(value);
}

SmartPointer::~SmartPointer()
{
    delete ptr;
    ptr = NULL;
}

int SmartPointer::getValue()
{
    return *ptr;
}

void SmartPointer::setValue(int value)
{
    if (ptr)
    {
        delete ptr;
    }
    ptr = new int(value);
}

int q1_1()
{
    const int value = 11;
    int result;
    SmartPointer sPointer(value);
    result = sPointer.getValue();
    if (result != value)
    {
        cout << "Error: (q1_1) got " << result << ", want " << value << endl;
        return 0;
    }
    return 1;
}

int q1_2()
{
    const int value = 133;
    int result;
    SmartPointer sPointer;
    sPointer.setValue(133);
    result = sPointer.getValue();
    if (result != value)
    {
        cout << "Error: (q1_2) got " << result << ", want " << value << endl;
        return 0;
    }
    return 1;
}

int main()
{
    int r = 1;
    r = r && q1_1();
    r = r && q1_2();
    if (r) cout << "Success" << endl;
    return !r;
}
