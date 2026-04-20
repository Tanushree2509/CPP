#include <iostream>
#include <vector>
using namespace std;

// Function to calculate average
double calculateAverage(vector<int> &grades) {
    int sum = 0;
    for (vector<int>::iterator it = grades.begin(); it != grades.end(); it++) {
        sum += *it;
    }
    return (double)sum / grades.size();
}

// Function to find minimum
int findMinimum(vector<int> &grades) {
    int minVal = *grades.begin();
    for (vector<int>::iterator it = grades.begin(); it != grades.end(); it++) {
        if (*it < minVal)
            minVal = *it;
    }
    return minVal;
}

// Function to find maximum
int findMaximum(vector<int> &grades) {
    int maxVal = *grades.begin();
    for (vector<int>::iterator it = grades.begin(); it != grades.end(); it++) {
        if (*it > maxVal)
            maxVal = *it;
    }
    return maxVal;
}

int main() {
    vector<int> grades;
    int n, value;

    cout << "Enter number of students: ";
    cin >> n;

    cout << "Enter grades:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        grades.push_back(value);
    }

    cout << "\nGrades are: ";
    for (vector<int>::iterator it = grades.begin(); it != grades.end(); it++) {
        cout << *it << " ";
    }

    cout << "\nAverage: " << calculateAverage(grades);
    cout << "\nMinimum: " << findMinimum(grades);
    cout << "\nMaximum: " << findMaximum(grades);

    return 0;
}