#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int priority;
    int waitingTime;
    int turnaroundTime;
};

// ---------- FCFS ----------
void FCFS(vector<Process> p, int n) {
    int time = 0;
    float totalWT = 0, totalTAT = 0;

    cout << "\n--- FCFS Scheduling ---\n";
    cout << "PID AT BT WT TAT\n";

    for (int i = 0; i < n; i++) {
        if (time < p[i].arrivalTime)
            time = p[i].arrivalTime;

        p[i].waitingTime = time - p[i].arrivalTime;
        p[i].turnaroundTime = p[i].waitingTime + p[i].burstTime;
        time += p[i].burstTime;

        totalWT += p[i].waitingTime;
        totalTAT += p[i].turnaroundTime;

        cout << p[i].pid << "  " << p[i].arrivalTime << "  "
             << p[i].burstTime << "  " << p[i].waitingTime
             << "  " << p[i].turnaroundTime << endl;
    }

    cout << "Average WT = " << totalWT / n << endl;
    cout << "Average TAT = " << totalTAT / n << endl;
}

// ---------- SJF ----------
void SJF(vector<Process> p, int n) {
    vector<bool> done(n, false);
    int time = 0, completed = 0;
    float totalWT = 0, totalTAT = 0;

    cout << "\n--- SJF Scheduling ---\n";
    cout << "PID AT BT WT TAT\n";

    while (completed < n) {
        int idx = -1, minBT = 1e9;

        for (int i = 0; i < n; i++) {
            if (!done[i] && p[i].arrivalTime <= time &&
                p[i].burstTime < minBT) {
                minBT = p[i].burstTime;
                idx = i;
            }
        }

        if (idx == -1) {
            time++;
            continue;
        }

        p[idx].waitingTime = time - p[idx].arrivalTime;
        p[idx].turnaroundTime = p[idx].waitingTime + p[idx].burstTime;
        time += p[idx].burstTime;

        done[idx] = true;
        completed++;

        totalWT += p[idx].waitingTime;
        totalTAT += p[idx].turnaroundTime;

        cout << p[idx].pid << "  " << p[idx].arrivalTime << "  "
             << p[idx].burstTime << "  " << p[idx].waitingTime
             << "  " << p[idx].turnaroundTime << endl;
    }

    cout << "Average WT = " << totalWT / n << endl;
    cout << "Average TAT = " << totalTAT / n << endl;
}

// ---------- Priority ----------
void PriorityScheduling(vector<Process> p, int n) {
    sort(p.begin(), p.end(), [](Process a, Process b) {
        return a.priority < b.priority;
    });

    int time = 0;
    float totalWT = 0, totalTAT = 0;

    cout << "\n--- Priority Scheduling ---\n";
    cout << "PID AT BT PR WT TAT\n";

    for (int i = 0; i < n; i++) {
        if (time < p[i].arrivalTime)
            time = p[i].arrivalTime;

        p[i].waitingTime = time - p[i].arrivalTime;
        p[i].turnaroundTime = p[i].waitingTime + p[i].burstTime;
        time += p[i].burstTime;

        totalWT += p[i].waitingTime;
        totalTAT += p[i].turnaroundTime;

        cout << p[i].pid << "  " << p[i].arrivalTime << "  "
             << p[i].burstTime << "  " << p[i].priority << "  "
             << p[i].waitingTime << "  " << p[i].turnaroundTime << endl;
    }

    cout << "Average WT = " << totalWT / n << endl;
    cout << "Average TAT = " << totalTAT / n << endl;
}

// ---------- Round Robin ----------
void RoundRobin(vector<Process> p, int n, int tq) {
    vector<int> remBT(n);
    for (int i = 0; i < n; i++)
        remBT[i] = p[i].burstTime;

    int time = 0;
    float totalWT = 0, totalTAT = 0;

    cout << "\n--- Round Robin Scheduling ---\n";
    cout << "PID BT WT TAT\n";

    while (true) {
        bool done = true;

        for (int i = 0; i < n; i++) {
            if (remBT[i] > 0) {
                done = false;

                if (remBT[i] > tq) {
                    time += tq;
                    remBT[i] -= tq;
                } else {
                    time += remBT[i];
                    p[i].waitingTime = time - p[i].burstTime;
                    remBT[i] = 0;
                }
            }
        }
        if (done) break;
    }

    for (int i = 0; i < n; i++) {
        p[i].turnaroundTime = p[i].waitingTime + p[i].burstTime;
        totalWT += p[i].waitingTime;
        totalTAT += p[i].turnaroundTime;

        cout << p[i].pid << "  " << p[i].burstTime << "  "
             << p[i].waitingTime << "  " << p[i].turnaroundTime << endl;
    }

    cout << "Average WT = " << totalWT / n << endl;
    cout << "Average TAT = " << totalTAT / n << endl;
}

// ---------- MAIN ----------
int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cout << "\nProcess " << i + 1 << endl;
        cout << "Arrival Time: ";
        cin >> p[i].arrivalTime;
        cout << "Burst Time: ";
        cin >> p[i].burstTime;
        cout << "Priority: ";
        cin >> p[i].priority;
    }

    int choice;
    do {
        cout << "\n===== CPU Scheduling Menu =====\n";
        cout << "1. FCFS\n";
        cout << "2. SJF\n";
        cout << "3. Priority Scheduling\n";
        cout << "4. Round Robin\n";
        cout << "5. Run All\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            FCFS(p, n);
            break;
        case 2:
            SJF(p, n);
            break;
        case 3:
            PriorityScheduling(p, n);
            break;
        case 4: {
            int tq;
            cout << "Enter Time Quantum: ";
            cin >> tq;
            RoundRobin(p, n, tq);
            break;
        }
        case 5: {
            int tq;
            FCFS(p, n);
            SJF(p, n);
            PriorityScheduling(p, n);
            cout << "Enter Time Quantum for Round Robin: ";
            cin >> tq;
            RoundRobin(p, n, tq);
            break;
        }
        case 0:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}