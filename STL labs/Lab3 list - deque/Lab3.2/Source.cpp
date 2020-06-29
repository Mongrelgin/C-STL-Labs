#include <iostream>
#include <list>
#include <ctime>
using namespace std;

/*������������ ���������, �������
a.	��������� list<int> 15 ���������� ���������� �� 1 �� 20, ������ ����� ��������� �� 0 �� 20 �������� 
(����������� ��������� �� ����� ������ 0, 1. 2, 3, 4, 5, 7, 14)
b.	������� ���������� ������ � ��������� �������: ������ �������, ��������� �������, ������ �������, ������������� �������, 
������ ������� � �.�.

�������� ���� ������ ��������:
1 2 3 4 5 6 7 8
�� ����� ����� ����� ��� 
1 8 2 7 3 6 4 5

���������: ����� ������������ �������� � ��������������� ���������
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
	srand(time(NULL));//��������� ��������� ����� ���������, � �� ����� � ��� �� ��� ���������
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