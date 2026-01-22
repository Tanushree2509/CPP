//14.01.2026
#include <iostream>
using namespace std;

class bank
{
   private:
      double bal;
      string name;
      string address;
      double amount;
      string pan;
      int account = 1;
   public:
      void open_account();
      void deposit_amount();
      void withdraw();
      void checkbalance();
      void kyc();

};

void bank :: open_account()
{
   cout << "Enter Name: ";
   cin.ignore();
   getline(cin, name);
   cout << "Enter Address: ";
   getline(cin, address);
   cout << "Enter PAN : ";
   cin >> pan;
   cout << "Enter the amount to deposit: ";
   cin >> amount;
   bal = amount;
   cout << "\nAccount opened successfully!" << endl;
   cout << "Your account number is : " << account << endl;
   account ++;
}  
   
void bank :: deposit_amount()
{   
   cout <<"Enter amount to deposit : ";
   cin >> amount;
    if (amount > 0)
    {
        //cout<<"\n";
        bal += amount;
        cout <<"Amount deposited successfully.\n";
    }
    else 
        cout << "Invalid deposit amount.\n";

}

void bank :: checkbalance()
{
   cout << "Current Balance : " << bal << endl;
}  

void bank :: withdraw()
{
   cout << "Enter the amount to withdraw : ";
   cin >> amount;
   if (amount > 0 && amount <= bal)
   {
      bal -= amount;
      cout << "Amount withdrawn successfully. ";
   }
   else 
      cout << "Insufficient Balance!";
}

void bank :: kyc()
{
   cout << "\n   KYC Details  \n";
   cout << "Name : " << name << endl;
   cout << "Address : " << address << endl;
   cout << "Account Number : " << account << endl;
   cout << "PAN : " << pan << endl;
}


int main ()
{
   int option;
   char choice;
   bank obj;
   cout << "Welcome to World Bank!\n";
   cout << "Do you wish to create a bank account (y/n) : ";
   cin >> choice;
   if (choice == 'y' || choice == 'Y')
   {
      obj.open_account();
      cout << "Do you wish to\n";
      cout << "1) Deposit money \n2) Withdraw amount \n3) Check Balance \n4) KYC \n5) Exit\n";
      cout << "\nEnter an option : ";
      cin >> option; 
      while(option != 5)
      {
         switch (option)
         {
         case 1: 
            obj.deposit_amount();
            cout << "\nEnter an option : ";
            cin >> option;
            break;

         case 2:
            obj.withdraw();
            cout << "\nEnter an option : ";
            cin >> option;
            break;

         case 3:
            obj.checkbalance();
            cout << "\nEnter an option : ";
            cin >> option;
            break;

         case 4:
            obj.kyc();
            cout << "\nEnter an option : ";
            cin >> option;
            break;

         case 5:
            cout<<"Thank you";
            break;
         
         default:
            cout << "Enter valid option: ";
            cout << "\nEnter an option : ";
            cin >> option;
            break;

         }

      }
      
   }
   /*else 
   {
      cout << "Enter valid option\n";
      cout << "Do you wish to create a bank account (y/n) : ";
      cin >> choice;     
   }
      */
   else if(choice == 'n')
   {
      cout <<"Thank you! Visit Again";
      return 0;
   }
}