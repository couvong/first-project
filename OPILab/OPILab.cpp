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
    cout << "¬ведите координаты точек (x y):" << endl;
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