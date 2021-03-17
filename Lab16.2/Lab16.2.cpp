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
    while (n < 1)
    {
        cin >> n;
        if (n < 1)
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
        cout << STR[i] << "\t";
    }
}
