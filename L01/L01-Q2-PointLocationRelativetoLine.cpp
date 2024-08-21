#include <simplecpp>

main_program
{
    int a, b, c;
    float x1, y1;
    float expr;
    ((cin >> a) >> b) >> c;
    (cin >> x1) >> y1;

    /* MATH BEHIND `expr`
    L: a*x + b*y + c = 0
    for a given x1, the corressponding y1
    such that (x1,y1) lies on L is
    y = -(a*x1 + c) / b
    so the required expression is
    expr = y1 - y
    expr > 0  => above
    expr == 0 => on
    expr < 0  => below
    */
    expr = y1 + (a * x1 + c) / b;

    if (expr == 0)
    {
        cout << "On the Line" << endl;
    }
    else if (expr < 0)
    {
        cout << "Below the Line" << endl;
    }
    else
    {
        cout << "Above the Line" << endl;
    }
}