import java.awt.*;
import java.awt.event.*;

class MyFrame extends Frame implements ActionListener{
    Button b;

    MyFrame(){
        b = new Button("Click Me");
        b.setBounds(100, 100, 80, 30);
        add(b);
        setSize(300, 300);
        setLayout(null);
        setVisible(true);

        b.addActionListener(this);
    }

    public void actionPerformed(ActionEvent e){
        System.out.println("Button Clicked");
    }

    public static void main(String[] args){
        new MyFrame();
    }
}