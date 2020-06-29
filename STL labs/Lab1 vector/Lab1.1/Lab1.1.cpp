#include <iostream>
#include <vector>
using namespace std;
//Напишите алгоритм сортировки (любой простейший) содержимого вектора целых чисел, используя оператор operator[].
//RAND_MAX = 32767

void FunkSort(vector <int>& v);//Прототип функции сортировки

int main()
{
	vector<int> v(10);//Объявляем вектор на 10 значений типа int
	for (int i = 0; i < v.size(); i++)
	{
		v.operator[](i) = rand();//Заполняем элементы случайные int числами
		cout << v.operator[](i) << '\n';
	}
	cout << '\n';
	FunkSort(v);//Вызов функции сортировки
	for (int i = 0; i < v.size(); i++) cout << v.operator[](i) << '\n';//Вывод Вектора
}

void FunkSort(vector <int>& v) {
	for (int i = 0;;)
	{
		if (v.operator[](i) > v.operator[](i + 1)) {//Если второе число больше первого
			swap(v.operator[](i), v.operator[](i + 1));//Меняем местами числа
			i = 0;//Обнуляем i что бы заново пройтись по вектору
		}
		else i++;
		if (i == v.size() - 1) break;//Выходим из цикла если дошли до последнего значения
	}
}