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
        while (c != last) {
            n = c->next;
            delete c;
            c = n;
        }
    }
    void printDLL() {
        Node *c = first;
        Node *n;
        do {
            cout << c->data << " ";
        } while ((c = c->next));
        cout << endl;
    }
};

int main() {
    int array[5] = {11,2,7,22,4};
    DLLStructure dll(array,5);
    dll.printDLL();
    return 0;
}
