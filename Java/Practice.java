interface A{
    int x = 100;
    void displayA();
}

interface B{
    int y = 120;
    void displayB();
}

class X implements A, B{
    public void displayA(){
        System.out.println("Hello");
    }

    public void displayB(){
        System.out.println("Hello B");
    }
}

public class Practice {
    public static void main(String[] args){

        X x1 = new X();
        x1.displayA();
        x1.displayB();
    }
}
