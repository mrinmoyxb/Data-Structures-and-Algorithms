class Student{
    String name;
    int age;
    Student(String name, int age){
        this.name = name;
        this.age = age;
    }

    Student(){
        this("ALex", 101);
        System.out.println("Done");
    }

    void display(){
        System.out.println("Name: " + this.name);
        System.out.println("Age: " + this.age);
    }

    void add(int num1, int num2){
        System.out.println("Done");
    }

    void add(double num1, int num2, int num3){
        System.out.println("Done");
    }

    void add(int num1, double num2){
        System.out.println("Done");
    }
}

class Employee{
    static final String companyName = "ABC";
    static String name = "X";
    protected int eid = 101;
    private int key = 102;

    static void changeName(String n){
        name = n;
    }

    Employee(String name){
        System.out.println("DONE");
    }

    void display(){
        name  = "X";
        System.out.println(companyName);
    }
}

class A extends Employee{
    A(String name){
        super(name);
    }
    void display(){
        System.out.println("DONe");
    }
}


public class Main {
    public static void main(String[] args){
        A a = new A("ALEx");
        a.display();
    }
}
