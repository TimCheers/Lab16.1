//не работает эта дичь
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
void met1(vector<int>&STR,int n)
{
    int max = 0, Sser = 1, Kolser = 1;
    while (Kolser != 0)
    {
        max = 0;
        Sser = 1;
        Kolser = 1;
        for (int i = 0; i < n - 2; i++)
        {
            if (STR[i] <= STR[i + 1])
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
        if (Kolser == 1)
        {
            Kolser = 0;
        }
        //cout << "\n------------------------------------------------------\n" << max << endl << Kolser << endl;
        if (Kolser != 0)
        {
            vector<int> tmp;
            vector < vector <int> > a(Kolser, vector <int>(max));
            int b = 0;
            bool f = 0, f1 = 0;
            for (int i = 0; i < Kolser; i++)
            {
                a[i][0] = STR[b];
                int j = 0;
                if (b != n - 1)
                {
                    if (STR[b] > STR[b + 1])
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
            }
            STR.clear();
            if (Kolser % 2 != 0)
            {
                int i = 0;
                while (a[Kolser - 1][i] != 0 && i != max - 1)
                {
                    tmp.push_back(a[Kolser - 1][i]);
                    i++;
                }
            }
            cout << "\n\nСерии:\n\n";
            int B = 0;
            for (int i = 0; i < Kolser; i++)
            {
                for (int j = 0; j < max; j++)
                    cout << a[i][j] << '\t';
                cout << endl;
            }
            int P = 0;
            int P1 = Kolser;
            if (Kolser % 2 != 0)
            {
                P1 = Kolser - 1;
            }
            for (int i = 0; i < P1; i++)
            {
                for (int o = 0; o < 2; o++)
                {
                    for (int j = 0; j < max; j++)
                    {
                        if (a[i][j] != 0)
                        {
                            STR.push_back(a[i][j]);
                        }
                        else
                        {
                            j = max;
                        }
                    }
                    i++;
                }
                int tmp;
                for (int i = P; i < STR.size() - 1; i++)
                {
                    for (int j = P; j < STR.size() - 1; j++)
                    {

                        if (STR[j] > STR[j + 1])
                        {
                            tmp = STR[j + 1];
                            STR[j + 1] = STR[j];
                            STR[j] = tmp;
                        }
                    }
                }
                P = STR.size();
                i--;
            }
            cout << "\n------------------------------------------------------\n" << endl;
            if (Kolser % 2 != 0)
            {
                for (int i = 0; i < tmp.size(); i++)
                {
                    STR.push_back(tmp[i]);
                }
                cout << "\n------------------------------------------------------\n" << endl;
                for (int i = 0; i < n; i++)
                {
                    cout << STR[i] << "\t";
                }
            }
        }
    }
    cout << "Отсартированный массив:" << endl;
    cout << "\n------------------------------------------------------\n" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << STR[i] << "\t";
    }
    cout << "\n------------------------------------------------------\n" << endl;
}
void met2(vector<int>& STR, int left, int right)
{
    if (left == right) return;
    int mid = (left + right) / 2;
    met2(STR, left, mid);
    met2(STR, mid + 1, right);
    int i = left;
    int j = mid + 1;
    int* a = new int[STR.size()];
    for (int step = 0; step < right - left + 1; step++)
    {
        if ((j > right) || ((i <= mid) && (STR[i] < STR[j])))
        {
            a[step] = STR[i];
            i++;
        }
        else
        {
            a[step] = STR[j];
            j++;
        }
    }
    for (int step = 0; step < right - left + 1; step++)
        STR[left + step] = a[step];
}
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
    met1(STR, n);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   /* cout << "\n\n----------------------------------------------------------------\n\n";
    met2(STR, 0, n - 1);*/
    for (int i = 0; i < n; i++)
    {
        cout << STR[i] << "\t";
    }
    return 0;
}

