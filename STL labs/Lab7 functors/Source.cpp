#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;

/*
Разработать функтор, позволяющий собирать статистику о последовательности целых чисел (послед может содержать числа от -500 до 500). 
Функтор после обработки последовательности алгоритмом for_each должен предоставлять следующую статистику:
a.	Максимальное число в последовательности
b.	Минимальное число в последовательности
c.	Среднее число в последовательности
d.	Количество положительных чисел
e.	Количество отрицательных чисел
f.	Сумму нечетных элементов последовательности
g.	Сумму четных элементов последовательности   
h.	Совпадают ли первый и последний элементы последовательности.

Проверить работу программы на случайно сгенерированных последовательностях.
*/

class integer_statistics : public unary_function<int, void>
{
public:
    void operator() (int arg)
    {
        lastNumber = arg;
        quantNumbers++;
        if (firstNumber == 501) firstNumber = arg;
        if (arg > maxNumber) maxNumber = arg;
        if (arg < minNumber) minNumber = arg;
        if (arg > 0) positiveNumbers++;
        if (arg < 0) negativeNumbers++;
        if (arg % 2 == 0) evenNumbers += arg;
        if (arg % 2 != 0) oddNumbers += arg;
    }

    void CoutOurData() {
        cout << "Max number in vector is: " << maxNumber << endl;
        cout << "Min number in vector is: " << minNumber << endl;
        cout << "Average number in vector is: " << ((double)evenNumbers + (double)oddNumbers) / (double)quantNumbers << endl;
        cout << "Quantity of positive numbers in vector is: " << positiveNumbers << endl;
        cout << "Quantity of negative numbers in vector is: " << negativeNumbers << endl;
        cout << "Sum of even numbers in vector is: " << evenNumbers << endl;
        cout << "Sum of odd numbers in vector is: " << oddNumbers << endl;
        cout << "First number is: " << firstNumber << ", last number is: " << lastNumber;
        if (firstNumber == lastNumber)
        {
            cout << " and they are equal!" << endl;
        }
        else {
            cout << " and they aren't equal!" << endl;
        }
    }

private:
    int firstNumber = 501;
    int lastNumber;
    int maxNumber = 0;
    int minNumber = 501;
    int averageNumber = 0;
    int positiveNumbers = 0;
    int negativeNumbers = 0;
    int oddNumbers = 0;
    int evenNumbers = 0;
    int quantNumbers = 0;
};

int main() {
    srand(time(NULL));
    vector<int> mainVector;
    int vectorSize = rand() % 100 + 1;
    cout << "Our vector:" << endl;
    for (size_t i = 0; i < vectorSize; i++)
    {
        int number = rand() % 1000 - 500;
        mainVector.push_back(number);
        cout << number << endl;
    }
    cout << endl;
    for_each(mainVector.begin(), mainVector.end(), integer_statistics()).CoutOurData();

	return 0;
}