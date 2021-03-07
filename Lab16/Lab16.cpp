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



    int max = 0, Sser = 1, Kolser = 1;
    for (int i = 0; i < n-2; i++)
    {
        if (STR[i] < STR[i + 1])
        {
            Sser++;
        }
        else
        {
            Kolser++;
            if (max < Sser)
            {
                max = Sser;
            }
            Sser = 1;
        }
    }
    if (STR[n - 1] < STR[n - 2])
    {
        Kolser++;
    }
    else
    {
        Sser++;
    }
    if (max < Sser)
    {
        max = Sser;
    }
    cout << "\n------------------------------------------------------\n" << max << endl << Kolser << endl;
    vector<int> tmp;
    vector < vector <int> > a(Kolser, vector <int>(max));
    int b = 0;
    bool f = 0, f1=0;
    for (int i = 0; i < Kolser; i++)
    {
        a[i][0] = STR[b];
        int j = 0;
        if (STR[b]>STR[b+1])
        {
            i++;
        }
        else
        {
            j = 1;
        }
        if (b != n - 1)
        {
            b++;
        }
        if (b == n - 1)
        {
            f1 = 1;
            j = 0;
            a[i][j] = STR[b];
        }
        for (j; j < max; j++)
        {
            if (f == 0 && f1 == 0)
            {
                if (STR[b] > STR[b + 1])
                {
                    f = 1;
                    a[i][j] = STR[b];
                }
                else
                {
                    a[i][j] = STR[b];
                }
                if (b != n - 2)
                {
                    b++;
                }
                else
                {
                    if (STR[b] < STR[b + 1])
                    {
                        b++;
                        j++;
                        a[i][j] = STR[b];
                        f = 1;
                    }
                    else
                    {
                        b++;
                    }
                }
            }
        }
        f = 0;
    }
    STR.clear();
    if (Kolser % 2 != 0)
    {
        int i = 0;
        while (a[Kolser-1][i]!=0&&i!=max-1)
        {
            tmp.push_back(a[Kolser-1][i]);
            i++;
        }
    }
    cout << "Серии:\n";
    int B = 0;
    for (int i = 0; i < Kolser; i++) 
    {
        for (int j = 0; j < max; j++) 
            cout << a[i][j] << '\t'; 
        cout << endl;
    }
    for (int i = 1; i < Kolser; i+=2)
    {
        for (int j = 0; j < max; j++)
        {
            if (a[i][j]!=0)
            {
                STR.push_back(a[i][j]);
            }
            else
            {
                j = max;
            }
        }
        int t = STR.size();
        int l = 0;
        for (int j = 0; j < max+1; j++)
        {
            if (a[i - 1][l] != 0 && a[i - 1][l] > STR[t-1])
            {
                if (t == STR.size())
                {
                    STR.push_back(a[i - 1][l]);
                    t++;
                }
                else
                {
                    auto iter = STR.cbegin();
                    STR.emplace(iter + t, a[i - 1][l]);
                    t+=2;
                }
                l++;
            }
            else
            {
                if (t == 1 && a[i - 1][l] < STR[t - 1])
                {
                    STR.emplace(STR.begin(), a[i - 1][l]);
                    t += STR.size();
                    l++;
                }
                if (t != 1)
                {
                    t--;
                }
            }
            if (j==max-1)
            {
                j = max + 2;
            }
        }
        cout << "\n------------------------------------------------------\n" << endl;
        for (int i = 0; i < STR.size(); i++)
        {
            cout << STR[i] << "\t";
        }
    }
    cout << "\n------------------------------------------------------\n" << endl;
    if (Kolser % 2 != 0)
    {
        for (int i = 0; i < tmp.size(); i++)
        {
            STR.push_back(tmp[i]);
        }
    }
    for (int i = 0; i < STR.size(); i++)
    {
        cout << STR[i] << "\t";
    }
    return 0;
}

