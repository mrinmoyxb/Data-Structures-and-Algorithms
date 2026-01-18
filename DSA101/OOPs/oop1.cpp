#include <iostream>
#include <string>

class Employee{
    private:
    int eid;
    std::string ename;
    float salary;

    public:
    Employee(int eid, std::string ename, float salary){
        this->eid = eid;
        this->ename = ename;
        this->salary = salary;
    }

    void displayInfo(){
        std::cout<<"name: "<<this->ename<<std::endl;
        std::cout<<"eid: "<<this->eid<<std::endl;
        std::cout<<"salary: "<<this->salary<<std::endl;
    }

    ~Employee(){
        std::cout<<"Destructor called"<<std::endl;
    }
};


int main(){
    Employee e = Employee(101, "Alex", 90000.00f);
    e.displayInfo();
    return 0;
}