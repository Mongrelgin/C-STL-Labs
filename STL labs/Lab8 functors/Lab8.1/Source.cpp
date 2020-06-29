#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;

/*
    Разработать программу, которая, используя только стандартные алгоритмы и функторы, 
    умножает каждый элемент списка чисел с плавающей  точкой на число PI
*/

void Print(double numb)
{
    cout << numb << endl;
}

int main() {
    srand(time(NULL));
    float pi = 3.14159265;
    vector<double> mainVector;
    vector<double>::iterator iter;
    int num = rand() % 20 + 1;

    cout << "Numbers before multiply:" << endl;
    for (size_t i = 0; i < num; i++)
    {
        double floatNumber = rand() % 30 + 1;
        mainVector.push_back(floatNumber);
        cout << floatNumber << endl;
    }
    cout << endl;
    for (iter = mainVector.begin(); iter != mainVector.end(); iter++)//Умножение вектора на pi
    {
        transform(iter, iter+1, &pi, iter, multiplies<double>());
    }

    cout << "Numbers after multiply:" << endl;
    for_each(mainVector.begin(), mainVector.end(), Print);

    return 0;
}
