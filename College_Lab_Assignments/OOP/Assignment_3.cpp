#include<iostream>
#include<string>
using namespace std;
class Rectangle
{
	private:
		double l, b;
	public:
		Rectangle ()
		{
			l = b = 1.0;
			cout << "Default Rectangle constructor " << endl;
		}
	Rectangle (double h, double b) 
	{
	l = h;
	b = b;
	cout << "Parameterized Rectangle constructor " << endl;
	}
	Rectangle (const Rectangle &r) 
		{	
			l = r.l;
			b = r.b;
			cout << "Rectangle copy constructor " << endl;
		}
		double area()
		{
			return l*b;
		}
		double perimeter()
		{
			return 2*(l+b);
		}
		~Rectangle ()
		{
			cout << "Rectangle destructor " << endl;
		}
	
};

class Circle
{
	private: 
		double r;
	public:
		Circle ()
		{
			r = 10;
			cout << "Default Circle Constructor " << endl;
		}
		Circle (double radius)
		{
			r = radius;		
			cout << "Parameterized Circle constructor " << endl;
		}
		Circle (const Circle &c) 
		{	
			r = c.r;
			cout << "Circle copy constructor " << endl;
		}
		double area()
		{
			return 3.14*r*r;
		}
		double perimeter()
		{
			return 2*3.14*r;
		}
		~Circle ()
		{
			cout << "Circle destructor " << endl;
		}
};

int main ()
{
	cout << "***Circle objects***" << endl;
	Circle c1;
	Circle c2(5.0);
	Circle c3 = c2;
	cout << "Area of c2: " << c2.area() << endl;
	cout << "Perimeter of c2: " << c2.perimeter() << endl;
	
	cout << "***Rectangle Objects***" << endl;
	Rectangle r1;
	Rectangle r2 (4.0, 6.0);
	Rectangle r3 = r2;
	cout << "Area of r2: " << r2.area() << endl;
	cout << "Perimeter of r2: " << r2.perimeter() << endl;
	
	return 0;
}