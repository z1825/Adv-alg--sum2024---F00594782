#include <iostream>
using namespace std;

struct Node {
    int row;
    int col;
    int value;
    Node* next;
};

class SparseMatrixLL {
private:
    Node* head;

public:
    SparseMatrixLL() : head(nullptr) {}

    ~SparseMatrixLL() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    void addElement(int r, int c, int val) {
        Node* newNode = new Node{r, c, val, nullptr};
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "Row: " << temp->row
                 << " Column: " << temp->col
                 << " Value: " << temp->value << endl;
            temp = temp->next;
        }
    }
};

int main() {
    SparseMatrixLL sm;

    sm.addElement(0, 2, 3);
    sm.addElement(0, 4, 4);
    sm.addElement(1, 2, 5);
    sm.addElement(1, 3, 7);
    sm.addElement(3, 1, 2);
    sm.addElement(3, 2, 6);

    sm.display();

    return 0;
}
