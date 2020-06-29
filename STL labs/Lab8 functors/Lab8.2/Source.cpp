#include <iostream>
#include <algorithm>
#include <list>
#include <functional>
#include <iterator>
#include <string>
using namespace std;
/*
����������� ���������, �������:
a.	��������� �������� �������������� ����� ��������� ��:
i.	����� Shape.
1.	�������� ���������� � ��������� ������ ������ (���������� x � y).
2.	�������� ����� IsMoreLeft, ����������� ���������� ����������� �� ������ ������ ����� (������������ �� ��������� ������) ��� ������ ���������� � �������� ���������
3.	�������� ����� IsUpper, ����������� ���������� ����������� �� ������ ������ ���� (������������ �� ��������� ������) ��� ������ ���������� � �������� ���������
4.	���������� ����� ����������� ������� ��������� Draw (������ ������ � ���������� ���� ������ ������ �������� �� ����������� ����� ���� �������� � ��������� �����)
ii.	����� Circle ����������� �� ������ Shape
1.	��������� Draw
iii.	����� Triangle ����������� �� ������ Shape
1.	��������� Draw
iv.	����� Square ����������� �� ������ Shape
1.	��������� Draw

b.	�������� ������ list<Shape*>, ���������� ����������� �� ��������� ������

c.	� ������� ����������� ���������� � ��������� ������� (Draw) ��� ������

d.	� ������� ����������� ���������� � ��������� ��������� ������ �� ��������� ������ �����-������� (������ � ����, ��� � ������ ������ ������ ���� ������ ����������� �����, ���������� x ) � ������� ������ (Draw)

e.	� ������� ����������� ���������� � ��������� ��������� ������ �� ��������� ������ ������-������ � ������� ������

f.	� ������� ����������� ���������� � ��������� ��������� ������ �� ��������� ������ ������-���� � ������� ������

g.	� ������� ����������� ���������� � ��������� ��������� ������ �� ��������� ������ �����-����� � ������� ������

*/

typedef struct {
    int x, y;
} Point;

class Shape {

    int x = 0, y = 0;
    string type = "";

protected:
    Point center;

public:
    Shape(int x, int y, string type) {
        this->x = x;
        center.x = x;
        this->y = y;
        center.y = y;
        this->type = type;
    }

    bool FromLeftToRight(Shape* sh) {
        return (center.x < sh->center.x);
    }

    bool FromRightToLeft(Shape* sh) {
        return (center.x > sh->center.x);
    }

    bool FromUpToDown(Shape* sh) {
        return (center.y > sh->center.y);
    }

    bool FromDownToUp(Shape* sh) {
        return (center.y < sh->center.y);
    }

    void Draw() {
        cout << "Type is: " << this->type << ". Mid in (" << this->x << ", " << this->y << ");" << endl;
    };

    int IsMoreLeft(int x, int y) {
        cout << "(" << x << ", " << y << ");" << endl;

        if (x < this->x) {
            cout << "Left? - Yes" << endl;
            return 1;
        }

        cout << "Left? - No" << endl;
        return 0;
    };

    int IsUpper(int x, int y) {
        cout << "(" << x << ", " << y << ");" << endl;
        if (y > this->y) {
            cout << "Up? - Yes" << endl;
            return 1;
        }

        cout << "Up? - No" << endl;
        return 0;
    };
};

class Circle : public Shape {

    int x = 0, y = 0;
    string type = "";

public:
    Circle(int x, int y, string type) : Shape(x, y, "Circle") {
        this->x = x;
        this->y = y;
        this->type = type;
    };

    ~Circle() {};

    void Draw() {
        cout << endl << "Type is: " << this->type << ". Mid in (" << this->x << ", " << this->y << ");" << endl;
    };
};

class Triangle : public Shape {

    int x = 0, y = 0;
    string type = "";

public:
    Triangle(int x, int y, string type) : Shape(x, y, "Triangle") {
        this->x = x;
        this->y = y;
        this->type = type;
    }

    void Draw() {
        cout << endl << "Type is: " << this->type << ". Mid in (" << this->x << ", " << this->y << ");" << endl;
    };
};

class Square : public Shape {
    int x = 0, y = 0;
    string type = "";

public:
    Square(int x, int y, string type) : Shape(x, y, "Square") {
        this->x = x;
        this->y = y;
        this->type = type;
    }

    void Draw() {
        cout << endl << "Type is: " << this->type << ". Mid in (" << this->x << ", " << this->y << ");" << endl;
    };
};



int main() {
    list<Shape*> myShapes;

    Shape shape(7, 8, "Shape");
    myShapes.push_back(&shape);
    shape.Draw();
    shape.IsMoreLeft(4, 6);
    shape.IsUpper(6, 9);

    Circle circle(-7, -8, "Circle");
    myShapes.push_back(&circle);
    circle.Draw();
    circle.IsMoreLeft(-8, -7);
    circle.IsUpper(-6, -7);

    Triangle triangle(-7, 8, "Triangle");
    myShapes.push_back(&triangle);
    triangle.Draw();
    triangle.IsMoreLeft(-8, 7);
    triangle.IsUpper(-6, 5);

    Square square(7, -8, "Square");
    myShapes.push_back(&square);
    square.Draw();
    square.IsMoreLeft(6, -6);
    square.IsUpper(7, -4);

    cout << endl << "All shapes:" << endl;
    for_each(myShapes.begin(), myShapes.end(), mem_fn(&Shape::Draw));
    cout << endl;

    myShapes.sort(mem_fun(&Shape::FromLeftToRight));
    cout << "After sort left -> right:" << endl;
    for_each(myShapes.begin(), myShapes.end(), mem_fn(&Shape::Draw));
    cout << endl;

    myShapes.sort(mem_fun(&Shape::FromRightToLeft));
    cout << "After sort right -> left:" << endl;
    for_each(myShapes.begin(), myShapes.end(), mem_fn(&Shape::Draw));
    cout << endl;

    myShapes.sort(mem_fun(&Shape::FromUpToDown));
    cout << "After sort up -> down:" << endl;
    for_each(myShapes.begin(), myShapes.end(), mem_fn(&Shape::Draw));
    cout << endl;

    myShapes.sort(mem_fun(&Shape::FromDownToUp));
    cout << "After sort down -> up:" << endl;
    for_each(myShapes.begin(), myShapes.end(), mem_fn(&Shape::Draw));
    cout << endl;
}
