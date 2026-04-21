import java.awt.*;
import java.awt.event.ActionListener;

import java.awt.event.*;

class MyAWT1 extends Frame{
    MyAWT1(){
        Label l = new Label("My AWT Application");
        l.setBounds(100, 100, 180, 70);
        Button b = new Button("Click Here");
        b.setBounds(80, 180, 100, 30);

        add(l);
        add(b);

        setSize(300, 300);
        setLayout(null);
        setVisible(true);
    }
}

class MyAWT2{
    MyAWT2(){
        Frame f = new Frame("Top frame");
        Label l = new Label("My AWT application");
        Button b = new Button("Click Here");
        l.setBounds(100, 100, 180, 70);
        b.setBounds(80, 180, 100, 30);

        f.add(l);
        f.add(b);

        f.setSize(300, 300);
        f.setLayout(null);
        f.setVisible(true);
    }
}

class ActionListener1 extends Frame implements ActionListener{

    Label name, age, marks1, marks2;
    TextField n, a, m1, m2;
    Button total, product;

    ActionListener1(){
        name = new Label("Enter name: ");
        n = new TextField();
        age = new Label("Enter age: ");
        a = new TextField();
        marks1 = new Label("Enter marks1: ");
        m1 = new TextField();
        marks2 = new Label("Enter marks2: ");
        m2 = new TextField();
        total = new Button("Total");
        product = new Button("Product");

        name.setBounds(50, 50, 70, 30);
        n.setBounds(200, 50, 70, 30);
        age.setBounds(50, 90, 70, 30);
        a.setBounds(200, 90, 70, 30);
        marks1.setBounds(50, 130, 70, 30);
        m1.setBounds(200, 130, 70, 30);
        marks2.setBounds(50, 170, 70, 30);
        m2.setBounds(200, 170, 70, 30);
        total.setBounds(50, 200, 70, 30);
        product.setBounds(200, 200, 70, 30);

        add(name);
        add(n);
        add(age);
        add(a);
        add(marks1);
        add(m1);
        add(marks2);
        add(m2);
        add(total);
        add(product);

        total.addActionListener(this);
        product.addActionListener(this);

        setSize(400, 400);
        setLayout(null);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e){
        String name = n.getText();
        int age = Integer.parseInt(a.getText());
        int m1x = Integer.parseInt(m1.getText());
        int m2x = Integer.parseInt(m2.getText());

        if(e.getSource() == total){
            System.out.println("Name: "+ name);
            System.out.println("TOTAL: " + (m1x+m2x));
        }

        if(e.getSource() == product){
            System.out.println("Age: " + age);
            System.out.println("PRODUCT: " + (m1x*m2x));
        }
    }
}

class DialogBox1 {
    DialogBox1(){
        Frame f = new Frame();
        Button b = new Button("Click Here");
        b.setBounds(100, 100, 80, 40);

        f.add(b);

        f.setSize(300, 300);
        f.setLayout(null);
        f.setVisible(true);

        b.addActionListener(ev -> {
            Dialog d = new Dialog(f, "My Dialog", false);
            d.setSize(200, 150);
            d.setLayout(new FlowLayout());

            d.add(new Label("Hello from dialog"));

            Button close = new Button("Close");
            close.addActionListener(e -> d.setVisible(false));
            d.add(close);

            d.setVisible(true);
        });
    }
} 

class PanelDemo extends Frame{
    PanelDemo(){
        Panel p1 = new Panel();
        p1.setLayout(new FlowLayout());
        p1.add(new Button("Button 1"));
        p1.add(new Button("Button 2"));

        Panel p2 = new Panel();
        p2.setLayout(new FlowLayout());
        p2.add(new Button("Button 3"));
        p2.add(new Button("Button 4"));

        setLayout(new BorderLayout());
        add(p1, BorderLayout.NORTH);
        add(p2, BorderLayout.SOUTH);
        setSize(300, 300);
        setVisible(true);
    }
}

class MyCanvas extends Canvas{
    public void paint(Graphics g){
        g.drawString("Hello Canvas!", 50, 50);
        g.setColor(Color.RED);
        g.fillRect(50, 70, 100, 50);
    }
}

class CanvasDemo extends Frame{
    CanvasDemo(){
        MyCanvas c = new MyCanvas();
        c.setSize(300, 300);
        
        add(c);
        setSize(400, 400);
        setLayout(null);
        setVisible(true);
    }
}

class LayoutDemo extends Frame{
    LayoutDemo(){
        //setLayout(new FlowLayout());
        //setLayout(new GridLayout(2, 3));
        setLayout(new BorderLayout());

        add(new Button("N"), BorderLayout.NORTH);
        add(new Button("S"), BorderLayout.SOUTH);
        add(new Button("E"), BorderLayout.EAST);
        add(new Button("W"), BorderLayout.WEST);
        add(new Button("C"), BorderLayout.CENTER);

        setSize(300, 300);
        setVisible(true);
    }
}

class KeyDemo extends Frame implements KeyListener{
    Label l;

    KeyDemo(){
        l = new Label();
        l.setBounds(50, 100, 300, 30);
        add(l);

        addKeyListener(this);

        setSize(400, 300);
        setLayout(null);
        setVisible(true);
    }

    public void keyPressed(KeyEvent e){
        l.setText("Key Pressed: " + e.getKeyCode());
    }
    public void keyReleased(KeyEvent e){
        l.setText("Key Released: " + e.getKeyCode());
    }

    public void keyTyped(KeyEvent e) {
        l.setText("Key Typed: " + e.getKeyChar());
    }
}

class MouseDemo extends Frame implements MouseListener{
    Label l;
    MouseDemo(){
        l = new Label("Interact with mouse");
        l.setBounds(50, 100, 200, 30);
        add(l);

        addMouseListener(this);

        setSize(300, 300);
        setLayout(null);
        setVisible(true);
    }

    public void mouseClicked(MouseEvent e) {
        l.setText("Mouse Clicked");
    }

    public void mousePressed(MouseEvent e) {
        l.setText("Mouse Pressed");
    }

    public void mouseReleased(MouseEvent e) {
        l.setText("Mouse Released");
    }

    public void mouseEntered(MouseEvent e) {
        l.setText("Mouse Entered");
    }

    public void mouseExited(MouseEvent e) {
        l.setText("Mouse Exited");
    }
}

class MouseMotionDemo extends Frame implements MouseMotionListener {

    Label l;

    MouseMotionDemo() {
        l = new Label("Move mouse...");
        l.setBounds(50, 50, 250, 30);
        add(l);

        addMouseMotionListener(this); // attach listener

        setSize(400, 300);
        setLayout(null);
        setVisible(true);
    }

    public void mouseMoved(MouseEvent e) {
        l.setText("Mouse moved: X=" + e.getX() + " Y=" + e.getY());
    }

    public void mouseDragged(MouseEvent e) {
        l.setText("Mouse dragged: X=" + e.getX() + " Y=" + e.getY());
    }
}

public class Temp1 {
    public static void main(String[] args) {
        new KeyDemo();
    }
}
