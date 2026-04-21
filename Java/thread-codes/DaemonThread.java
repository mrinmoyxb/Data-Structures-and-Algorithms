class MyThread extends Thread {
    public void run() {
        for(int i=0; i<20; i++){
            System.out.println(i);
        }
        System.out.println("Daemon thread task done");
    }
}

public class DaemonThread {
    public static void main(String[] args) {
        MyThread t = new MyThread();
        t.setDaemon(true); // making it daemon
        t.start();
        System.out.println("DONE");
    }
}
