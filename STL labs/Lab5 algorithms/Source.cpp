#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <ctime>
using namespace std;

/*
��������� vector<DataStruct> ����������� DataStruct, ��� ���� key1 � key2, ������������ ��������� ������� � ��������� �� -5 �� 5, str ����������� �� ������� (������� �������� 10 ������������ �����, ������ ������ ������������ ��������� �������)
������� ���������� ������ �� ������
��������� ������ ��������� �������:
    �� ����������� key1
    ���� key1 ����������, �� �� ����������� key2
    ���� key1 � key2 ����������, �� �� ����������� ������ ������ str
������� ���������� ������ �� ������
*/

typedef struct
{
    int key1;
    int key2;
    string str;
} DataStruct;

void TextTableFilling(vector<string>& textTable);
void MainVectorFilling(vector<DataStruct>& mainVector, vector<string>& textTable);
void MainVectorPrint(vector<DataStruct>& mainVector);
bool cmp(DataStruct beginVector, DataStruct endVector);

int main() {
    srand(time(NULL));

    vector<DataStruct> mainVector;    
    vector<string> textTable;

    TextTableFilling(textTable);
    MainVectorFilling(mainVector, textTable);
    cout << "Main vector before sort:" << endl;
    MainVectorPrint(mainVector);
    sort(mainVector.begin(), mainVector.end(), cmp);
    cout << "Main vector after sort:" << endl;
    MainVectorPrint(mainVector);

	return 0;
}

void TextTableFilling(vector<string>& textTable) {
    textTable.push_back("1textLel");
    textTable.push_back("2textQuadro");
    textTable.push_back("3textSaske");
    textTable.push_back("4textMomo");
    textTable.push_back("5textAlehandro");
    textTable.push_back("6textChidori");
    textTable.push_back("7textResurection");
    textTable.push_back("8textCrocodiles");
    textTable.push_back("9textPorompomomomo");
    textTable.push_back("10text");
}

void MainVectorFilling(vector<DataStruct>& mainVector, vector<string>& textTable) {
    vector<string>::iterator iter;

    for (size_t i = 0; i < 10; i++)
    {
        DataStruct addStruct;
        int textNumb = rand() % 10;
        iter = textTable.begin() + textNumb;
        addStruct.key1 = rand() % 10 - 5;
        addStruct.key2 = rand() % 10 - 5;
        addStruct.str = *iter;
        mainVector.push_back(addStruct);
    }
}

void MainVectorPrint(vector<DataStruct>& mainVector) {
    vector<DataStruct>::iterator iter = mainVector.begin();

    for (size_t i = 0; i < 10; i++)
    {
        DataStruct printStruct = *iter;
        cout << i + 1 << " element: ";
        cout << "Key1: " << printStruct.key1 << ' ';
        cout << "Key2: " << printStruct.key2 << ' ';
        cout << "str: " << printStruct.str << endl;
        iter++;
    }
}

bool cmp(DataStruct firstElement, DataStruct secondElement) {

    if (firstElement.key1 == secondElement.key1 && firstElement.key2 == secondElement.key2) {
        return firstElement.str.size() > secondElement.str.size();
    }
    else if (firstElement.key1 == secondElement.key1) {
        return firstElement.key2 > secondElement.key2;
    }
    else {
        return firstElement.key1 > secondElement.key1;
    }
}