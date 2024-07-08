#include <iostream>
using namespace std;

struct Triple {
    int row;
    int col;
    int value;
};

class SparseMatrix {
private:
    int rows, cols, numNonZero;
    Triple* elements;

public:
    SparseMatrix(int r, int c, int num) : rows(r), cols(c), numNonZero(num) {
        elements = new Triple[numNonZero];
    }

    ~SparseMatrix() {
        delete[] elements;
    }

    void addElement(int index, int r, int c, int val) {
        if (index >= 0 && index < numNonZero) {
            elements[index].row = r;
            elements[index].col = c;
            elements[index].value = val;
        }
    }

    void display() {
        for (int i = 0; i < numNonZero; i++) {
            cout << "Row: " << elements[i].row
                 << " Column: " << elements[i].col
                 << " Value: " << elements[i].value << endl;
        }
    }
};

int main() {
    int rows, cols, numNonZero;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    cout << "Enter number of non-zero elements: ";
    cin >> numNonZero;

    SparseMatrix sm(rows, cols, numNonZero);

    for (int i = 0; i < numNonZero; i++) {
        int r, c, val;
        cout << "Enter row index, column index and value for element " << i + 1 << ": ";
        cin >> r >> c >> val;
        sm.addElement(i, r, c, val);
    }

    cout << "\nSparse Matrix:" << endl;
    sm.display();

    return 0;
}
