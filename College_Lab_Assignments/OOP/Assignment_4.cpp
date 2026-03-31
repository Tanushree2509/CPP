#include <iostream>
using namespace std;

class Point {
public : 
   int x,y;
   Point(int a=0, int b=0) {
      x = a;
      y = b;
   }
};

int add (int a, int b){
   return a + b;
}

int sub(int a, int b){
   return a - b;
}

int mul(int a, int b){
   return a * b;
}

Point add (Point p1, Point p2) {
   return Point (p1.x + p2.x, p1.y + p2.y);
}

Point sub (Point p1, Point p2) {
   return Point (p1.x - p2.x, p1.y - p2.y);
}

Point mul (Point p1, Point p2) {
   return Point (p1.x * p2.x, p1.y * p2.y);
}

void display(Point p){
   cout << "Coordinate : (" << p.x << "," << p.y << ")" << endl;
}

int main () 
{
   int x,y;
   cin >> x >> y;
   cout << "Integer operations:"<< endl;
   cout << "Addition operations:"<< add(x,y)<<endl;
   cout << "Subtraction operations:"<< sub(x,y)<<endl;
   cout << "Multiplication operations:"<< mul(x,y)<<endl;

   // Point objects
   Point p1(2, 3), p2(4, 5);
   cout << "\n Point Operations:" << endl;
   cout << "\nUsing Function Overloading:\n";
    display(add(p1, p2));
    display(sub(p1, p2));
    display(mul(p1, p2));

    return 0;
}