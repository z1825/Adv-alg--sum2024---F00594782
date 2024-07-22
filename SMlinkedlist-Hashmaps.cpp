#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int col;
    int value;
    Node* next;

    Node(int c, int v) : col(c), value(v), next(nullptr) {}
};

class Row {
public:
    Node* head;

    Row() : head(nullptr) {}

    void insert(int col, int value) {
        if (value == 0) return;

        Node* newNode = new Node(col, value);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display(int row) const {
        Node* temp = head;
        while (temp) {
            cout << "Row: " << row << " Col: " << temp->col << " Value: " << temp->value << endl;
            temp = temp->next;
        }
    }

    ~Row() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

class SparseMatrix {
private:
    unordered_map<int, Row*> rows;

public:
    SparseMatrix() {}

    void insert(int row, int col, int value) {
        if (value == 0) return;

        if (rows.find(row) == rows.end()) {
            rows[row] = new Row();
        }
        rows[row]->insert(col, value);
    }

    void display() const {
        for (const auto& row : rows) {
            row.second->display(row.first);
        }
    }

    ~SparseMatrix() {
        for (auto& row : rows) {
            delete row.second;
        }
    }
};

int main() {
    SparseMatrix matrix;

    int row, col, value;
    cout << "Enter the matrix values (row, column, value) and enter -1 for row to stop:" << endl;
    while (true) {
        cout << "Row: ";
        cin >> row;
        if (row == -1) break;
        cout << "Col: ";
        cin >> col;
        cout << "Value: ";
        cin >> value;

        matrix.insert(row, col, value);
    }

    cout << "Sparse Matrix Representation:" << endl;
    matrix.display();

    return 0;
}
