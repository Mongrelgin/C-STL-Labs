#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

/*Прочитайте во встроенный массив С содержимое текстового файлы, скопируйте данные в вектор одной строкой кода
(без циклов и алгоритмов STL)*/

int main() {
	const int len = 14;//Длина строки
	char Text[len];//Массив содержащий строку

	ifstream fs("Text.txt", ios::in | ios::binary);//Открытие файла
	if (!fs) return 1;//Если открытие файла не удалось

	fs.getline(Text, len - 1);//Запись из файла в массив Text
	cout << "Our string: " << Text << endl;//Вывод Массива
	fs.close();//Закрытие файла

	vector<char> v(Text, &Text[sizeof(Text) - 1]);//Создание вектора и запись массива в него
	for (int i = 0; i < v.size(); i++) cout << v.at(i);//Вывод вектора

	return 0;
}