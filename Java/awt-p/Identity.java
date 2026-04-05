import java.awt.*;
import java.awt.event.*;

public class Identity extends Frame implements ActionListener{
    Button b;
    TextArea t1, t2;
    Label l1, l2;

    Identity(){
        l1 = new Label("Name: ");
        l1.setBounds(50, 50, 100, 30);

        t1 = new TextArea();
        t1.setBounds(50, 90, 200, 60);

        l2 = new Label("Age: ");
        l2.setBounds(50, 50, 100, 30);

        t2 = new TextArea();
        t2.setBounds(50, 110, 200, 60);

        b = new Button("Submit");
        b.setBounds(50, 170, 80, 30);
        add(l1);
        add(t1);
        add(l2);
        add(t2);
        add(b);

        setSize(300, 300);
        setLayout(null);
        setVisible(true);

        b.addActionListener(this);
    }

    public void actionPerformed(ActionEvent e){
        String name = t1.getText();
        String age = t1.getText();
        System.out.println("Clicked: " + name + "Age: " + age);
    }

    public static void main(String[] args){
        new Identity();
    }
}
