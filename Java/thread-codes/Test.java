//! Thread.sleep()
class T1 extends Thread {
    public void run() {
        try {
            for (int i = 0; i < 5; i++) {
                if (i == 3) {
                    Thread.sleep(1000);
                    System.out.println("T1 is running: " + i);
                } else {
                    System.out.println("T1 is running: " + i);
                }
            }
        } catch (InterruptedException e) {
            System.out.println(e);
        }
    }
}

class T2 extends Thread {
    public void run() {
        for(int i=11; i<=15; i++){
            System.out.println("T2 is running: " + i);
            Thread.yield();
        }
    }
}

//! .join()
class T3 extends Thread{
    @Override
    public void run(){
        for(int i=0; i<5; i++){
            System.out.println("T3: " + i);
        }
    }
}

public class Test {
    public static void main(String[] args) throws InterruptedException{
        T2 t2 = new T2();
        T3 t3 = new T3();
        t2.start();
        t3.start();
        System.out.println("DONE");

    }
}
