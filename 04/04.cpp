#include <simplecpp>

main_program {
	for (int i = 0; i <= 4; )
    {
        cout << "i == " << i;
        cout << " | i++ == " << i++;
        cout << " | i == " << i << endl;
    }
    cout << endl;

    for (int j = 0; j <= 4; )
    {
        cout << "j == " << j;
        cout << " | ++j == " << ++j;
        cout << " | j == " << j << endl;
    }
}
