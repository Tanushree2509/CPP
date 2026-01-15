#include<iostream>
  #include<string>
  using namespace std;
  class mobileuser
  {
  string username;
  long mobileno;
  string address;
  public: 
  	void accept();
 	void display();
 	void seqsearch(mobileuser s[20], int n, string key);
 };
  void mobileuser:: accept ()
  {
  cout << "\nEnter username:";
  cin >> username;
  cout << "\n enter mobile no:";
  cin >> mobileno;
  cout << "\n enter address:";
  cin >> address;
  }
  void mobileuser:: display()
  {
  cout << username<<" ";
  cout<<mobileno<<" ";
  cout << address<<" ";
  }
  void mobileuser :: seqsearch(mobileuser s[20], int n, string key)
  {
  int i;
  for (i =0; i<n; i++)
  {
  if (s[i].username==key)
{
cout << "Key found";
break;
}
  }
  if (i ==n)
  cout<<"key not found";
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
  mobileuser si[20];
  int n, i;
  string key;
  cout <<"enter no. of user:";
  cin >> n;
  for (i = 0; i<n; i++)
  si[i].accept();
  for (i=0; i<n; i++)
  si[i].display();
  cout<<"Enter name to search";
  cin >> key;
  si[0].seqsearch(si,n,key);
  return 0;
  
  }