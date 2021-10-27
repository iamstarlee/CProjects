#include<iostream>
using namespace std;

class Point
{
    private:
        int x, y;
    public:
        Point(int a, int b);
        ~Point();
};
Point::Point(int a, int b)
{
    x = a;
    y = b;
}
Point::~Point()
{
    cout<<"Point's Destructor called"<<endl;
}

class Line: public Point
{
    private:
        int x, y;
    public:
        Line(int a, int b, int c, int d);
        ~Line();
};
Line::Line(int a, int b, int c, int d):Point(a, b)
{
    x = c;
    y = d;
}
Line::~Line()
{
    cout<<"Line's Destructor called"<<endl;
}
