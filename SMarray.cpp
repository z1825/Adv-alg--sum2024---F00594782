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
    SparseMatrix sm(4, 5, 6);

    sm.addElement(0, 0, 2, 3);
    sm.addElement(1, 0, 4, 4);
    sm.addElement(2, 1, 2, 5);
    sm.addElement(3, 1, 3, 7);
    sm.addElement(4, 3, 1, 2);
    sm.addElement(5, 3, 2, 6);

    sm.display();

    return 0;
}
