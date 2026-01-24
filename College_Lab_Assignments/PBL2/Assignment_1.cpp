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
        void binarysearch(mobileuser s[], int start, int end, string key);
        void recbinarysearch(mobileuser s[], int start, int end, string key);
  };
  void mobileuser :: accept ()
  {
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter mobile no: ";
    cin >> mobileno;
    cout << "Enter address: ";
    cin >> address;
  }
  void mobileuser :: display()
  { 
    cout << "\nUsername: " << username << endl;
    cout << "Number: " << mobileno << endl;
    cout << "Address: " << address << endl;
  }
  //Linear search
  void mobileuser :: seqsearch(mobileuser s[], int n, string key)
  {
    int found = 0;
    for (int i = 0; i < n; i++)
    {
     if (s[i].username == key)
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
  // Binary Search (iterative)
  void mobileuser :: binarysearch(mobileuser s[], int start, int end, string key)
  {
    int found = 0;
      while(start <= end) 
      {
          int mid = start + (end - start) / 2;

          if (s[mid].username == key)
          {
            cout << "\nKey found" << endl;
            s[mid].display();
            found = 1;
            break;                  
          }  
          else if (key < s[mid].username)
          {
            end = mid - 1;
          }
          else
          {
            start = mid + 1;
          }
      }
      if (!found)
        cout << "\nKey not found";    
  }
  // Binary Search (Recursive)
  void mobileuser :: recbinarysearch(mobileuser s[], int start, int end, string key)
  {
    if (start > end)
    {
      cout << "\nKey not found";
      return;
    }
    int mid = start +(end - start)/ 2;
    if (s[mid].username == key)
    {
      cout << "\nKey found" << endl;
      s[mid].display();
      return;
    }
    else if (key < s[mid].username)
    {
      recbinarysearch (s, start, mid-1, key);
    }
    else
    {
      recbinarysearch(s, mid+1, end, key);
    }
  }
  
  int  main ()
  { 
    mobileuser s1[20];
    int n, i, choice;
    string key;
    cout << "Enter number of users: ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "\nEnter details for user " << (i + 1) << ":" << endl;
        s1[i].accept();
    }
    cout << "1) Display all users \n2) Linear search \n3) Binary search \n4) Binary search Recursive \n5) Exit" << endl;
    cout << "Enter your choicee : ";
    cin >> choice;
    while(choice != 5)
    {
      switch (choice)
      {
          case 1: 
          for (int i = 0; i < n; i++)
          {
            cout <<"The registered user are " << (i+1)<< ":" << endl;
            s1[i].display();
          }
          break;

          case 2:
            ////assuming array is sorted
            cout << "Enter the username to search: ";
            cin >> key;
            s1[0].seqsearch(s1, n, key);
            break;
          
          case 3:
          ////assuming array is sorted
            cout << "Enter the username to search: ";
            cin >> key;
            s1[0].binarysearch(s1, 0, n - 1, key);
            break;

          case 4:
            cout << "Enter the username to search: ";
            cin >> key;
            s1[0].recbinarysearch(s1, 0, n - 1, key);
            break;

          case 5:
            cout << "Thank you!\n";
            break;

          default:
            cout << "Invalid choice\n";

      }
      cout << "Enter your choice: ";
      cin >> choice;
    }
    return 0;
  }