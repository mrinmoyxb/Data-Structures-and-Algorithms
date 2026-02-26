class Employee{
    
    int empId;
    String empName;
    String designation;
    float salary;
    float bonus;
    
    static int empCount;

    Employee(){
        System.out.println("No argument constructor called");
        empCount+=1;
    }

    Employee(int empId, String empName, String designation, float salary, float bonus){
        this.empId = empId;
        this.empName = empName;
        this.designation = designation;
        this.salary = salary;
        this.bonus = bonus;
        empCount+=1;
    }

    void display(){
        System.out.println("EmpId: " + empId);
        System.out.println("EmpName: " + empName);
        System.out.println("Designation: " + designation);
        System.out.println("Salary: " + salary);
        System.out.println("Bonus: " + bonus);
    }

    static void displayEmpCount(){
        System.out.println("Total employee: " + empCount);
    }
}

class Demo1{
    
    int eid;
    String ename;

    Demo1(int eid, String ename){
        this.eid = eid;
        this.ename = ename;
    }

    void display(){
        System.out.println("Eid: " + eid);
        System.out.println("Ename: " + ename);
    }

    void display(int eid){
        System.out.println("Eid: " + eid);
        System.out.println("Ename: " + ename);
    }
}

class A {

    protected String ename = "ABC";
    protected static String cname = "A";

    A(String name){
        this.ename = name;
        System.out.println("CLASS A");
    }

    void displayA(){
        System.out.println("parent class A " + ename);
    }

    static void printClassName(){
        System.out.println("Class is: " + cname);
    }
}

class B extends A {

    int num;
    protected static String cname = "B";

    B(String name, int num){
        super(name);
        System.out.println("CLASS B");
    }
    void displayB(){
        System.out.println("Child class B");
        System.out.println("ENAME: " + super.ename);
    }

    static void printClassName(){
        System.out.println("Class is: " + cname);
    }
}

final class C extends B{
    C(String name, int num){
        super(name, num);
        System.out.println("CLASS C");
    }
    void displayC(){
        super.displayA();
        System.out.println("Child class C");
    }
}


public class Main {
    public static void main(String[] args){
        C c = new C("ABBBCCC", 101);
        c.displayC();

        System.out.println("Protected member: " + c.ename);

        C.printClassName();

    }
}
