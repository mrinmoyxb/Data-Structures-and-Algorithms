#include <iostream>
using namespace std;

void fcfs(int numOfProcesses, int burstTimes[]){
    int arrivalTime[numOfProcesses] = {0};
    int completionTime[numOfProcesses];
    int turnAroundTime[numOfProcesses];
    int waitingTime[numOfProcesses];

    int avgTAT, avgWT;
    int sum = 0;
    float tat=0.0, wt=0.0;

    //* completion time
    for(int i=0; i<numOfProcesses; i++){
        sum = sum + burstTimes[i];
        completionTime[i] = sum;
    }

    //* Turnaround Time(TAT) = Completion Time(CT) - Arrival Time(AT)
    for(int i=0; i<numOfProcesses; i++){
        turnAroundTime[i] = completionTime[i] - arrivalTime[i];
    }

    //* Waiting Time(WT) = Turnaround Time(TAT) - Burst Time(BT)
    for(int i=0; i<numOfProcesses; i++){
        waitingTime[i] = turnAroundTime[i] - burstTimes[i];
    }

    cout<<"Process"<<"     "<<"Arrival Time"<<"     "<<"Burst Time"<<"     "<<"Completion Time"<<"     "<<"Turnaround Time"<<"     "<<"Waiting Time"<<endl;
    for(int i=0; i<numOfProcesses; i++){
        cout<<"P"<<i+1<<"               "<<arrivalTime[i]<<"                  "<<burstTimes[i]<<"               "<<completionTime[i]<<"                  "<<turnAroundTime[i]<<"               "<<waitingTime[i]<<endl;
    }

    //* Average TAT and WT
    for(int i=0; i<numOfProcesses; i++){
        tat = tat + turnAroundTime[i];
        wt = wt + waitingTime[i];
    }
    avgTAT = tat / float(numOfProcesses);
    avgWT = wt / float(numOfProcesses);

    cout<<"Average Turnaround Time: "<<avgTAT<<endl;
    cout<<"Average Waiting Time: "<<avgWT<<endl;
}

int main(){
    int numOfProcess;
    cout<<"Enter the number of processes: ";
    cin>>numOfProcess;

    int burstTimes[numOfProcess];

    cout<<"Enter burst time: "<<endl;
    for(int i=0; i<numOfProcess; i++){
        int burstTime;
        cout<<"Enter burst time of P"<<i+1<<": ";
        cin>>burstTime;
        burstTimes[i] = burstTime;
    }
    

    fcfs(numOfProcess, burstTimes);
    return 0;
}