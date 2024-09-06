#include <simplecpp>

struct MyComplex { float real, imag; };

MyComplex addComplex(MyComplex c1, MyComplex c2) {
    return {c1.real + c2.real, c1.imag + c2.imag};
}

MyComplex subComplex(MyComplex c1, MyComplex c2) {
    return {c1.real - c2.real, c1.imag - c2.imag};
}

MyComplex mulComplex(MyComplex c1, MyComplex c2) {
    return {c1.real * c2.real - c1.imag * c2.imag, c1.real * c2.imag + c1.imag * c2.real};
}

MyComplex divideByScalar(MyComplex c, float s) {
    return {c.real / s, c.imag / s};
}

MyComplex divideComplex(MyComplex c1, MyComplex c2) {
    return divideByScalar(mulComplex(c1, {c2.real, -c2.imag}), (c2.real * c2.real + c2.imag * c2.imag));
}

void print_complex(MyComplex c) {
    cout << c.real << " + " << c.imag << "i" << endl;
}

main_program {
    float w, x, y, z;
    char c;
    cin >> w >> x >> y >> z;
    MyComplex c1 = {w, x};
    MyComplex c2 = {y, z};
    cin >> c;

    if (c == 'A') print_complex(addComplex(c1, c2));
    else if (c == 'S') print_complex(subComplex(c1, c2));
    else if (c == 'M') print_complex(mulComplex(c1, c2));
    else if (c == 'D') print_complex(divideComplex(c1, c2));
}
