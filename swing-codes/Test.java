import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

abstract class Shape{
    abstract void area();

    void display(){
        System.out.println("Shape");
    }
}

interface A{
    int x = 100;
    void displayA();
}

interface B{
    void display();
}

class C implements A, B{
    public void display(){
        System.out.println("A");
    }

    public void displayA(){
        System.out.println("A");
    }
}

class MySwingApp extends JFrame{
    MySwingApp(){
        JLabel l = new JLabel("My Swing app");
        JButton b = new JButton("Click Here");
        l.setBounds(100, 100, 120, 30);
        b.setBounds(100, 150, 100, 30);

        add(l);
        add(b);

        setSize(300, 300);
        setLayout(null);
        setVisible(true);
    }
}

class ActionListenerDemo extends JFrame implements ActionListener{
    JLabel nameLabel, ageLabel;
    JTextField name, age;
    JButton b;

    ActionListenerDemo(){
        nameLabel = new JLabel("Enter your name");
        name = new JTextField();
        ageLabel = new JLabel("Enter age");
        age = new JTextField();
        b = new JButton("Click Here");

        nameLabel.setBounds(50, 100, 100, 40);
        name.setBounds(150, 100, 150, 40);
        ageLabel.setBounds(50, 170, 100, 40);
        age.setBounds(150, 170, 100, 40);
        b.setBounds(85, 230, 80, 40);

        b.addActionListener(this);
        
        add(nameLabel);
        add(name);
        add(ageLabel);
        add(age);
        add(b);

        setSize(400, 400);
        setLayout(null);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e){
        String n = name.getText();
        int a = Integer.parseInt(age.getText());
        System.out.println("Name: " + n + " age: " + a);
    }
}

class ColorChooserDemo extends JFrame implements ActionListener{
    JTextArea ta;
    JPasswordField f;

    ColorChooserDemo(){
        ta = new JTextArea();
        ta.setBounds(200, 100, 100, 100);
        JButton b = new JButton("Click Here");
        b.setBounds(200, 200, 80, 40);
        f = new JPasswordField();
        f.setBounds(200, 260, 120, 40);

        b.addActionListener(this);

        add(b);
        add(ta);
        add(f);
        
        setSize(400, 400);
        setLayout(null);
        setVisible(true);

    }

    public void actionPerformed(ActionEvent e){
        Color c = JColorChooser.showDialog(this, "Choose", Color.CYAN);
        ta.setBackground(c);
        System.out.println("PASS: " + f.getPassword());
    }
}

class ProgressBarDemo extends JFrame {
    JProgressBar jb;
    int i=0, num=0;

    ProgressBarDemo(){
        jb = new JProgressBar(0, 2000);
        jb.setBounds(100, 100, 180, 40);
        jb.setValue(0);
        jb.setStringPainted(true);
        
        add(jb);

        setSize(400, 400);
        setLayout(null);
        setVisible(true);
    }

    public void iterate(){
        while(i<=2000){
            
            try{
                Thread t = new Thread();
                t.sleep(2000);
                jb.setValue(i);
                i=i+20;
            
            }catch(InterruptedException e){

            }
            
        }
    }
}

class RegistrationForm extends JFrame implements ActionListener{
    JLabel name, age, gender;
    JRadioButton male, female;
    JComboBox dept;
    JTextField n, a;
    JButton b;

    RegistrationForm(){
        name = new JLabel("Enter name");
        n = new JTextField();
        age = new JLabel("Enter age");
        a = new JTextField();
        gender = new JLabel("Enter gender");
        male = new JRadioButton("Male");
        female = new JRadioButton("Female");
        ButtonGroup bg = new ButtonGroup();
        bg.add(male);
        bg.add(female);
        String[] items = {"MCA", "BCA"};
        dept = new JComboBox(items);
        b = new JButton("Done");

        add(name);
        add(n);
        add(age);
        add(a);
        add(gender);
        add(male);
        add(female);
        add(dept);
        add(b);

        name.setBounds(50, 100, 80, 40);
        n.setBounds(120, 100, 120, 40);
        age.setBounds(50, 120, 80, 40);
        a.setBounds(120, 120, 120, 40);
        gender.setBounds(50, 180, 80, 40);
        male.setBounds(120, 180, 120, 40);
        female.setBounds(150, 180, 80, 40);
        dept.setBounds(50, 220, 80, 40);
        b.setBounds(50, 290, 80, 40);

        b.addActionListener(this);

        setLayout(null);
        setVisible(true);
        setSize(400, 400);

    }

    public void actionPerformed(ActionEvent e){
        String name = n.getText();
        int age = Integer.parseInt(a.getText());
        String genderSelected;
        if(male.isSelected()){
            genderSelected = "Male";
        }else{
            genderSelected = "Female";
        }
        String d = (String) dept.getSelectedItem();
        System.out.println("DONE");
    }
}

public class Test {
    public static void main(String[] args) {
        ProgressBarDemo j = new ProgressBarDemo();
        j.iterate();
        
    }
}
