#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point 
{
    double x, y;
};

vector<Point> InputPoints(int n) 
{
    vector<Point> points(n);
    cout << "Введите координаты точек (x y):" << endl;
    for (int i = 0; i < n; i++) 
        cin >> points[i].x >> points[i].y;
    
    return points;
}

bool ValidatePoints(const vector<Point>& points) 
{
    return true;
}

pair<double, double> FindLine(const Point& p1, const Point& p2) 
{
    double m = (p2.y - p1.y) / (p2.x - p1.x);
    double c = p1.y - m * p1.x;

    return { m, c };
}

int PointOfLine(const Point& point, const pair<double, double>& line) 
{
    double result = line.first * point.x - point.y + line.second;
    if (result > 0)
        return 1;
    else if (result < 0)
        return -1;
    else
        return 0;
}

pair<Point, Point> Optimize(const vector<Point>& points)
{
    int n = points.size();
    int minDifference = n;
    pair<Point, Point> optimalPoints;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int difference = 0;
            auto line = FindLine(points[i], points[j]);
            for (int k = 0; k < n; k++)
            {
                if (k != i && k != j)
                {
                    difference += PointOfLine(points[k], line);
                }
            }

            if (abs(difference) < minDifference)
            {
                minDifference = abs(difference);
                optimalPoints = { points[i], points[j] };
            }
        }
    }

    return optimalPoints;
}

void VisResult(const pair<Point, Point>& optimalPoints)
{
    cout << "Оптимальные точки: (" << optimalPoints.first.x << ", " << optimalPoints.first.y << ") и ("
        << optimalPoints.second.x << ", " << optimalPoints.second.y << ")" << endl;
}

int main()
{
    setlocale(LC_ALL, "ru");

    int n;
    cout << "Введите количество точек: ";
    cin >> n;

    vector<Point> points = InputPoints(n);

    if (ValidatePoints(points))
    {
        auto optimalPoints = Optimize(points);
        VisResult(optimalPoints);
    }
    else
    {
        cout << "Некорректные данные точек. Пожалуйста, повторите ввод." << endl;
    }

    return 0;
}