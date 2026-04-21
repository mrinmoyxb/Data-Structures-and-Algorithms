
public class Thread1 extends Thread{

    @Override
    public void run(){

    }
    public static void main(String[] args){
        Thread1 t1 = new Thread1();

        System.out.println("STATE: " + t1.getState());
        for(int i=0; i<5; i++){
            System.out.println("Thread: " + Thread.currentThread().getName());
        }
        System.out.println("STATE: " + t1.getState());
    }
}
