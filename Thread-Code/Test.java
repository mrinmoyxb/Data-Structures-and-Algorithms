
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

public class Test {
    public static void main(String[] args) {
        // Thread1 t = new Thread1();
        Thread2 t2 = new Thread2();
        Thread t = new Thread(t2);
        t.start();

        for(int i=11; i<15; i++){
            System.out.println(Thread.currentThread().getName() + " " + i);
        }
    }
}
