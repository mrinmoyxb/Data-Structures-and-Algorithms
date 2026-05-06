import java.io.FileReader;
import java.io.IOException;

class Thread1 extends Thread{
    public void run(){
        for(int i=0; i<5; i++){
            System.out.println(Thread.currentThread().getName() + " " + i);
        }
    }
}

class Thread2 implements Runnable{
    public void run(){
        for(int i=0; i<5; i++){
            System.out.println(Thread.currentThread().getName() + " " + i);
        }
    }
}

class Thread3 extends Thread{
    public void run(){
        for(int i=0; i<5; i++){
            System.out.println(Thread.currentThread().getName() + " : " + i);
        }
    }
}

class Thread4 extends Thread{
    public void run(){
        try{
            for(int i=0; i<5; i++){
                System.out.println(Thread.currentThread().getName() + " : " + i);
                Thread.sleep(1000);
            }
        }catch(InterruptedException e){
            System.out.println(e);
        }
    }
}

class Except {

    void error1(){
        try{
            FileReader f = new FileReader("abc.txt");
        }catch(IOException e){
            System.out.println("ERROR " + e );
        }
    }

    void error2(){
        try{
            int a = 10, b = 5;
            System.out.println(a/b);
        }catch(ArithmeticException e){
            System.out.println("ERROR " + e );
        }
    }
}

public class Test {
    public static void main(String[] args){
        // Thread1 t = new Thread1();
        // Thread2 t2 = new Thread2();
        // Thread t = new Thread(t2);
        // Thread3 t3 = new Thread3();
        Thread4 t4 = new Thread4();
        t4.start();

        for(int i=11; i<15; i++){
            System.out.println(Thread.currentThread().getName() + " : " + i);
        }
        // Except e = new Except();
        // e.error1();
        // e.error2();
    }
}
