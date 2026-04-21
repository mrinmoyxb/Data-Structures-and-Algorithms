

public class ThreadStates extends Thread{

    public void run(){
        System.out.println("RUNNING");
    }
    public static void main(String[] args) throws InterruptedException{
        ThreadStates t = new ThreadStates();
        System.out.println(t.getState());
        t.start();
        System.out.println(t.getState());
        Thread.sleep(2000);
        t.join();
        System.out.println(t.getState());
    }
}
