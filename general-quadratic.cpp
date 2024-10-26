#include <iostream>
using std::cout, std::cin, std::cerr;

#define dbg(x) cout << #x << "=" x << " "
#define nl cout << '\n'

const int BUFSIZE = 1024;

struct genQuad {
    int a, b, c;
};

struct solution {
    double x1, x2;
};

genQuad handleInput(char* text, int size);
solution solveExpr(genQuad expr);
void printSolution(solution soln);

int main() {
    char text[BUFSIZE], c;
    cin >> c;
    int i = 0;
    for (; (c != '\n' && i < BUFSIZE); cin >> c, i++) text[i] = c;

    genQuad expr = handleText(text, i + 1);
    solution soln = solveExpr(expr);

    printSolution();
}

genQuad handleInput(char* text, int size) {
    genQuad expr = {0, 0, 0};
    char c, s[BUFSIZE] = "";
    int coeff, pow;

    /* assume text is of the form:
    coeff*x^(1/2) +/-/= coeff

    no spaces within a term
    terms delimited by space
    only non-neg coefficient
    use any lower case alphabet for variable
    */

    for (int i = 0; i < size; i++) {
        c = text[i];
        s += c;

        int readMode = 0;
        // 0 - reset
        // 1 - coeff
        // 2 - power

        // // delimit term
        // if (c == ' ') {
        //     readMode = 0;
        // }
        // // begin + delimit variable
        // else if (c >= 'a' && c <= 'z') {
        // }
        // // delimit coefficient
        // else if (c == '*') {
        //     readMode = 2;
        // }
        // // delimit operator
        // else if (c == '+' || c == '-') {
        //     //
        // }
        // // delimit equality
        // else if (c == '=') {
        //     //
        // }
        // // begin term / read coefficient
        // else if (c >= '0' && c <= '9') {
        //     //
        // }

        switch (readMode)
        {
        case 0: // reset
            if (c == ' ')
            break;

        case 1: // coeff
            //
            break;

        case 2: // power
            //
            break;
        
        default: // invalid character
            cerr << "Invalid character '" << c << "' at position " << i + 1 << "!\n";
            return {0, 0, 0};  // TODO
            break;
        }
    }
}
