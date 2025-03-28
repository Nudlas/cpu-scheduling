# CPU Scheduling Algorithms

This program implements two CPU scheduling algorithms:
1. First Come First Serve (FCFS)
2. Shortest Job First (SJF)

## Features
- Calculates waiting time and turnaround time for each process
- Computes average waiting time and average turnaround time
- Supports multiple processes with different arrival times and burst times
- Displays results in a formatted table

## Compilation
```bash
g++ scheduling.cpp -o scheduling
```

## Execution
```bash
./scheduling
```

## Example Output
```
----------------- FCFS -----------------
Process ID | Waiting Time | Turnaround Time
     1     |      0      |      8
     2     |      7      |      11
     3     |      11     |      20
     4     |      20     |      25

Average Waiting Time: 9.5
Average Turnaround Time: 16

----------------- SJF -----------------
Process ID | Waiting Time | Turnaround Time
     1     |      0      |      8
     2     |      7      |      11
     4     |      11     |      16
     3     |      16     |      25

Average Waiting Time: 8.5
Average Turnaround Time: 15
```

## Process Data
The program uses the following example processes:
- Process 1: arrival time 0, burst time 8
- Process 2: arrival time 1, burst time 4
- Process 3: arrival time 2, burst time 9
- Process 4: arrival time 3, burst time 5 #   s c h e d u l i n g  
 #   c p u - s c h e d u l i n g  
 