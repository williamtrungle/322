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
            prev = NULL;
            next = NULL;
        }
        ~Node() {}
};

int main() {
    Node node();
    return 0;
}
