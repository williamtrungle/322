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
        while (c != last) {
            if (c->data == after) {
                n = new Node(value, c, c->next);
                c->next->prev = n;
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
    void Sort() {
        bool unsorted;
        Node *c, *n, *ichi, *ni, *san, *shi;
        while (true) {
            unsorted = false;
            c = first->next;
            while (c != NULL) {
                n = c->next;
                if (c->data < c->prev->data) {
                    ichi = c->prev->prev;
                    ni = c->prev;
                    san = c;
                    shi = c->next;
                    if (ichi != NULL) {
                        ichi->next = san;
                    }
                    san->prev = ichi;
                    if (shi != NULL) {
                        shi->prev = ni;
                    }
                    ni->next = shi;
                    ni->prev = san;
                    san->next = ni;
                    unsorted = true;
                }
                c = n;
            }
            if (!unsorted) {
                break;
            }
        }
    }
    bool IsEmpty() {
        return first == NULL;
    }
};


int main() {
    int array[5] = {11,2,7,22,4};
    DLLStructure dll(array,5);
    cout << "Initialize new DLLStructure with values: ";
    dll.PrintDLL();
    cout << "Insert 13 after 7, and 26 before 7: ";
    dll.InsertAfter(7, 13);
    dll.InsertBefore(7,26);
    dll.PrintDLL();
    cout << "Delete 22: ";
    dll.Delete(22);
    dll.PrintDLL();
    cout << "Sort: ";
    dll.Sort();
    dll.PrintDLL();
    cout << "Initialize new DLLStructure and check if is empty: ";
    DLLStructure empty;
    if (empty.IsEmpty()) {
        cout << "Empty!" << endl;
    } else {
        cout << "Not empty :(" << endl;
    }
    return 0;
}
