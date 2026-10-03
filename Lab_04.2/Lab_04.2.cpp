#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    double x, xp, xk, dx, A, B, y;

    cout << "xp = ";
    cin >> xp;
    cout << "xk = ";
    cin >> xk;
    cout << "dx = ";
    cin >> dx;

    if (cin.fail() || dx <= 0 || xp > xk)
    {
        cout << "no value" << endl;
        return 1;
    }

    cout << fixed;
    cout << "------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |" << setw(12) << "y" << " |" << endl;
    cout << "------------------------" << endl;

    x = xp;
    while (x <= xk + 1e-9)
    {
        A = 1 + 9 * x;

        cout << "|" << setw(7) << setprecision(2) << x << " |";

        if (x <= 0 && sin(x) == 0)
            cout << setw(12) << "no value" << " |" << endl;
        else
        {
            if (x <= 0)
                B = log(fabs(sin(x))) + pow(x, 7);
            else if (x <= 3)
                B = 1 / tan(fabs(x + 1) / 2);
            else
                B = 3 * x - pow(x, 5);

            y = A + B;
            cout << setw(12) << setprecision(3) << y << " |" << endl;
        }
        x += dx;
    }
    cout << "------------------------" << endl;

    return 0;
}