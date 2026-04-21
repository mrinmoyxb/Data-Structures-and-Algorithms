import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

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
            jb.setValue(i);
            i=i+20;
        }
    }
}

public class Test {
    public static void main(String[] args) {
        ProgressBarDemo p = new ProgressBarDemo();
        p.iterate();
    }
}
