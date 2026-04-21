class Test1{
    int num;
    String name;

    Test1(int num, String name){
        System.out.println("Name: " + this.name);
        System.out.println("Num: " + this.num);
    }
}

class Test2 extends Test1{
    int id;
    Test2(int num, String name, int id){
        super(num, name);
        this.id = id;
    }
}

public class X {
    public static void main(String[] args){
        Test1 t = new Test1(10, "A");
    }
}
