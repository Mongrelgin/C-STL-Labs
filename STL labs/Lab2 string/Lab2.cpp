#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;
/*1.	��������� ���������� ���������� �����. ���� ����� ���������:
    a.	����� � ������� �� ��������� �������� � ��������� ����, � ����� ����, ������ ����� ������ ���� �� ����� 20 ��������
    b.	����� ���������� � �.�, �,� �!� �?� �:� �;�
    c.	���������� ������� � ������, ���������, ������ ����� ������.
2.	��������������� ����� ��������� �������:
    a.	�� ������ ����  ���������� �������� �������� �� �������
    b.	�� ������ ���� ������ ����� ������ �������
    c.	����� ������ � ������ ���������� �� ������ ���� �������
    d.	����� ����� ���������� ������ ������ ���� ������
    e.	����� ������ ����� 10 �������� ���������� �� ����� �Vau!!!�
3.	������������� ���������� ����� � ����� ������, ������ �� ������� �������� ����� ���������� ����� (����� ������ ������� ���������� � ������)
� �� ������ �� ��������� 40 ��������.*/

void deleteSimbols(string& str);
void spaceCheck(string& str);
void enterVau(string& str);
void deleteSpaces(string& str);
void stringLong(string& str);
void enterString(string& str, string way);

int main() {
    string str;//string ������ � ����� �������

    string way = "strings.txt";//���� �� ����� � �������

    enterString(str, way);//������ ������ � string ������

    deleteSimbols(str);//�������� �������� �������� � ������

    deleteSpaces(str);//�������� ������ ��������

    enterVau(str);//������ ���� ��������� �� 10+ ��������

    spaceCheck(str);//�������� ������� �������� ����� � ����� ������� ����������

    stringLong(str);//�������� ����� ������, ��� �� ��� �� ��������� 40 ��������


    for (int i = 0; i < str.size(); i++) cout << str[i];
    return 0;
}

void deleteSimbols(string& str) {//������ �������� (��������� ������ ������� ����� ��������� �� �������� �������)
    
    for (int i = 0; i < str.size(); i++) {//���� ����� � ����� �� �������� (size() - ���������� ������ string)
        size_t position = str.find_first_of("\a\b\f\n\r\t\v");//������ ������� ��������� ������� (find_first_of - ������ ��� ����� ������� ��� ������)
        if (position != string::npos) str.replace(position, 1, " ");// ���� ������ �� �������� �������� ����� ��������� (string::npos ����������� ��������� ������� ���� size_t) ������� ������ (replace - �������� �������� ������ �� ������)
    }

}

void spaceCheck(string& str) {//�������� ������� ��������

    for (int i = 0; i < str.size(); i++) {//���� ����� � ����� �� �������� (size() - ���������� ������ string)
        int pos = str.find_last_of(".,!?:;", i);//����� ������� ������� c i � ������ ��� ������� � pos
        if (pos != string::npos) {//���� �� �������� �����
            string::iterator itr = str.begin() + pos;//string �������� itr = ������ ������ + ������� �������
            if (*--itr == ' ') str.erase(itr);// ���� ������ ����� pos = ' ' ������� �������� ������
        }

        pos = str.find_last_of(".,!?:;", i);//����� ������� ������� c i � ������ ��� ������� � pos

        if (pos != string::npos) {//���� �� �������� �����
            string::iterator itr = str.begin() + pos;//string �������� itr = ������ ������ + ������� �������
            if (*++itr != ' ') str.insert(itr, ' ');//���� ������ ����� pos != ' ' �������� ' '
        }
    }
}


void enterVau(string& str) {//������ ���� ���������� 10+ ������
    regex e("([a-zA-Z]){10,}");//��������� e � ����������� �����������
    string tmp = str;
    str = regex_replace(tmp, e, "Vau!!!");//������ � tmp ����� e �� ������ Vau!!!
}

void deleteSpaces(string& str) {//�������� ������ ��������
    for (string::iterator itr = str.begin(); itr != str.end(); itr++) {//���� �������� � str �� ����������
        string::iterator begin = itr;//begin ����� itr
        while (itr != str.end() && *itr == ' ') itr++;//���� ����� �� �������� � itr = ' '
        if (itr - begin > 1) itr = str.erase(begin + 1, itr) - 1;// ���� ������� ���� itr � begin > 1 �������� ���� �������� �������� � ������ � itr ������� �������
        if (itr == str.end()) break;//����� �� ����� ���� ������ �����������
    }
}

void stringLong(string& str) {//�������� ����� ������, ��� �� ��� �� ��������� 40 ��������
    for (int i = 40; i < str.size(); i += 40) {//���� ������ �� ���������� ���������� i �� 40 ������ ���
        while (!isspace(str.at(i)) && i > 0) i--;//���� ������ �� ' ' � i > o (isspace - ���������� ��������� ��������, ���� ������ �������� ����������, ����� 0
        if (i <= 0) break;
        str.replace(i, 1, 1, '\n');//������� �������� i �� ������ �������� ������
        i++;
    }
}

void enterString(string& str, string way) {//������ ������ � string ������
    ifstream file(way);//file - ���� � �������

    if (file.is_open()) while (!file.eof()) getline(file, str, '\0');//������ � str ����������� ����� file ���� �� ����� �� \0
    file.close();//�������� �����

}