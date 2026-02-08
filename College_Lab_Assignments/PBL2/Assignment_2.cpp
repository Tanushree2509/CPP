#include <iostream>
using namespace std;
class mobileuser
{
    string username;
    string mobileno;
    string address;
    int comparisons;   // To track comparisons
    int passes; // To track passes (partition calls)
    public:
    void accept();
    void display();
    void merge(mobileuser s[], int low, int mid, int high);
    void mergesort(mobileuser arr[], int low, int high);
    int partition(mobileuser arr[], int low, int high); 
    void quicksort(mobileuser arr[], int low, int high);
    void resetCounters() { comparisons = 0; passes = 0; }  //  Reset counters
    int getComparisons() const { return comparisons; }    //  Get comparisons
    int getPasses() const { return passes; }             // Get passes

};

void mobileuser::accept()
{
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter mobile number: ";
    cin >> mobileno;
    cout << "Enter address: ";
    cin >> address;
}

void mobileuser::display()
{
    cout << "Username: " << username << endl;
    cout << "Number: " << mobileno << endl;
    cout << "Address: " << address << endl;
}
//partition
int mobileuser::partition(mobileuser arr[], int low, int high)
{
    string pivot = arr[high].mobileno;  // Compare by mobile number 
    int i = low - 1;
    passes++;  // Increment passes counter
    
    for(int j = low; j < high; j++)
    {
        comparisons++;  //  Track comparisons
        if(arr[j].mobileno <= pivot)  // Compare mobile numbers for descending order
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i + 1;
}
  
//merge sort
void mobileuser::mergesort(mobileuser arr[], int low, int high)
{
    if(low >= high) return;
        
    int mid = low + (high - low) / 2;
    passes++;  // Count each divide as a pass
        
    mergesort(arr, low, mid);
    mergesort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}
  
void mobileuser::merge(mobileuser arr[], int low, int mid, int high)
{
    mobileuser temp[20];
    int i = low, j = mid+1, k = low;
      
    // Merge two sorted halves (descending order)
    while(i <= mid && j <= high) 
    {
        comparisons++;
        if(arr[i].mobileno >= arr[j].mobileno) 
        {  // Descending: larger first
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
      
    // Copy remaining elements
    while(i <= mid) temp[k++] = arr[i++];
    while(j <= high) temp[k++] = arr[j++];
      
    // Copy back to original array
    for(int idx = low; idx <= high; idx++) {
        arr[idx] = temp[idx];
    }
}

void mobileuser::quicksort(mobileuser arr[], int low, int high)
{
    if(low >= high)
    {
        return;
    }
    int j = partition(arr, low, high); 
    quicksort(arr, low, j-1);
    quicksort(arr, j+1, high);
}  

int main ()
{ 
    mobileuser s1[20], s2;
    int n, choice;
    string key;
    cout << "Enter no. of users: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details for user " << (i + 1) << ":" << endl;
        s1[i].accept();
    }
    while (choice!= 4)
    {
      cout << "\n1) Display all users \n2) Quick sort (descending mobile no.) \n3) Merge sort (descending mobile no.) \n4)Exit\n";
      cout << "Enter your choice: ";
      cin >> choice;
      switch (choice)
      {
        case 1: 
            cout << "\n--- All Users ---\n";
            for (int i = 0; i < n; i++)
            {
                cout << "User " << (i+1) << ":" << endl;
                s1[i].display();
                cout << endl;
            }
            break;
        case 2:
            s2.resetCounters();  
            s2.quicksort(s1, 0, n-1);
            cout << "Users sorted in descending order of mobile number!\n";
            cout << "Passes: " << s2.getPasses() << ", Comparisons: " << s2.getComparisons() << endl;
            break;
         case 3:  
            s2.resetCounters();
            s2.mergesort(s1, 0, n-1);
            cout << "Merge Sort - Users sorted in descending order!\n";
            cout << "Passes: " << s2.getPasses() << ", Comparisons: " << s2.getComparisons() << endl;
            break;
        case 4:
            cout << "Thank you!\n";
            break;

        default:
            cout << "Invalid choice\n";
        

      }
    }
    
    return 0;
}