#include <iostream>
#include <vector>
using namespace std;
//Напишите алгоритм сортировки (любой простейший) содержимого вектора целых чисел, используя оператор at.
//RAND_MAX = 32767

void FunkSort(vector <int>& v);//Прототип функции сортировки

int main()
{
	vector<int> v(10);//Объявляем вектор на 10 значений типа int
	for (int i = 0; i < v.size(); i++)
	{
		v.at(i) = rand();//Заполняем элементы случайными int числами
		cout << v.at(i) << '\n';
	}
	cout << '\n';
	FunkSort(v);//Вызов функции сортировки
	for (int i = 0; i < v.size(); i++) cout << v.at(i) << '\n';//Вывод Вектора
}

void FunkSort(vector <int>& v) {
	try {
		for (int i = 0;;)
		{
			if (v.at(i) > v.at(i + 1)) {//Если второе число больше первого
				swap(v.at(i), v.at(i + 1));//Меняем местами числа
				i = 0;//Обнуляем i что бы заново пройтись по вектору
			}
			else i++;
			if (i == v.size()) break;//Выходим из цикла если дошли до последнего значения (Ошибка из за переполнения из за отсутствия -1)
		}
	}
	catch (out_of_range) {
		cout << "Out of range" << '\n';
	}
}