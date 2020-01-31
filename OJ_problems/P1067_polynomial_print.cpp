#include <iostream>
#include <cstdio>

using namespace std;

int main()
{

    int n, i, a[100];
    cin >> n;
    for (i = 0; i < n + 1; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n + 1; i++)
    {
        if (i == 0)
        {
            if (a[i] > 0 && a[i] != 1)
            {
                cout << a[i] << "x^" << n - i;
            }
            else if (a[i] == 1)
            {
                cout << "+"
                     << "x^" << n - i;
            }
            else if (a[i] == 0)
            {
                cout << "";
            }
            else if (a[i] == -1)
            {
                cout << "-"
                     << "x^" << n - i;
            }
            else if (a[i] < 0)
            {
                cout << a[i] << "x^" << n - i;
            }
        }
        else if (i == n)
        {
            if (a[i] > 0)
            {
                cout << "+" << a[i];
            }
            else if (a[i] == 0)
            {
                cout << "";
            }
            else
            {
                cout << a[i];
            }
        }

        else
        {
            if (a[i] > 0 && a[i] != 1)
            {
                cout << "+" << a[i] << "x^" << n - i;
            }
            else if (a[i] == 1)
            {
                cout << "+"
                     << "x^" << n - i;
            }
            else if (a[i] == 0)
            {
                cout << "";
            }
            else if (a[i] == -1)
            {
                cout << "-"
                     << "x^" << n - i;
            }
            else if (a[i] < 0)
            {
                cout << a[i] << "x^" << n - i;
            }
        }
    }
    cout << endl;
    return 0;
}