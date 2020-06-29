#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

/*���������� �� ���������� ������ � ���������� ���������� �����, ���������� ������ � ������ ����� ������� ����
(��� ������ � ���������� STL)*/

int main() {
	const int len = 14;//����� ������
	char Text[len];//������ ���������� ������

	ifstream fs("Text.txt", ios::in | ios::binary);//�������� �����
	if (!fs) return 1;//���� �������� ����� �� �������

	fs.getline(Text, len - 1);//������ �� ����� � ������ Text
	cout << "Our string: " << Text << endl;//����� �������
	fs.close();//�������� �����

	vector<char> v(Text, &Text[sizeof(Text) - 1]);//�������� ������� � ������ ������� � ����
	for (int i = 0; i < v.size(); i++) cout << v.at(i);//����� �������

	return 0;
}