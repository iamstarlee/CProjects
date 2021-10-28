#include<iostream>
using namespace std;

class Point
{
    private:
        int x, y;
    public:
        Point();
        Point(Point &p);
        Point(int a, int b);
        ~Point();
        void Display() const;
};
Point::Point(int a, int b)
{
    x = a;
    y = b;
}
Point::Point(Point &p){
    x = p.x;
    y = p.y;
}
Point::~Point()
{
    cout<<"Point's Destructor called"<<endl;
}
void Point::Display() const
{
    cout<<"my x-axis is "<<x<<" and my y-axis is "<<y<<endl;
}


class Line: public Point
{
    private:
        Point p;
        
    public:
        Line(Point p1, Point p2);
        ~Line();
        void Display() const;
};

Line::Line(Point p1, Point p2):Point(p2)
{
    p = p1;
}
Line::~Line()
{
    cout<<"Line's Destructor called"<<endl;
}
void Line::Display() const
{
    Point::Display();
    p.Display();
}


int main()
{
    Point obj1(1, 2), obj2(3, 4);
    Line line1(obj1, obj2);
    line1.Display();
    
}