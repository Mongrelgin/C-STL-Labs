#include <iostream>
#include <vector>
using namespace std;

void fillRandom(double* arr, int size);
double fRand(double fMin, double fMax);
void vectorFill(vector<double>& v, double* arr, int size);
void sortVector(vector<double>& v);

int main() {
	const int s5 = 5, s10 = 10, s25 = 25, s50 = 50, s100 = 100;
	double d5[s5], d10[s10], d25[s25], d50[s50], d100[s100];
	vector<double> v5(s5), v10(s10), v25(s25), v50(s50), v100(s100);
	
	fillRandom(d5, s5);
	fillRandom(d10, s10);
	fillRandom(d25, s25);
	fillRandom(d50, s50);
	fillRandom(d100, s100);

	vectorFill(v5, d5, s5);
	vectorFill(v10, d10, s10);
	vectorFill(v25, d25, s25);
	vectorFill(v50, d50, s50);
	vectorFill(v100, d100, s100);

	sortVector(v5);
	sortVector(v10);
	sortVector(v25);
	sortVector(v50);
	sortVector(v100);
	

	for (int k = 0; k < v10.size(); k++) cout << v10.at(k) << '\n';
	return 0;
}

void fillRandom(double* arr, int size) {//Функция заполняет массив arr размерности size рандомными числами
	for (int i = 0; i < size; i++)
	{
		arr[i] = fRand(-1, 1);
	}
}

double fRand(double fMin, double fMax) {//Возвращает рандомное double число от dMin до fMax
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}

void vectorFill(vector<double>& v, double* arr, int size) {//Заполняет вектор v размерности size значениями из массива arr
	for (int i = 0; i < size; i++)
	{
		v.at(i) = arr[i];
		//cout << v.at(i) << '\n';
	}
	//cout << '\n';
}

void sortVector(vector<double>& v) {//Сортировка вектора v
	for (int i = 0;;)
	{
		if (v.at(i) > v.at(i + 1)) {//Если второе число больше первого
			swap(v.at(i), v.at(i + 1));//Меняем местами числа
			i = 0;//Обнуляем i что бы заново пройтись по вектору
		}
		else i++;
		if (i == v.size() - 1) break;//Выходим из цикла если дошли до последнего значения (Ошибка из за переполнения из за отсутствия -1)
	}
}