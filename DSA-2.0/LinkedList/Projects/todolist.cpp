#include <iostream>
#include <string>

class Task{
    public:
    int id;
    std::string title;
    std::string description;
    Task* prev;
    Task* next;

    Task(int id, std::string title, std::string descpription){
        this->id = id;
        this->title = title;
        this->description = descpription;
        this->prev = NULL;
        this->next = NULL;
    }
};

class ToDoList{
    public:
    int noOfTask = 0;
    int noOfCompletedTask = 0;
    Task* head = NULL;
    Task* tail = NULL;

    void addTask(std::string title, std::string description){
        Task* newTask = new Task(noOfTask+1, title, description);
        if(head==NULL){
            head = tail = newTask;
            noOfTask += 1;
        }else{
            Task* current = head;
            while(current->next != NULL){
                current = current->next;
            }
            current->next = newTask;
            newTask->prev = current;
            tail = newTask;
            noOfTask += 1;
        }
    }

    void stats(){
        std::cout<<"No. of tasks: "<<noOfTask<<std::endl;
        std::cout<<"No. of completed tasks: "<<noOfCompletedTask<<std::endl;
        std::cout<<"No. of remaining tasks: "<<(noOfTask - noOfCompletedTask)<<std::endl;
    }

    void showTasks(){
        Task* current = head;
        while(current!=NULL){
            std::cout<<"Task: "<<current->id<<std::endl;
            std::cout<<"Title: "<<current->title<<std::endl;
            std::cout<<"Description: "<<current->description<<std::endl;
            std::cout<<std::endl;
            current = current->next;
        }
    }

    void deleteTask(int id){
        Task* current = head;
        if(id==1){
            Task* delTask = current;
            current = current->next;
            current->next->prev = NULL;
            delete delTask;
        }else{
            while(current!=NULL){
                if(current->next->id==id){
                    std::cout<<"Deleting task "<<current->next->id<<std::endl;
                    Task* nextNode = current->next;
                    current->next = nextNode->next;
                    nextNode->prev = NULL;
                    delete nextNode;
                    break;
                }else{
                    current = current->next;
                }
            }
        }
    }
};

int main(){
    ToDoList l = ToDoList();
    l.addTask("Coding", "Need to complete the file management");
    l.addTask("Gym", "Chest day");
    l.addTask("Shopping", "Need to buy something for her");
    l.addTask("Report", "Need to sumbit the report to HR by 10pm");
    l.showTasks();
    l.stats();
    l.deleteTask(3);
    l.showTasks();
    return 0;
}