#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    /* data */
    int process_id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

//int compareArrivalTime(){
    // pass
//}

// Fnction to manually sort the process by arrival time
void sortProcessesByArrival(Process proc[], int n){
    //pass
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n-i-1; j++){
            if(proc[j].arrival_time > proc[j+1].arrival_time){
                //swap proceeses
                Process temp = proc[j];
                proc[j] = proc[j+1];
                proc[j+1] = temp;
            }
        }
    }
}

void fcfs(Process proc[], int n){
    //sort the  process by Arrival time
    sortProcessesByArrival(proc, n);
    // 2,3,1 order of array

    proc[0].waiting_time = 0; // first process always has zero waiing time in FCFS
    for (int i=1;i<n; i++){
        proc[i].waiting_time = proc[i-1].waiting_time + proc[i-1].burst_time;
    }
    for (int i = 0; i<n;i++){
        proc[i].turnaround_time = proc[i].waiting_time + proc[i].burst_time;
    }
    // Print the order of Execution
    printf("Order of Execution: \n");
    for(int i = 0; i < n; i++){
        printf("P %d", proc[i].process_id);
        printf("\n");
    }
}

void printProcess(Process proc[], int n){
    printf("Process ID\t Arrival Time \t Burst Time \t Waiting Time \t Turnaround Time \n");
    for (int i=0;i<n;i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].process_id, proc[i].arrival_time, proc[i].burst_time, proc[i].waiting_time, proc[i].turnaround_time);
    }
}

int main(){
    //initialzize the processes with their IDs,
    //Arrival times, and burst time
    Process proc[] = {{1,4,24},{2,0,3},{3,2,3}};
    int n = sizeof(proc) / sizeof(proc[0]);

    fcfs(proc,n);
    printProcess(proc,n);
    
    return 0;
}
