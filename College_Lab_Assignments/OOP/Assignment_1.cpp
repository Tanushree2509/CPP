//07.01.2026
#include <iostream>
using namespace std;
void Rarea()
{   
    int l,b;
    cout << "Enter the length: ";
    cin >> l;
    cout << "Enter the breadth: ";
    cin >> b;
    int area = l*b;
    cout << "The area of Rectangle is "<< area << endl;

}
void Sarea()
{   
    int s;
    cout << "Enter the Side: ";
    cin >> s;
    int area = s*s;
    cout << "The area of Square is "<< area << endl;

}
void Tarea()
{   
    int b,h;
    cout << "Enter the length of base: ";
    cin >> b;
    cout << "Enter the length of height: ";
    cin >> h;
    int area = ((0.5)*(b*h));
    cout << "The area of Triangle is "<< area << endl;

}
int main()
{
    int choice;
    char ch = 'y';
    while (ch == 'y' || ch == 'Y')
    {
        cout << "\n----Area Calculation----";
        cout << "\n1. Area of Rectangle \n2. Area of Square \n3. Area of Triangle";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                Rarea();
                break;
            
            case 2:
                Sarea();
                break;

            case 3:
                Tarea();
                break;

            default:
                cout << "Invalid choice";

        }
         cout << "\nDo you want to continue? (y/n): ";
         cin >> ch;
    }
    return 0;
}
