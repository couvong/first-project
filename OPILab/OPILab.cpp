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
