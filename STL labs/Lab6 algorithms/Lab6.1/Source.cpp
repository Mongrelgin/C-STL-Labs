#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <algorithm>
using namespace std;

/*
	������ ���������� ���������� �����
	�������� �����, ������ ��������� ������������������ �������� ����������� ��������� �/��� ������� ��������� �/��� ��������� ����� ������
	������� ������ ���� �������������� � ������ ��� ���������� (������� � ����, ��� ���� � �� �� ����� ����� �������������� � ������ ������ ���� ���)
*/

int main() {
    ifstream file;
    string tmp, allText;
    list<string> allWords;
    int startWord = 0, endWord = 0;

    file.open("text.txt");

    if (!file.is_open()) {
        cout << "������, ���������� ������� ����!" << endl;
        return 0;
    }
    else {
        while (!file.eof()) {
            getline(file, tmp);
            allText += tmp;
        }
    }

    tmp.clear();
    file.close();

    cout << "Original text: " << endl;
    cout << allText << endl;

    for (int i = 0; i < allText.size(); i++) {

        startWord = allText.find_first_not_of("\n\t.,?!:;()\" ", i);
        if (startWord != string::npos) {
            endWord = allText.find_first_of("\n\t.,?!:;()\" ", 1 + startWord);
            if (endWord != string::npos) {
                tmp.assign(allText.begin() + startWord, allText.begin() + endWord);
                allWords.push_back(tmp);
                i = endWord;
            }
        }
    }

    allWords.sort();
    allWords.unique();
    
    cout << endl << "All words:" << endl;
    for (list<string>::iterator iter = allWords.begin(); iter != allWords.end(); iter++) cout << *iter << endl;

	return 0;
}