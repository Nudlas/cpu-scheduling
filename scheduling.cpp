#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Process {
public:
    int id;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
    bool completed;

    Process(int i, int at, int bt) : id(i), arrivalTime(at), burstTime(bt), 
                                   waitingTime(0), turnaroundTime(0), completed(false) {}
};

// Function to calculate FCFS scheduling
void calculateFCFS(vector<Process>& processes) {
    int currentTime = 0;
    
    // Sort processes by arrival time
    sort(processes.begin(), processes.end(), 
         [](const Process& a, const Process& b) { return a.arrivalTime < b.arrivalTime; });
    
    for (auto& p : processes) {
        if (currentTime < p.arrivalTime) {
            currentTime = p.arrivalTime;
        }
        p.waitingTime = currentTime - p.arrivalTime;
        currentTime += p.burstTime;
        p.turnaroundTime = p.waitingTime + p.burstTime;
    }
}

// Function to calculate SJF scheduling
void calculateSJF(vector<Process>& processes) {
    int currentTime = 0;
    int completed = 0;
    int n = processes.size();
    
    while (completed != n) {
        int shortest = -1;
        int minBurst = INT_MAX;
        
        // Find the shortest job that has arrived
        for (int i = 0; i < n; i++) {
            if (!processes[i].completed && processes[i].arrivalTime <= currentTime) {
                if (processes[i].burstTime < minBurst) {
                    minBurst = processes[i].burstTime;
                    shortest = i;
                }
            }
        }
        
        // If no process has arrived yet, find the one with earliest arrival time
        if (shortest == -1) {
            int earliest = INT_MAX;
            for (int i = 0; i < n; i++) {
                if (!processes[i].completed && processes[i].arrivalTime < earliest) {
                    earliest = processes[i].arrivalTime;
                    shortest = i;
                }
            }
        }
        
        // Process the selected job
        if (currentTime < processes[shortest].arrivalTime) {
            currentTime = processes[shortest].arrivalTime;
        }
        processes[shortest].waitingTime = currentTime - processes[shortest].arrivalTime;
        currentTime += processes[shortest].burstTime;
        processes[shortest].turnaroundTime = processes[shortest].waitingTime + processes[shortest].burstTime;
        processes[shortest].completed = true;
        completed++;
    }
}

void printResults(const vector<Process>& processes, const string& algorithm) {
    cout << "\n----------------- " << algorithm << " -----------------\n";
    cout << "Process ID | Waiting Time | Turnaround Time\n";
    
    double avgWaitingTime = 0;
    double avgTurnaroundTime = 0;
    
    for (const auto& p : processes) {
        cout << "     " << p.id << "     |      " << p.waitingTime 
             << "      |      " << p.turnaroundTime << "\n";
        avgWaitingTime += p.waitingTime;
        avgTurnaroundTime += p.turnaroundTime;
    }
    
    avgWaitingTime /= processes.size();
    avgTurnaroundTime /= processes.size();
    
    cout << "\nAverage Waiting Time: " << avgWaitingTime << endl;
    cout << "Average Turnaround Time: " << avgTurnaroundTime << endl;
}

int main() {
    // Example processes from Q2
    vector<Process> processes = {
        Process(1, 0, 8),  // Process 1: arrival time 0, burst time 8
        Process(2, 1, 4),  // Process 2: arrival time 1, burst time 4
        Process(3, 2, 9),  // Process 3: arrival time 2, burst time 9
        Process(4, 3, 5)   // Process 4: arrival time 3, burst time 5
    };
    
    // Calculate FCFS
    vector<Process> fcfsProcesses = processes;
    calculateFCFS(fcfsProcesses);
    printResults(fcfsProcesses, "FCFS");
    
    // Calculate SJF
    vector<Process> sjfProcesses = processes;
    calculateSJF(sjfProcesses);
    printResults(sjfProcesses, "SJF");
    
    return 0;
} 