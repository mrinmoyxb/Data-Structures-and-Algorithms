class World extends Thread{
    @Override
    public void run(){
        for(int i=0; i<5; i++){
            System.out.println(Thread.currentThread().getName());
        }
    }
}

class Check implements Runnable{
    @Override
    public void run(){
        for(int i=0; i<5; i++){
            System.out.println(Thread.currentThread().getName());
        }
    }
}

public class ThreadTest {
    public static void main(String[] args) {

        World w = new World();
        w.start();

        Check c = new Check();
        Thread t1 = new Thread(c);
        t1.start();

        for(int i=0; i<5; i++){
            System.out.println(Thread.currentThread().getName());
        }

        System.out.println(t1.getState());

    }
}
