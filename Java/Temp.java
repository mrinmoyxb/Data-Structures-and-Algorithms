abstract class Employee{
    int empId;
    String empName;

    Employee(int empId, String empName){
        this.empId = empId;
        this.empName = empName;
        System.out.println("Abstract class");
    }

    abstract void display();

    void className(){
        System.out.println("Class is : Employee");
    }

}

class Child extends Employee{

    Child(int empId, String empName){
        super(empId, empName);
        System.out.println("Child class");
    }
    void display(){
        System.out.println("Name: " + empName);
        System.out.println("Id: " + empId);
    }
}

public class Temp {
    public static void main(String[] args){
        Child c = new Child(101, "A");
    }
}
