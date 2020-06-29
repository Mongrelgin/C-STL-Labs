#include <iostream>
#include <vector>
using namespace std;
//�������� �������� ���������� (����� ����������) ����������� ������� ����� �����, ��������� �������� at.
//RAND_MAX = 32767

void FunkSort(vector <int>& v);//�������� ������� ����������

int main()
{
	vector<int> v(10);//��������� ������ �� 10 �������� ���� int
	for (int i = 0; i < v.size(); i++)
	{
		v.at(i) = rand();//��������� �������� ���������� int �������
		cout << v.at(i) << '\n';
	}
	cout << '\n';
	FunkSort(v);//����� ������� ����������
	for (int i = 0; i < v.size(); i++) cout << v.at(i) << '\n';//����� �������
}

void FunkSort(vector <int>& v) {
	try {
		for (int i = 0;;)
		{
			if (v.at(i) > v.at(i + 1)) {//���� ������ ����� ������ �������
				swap(v.at(i), v.at(i + 1));//������ ������� �����
				i = 0;//�������� i ��� �� ������ �������� �� �������
			}
			else i++;
			if (i == v.size()) break;//������� �� ����� ���� ����� �� ���������� �������� (������ �� �� ������������ �� �� ���������� -1)
		}
	}
	catch (out_of_range) {
		cout << "Out of range" << '\n';
	}
}