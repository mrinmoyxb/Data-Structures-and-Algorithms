class MyThread4 extends Thread{
    
}

public class ThreadStates extends Thread{

    public void run(){
        System.out.println("RUNNING");
        try{
            Thread.sleep(2000);
        }catch(InterruptedException e){
            System.out.println(e);
        }
    }

    public static void main(String[] args) throws InterruptedException{
        ThreadStates t = new ThreadStates();
        System.out.println(t.getState());
        t.start();
        System.out.println(t.getState());
        Thread.sleep(100);
        System.out.println(t.getState());
        t.join();
        System.out.println(t.getState());
    }
}
