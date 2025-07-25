#include <iostream>
#include <string>

class Coach{
    public:
    int seatsAvailable = 5;
    bool isSeatsAvailable = true;
    int seatsBooked = 0;
    Coach* next;
    Coach* prev;
    Coach(int seatsBooked){
        this->next=NULL;
        this->prev=NULL;
        this->seatsBooked=seatsBooked;

        if(seatsBooked<seatsAvailable){
            isSeatsAvailable=true;
        }else{
            isSeatsAvailable=false;
        }
    }
};

class Train{
    public:
    int noOfCoaches=0;
    Coach* head = NULL;
    Coach* tail = NULL;

    void addCoach(){
        Coach* newCoach = new Coach(4);
        if(head==NULL){
            newCoach = head = tail;
        }
        else{
            tail->next = newCoach;
            tail = newCoach;
        }
    }

    void removeCoach(){
    }

    void checkCoach(){
        
    }
};