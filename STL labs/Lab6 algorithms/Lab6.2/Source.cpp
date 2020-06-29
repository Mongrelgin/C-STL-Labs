#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

/*
�������� ���������, ������� ��������� ��������� �������� (��� �������� ������ ����������� � ������� ����������� ����������):
a.	��������� ������ ��������������� ��������. �������������� ������ ����� ���� �������������, ���������, ��������������� ��� ���� ����������. ��������� ����������� �������������� ������  ���������� ����, 
b.	������������ ����� ���������� ������ ���� ����� ������������ � ������� (��� ����������� ��������� � ������ ����� 3, ������� 4 � �.�.)
c.	������������ ���������� �������������, ��������� � ��������������� � �������
d.	������� ��� ������������� 
e.	�� ��������� ����� ������� ������� vector<Point>, ������� �������� ���������� ����� �� ������ (�����) ������ ������, �.�. ������ ������� ����� ������� �������� ���������� ����� �� ������� ������ ������, ������ ������� ����� ������� �������� ���������� ����� �� ������� ������ ������ � �.�.
f.	�������� ������ ���, ����� �� �������� � ������ ��� ������������, ����� ��� ��������, � ����� ��������������.
g.	������������� ������ ����� ������� ����� ������
*/

typedef struct
{
    int x, y;
} Point;

typedef  struct
{
    int vertex_num;      // ���������� ������, ��� ������������ 3, ��� �������� � 
                                   // �������������� 4, ��� ���� ��������� 5
    vector<Point> vertexes;   // ������ ���������� ���������� ������ ������
    // ��� ������������ �������� 3 ��������
                    // ��� �������� � �������������� �������� 4 
                                             // ��������
                                             // ��� ������������� 5 ���������
} Shape;

Shape CreateFigure(int verNumb, int quadrangle = 0);
void DeleteAllPentagons(vector<Shape>& mainVector);
void PrintVector(vector<Shape>& mainVector);
void CreateFirstPointsVector(vector<Point>& firstPoints, vector<Shape>& mainVector);
bool Cmp(Shape firstShape, Shape secondShape);
bool ConfirmationOfQuadratism(Shape  mainShape);

int allTops = 0, allTriangles = 0, allSquares = 0, allRectangles = 0, allPentagons = 0;

int main() {
    srand(time(NULL));
    vector<Shape> mainVector;
    vector<Point> firstPoints;
    int numThree = 3, numFour = 4, numFive = 5;
    int square = 1, rectangle = 2;

    
    mainVector.push_back(CreateFigure(numFive));
    mainVector.push_back(CreateFigure(numFour, rectangle));
    mainVector.push_back(CreateFigure(numThree));
    mainVector.push_back(CreateFigure(numFive));
    mainVector.push_back(CreateFigure(numFour, square));
    mainVector.push_back(CreateFigure(numFour, rectangle));

    cout << "All figures: " << endl;
    PrintVector(mainVector);

    cout << endl;
    DeleteAllPentagons(mainVector);
    cout << "All figures after deleted pentagons: " << endl;
    PrintVector(mainVector);

    cout << endl;
    CreateFirstPointsVector(firstPoints, mainVector);

    cout << "All figures after sort: " << endl;
    sort(mainVector.begin(), mainVector.end(), Cmp);
    PrintVector(mainVector);
	return 0;
}

Shape CreateFigure(int verNumb, int quadrangle) {
    Shape ourFigure;

    ourFigure.vertex_num = verNumb;
    allTops += verNumb;

    if (verNumb == 3)
    {
        allTriangles++;
    }
    else if (verNumb == 4) {
        if (quadrangle == 1)
        {
            Point onePoint;
            int n = rand() % 5 + 1;

            onePoint.x = rand() % 10;
            onePoint.y = rand() % 10;
            ourFigure.vertexes.push_back(onePoint);

            onePoint.x += n;
            ourFigure.vertexes.push_back(onePoint);

            onePoint.x -= n;
            onePoint.y += n;
            ourFigure.vertexes.push_back(onePoint);

            onePoint.x += n;
            ourFigure.vertexes.push_back(onePoint);

            allSquares++;

            return ourFigure;

        }
        else {
            Point onePoint;
            int n = rand() % 5 + 1;
            int l = n + rand() % 5 + 1;

            onePoint.x = rand() % 10;
            onePoint.y = rand() % 10;
            ourFigure.vertexes.push_back(onePoint);

            onePoint.x += l;
            ourFigure.vertexes.push_back(onePoint);

            onePoint.x -= l;
            onePoint.y += n;
            ourFigure.vertexes.push_back(onePoint);

            onePoint.x += l;
            ourFigure.vertexes.push_back(onePoint);

            allRectangles++;

            return ourFigure;
        }
    }
    else {
        allPentagons++;
    }

    for (int i = 0; i < verNumb; i++)
    {
        Point onePoint;
        onePoint.x = rand() % 10;
        onePoint.y = rand() % 10;
        ourFigure.vertexes.push_back(onePoint);
    }
    return ourFigure;
}

void DeleteAllPentagons(vector<Shape>& mainVector) {
    vector<Shape>::iterator iter = mainVector.begin();
    int kek = 0;
    for (int i = 0; i < mainVector.size() - kek; i++)
    {
        Shape ourFigure = *iter;
        if (ourFigure.vertex_num == 5) {
            mainVector.erase(iter);
            allPentagons--;
            allTops -= 5;
            iter = mainVector.begin() + i;
            kek++;
            i--;
        }
        iter++;
    }
}

void PrintVector(vector<Shape>& mainVector) {
    vector<Shape>::iterator iter = mainVector.begin();

    cout << "AllTops: " << allTops << " AllTriangles: " << allTriangles << " AllSquares: " << allSquares << " AllRectangles: " 
        << allRectangles << " AllPentagons: " << allPentagons << endl;

    for (int i = 0; i < mainVector.size(); i++)
    {
        Shape ourFigure = *iter;
        for (int j = 0; j < ourFigure.vertex_num; j++)
        {
            cout << '[' << ourFigure.vertexes[j].x << ',' << ourFigure.vertexes[j].y << ']' << ' ';
        }
        cout << endl;
        iter++;
    }
}

void CreateFirstPointsVector(vector<Point>& firstPoints, vector<Shape>& mainVector) {
    vector<Shape>::iterator iter = mainVector.begin();
    cout << "First points all figures: " << endl;
    for (int i = 0; i < mainVector.size(); i++)
    {
        Shape ourFigure = *iter;
        vector<Point>::iterator pointIter = ourFigure.vertexes.begin();
        firstPoints.push_back(*pointIter);
        cout << '[' << firstPoints[i].x << ',' << firstPoints[i].y << ']' << ' ';
        iter++;
    }
    cout << endl;
}


bool Cmp(Shape firstShape, Shape secondShape)
{
    if (firstShape.vertex_num == 4 && secondShape.vertex_num == 4)//���� � ������������ ����� 4 ���� �� ���� ���� �� ��� ������� return true, else false
    {
        if (ConfirmationOfQuadratism(firstShape) && ConfirmationOfQuadratism(secondShape))//���� ��� ������ ��������
            return false;
        if (!ConfirmationOfQuadratism(firstShape) && !ConfirmationOfQuadratism(secondShape))//���� ��� ������ ��������������
            return false;
        if (ConfirmationOfQuadratism(firstShape))//���� 1 ������ �������
            return true;
        if (ConfirmationOfQuadratism(secondShape))//���� 2 ������ �������
            return false;
    }
    else
    {
        if (firstShape.vertex_num < secondShape.vertex_num)
            return true;
        else
            return false;
    }
}

bool ConfirmationOfQuadratism(Shape  mainShape)//�������� �� ������ � 4 ������ ��������� true, ��� ��������������� false
{
    if ((mainShape.vertexes[3].x - mainShape.vertexes[0].x) == (mainShape.vertexes[3].y - mainShape.vertexes[0].y))
    {
        return true;
    }
    return false;
}
