
#! SJF is a non-preemptive CPU scheduling algorithm
#! Assuming arrival time is zero for all processes 
from itertools import accumulate

def calculateCompletionTime(burstTimes):

    # calculating completion time
    burstTimeIndex = {}
    for i in range(len(burstTimes)):
        burstTimeIndex[i] = burstTimes[i]

    filteredBT = dict(sorted(burstTimeIndex.items(), key = lambda item: item[1]))
    tempCompletionTime = [bt for bt in accumulate(filteredBT.values())]
    finalBT = {}
    for i, key in enumerate(filteredBT.keys()):
        finalBT[key] = tempCompletionTime[i]
    arrangedBT = dict(sorted(finalBT.items(), key = lambda item: item[0]))
    
    completionTimes = [value for value in arrangedBT.values()]
    return completionTimes

def avgTime(numOfprocesses, arrivalTime, completionTime, turnaroundTime, waitingTime):
    avgTAT = sum(turnaroundTime)/len(turnaroundTime)
    avgWT = sum(waitingTime)/len(waitingTime)
    schedulingLength = max(completionTime) - min(arrivalTime)
    throughput = numOfprocesses / schedulingLength

    print(f"\nAverage turn around time: {round(avgTAT, 2)}")
    print(f"Average waiting time: {round(avgWT, 2)}")
    print(f"Scheduling Length: {round(schedulingLength, 2)}")
    print(f"Throughput: {round(throughput,2)}")

def calculateSchedulingTime(numOfProcesses, burstTime):

    arrivalTime = [0 for i in range(3)]
    completionTime = calculateCompletionTime(burstTime)
    turnaroundTime = [ct - at for at, ct in zip(arrivalTime, completionTime)]
    waitingTime = [tat-bt for bt, tat in zip(burstTime, turnaroundTime)]
    print("\nProcess          Arrival Time          Burst Time          Completion Time          Turnaround Time         Waiting Time")
    for i in range(numOfProcesses):
        print(f"P{i}                    {arrivalTime[i]}                   {burstTime[i]}                   {completionTime[i]}                       {turnaroundTime[i]}                        {waitingTime[i]}")
    
    avgTime(numOfProcesses, arrivalTime, completionTime, turnaroundTime, waitingTime)

def shortestJobFirst():
    numOfProcess = int(input("Enter the number of processes: "))
    burstTimes = []

    for i in range(numOfProcess):
        burstTime = int(input(f"Enter burst time for process P{i+1}: "))
        burstTimes.append(burstTime)

    calculateSchedulingTime(numOfProcess, burstTimes)
        

shortestJobFirst()