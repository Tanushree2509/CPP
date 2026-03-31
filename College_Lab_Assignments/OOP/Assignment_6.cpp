#include<iostream>
#include<fstream>
using namespace std;
class Student{
public:
   int id;
   string name;
   float marks;
   void readfile(ifstream &fin){
      fin >> id >>name >>marks;
   }

   void writefile(ofstream &fout){ 
      fout << id << " " << name << " " << marks<< endl;
   }

   void display(){
      cout << id << " " << name << " " << marks << endl;
   }
};
int main(){
   ifstream fin("input.txt");
   if(!fin.is_open()){
      cout<<"File is not open ";
      return 1;
   }
   ofstream fout("output.txt");
   if(!fout.is_open()){
      cout<<"File is not open ";
   }
   Student s;
   cout << "Reading from file:\n";
   while (fin >> s.id >> s.name >> s.marks) {
      s.display();          // display on screen
      s.writefile(fout);  // write to output file
   }
   fin.close();
   fout.close();
   cout << "\nData written to output.txt successfully.";
   return 0;

}
/*
#include <iostream>
#include <fstream>
using namespace std;

// Student class
class Student {
public:
    int id;
    string name;
    int marks;

    void input() {
        cin >> id >> name >> marks;
    }

    void display() {
        cout << id << " " << name << " " << marks << endl;
    }
};

int main() {
    Student s[10];
    int count = 0;

    // -------- Reading from file --------
    ifstream fin("input.txt");

    if (!fin) {
        cout << "Error opening input file!" << endl;
        return 0;
    }

    while (fin >> s[count].id >> s[count].name >> s[count].marks) {
        count++;
    }

    fin.close();

    // -------- Display Data --------
    cout << "Data read from file:\n";
    for (int i = 0; i < count; i++) {
        s[i].display();
    }

    // -------- Writing to file --------
    ofstream fout("output.txt");

    if (!fout) {
        cout << "Error opening output file!" << endl;
        return 0;
    }

    for (int i = 0; i < count; i++) {
        fout << s[i].id << " " << s[i].name << " " << s[i].marks << endl;
    }

    fout.close();

    cout << "\nData written to output.txt successfully!" << endl;

    return 0;
}
*/