import java.awt.*;
import java.awt.event.*;

public class Student extends Frame implements ActionListener {
    Label l1, l2, l3;
    TextField t1, t2, t3;
    Button b;

    Student(){
        l1 = new Label("Name: ");
        l1.setBounds(50, 50, 80, 30);
        t1 = new TextField();
        t1.setBounds(150, 50, 100, 30);

        l2 = new Label("Marks1: ");
        l2.setBounds(50, 100, 80, 30);
        t2 = new TextField();
        t2.setBounds(150, 100, 100, 30);

        l3 = new Label("Marks2: ");
        l3.setBounds(50, 150, 80, 30);
        t3 = new TextField();
        t3.setBounds(150, 150, 100, 30);

        b = new Button("Total");
        b.setBounds(100, 200, 80, 30);

        add(l1);
        add(t1);
        add(l2);
        add(t2);
        add(l3);
        add(t3);
        add(b);

        setSize(300, 300);
        setLayout(null);
        setVisible(true);

        b.addActionListener(this);
    }

    public void actionPerformed(ActionEvent e){
        String name = t1.getText();
        int m1 = Integer.parseInt(t2.getText());
        int m2 = Integer.parseInt(t3.getText());
        System.out.println("name: " + name + " m1: " + m1 + " m2: " + m2 + " total: " + (m1+m2));
    }

    public static void main(String[] args){
        new Student();
    }
}
