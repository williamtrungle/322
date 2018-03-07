// @author: William Le
// @studentid:260239181 

#include <iostream>
#include <cstdlib>
using namespace std;

class Node {
  public:
    int data;
    Node *prev;
    Node *next;
    Node(int d, Node *p, Node *n) {
        data = d;
        prev = p;
        next = n;
    }
    Node() {
        data = 0;
        prev = next = NULL;
    }
    ~Node() {}
};

class DLLStructure {
  private:
    Node *first, *last;
  public:
    DLLStructure() {
        first = last = NULL;
    }
    DLLStructure(int array[], int size) {
        int i = 0;
        Node *c = NULL;
        Node *p = NULL;
        while (i < size) {
            c = new Node(array[i], p, NULL);
            if (i > 0) {
                p->next = c;
            } else {
                first = c;
            }
            p = c;
            i++;
        }
        last = c;
    }
    ~DLLStructure() {
        Node *c = first;
        Node *n;
        while (c != NULL) {
            n = c->next;
            delete c;
            c = n;
        }
    }
    void PrintDLL() {
        Node *c = first;
        do {
            cout << c->data << " ";
        } while ((c = c->next));
        cout << endl;
    }
    void InsertAfter(int after, int value) {
        Node *c = first;
        Node *n;
        while (c != NULL) {
            if (c->data == after) {
                n = new Node(value, c, c->next);
                if (c->next != NULL) {
                    c->next->prev = n;
                }
                c->next = n;
                break;
            }
            c = c->next;
        }
    }
    void InsertBefore(int before, int value) {
        this->InsertAfter(before, before);
        this->InsertAfter(before, value);
        this->Delete(before);
    }
    void Delete(int value) {
        Node *c = first;
        while (c->data != value) {
            if (c == NULL) {
                break;
            }
            c = c->next;
        }
        if (c != NULL) {
            c->prev->next = c->next;
            c->next->prev = c->prev;
            delete c;
        }
    }
    void swap(Node *a, Node *b) {
        Node *alpha = a->prev;
        Node *beta = b->next;
        if (&*a == &*first) {
            first = b;
        }
        if (&*b == &*last) {
            last = a;
        }
        if ((alpha)) { alpha->next = b; }
        if ((beta)) { beta->prev = a; }
        a->next = beta;
        a->prev = b;
        b->next = a;
        b->prev = alpha;
    }
    void Sort() {
        bool unsorted;
        Node *c;
        while (true) {
            unsorted = false;
            c = first;
            while ((c = c->next)) {
                if (c->prev->data > c->data) {
                    swap(c->prev, c);
                    unsorted = true;
                    c = c->next;
                }
            }
            if (!unsorted) {
                break;
            }
        }
    }
    bool IsEmpty() {
        return first == NULL;
    }
    int GetHead() {
        return first->data;
    }
    int GetTail() {
        return last->data;
    }
    int GetSize() {
        int size = 0;
        Node *c = first;
        while ((c)) {
            size++;
            c = c->next;
        }
        return size;
    }
    int GetMax() {
        int m = 0;
        Node *c = first;
        while ((c)) {
            m = c->data > m ? c->data : m;
            c = c->next;
        }
        return m;
    }
    int GetMin() {
        int m = 0;
        Node *c = first;
        while ((c)) {
            m = c->data < m ? c->data : m;
            c = c->next;
        }
        return m;
    }
    DLLStructure(const DLLStructure &other) {
        if ((!other.first)) {
            first = last = NULL;
        } else {
            Node *c = NULL;
            Node *o = other.first;
            first = new Node(o->data, NULL, NULL);
            Node *p = first;
            while ((o = o->next)) {
                c = new Node(o->data, p, NULL);
                p->next = c;
                p = c;
            }
            last = c;
        }
    }
};

// ----------------------------------------------------------------------------
// Question 10 (5 pts)

string q10 = "Ideally the value of the size of the list would be saved as a private field of the class, and be updated on every insertion/deletion method. This would reduce the O(n) size lookup downt to O(1).";

// ----------------------------------------------------------------------------
// Question 11 (10 pts)

string q11 = "Similar to the GetSize case, the value of max and min should be saved as a field of the object, and be updated whenever an element is added or removed. In those case, we modify either value by simply comparing with the current max and min, which has a O(1) time complexity.";

// ----------------------------------------------------------------------------
// Question 12 (15 pts)
string q12 = "If we only rely on the implicit copy constructor provided by the compiler, the resulting object will have a copy of all of the fields of the original object. What this entails is that both objects point to the same list! Therefore a modification in our newly created object will unexpectedly modify the contents of the original object. This is not the behaviour we want. Thus, we require an explicity copy structor method, which will perform a deep copy of the original method. Implementing this requires simply to traverse the original list and make a copy of each node for the new copied DLLStructure object.";

int main() {
    int array[5] = {11,2,7,22,4};
    DLLStructure dll(array,5);
    cout << "Initialize new DLLStructure with values: ";
    dll.PrintDLL();
    cout << "Insert 13 after 7, and 26 before 7: ";
    dll.InsertAfter(7, 13);
    dll.InsertBefore(7,26);
    dll.PrintDLL();
    cout << "Sort: ";
    dll.Sort();
    dll.PrintDLL();
    cout << "Get head: ";
    cout << dll.GetHead() << endl;
    cout << "Get tail: ";
    cout << dll.GetTail() << endl;
    cout << "Delete 22: ";
    dll.Delete(22);
    dll.PrintDLL();
    cout << "Get size: " << dll.GetSize() << endl;
    cout << "Question 10:" << endl << q10 << endl;
    cout << "Get max and min: " << dll.GetMax() << ", " << dll.GetMin() << endl;
    cout << "Question 11:" << endl << q11 << endl;
    cout << "Initialize new DLLStructure and check if is empty: ";
    DLLStructure empty;
    if (empty.IsEmpty()) {
        cout << "Empty!" << endl;
    } else {
        cout << "Not empty :(" << endl;
    }
    cout << "Copy lis, insert 666 before 26, and check that original and new are different" << endl;
    DLLStructure newList = dll;
    newList.InsertBefore(26, 666);
    cout << "Original:\t";
    dll.PrintDLL();
    cout << "New:\t\t";
    newList.PrintDLL();
    cout << "Question 12:" << endl << q12 << endl;

    return 0;
}
