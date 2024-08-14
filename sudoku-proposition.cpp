#include <iostream>
using namespace std;

/*
Solving a sudoku board using propositional calculus

1. Model a sudoku board as a combination of compound propositions.
2. Try solving the sudoku board by brute forcing true-false values for all propositions.
3. Optimize it by invoking properties of OR and AND operators
*/

// Proposition
class Prop {
public:
    // whether `value` has been fixed or not
    bool solved;
    bool value;
    Prop() { solved = value = false; }
};

// Proposition `p(i,j,n)`: whether `(i,j)` cell has `n` value
class CellVal : public Prop {
public:
    int i, j;
    int n = -1;
    int old_n = n;
    CellVal(int _i, int _j) {
        i = _i;
        j = _j;
    }

    // Set `n` value and assume solved and true
    int set_n(int _n) {
        if (n == -1)
            n = _n;
        else {
            printf("CellVal at (%d,%d) has been set to %d already and solved.\n", i, j,
                   n);
            return 1;
        }
        solved = true;
        value = true;
        return 0;
    }

    // Push `n` value but assuming not solved
    int push_n(int _n) {
        // Older value of `n` is saved in `old_n`
        if (!solved) {
            old_n = n;
            n = _n;
            return 0;
        }
        printf("CellVal at (%d,%d) has been set to %d already and solved.\n", i, j, n);
        return 1;
    }

    // Replace `n` with `old_n` value
    int pop_n(int _n) {
        if (old_n == -1) {
            printf("CellVal at (%d,%d) was not pushed any value of n.\n", i, j);
            return 1;
        }
        n = old_n;
        return 0;
    }
};

// Compound proposition over cell values. Inherits from `CellVal`
class CompdCellVal : public Prop {
public:
    // Array ptr of CellVal ptrs / CellVal*
    CellVal** members;
    int size;

    // Constructor
    CompdCellVal(CellVal* _members[], int _size) {
        size = _size;
        // ! using the following causes `members` to revert to null pointer idk why
        // Prop* members[size]
        members = new CellVal*[size];

        for (int i = 0; i < size; i++) {
            members[i] = _members[i];
        }
    }

    // Destructor to free the dynamically allocated memory
    ~CompdCellVal() {
        // only free up the Prop* array
        // Prop objects may be cleared up later
        delete[] members;
    }

    // Solve the proposition
    int solve() {
        // iterate over all CellVal's
        for (int i = 0; i < size; i++) {
            CellVal* pCV = members[i];
            // check if solved or not
            if (pCV->solved)
                continue;
                }

        return 1;
    }
};

// Logical AND of `CompdCellVal`
class And : public CompdCellVal {
public:
};

int main() {
    CellVal* p1 = new CellVal(1, 1);
    CellVal* p2 = new CellVal(1, 2);
    CellVal* p3 = new CellVal(1, 3);
    CellVal* ps[3] = {p1, p2, p3};
    CompdCellVal* p4 = new CompdCellVal(ps, 3);

    return 0;
}
