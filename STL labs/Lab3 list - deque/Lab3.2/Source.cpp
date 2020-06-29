#include <iostream>
#include <list>
#include <ctime>
using namespace std;

/*Разработайте программу, которая
a.	Заполняет list<int> 15 случайными значениями от 1 до 20, список может содержать от 0 до 20 значений 
(обязательно проверить на длине списка 0, 1. 2, 3, 4, 5, 7, 14)
b.	Выводит содержимое списка в следующем порядке: первый элемент, последний элемент, второй элемент, предпоследний элемент, 
третий элемент и т.д.

Например если список содержит:
1 2 3 4 5 6 7 8
то вывод будет иметь вид 
1 8 2 7 3 6 4 5

Подсказка: можно использовать рекурсию и двунаправленные итераторы
*/
void RandListFunc(list<int>& mainList, int listSize);
void ListPrint(list<int>& mainList, list<int>::iterator iterBegin, list<int>::iterator iterEnd);

int main() {
	list<int> mainList;	
	list<int>::iterator iterBegin, iterEnd;
	int amountOfNumbers = 15;
	RandListFunc(mainList, amountOfNumbers);
	iterBegin = mainList.begin();
	iterEnd = --mainList.end();
	//iterEnd--;
	cout << '\n' << "Changed list: ";
	ListPrint(mainList, iterBegin, iterEnd);
	return 0;
}

void RandListFunc(list<int>& mainList, int amountOfNumbers) {
	srand(time(NULL));//Генерация случайных чисел постоянно, а не одних и тех же при включении
	cout << "Original list: ";
	for (int i = 0; i < amountOfNumbers; i++)
	{
		int randNumber = 1 + rand() % 20;
		mainList.push_back(randNumber);
		cout << randNumber << ' ';
	}
}

void ListPrint(list<int>& mainList, list<int>::iterator iterBegin, list<int>::iterator iterEnd) {
	
	if (iterBegin == iterEnd) {
		cout << *iterBegin;
		return;
	}
	cout << *iterBegin << ' ' << *iterEnd << ' ';
	iterBegin++;
	iterEnd--;
	ListPrint(mainList, iterBegin, iterEnd);
}