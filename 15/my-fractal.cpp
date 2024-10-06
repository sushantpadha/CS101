#include<simplecpp>

const int SIZE = 1000;

void koch(int level, double L){
    if (!level) { forward(L); return; }
    level--; L /= 3;
    koch(level, L); left(60);
    koch(level, L); right(120);
    koch(level, L); left(60);
    koch(level, L);
}

void hilbert(int level, double L){}

void binaryTree(int level, double boxHeight, double boxWidth) {
    if(!level) return;

    double childBoxHeight = boxHeight - boxHeight / level;
    double childBoxWidth = boxWidth / 2;
    double y = boxHeight / level;
    double x = childBoxWidth;
    double angle = atan(x / y) * 180.0 / PI;
    double edgeLen = sqrt(x*x + y*y);

    level--;

    // left child
    left(angle); forward(edgeLen); left(-angle);
    binaryTree(level, childBoxHeight, childBoxWidth);
    left(angle); forward(-edgeLen); left(-angle);

    // right child
    right(angle); forward(edgeLen); right(-angle);
    binaryTree(level, childBoxHeight, childBoxWidth);
    right(angle); forward(-edgeLen); right(-angle);

}


int main() {
    cout << "1. Koch Curve \n2. Binary Tree\n3. Hilbert Curve\n";
    int n; cin >> n;

    cout << "Enter level of recursion: ";
    int level; cin >> level;

    turtleSim("Fractal", SIZE, SIZE);

    switch(n) {
        case 1:
            penUp(); forward(-SIZE/2); penDown();
            koch(level, 500);
            break;
        case 2:
            penUp(); right(90); forward(-SIZE/2); penDown();
            binaryTree(level, 800, 400);
            break;
        case 3:
            hilbert(level, 20);
            break;
        default:
            break;
    }

    cout << "Click to exit\n";
    getClick();
}
