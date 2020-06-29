#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;
/*1.	Прочитать содержимое текстового файла. Файл может содержать:
    a.	Слова – состоят из латинских строчных и заглавных букв, а также цифр, длинна слова должна быть не более 20 символов
    b.	Знаки препинания – «.», «,» «!» «?» «:» «;»
    c.	Пробельные символы – пробел, табуляция, символ новой строки.
2.	Отформатировать текст следующим образом:
    a.	Не должно быть  пробельных символов отличных от пробела
    b.	Не должно идти подряд более одного пробела
    c.	Между словом и знаком препинания не должно быть пробела
    d.	После знака препинания всегда должен идти пробел
    e.	Слова длиной более 10 символов заменяются на слово «Vau!!!»
3.	Преобразовать полученный текст в набор строка, каждая из которых содержит целое количество строк (слово должно целиком находиться в строке)
и ее длинна не превышает 40 символов.*/

void deleteSimbols(string& str);
void spaceCheck(string& str);
void enterVau(string& str);
void deleteSpaces(string& str);
void stringLong(string& str);
void enterString(string& str, string way);

int main() {
    string str;//string массив с нашим текстом

    string way = "strings.txt";//Путь до файла с текстом

    enterString(str, way);//Запись текста в string массив

    deleteSimbols(str);//Удаление ненужных символов в тексте

    deleteSpaces(str);//Удаление лишних пробелов

    enterVau(str);//Замена слов состоящих из 10+ символов

    spaceCheck(str);//Проверка наличия пробелов после и перед знаками припинания

    stringLong(str);//Проверка длины строки, что бы она не превышала 40 символов


    for (int i = 0; i < str.size(); i++) cout << str[i];
    return 0;
}

void deleteSimbols(string& str) {//Замена символов (принимает строку которую будет проверять на ненужные символы)
    
    for (int i = 0; i < str.size(); i++) {//Пока текст в файле не кончился (size() - возвращаеи размер string)
        size_t position = str.find_first_of("\a\b\f\n\r\t\v");//Запись позиции ненужного символа (find_first_of - первый раз когда элемент был найден)
        if (position != string::npos) str.replace(position, 1, " ");// Если символ не является символом конца документа (string::npos максимально возможный элемент типа size_t) Удалить символ (replace - заменяет ненужный символ на пробел)
    }

}

void spaceCheck(string& str) {//Проверка наличия пробелов

    for (int i = 0; i < str.size(); i++) {//Пока текст в файле не кончился (size() - возвращаеи размер string)
        int pos = str.find_last_of(".,!?:;", i);//Поиск символа начиная c i и запись его индекса в pos
        if (pos != string::npos) {//Пока не кончится текст
            string::iterator itr = str.begin() + pos;//string итератор itr = началу строки + позиции символа
            if (*--itr == ' ') str.erase(itr);// Если символ перед pos = ' ' удалить ненужный пробел
        }

        pos = str.find_last_of(".,!?:;", i);//Поиск символа начиная c i и запись его индекса в pos

        if (pos != string::npos) {//Пока не кончится текст
            string::iterator itr = str.begin() + pos;//string итератор itr = началу строки + позиции символа
            if (*++itr != ' ') str.insert(itr, ' ');//Если символ после pos != ' ' Вставить ' '
        }
    }
}


void enterVau(string& str) {//Замена слов содержащих 10+ символ
    regex e("([a-zA-Z]){10,}");//Перменная e с регулярными выражениями
    string tmp = str;
    str = regex_replace(tmp, e, "Vau!!!");//Замена в tmp строк e на строку Vau!!!
}

void deleteSpaces(string& str) {//Удаление лишних пробелов
    for (string::iterator itr = str.begin(); itr != str.end(); itr++) {//Пока элементы в str не закончатся
        string::iterator begin = itr;//begin копия itr
        while (itr != str.end() && *itr == ' ') itr++;//Пока текст не кончился и itr = ' '
        if (itr - begin > 1) itr = str.erase(begin + 1, itr) - 1;// Если разница межу itr и begin > 1 Удаление всхе ненужных пробелов и запись в itr позиции символа
        if (itr == str.end()) break;//Выход из цикла если строка закончилась
    }
}

void stringLong(string& str) {//Проверка длины строки, что бы она не превышала 40 символов
    for (int i = 40; i < str.size(); i += 40) {//Пока строка не закончится увеичивать i на 40 каждый раз
        while (!isspace(str.at(i)) && i > 0) i--;//Пока символ не ' ' и i > o (isspace - возвращает ненулевое значение, если символ является пробельным, иначе 0
        if (i <= 0) break;
        str.replace(i, 1, 1, '\n');//Замента элемента i на символ переноса строки
        i++;
    }
}

void enterString(string& str, string way) {//Запись текста в string массив
    ifstream file(way);//file - файл с текстом

    if (file.is_open()) while (!file.eof()) getline(file, str, '\0');//Запись в str содержимого файла file пока не дойдём до \0
    file.close();//Закрытие файла

}