
class ThreadX extends Thread{

    ThreadX(String name){
        super(name);
    }

    public void run(){
        try{
            System.out.println(Thread.currentThread().getName() + " Priority: " + Thread.currentThread().getPriority());
            System.out.println("ThreadX Start");
            Thread.sleep(1000);
            System.out.println("ThreadX End");
        }catch(InterruptedException e){
            throw new RuntimeException(e);
        }
    }
}

public class ThreadMethods extends Thread{

    public static void main(String[] args) {
        
        ThreadX t1 = new ThreadX("Low Priority");
        ThreadX t2 = new ThreadX("Medium Priority");
        ThreadX t3 = new ThreadX("High Priority");

        t1.setPriority(Thread.MIN_PRIORITY);
        t2.setPriority(Thread.NORM_PRIORITY);
        t3.setPriority(Thread.MAX_PRIORITY);
        
        t1.start();
        t2.start();
        t3.start();
    }
}
