#include <iostream>
using namespace std;

class Shape {
public :
   virtual void draw() = 0;
};

class Rectangle : public Shape {
public :
   void draw() {
      cout<<"Drawing Rectangle"<< endl;
    }
};

class Circle : public Shape {
public :
   void draw() {
      cout<<"Drawing Circle"<< endl;
    }
};

int main () {
   Shape *s;
   Rectangle r;
   Circle c;
   s = &c;
   s -> draw();
   s = &r;
   s -> draw();
   return 0;
}
