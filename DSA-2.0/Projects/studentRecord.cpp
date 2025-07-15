#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cctype>

class Student{
    public:
    int id;
    std::string first_name;
    std::string last_name;
    int age;
    int rollNo;
    std::map<std::string, float>marks;
    Student* next;
    Student* prev;
    Student(int id, std::string first_name, std::string last_name, int age, int rollNo){
        this->id = id;
        this->first_name = first_name;
        this->last_name = last_name;
        this->age = age;
        this->rollNo = rollNo;
        marks = {};
    }
};

class StudentRecord{
    public:
    int totalNoOfStudents=0;
    const int totalNoOfSubjects=5;
    Student* head = NULL;
    Student* tail = NULL;

    void insertStudentRecord(std::string first_name, std::string last_name, int age, int rollNo, std::vector<float> marks){
        std::transform(first_name.begin(), first_name.end(), first_name.begin(), ::tolower);
        std::transform(last_name.begin(), last_name.end(), last_name.begin(), ::tolower);
        Student* newStudent = new Student(totalNoOfStudents+1, first_name, last_name, age, rollNo);
        for(int i=0; i<totalNoOfSubjects; i++){
            if(i<marks.size()){
                newStudent->marks["sub"+std::to_string(i+1)] = marks[i];
            }else{
                newStudent->marks["sub"+std::to_string(i+1)] = 0.0f;
            }
        }
        if(head==NULL){
            head = tail = newStudent;
        }else{
            tail->next = newStudent;
            newStudent->prev = tail;
            tail = newStudent;
        }
        totalNoOfStudents+=1;
    }

    void showAllStudents(){
        Student* currentStudent = head;
        while(currentStudent!=NULL){
            std::cout<<"\nStudent Id: "<<currentStudent->id<<std::endl;
            std::cout<<"First Name: "<<currentStudent->first_name<<std::endl;
            std::cout<<"Last Name: "<<currentStudent->last_name<<std::endl;
            std::cout<<"Student Age: "<<currentStudent->age<<std::endl;
            std::cout<<"Roll No.: "<<currentStudent->rollNo<<std::endl;
            for(const auto &pair: currentStudent->marks){
                std::cout<<pair.first<<" : "<<pair.second<<std::endl;
            }
            currentStudent = currentStudent->next;
        }
    }

    void searchById(int id){
        Student* currentStudent = head;
        while(currentStudent!=NULL){
            if(currentStudent->id==id){
                std::cout<<"\nStudent Details: "<<std::endl;
                std::cout<<"Student Id: "<<currentStudent->id<<std::endl;
                std::cout<<"First Name: "<<currentStudent->first_name<<std::endl;
                std::cout<<"Last Name: "<<currentStudent->last_name<<std::endl;
                std::cout<<"Student Age: "<<currentStudent->age<<std::endl;
                std::cout<<"Roll No.: "<<currentStudent->rollNo<<std::endl;
                for(const auto &pair: currentStudent->marks){
                    std::cout<<pair.first<<" : "<<pair.second<<std::endl;
                }
                return;
            }else{
                currentStudent = currentStudent->next;
            }
        }
        std::cout<<"Not available"<<std::endl;
    }

    void deleteStudent(int id){
        if(head!=NULL && head->id==id){
            Student* delNode = head;
            head = head->next;
            if(head!=NULL){
                head->prev = NULL;
            }else{
                tail = NULL;
            }
            delete delNode;
            totalNoOfStudents-=1;
            return;
        }else{
            Student *currentStudent = head;
            while(currentStudent!=NULL){
                if(currentStudent->next->id==id){
                    Student* delNode = currentStudent->next;
                    currentStudent->next = delNode->next;
                    delNode->prev = NULL;
                    delete delNode;
                    totalNoOfStudents-=1;
                    break;
                }else{
                    currentStudent = currentStudent->next;
                }
            }
        }
    }

    ~StudentRecord(){
        Student* currentStudent = head;
        while(currentStudent!=NULL){
            Student* remainingStudents = currentStudent->next;
            delete currentStudent;
            currentStudent = remainingStudents;
        }
    }
};

int main(){
    StudentRecord s = StudentRecord();
    s.insertStudentRecord("Alex", "Borah", 20, 200, {92.2f, 80.5f, 95.0f, 99.5f, 85.5f});
    s.insertStudentRecord("Bob", "Kim", 20, 200, {50.2f, 80.0f, 95.0f, 85.5f, 100.0f});
    s.insertStudentRecord("Aman", "Boruah", 20, 200, {64.2f, 40.5f, 55.0f, 96.5f, 85.5f});
    s.insertStudentRecord("Cam", "Kim", 20, 200, {70.2f, 60.0f, 95.0f, 75.5f, 60.0f});
    s.insertStudentRecord("John", "Borah", 20, 200, {70.2f, 80.5f, 95.0f, 99.5f, 85.5f});
    s.insertStudentRecord("Miriam", "Maisel", 20, 200, {64.2f, 40.5f, 55.0f, 96.5f, 85.5f});
    s.insertStudentRecord("Zen", "Kim", 20, 200, {50.2f, 80.0f, 65.0f, 85.5f, 100.0f});
    s.showAllStudents();
    s.searchById(4);
    s.deleteStudent(5);
    s.showAllStudents();
    return 0;
}