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
        Line(Line &line1);
        ~Line();
        void Display() const;
};
Line::Line(Point p1, Point p2):Point(p2), p(p1)
{
    cout<<"Line's Constructor called"<<endl;
}
Line::Line(Line & line1)
{
    p = line1.p;
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

class Circle:public Point
{
    private:
        int radius;
        
    public:
        Circle(Point p1, int r);
        ~Circle();
        void Display() const;
};
Circle::Circle(Point p1, int r):Point(p1)
{
    radius = r;
    cout<<"Circle's Constructor called"<<endl;
}
Circle::~Circle()
{
    cout<<"Circle's Destructor called"<<endl;
}
void Circle::Display() const
{
    // cout<<"The center of the circle is "<<endl;
    Point::Display();
    cout<<"The radius is "<<radius<<endl;
}


class Rectangle:public Line
{
    private:
        Line line1;
    public:
        Rectangle(Line line1, Line line2);
        // Rectangle(Line &line1);
        ~Rectangle();
        void Display() const;

};
Rectangle::Rectangle(Line l1, Line l2):line1(l1), Line(l2)
{
    cout<<"Line's Constructor called"<<endl;
}
Rectangle::~Rectangle()
{
    cout<<"Rectangle's Desctructor called"<<endl;
}
void Rectangle::Display() const
{
    line1.Display();
}


class Curve
{
    private:
        Point p1, p2;
    public:
        Curve(Point p1, Point p2);
        ~Curve();
        void Display() const;
};
Curve::Curve(Point p1, Point p2)
{
    this->p1 = p1;
    this->p2 = p2;
}
Curve::~Curve()
{
    cout<<"Curve's Dectructor called"<<endl;
}
void Curve::Display() const
{
    p1.Display();
    p2.Display();
}


int main()
{
    Point obj1(1, 2), obj2(3, 4);
    Line line1(obj1, obj2);
    int r;
    cout<<"How long is your radius?"<<endl;
    cin>>r;
    Circle circle1(obj1, r);
    line1.Display();
    circle1.Display();
}