#include <iostream>
#include <vector>
using namespace std;
//�������� �������� ���������� (����� ����������) ����������� ������� ����� �����, ��������� �������� operator[].
//RAND_MAX = 32767

void FunkSort(vector <int>& v);//�������� ������� ����������

int main()
{
	vector<int> v(10);//��������� ������ �� 10 �������� ���� int
	for (int i = 0; i < v.size(); i++)
	{
		v.operator[](i) = rand();//��������� �������� ��������� int �������
		cout << v.operator[](i) << '\n';
	}
	cout << '\n';
	FunkSort(v);//����� ������� ����������
	for (int i = 0; i < v.size(); i++) cout << v.operator[](i) << '\n';//����� �������
}

void FunkSort(vector <int>& v) {
	for (int i = 0;;)
	{
		if (v.operator[](i) > v.operator[](i + 1)) {//���� ������ ����� ������ �������
			swap(v.operator[](i), v.operator[](i + 1));//������ ������� �����
			i = 0;//�������� i ��� �� ������ �������� �� �������
		}
		else i++;
		if (i == v.size() - 1) break;//������� �� ����� ���� ����� �� ���������� ��������
	}
}