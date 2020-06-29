#include <iostream>
#include <vector>
using namespace std;

/* Напишите программу, сохраняющую в векторе числа, полученные из стандартного ввода (окончанием ввода является число 0). 
Удалите все элементы, которые делятся на 2 (не используете стандартные алгоритмы STL), если последнее число 1. 
Если последнее число 2, добавьте после каждого числа которое делится на 3 три единицы.*/

void show(vector<int> v);

int main()
{
    int i = 0, buf = 1;
    vector<int> num;
    vector<int>::iterator iter;
    do
    {
        cin >> buf;
        if (buf != 0)
            num.push_back(buf);
    } while (buf != 0);

    show(num);
    iter = num.begin();
    if (num[num.size() - 1] == 1)
    {
        while (i < num.size())
        {
            if (num[i] % 2 == 0)
            {
                num.erase(num.begin() + i);
                i = 0;
            }
            else
                i++;
        }
        show(num);
    }
    i = 0;
    if (num[num.size() - 1] == 2)
    {
        while (i < num.size())
        {
            if (num[i] % 3 == 0)
            {
                i++;
                num.insert(num.begin() + i, 3, 1);
            }
            i++;
        }
        show(num);
    }
    return 0;
}

void show(vector<int> v)//Вывод содержимого вектора
{
    vector<int>::iterator iter;

    iter = v.begin();
    while (iter != v.end())//
    {
        cout << *iter << " ";
        iter++;
    }
    cout << endl;
}