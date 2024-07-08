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

    int numNonZero;
    cout << "Enter number of non-zero elements: ";
    cin >> numNonZero;

    for (int i = 0; i < numNonZero; i++) {
        int r, c, val;
        cout << "Enter row index, column index and value for element " << i + 1 << ": ";
        cin >> r >> c >> val;
        sm.addElement(r, c, val);
    }

    cout << "\nSparse Matrix:" << endl;
    sm.display();

    return 0;
}
