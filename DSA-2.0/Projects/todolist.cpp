#include <iostream>
#include <string>

class Task{
    public:
    int id;
    std::string title;
    std::string description;
    bool isTaskCompleted;
    Task* prev;
    Task* next;

    Task(int id, std::string title, std::string descpription){
        this->id = id;
        this->title = title;
        this->description = descpription;
        this->isTaskCompleted = false;
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
        }else{
            tail->next = newTask;
            newTask->prev = tail;
            tail = newTask;
        }
        noOfTask += 1;
    }

    void stats(){
        std::cout<<"\nNo. of tasks: "<<noOfTask<<std::endl;
        std::cout<<"No. of completed tasks: "<<noOfCompletedTask<<std::endl;
        std::cout<<"No. of remaining tasks: "<<(noOfTask - noOfCompletedTask)<<std::endl;
    }

    void showTasks(){
        Task* current = head;
        while(current!=NULL){
            std::cout<<"\nTask: "<<current->id<<std::endl;
            std::cout<<"Title: "<<current->title<<std::endl;
            std::cout<<"Description: "<<current->description<<std::endl;
            std::string isTaskComplete = (current->isTaskCompleted == true) ? "Yes":"No";
            std::cout<<"Completed: "<<isTaskComplete<<std::endl;
            current = current->next;
        }
    }

    void deleteTask(int id){
        if(head!=NULL && head->id==id){
            Task* delTask = head;
            head = head->next;
            if(head!=NULL){
                head->prev = NULL;
                head->id = 1;
            }else{
                tail = NULL;
            }
            delete delTask;
            noOfTask-=1;
            return;
        }else{
            Task* current = head;
            while(current!=NULL){
                if(current->next->id==id){
                    std::cout<<"\nDeleted task "<<current->next->id<<std::endl;
                    Task* nextNode = current->next;
                    current->next = nextNode->next;
                    nextNode->prev = NULL;
                    delete nextNode;
                    noOfTask-=1;
                    Task* forward = current->next;

                    while(forward!=NULL){
                        forward->id-=1;
                        forward=forward->next;
                    }
                    break;
                }else{
                    current = current->next;
                }
            }
        }
    }

    void completeTask(int id){
        Task* current = head;
        while(current!=NULL){
            if(current->id==id){
                current->isTaskCompleted = true;
                noOfCompletedTask+=1;
                break;
            }else{
                current = current->next;
            }
        }
    }

    ~ToDoList(){
        Task* current = head;
        while(current!=NULL){
            Task* nextTask = current->next;
            delete current;
            current = nextTask;
        }
    }
};

int main(){
    ToDoList l = ToDoList();
    l.addTask("Coding", "Need to complete the file management");
    l.addTask("Gym", "Chest day");
    l.addTask("Shopping", "Need to buy something for her");
    l.addTask("Report", "Need to sumbit the report to HR by 10pm");
    l.addTask("Date", "Date with my muffin");
    l.addTask("Gaming Session", "Gamming Session");
    l.addTask("Meeting", "Imp. meeting tomorrow, so prepare ppt.");
    l.showTasks();
    l.stats();
    l.completeTask(4);
    l.completeTask(5);
    l.completeTask(7);
    l.deleteTask(3);
    l.showTasks();
    l.deleteTask(5);
    l.showTasks();
    l.stats();
    return 0;
}