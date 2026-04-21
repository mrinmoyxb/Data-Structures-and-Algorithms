
class MyThread2 extends Thread {
    public void run(){
        for(int i=0; i<10; i++){
            System.out.println("Current Thread: " + Thread.currentThread().getName() + " T2: " + i);
        }
    }
}

class MyThread3 implements Runnable{
    public void run(){
        for(int i=0; i<20; i++){
            System.out.println("Current Thread: " + Thread.currentThread().getName() + " T3: " + i);
        }
    }
}

public class MyThread {
    public static void main(String[] args){
        

        MyThread2 m1 = new MyThread2();
        m1.start();

        MyThread3 m2 = new MyThread3();
        Thread t1 = new Thread(m2);
        t1.start();

        for(int i=0; i<5; i++){
            System.out.println("Current Thread: " + Thread.currentThread().getName() + " T1: " + i);
        }
    }
}
