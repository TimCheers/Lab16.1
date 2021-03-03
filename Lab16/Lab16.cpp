#include <iostream>
#include <vector>
using namespace std;
int main()
{
	system("chcp 1251>nul");
	srand(time(NULL));
	vector<int> STR;
    int n = -1;
    cout << "Введите количество элементов: ";
    while (n < 0)
    {
        cin >> n;
        if (n < 0)
        {
            cout << "Введено некоректное значение. Введите значение заново";
        }
    }
    cout << "Введите элементы:\n\n";
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cout << "Введите " << i + 1 << " эелемент:";
        cin >> tmp;
        STR.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        cout << STR[i] << endl;
    }
    vector<int> a;
    vector<int> b;
    int grup = 1;
    cout << "\n----------------------------------------------\n";
    while (grup < n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < grup; j++)
            {
                a.push_back(STR[i]);
                i++;
            }
            for (int j = 0; j < grup; j++)
            {
                b.push_back(STR[i]);
                i++;
            }
            if (n % 2 != 0 && i == n - 1)
            {
                b.push_back(STR[i]);
            }
            i--;
        }
        for (int k = 0; k < a.size(); k++)
        {
            cout << a[k] << endl;
        }
        cout << "\n----------------------------------------------\n";
        if (n % 2 == 0)
        {
            for (int k = 0; k < b.size(); k++)
            {
                cout << b[k] << endl;
            }
        }
        else
        {
            for (int k = 0; k < b.size(); k++)
            {
                cout << b[k] << endl;
            }
        }
        for (int i = 0; i < n; i++)
        {
            int A = 0, B = 0;
            for (int j = 0; j < grup; j++)
            {

            }
        }
        grup *= 2;
        a.clear();
        b.clear();
    }
    return 0;
}

