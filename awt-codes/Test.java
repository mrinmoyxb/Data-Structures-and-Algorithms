import java.awt.*;
import java.awt.event.*;

class MyFrame extends Frame{
    MyFrame(){
        Button b = new Button("Click Me");
        b.setBounds(100, 100, 100, 100);
        add(b);
        setSize(300, 300);
        setLayout(null);
        setVisible(true);
    }
}

class EventDemo implements ActionListener{

    Label l1, l2, m1, m2;
    TextField t1, t2, t3, t4;
    Button b, b1;

    EventDemo(){
        Frame f = new Frame("Student");

        l1 = new Label("Name");
        l1.setBounds(50, 50, 80, 30);
        t1 = new TextField();
        t1.setBounds(150, 50, 80, 30);

        l2 = new Label("Age");
        l2.setBounds(50, 90, 100, 30);
        t2 = new TextField();
        t2.setBounds(150, 90, 80, 30);

        m1 = new Label("marks1");
        m1.setBounds(50, 130, 80, 30);
        t3 = new TextField();
        t3.setBounds(150, 130, 80, 30);

        m2 = new Label("marks2");
        m2.setBounds(50, 170, 80, 30);
        t4 = new TextField();
        t4.setBounds(150, 170, 80, 30);

        b = new Button("Click Me");
        b.setBounds(100, 210, 80, 30);

        b1 = new Button("Button");
        b1.setBounds(170, 210, 80, 30);

        f.add(l1);
        f.add(t1);
        f.add(l2);
        f.add(t2);
        f.add(m1);
        f.add(t3);
        f.add(m2);
        f.add(t4);
        f.add(b);
        f.add(b1);

        b.addActionListener(this);
        b1.addActionListener(this);

        f.setSize(300, 300);
        f.setLayout(null);
        f.setVisible(true);
    }

    public void actionPerformed(ActionEvent e){
        String name = t1.getText();
        int age = Integer.parseInt(t2.getText());
        int m1 = Integer.parseInt(t3.getText());
        int m2 = Integer.parseInt(t4.getText());
        
        if(e.getSource() == b){
            System.out.println("Name: " + name);
            System.out.println("Age: "+ age);
            System.out.println("M1: " + m1 + " M2: " + m2 + " = " + (m1+m2));
        }

        if(e.getSource() == b1){
            System.out.println("\n Helllo \n");
        }
    }
    
}

class DialogDemo{
    DialogDemo(){
        Frame f = new Frame("Dialog Box");

        Button b = new Button("Open Dialog");
        b.setBounds(150, 150, 100, 80);

        f.add(b);

        b.addActionListener(e -> {
            Dialog d = new Dialog(f, "My Dialog", false);
            d.setSize(200, 150);
            d.setLayout(new FlowLayout());

            d.add(new Label("Hello from dialog"));

            Button close = new Button("Close");
            close.addActionListener(ev -> d.setVisible(false));
            d.add(close);

            d.setVisible(true);
        });

        f.setSize(300, 300);
        f.setLayout(null);
        f.setVisible(true);

    }
}

class AWT1 extends Frame{

    Label l;
    Button b;

    AWT1(){
        l = new Label("AWT application");
        l.setBounds(50, 50, 150, 80);
        b = new Button("Click Here");
        b.setBounds(50, 150, 120, 80);

        add(l);
        add(b);

        setSize(300, 300);
        setLayout(null);
        setVisible(true);
    }
}

class AWT2 {

    AWT2(){
        Frame f = new Frame("New frame");
        Label l = new Label("AWT application");
        l.setBounds(100, 100, 100, 100);


        f.add(l);

        f.setSize(300, 300);
        f.setLayout(null);
        f.setVisible(true);
    }
}

class AWT3 extends Frame implements ActionListener{
    Label name, age, gender, dept;
    TextField nameField, ageField;
    Button b;
    Choice ch;
    CheckboxGroup genderGroup;
    Checkbox male, female;

    AWT3(){
        name = new Label("Enter your name ");
        nameField = new TextField();
        age = new Label("Enter your age");
        ageField = new TextField();
        gender = new Label("Gender");
        genderGroup = new CheckboxGroup();
        male = new Checkbox("male", genderGroup, false);
        female = new Checkbox("female", genderGroup, false);
        dept = new Label("Select your dept");
        ch = new Choice();
        ch.add("BCA");
        ch.add("MCA");
        b = new Button("Submit");
        b.addActionListener(this);

        name.setBounds(50, 50, 150, 30);
        nameField.setBounds(220, 50, 150, 30);

        age.setBounds(50, 100, 150, 30);
        ageField.setBounds(220, 100, 150, 30);

        gender.setBounds(50, 150, 150, 30);
        male.setBounds(220, 150, 70, 30);
        female.setBounds(300, 150, 80, 30);

        dept.setBounds(50, 200, 150, 30);
        ch.setBounds(220, 200, 150, 30);

        b.setBounds(150, 260, 100, 40);

        add(name);
        add(nameField);
        add(age);
        add(ageField);
        add(gender);
        add(male);
        add(female);
        add(ch);
        add(dept);
        add(b);

        setSize(600, 600);
        setLayout( null);
        setVisible(true);

    }

    public void actionPerformed(ActionEvent e){
        String name = nameField.getText();
        String age = ageField.getText();

        Checkbox selected = genderGroup.getSelectedCheckbox();
        String gender = (selected!=null) ? selected.getLabel() : "Not selected";

        String dept = ch.getSelectedItem();

        System.out.println("Name: " + name + " age: " + age + " Gender: " + gender + " Dept: " + dept);
    }
}

class Layout1{
    Layout1(){
        Frame f = new Frame();

        f.setLayout(new GridLayout(2, 2));

        f.add(new Button("1"));
        f.add(new Button("2"));
        f.add(new Button("3"));
        f.add(new Button("4"));

        f.setSize(300, 200);
        f.setVisible(true);
    }
}

class PanelDemo extends Frame{
    PanelDemo(){
        Panel p1 = new Panel();
        p1.setLayout(new FlowLayout());
        p1.add(new Button("OK"));
        p1.add(new Button("Cancel"));

        Panel p2 = new Panel();
        p2.setLayout(new GridLayout(2, 1));
        p2.add(new Button("OK"));
        p2.add(new Button("Cancel"));

        setLayout(new BorderLayout());
        add(p1, BorderLayout.NORTH);
        add(p2, BorderLayout.SOUTH);
        setSize(300, 300);
        setVisible(true);
    }
}

class DialogDemo1 extends Frame{
    
    DialogDemo1(){
        Button b = new Button("Click Here");
        b.setBounds(50, 50, 100, 80);

        add(b);

        setSize(300, 300);
        setVisible(true);
        setLayout(null);

        b.addActionListener(e -> {
            Dialog d = new Dialog(this, "My dialog", true);
            d.setSize(250, 200);
            d.setLayout(new FlowLayout());

            d.add(new Label("Hello User"));
            Button close = new Button("Done");
            close.addActionListener(ev -> d.setVisible(false));
            d.add(close);

            d.setVisible(true);
        });
    }
}

class MyCanvas extends Canvas{
    public void paint(Graphics g){
        g.drawString("Hello", 100, 100);
        g.drawLine(50, 50, 150, 50);
    }
}

class CanvasDemo {
    CanvasDemo(){
        Frame f = new Frame("Canvas Example");

        MyCanvas c = new MyCanvas();
        c.setSize(300, 300);

        f.add(c);
        f.setSize(400, 400);
        f.setVisible(true);
    }
}



public class Test {
    public static void main(String[] args){
    }
}
