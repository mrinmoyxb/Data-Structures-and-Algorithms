
#! FCFS is a non-preemptive CPU scheduling algorithm
#! Assuming arrival time is zero for all processes 

def caclulateAvg(numOfProcess, at, ct, tat, wt):
    avgTAT = sum(tat)/len(tat)
    avgWT = sum(wt)/len(wt)
    print(f"\nAverage Turnaround time: {round(avgTAT, 2)}")
    print(f"Average Waiting time: {round(avgWT, 2)}")

    schedulingLength = max(ct) - min(at)
    print(f"Scheduling Length: {schedulingLength}")

    throughPut = numOfProcess / schedulingLength
    print(f"Troughput: {round(throughPut, 2)}")


def calculateTime(numOfProcess, burstTimes):
    arrivalTime = [0 for i in range(3)]
    completionTime = []
   
    s = 0
    for i in burstTimes:
        s = s + i
        completionTime.append(s)

    turnaroundTime = [ct-at for at, ct in zip(arrivalTime, completionTime)]
    waitingTime = [tat-bt for bt, tat in zip(burstTimes, turnaroundTime)]

    print("\nProcess          Arrival Time          Burst Time          Completion Time          Turnaround Time         Waiting Time")
    for i in range(numOfProcess):
        print(f"P{i}                    {arrivalTime[i]}                   {burstTimes[i]}                   {completionTime[i]}                       {turnaroundTime[i]}                        {waitingTime[i]}")

    
    caclulateAvg(numOfProcess, arrivalTime, completionTime, turnaroundTime, waitingTime)

def firstComeFirstServed():
    numOfProcesses = int(input("Enter the number of processes: "))
    burstTimes = []
    for i in range(numOfProcesses):
        burstTime = int(input(f"Enter the burst time for process P{i+1}: "))
        burstTimes.append(burstTime)
    calculateTime(numOfProcesses, burstTimes)

firstComeFirstServed()