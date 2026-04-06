package Java.swing;

import javax.swing.*;

public class SwingDemo {
    public static void main(String[] args){
        JFrame frame = new JFrame("My first swing app");

        JLabel l = new JLabel("Name");
        l.setBounds(100, 100, 150, 30);

        JButton button = new JButton("Click Me");
        button.setBounds(100, 150, 120, 30);

        frame.add(l);
        frame.add(button);

        frame.setSize(400, 400);
        frame.setLayout(null);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    }
}
