#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
} Process;



// Function to calculate waiting times and execution order for all processes
void calculateWaitingTimeAndExecutionOrder(Process proc[], int n, int quantum) {
    // Array to store remaining burst times
    // Assuming a maximum of 1000 executions for simplicity
    int rembt[n];
    //load rembt with burst times
    for(int i = 0; i<n;i++){
        rembt[i]=proc[i].burst_time;
    }

    int exec_order[1000], exec_count = 0;
    

    // Current time
    int current_time=0;

    // Keep traversing processes in round-robin manner until all of them are not done
    while (1) {
        int done = 1;
        for (int i = 0; i<n; i++) {
            // If burst time of a process is greater than 0 then only need to process further
            if(rembt[i]>0){
                done=0;
                exec_order[exec_count++]=proc[i].process_id;
                if(rembt[i]>quantum){
                    current_time=current_time+quantum;
                    rembt[i]-=quantum;
                }else{
                    current_time = current_time+rembt[i];
                    proc[i].waiting_time=current_time-proc[i].burst_time - proc[i].arrival_time;
                    rembt[i] = 0;
                }
            }
            
        }

        // If all processes are done
        if (done == 1) break;
    }

    // Print the execution order
    printf("Execution Order: ");
    for(int i=0;i<exec_count;i++){
        printf("P%d ",exec_order[i]);
    }
    
}

// Function to calculate turnaround times for all processes
void calculateTurnaroundTime(Process proc[], int n) {
    
    for(int i = 0; i < n; i++){
        proc[i].turnaround_time=proc[i].waiting_time+proc[i].burst_time;
    }
   
}

void roundRobin(Process proc[], int n, int quantum) {
    calculateWaitingTimeAndExecutionOrder(proc, n, quantum);
    calculateTurnaroundTime(proc, n);
}

void printProcesses(Process proc[], int n) {
    printf("\nProcess ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               proc[i].process_id, proc[i].arrival_time, proc[i].burst_time,
               proc[i].waiting_time, proc[i].turnaround_time);
    }
}

int main() {
    Process proc[] = {{1, 0, 24}, {2, 0, 3}, {3, 0, 3}};
    int n = sizeof(proc) / sizeof(proc[0]); // Number of processes
    int quantum = 4; // Time quantum for Round Robin scheduling
 

    roundRobin(proc, n, quantum);
    printProcesses(proc, n);

    return 0;
}

