#include <iostream>
#include <vector>
#include <list>
using namespace std;

/*� ������� ����� ���� ��������� ��������, ������� �������� ��� ���������� ������������� ���� �� ���� ������� ���������� (low, normal, high)

�������� �� ������� ����������� � ������������ � �� ������������ (������� ����������� �������� � ����������� high, ����� normal, ����� low), 
�������� � ����������� ������������ ����������� �� ������� � ������� �� �����������. 

� ������� ����� ����� ����������� �������� ����������� � ��� �������� � ����������� low ����������� � ������ ����������� � ������� 
����������� ���� ��������� �� high � ��������� �������� � ����������� normal.

����������� ���� �����, ��������� list ��� deque. ��������� ���� �����.
������������� ���������, �������� ���������� �����, ������������, ���  ����� �������� ���������.
*/

typedef enum {
	LOW,
	NORMAL,
	HIGH
} ElementPriority;

typedef struct {
	string name;
} QueueElement;

class QueueWithPriority {
	list<QueueElement> listLow;
	list<QueueElement> listNormal;
	list<QueueElement> listHigh;

public:
	//����������� ������� ������ �������
	QueueWithPriority() {
		listLow = {};
		listNormal = {};
		listHigh = {};
	};

	//����������
	~QueueWithPriority() {};
	//�������� � ������� ������� element � ����������� priority
	void PutElementToQueue(const QueueElement& element, ElementPriority priority);

	//�������� ������� �� �������, ����� ������ ���������� ������� � ���������� �����������, ������� ��� �������� � ������� ������ ������
	QueueElement GetElementFromQueue();

	//��������� ������������
	void Accelerate();
};

void QueueWithPriority::PutElementToQueue(const QueueElement& element, ElementPriority priority) {
	switch (priority)
	{
	case LOW:
		listLow.push_back(element);
		cout << "Element: " << element.name << " was added to the Low list" << '\n';
		break;
	case NORMAL:
		listNormal.push_back(element);
		cout << "Element: " << element.name << " was added to the Normal list" << '\n';
		break;
	case HIGH:
		listHigh.push_back(element);
		cout << "Element: " << element.name << " was added to the High list" << '\n';
		break;
	default:
		break;
	}
}

QueueElement QueueWithPriority::GetElementFromQueue() {
	list<QueueElement>::iterator iter;
	if (!listHigh.empty()) {
		iter = listHigh.begin();
		return *iter;
	}
	else if (!listNormal.empty()) {
		iter = listNormal.begin();
		return *iter;
	}
	else if (!listLow.empty()) {
		iter = listLow.begin();
		return *iter;
	}
}

void QueueWithPriority::Accelerate() {
	listHigh.splice(listHigh.end(), listLow);
	cout << "Queue after acceleration" << '\n';
	cout << "High list:" << '\n';
	list<QueueElement>::iterator iter;
	iter = listHigh.begin();
	for (int i = 0; i < listHigh.size(); i++)
	{		
		QueueElement text = *iter;
		cout << "Element " << i << " from listLow is: " << text.name << '\n';
		iter++;
	}

	cout << "Normal list:" << '\n';
	iter = listNormal.begin();
	for (int i = 0; i < listNormal.size(); i++)
	{
		QueueElement text = *iter;
		cout << "Element " << i << " from listLow is: " << text.name << '\n';
		iter++;
	}

	cout << "Low list:" << '\n';
	iter = listLow.begin();
	for (int i = 0; i < listLow.size(); i++)
	{
		QueueElement text = *iter;
		cout << "Element " << i << " from listLow is: " << text.name << '\n';
		iter++;
	}
}

int main() {
	QueueWithPriority classQueue;
	QueueElement text{ "FirstLow" };
	classQueue.PutElementToQueue(text, LOW);
	text = { "FirstNormal" };
	classQueue.PutElementToQueue(text, NORMAL);
	text = { "FirstHigh" };
	classQueue.PutElementToQueue(text, HIGH);
	text = { "SecondNormal" };
	classQueue.PutElementToQueue(text, NORMAL);
	text = { "ThirdNormal" };
	classQueue.PutElementToQueue(text, NORMAL);
	text = { "SecondHigh" };
	classQueue.PutElementToQueue(text, HIGH);

	
	text = classQueue.GetElementFromQueue();
	cout << "First element from Queue with the highest priority is: " << text.name << '\n';
	classQueue.Accelerate();

	return 0;	
}