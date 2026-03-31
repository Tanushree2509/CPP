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