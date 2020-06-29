#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <iterator>
#include <time.h>
#include <conio.h>
#include <algorithm>
using namespace std;

/*
 Напишите программу – «телефонную книжку».  Записи (имя и телефон) должны хранится
 в каком-либо STL-контейнере (vector или list), причем крайне желательно, чтобы от
 типа контейнера не зависело ничего, кроме одной строки в программе – объявления
 этого контейнера (указание: используйте typedef).
 Программа должна поддерживать следующие операции:
 • Просмотр текущей записи
 • Переход к следующей записи
 • Переход к предыдущей записи
 • Вставка записи перед/после просматриваемой
 • Замена просматриваемой записи
 • Вставка записи в конец базы данных
 • Переход вперед/назад через n записей.
 Помните, что после вставки элемента итераторы становятся недействительными, поэтому
 после вставки целесообразно переставлять итератор на начало базы данных.
Постарайтесь реализовать операции вставки и замены с помощью одной и той же функции,
которой в зависимости от требуемого действия передается либо обычный итератор,
либо адаптер – один из итераторов вставки: void modifyRecord(iterator pCurrentRecord, CRecord newRecord).
Программа может сразу после запуска сама (без команд пользователя) заполнить  записную книжку некоторым
количеством записей.
*/

typedef struct {
    string lastName;
    string Name;
    string phoneNumber;
}Contact;

typedef enum {
    BACK,
    BEF,
    AFTER,
    REPLACE
}AddOption;

class PhoneBook {

    vector<Contact> contact;
    vector<Contact>::iterator curIt;

public:
    PhoneBook();
    ~PhoneBook();
    void addContacts(Contact contact);
    void showContact(const vector<Contact>::iterator itr);
    void showContact();
    void nextPage();
    void previousPage();
    template<class Iterator>
    void modifyRecord(Iterator itr, Contact cont);
    void change();
    void addContact();
    void showList();
};

PhoneBook::PhoneBook() {
}

PhoneBook::~PhoneBook() {
    contact.clear();
}

void PhoneBook::addContacts(Contact cont) {
    contact.push_back(cont);
    curIt = contact.begin();
}

template<class Iterator>
void PhoneBook::modifyRecord(Iterator itr, Contact cont) {
    fill_n(itr, 1, cont);
}

void PhoneBook::change() {
    system("cls");
    Contact cont;
    cout << "Editting page" << endl << endl;
    cout << "Enter the data and press enter." << endl << endl;
    cout << "Last name: ";
    cin >> cont.lastName;
    cout << "Name: ";
    cin >> cont.Name;
    cout << "Phone number: ";
    cin >> cont.phoneNumber;
    cout << endl << "Change record?" << endl << "Press [Y] to yes or [N] to no" << endl;
    bool exit = false;
    while (!exit) {
        char key = _getch();
        switch (key)
        {
        case 'y':
            modifyRecord(curIt, cont);
            curIt = contact.begin();
            exit = true;
            break;
        case 'n':
            exit = true;
        default:
            break;
        }
    }
    showContact(curIt);
}

void PhoneBook::addContact() {
    system("cls");
    Contact cont;
    char key;
    bool exit = false;
    bool cancel = false;
    cout << "Add page" << endl << endl;
    cout << "Enter FIO and Phone and press enter." << endl << endl;
    cout << "Last name: ";
    cin >> cont.lastName;
    cout << "Name: ";
    cin >> cont.Name;
    cout << "Phone: ";
    cin >> cont.phoneNumber;
    cout << "If you want to add the record after current record - press [1]." << endl
        << "If you want to add the record until current record - press [2]." << endl
        << "If you want to add the record at back of list - press [3]." << endl
        << "if you want to cancel addition - press [C] to cancel." << endl;
    while (!exit) {
        key = _getch();
        cout << key;
        switch (key)
        {
        case '1':
            if (curIt != contact.begin()) --curIt;
            modifyRecord(inserter(contact, curIt), cont);
            exit = true;
            break;
        case '2':
            modifyRecord(inserter(contact, ++curIt), cont);
            exit = true;
            break;
        case '3':
            modifyRecord(back_inserter(contact), cont);
            exit = true;
            break;
        case 'c':
            cancel = true;
            exit = true;
        default:
            break;
        }
    }
    if (!cancel) curIt = contact.begin();
    showContact(curIt);
}

void PhoneBook::nextPage() {
    if (1 + curIt != contact.end()) {
        ++curIt;
        showContact(curIt);
    }
    else {
        curIt = contact.begin();
        showContact(curIt);
    }
}

void PhoneBook::previousPage() {
    if (curIt != contact.begin()) {
        --curIt;
        showContact(curIt);
    }
    else {
        curIt = --contact.end();
        showContact(curIt);
    }
}

void PhoneBook::showContact() {
    system("cls");
    curIt = contact.begin();
    Contact tmpContact = *curIt;
    cout << endl << "Phone Book" << endl << endl;
    cout << "Last name: " << tmpContact.lastName << endl
        << "Name: " << tmpContact.Name << endl
        << "Phone: " << tmpContact.phoneNumber << endl;
    cout << endl << "[<] - Previous page " << "[E] - Edit page" << endl
        << "[>] - Next page     " << "[A] - Add contact" << endl
        << "[Tab] - select the page " << "\n[ESC] - Exit" << endl;
}

void PhoneBook::showContact(const vector<Contact>::iterator itr) {
    system("cls");
    if (itr != contact.end()) {
        Contact tmpContact = *itr;
        cout << endl << "Phone Book" << endl << endl;
        cout << "Last name: " << tmpContact.lastName << endl
            << "Name: " << tmpContact.Name << endl
            << "Phone: " << tmpContact.phoneNumber << endl;
        cout << endl << "[<] - Previous page " << "[E] - Edit page" << endl
            << "[>] - Next page     " << "[A] - Add contact" << endl
            << "[Tab] - select the page" << "\n[ESC] - Exit" << endl;
    }
}

void PhoneBook::showList() {
    system("cls");
    cout << "List of contacts:" << endl << endl;
    for (int i = 0; i < contact.size(); i++) {
        int ind = 1 + i;
        cout << ind << " " << contact[i].lastName << " " << contact[i].lastName << endl;
    }
    int number = 0;
    bool exit = false;
    while (!exit) {
        cout << endl << "Enter the number of page: ";
        cin >> number;
        --number;
        if (number < contact.size() && number >= 0) {
            curIt = contact.begin();
            advance(curIt, number);
            exit = true;
        }
        else {
            cout << "There is no page with that number." << endl;
        }
    }
    showContact(curIt);
}

int main()
{
    PhoneBook phoneBook;
    Contact cont;
    cont.lastName = "Petrov";
    cont.Name = "Sasha";
    cont.phoneNumber = "88005553535";
    phoneBook.addContacts(cont);
    cont.lastName = "Sidorova";
    cont.Name = "Svetlana";
    cont.phoneNumber = "89021389073";
    phoneBook.addContacts(cont);
    phoneBook.showContact();

    bool exit = false;
    int key = 0;
    while (!exit) {
        key = _getch();
        switch (key)
        {
        case 9:
            phoneBook.showList();
            break;
        case 75:
            phoneBook.previousPage();
            break;
        case 77:
            phoneBook.nextPage();
            break;
        case 101:
            phoneBook.change();
            break;
        case 97:
            phoneBook.addContact();
            break;
        case 27:
            exit = true;
            break;
        default:
            break;
        }
    }
}
