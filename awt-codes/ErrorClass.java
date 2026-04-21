class DemoError{
    static void checkAge(int age) throws Exception {
        if(age < 18){
            throw new Exception("Underage");
        }
    }
}


public class ErrorClass {
    public static void main(String[] args){
        try {
            DemoError.checkAge(22);
        }catch(Exception e){
            System.out.println(e.getMessage());
        }
    }
}
