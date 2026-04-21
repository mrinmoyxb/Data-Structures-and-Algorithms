import java.io.IOException;
import java.util.Vector;
import java.awt.*;
import java.awt.event.MouseListener;
import java.util.*;

abstract class Ze{
    void display(){
        System.out.println("Abstract method");
    }

    abstract void sound();
}

class Aa extends Ze{

    static int data;

    Aa(){
        System.out.println("Done");
    }

    static void addValue(int d){
        data = d;
    }

    void sound(){
        System.out.println("Hello");
    }

    void errorCheck() throws IOException, ArithmeticException{
        for(int i=0; i<5; i++){
            System.out.println(i);
        }
    }
}

class ErrorDemo1{
    void checkAge(int age) throws Exception{
        if(age<18){
            throw new Exception("Age is less than 18");
        }else{
            System.out.println("Done");
        }
    }
}

class NoMatchException extends Exception{
    NoMatchException(String message){
        super(message);
    }
}

class ShoppingList{
    Vector<String> items = new Vector<>();

    void acceptItems(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter 5 items");

        for(int i=0; i<5; i++){
            String s = sc.nextLine();
            items.add(s);
        }
    }

    void display(){
        System.out.println(items);
    }

    void deleteItem(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter an item to delete: ");
        String item = sc.nextLine();

        if(items.remove(item)){
            System.out.println("Done");
        }
        
    }
}

public class Check2 {
    public static void main(String[] args){
        String wordx = "Hello";
        String[] words = wordx.toLowerCase().split("\\s+");
        HashMap<String, Integer> map = new HashMap<>();
        for(String word: words){
            if(map.containsKey(word)){
                map.put(word, map.get(word)+1);
            }
        }
    }
}
