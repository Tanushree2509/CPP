#include<iostream>
  #include<string>
  using namespace std;
  class mobileuser
  {
  string username;
  string mobileno;
  string address;
  public: 
  	void accept();
 	void display();
 	void seqsearch(mobileuser s[], int n, string key);
 };
  void mobileuser:: accept ()
  {
  cout << "Enter username: ";
  cin >> username;
  cout << "Enter mobile no: ";
  cin >> mobileno;
  cout << "Enter address: ";
  cin >> address;
  }
  void mobileuser:: display()
  { 
    cout << "\nUsername: " << username << endl;
    cout << "Number: " << mobileno << endl;
    cout << "Address: " << address << endl;
  }
  void mobileuser :: seqsearch(mobileuser s[], int n, string key)
  {
  int found = 0;
  for (int i = 0; i<n; i++)
  {
  if (s[i].username==key)
{
cout << "\nKey found" << endl;
s[i].display();
found++;
break;
}
  }
  
  if (!found)
  cout<<"\nKey not found";
  
}
  int  main ()
  { /*
  int i, n;
  cout << "number of users\n"<<endl;;
  cin >> n;
  for (i = 0; i<n; i++)
  {
  mobileuser m;
  m.accept();
  m.display();
  }*/
  mobileuser s1[20];
  int n, i;
  string key;
  cout <<"Enter no. of users: ";
  cin >> n;
  for (i = 0; i<n; i++){
  cout << "\nEnter details for user " << (i + 1) << ":" << endl;
  s1[i].accept();
  }
  cout<<"\n---------Entered Data------------";
  for (i=0; i<n; i++)
  s1[i].display();
  cout<<"\nEnter name to search: ";
  cin >> key;
  s1[0].seqsearch(s1,n,key);
  return 0;
  }