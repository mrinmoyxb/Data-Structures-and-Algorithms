package temp;

import java.awt.*;

class MyAWT extends Frame {
    MyAWT() {
        Label l = new Label("My AWT Application");
        l.setBounds(80, 150, 150, 30); // position + size
        add(l);

        setSize(300, 300);
        setLayout(null);
        setVisible(true);
    }
}

public class MyAWT1 {
    public static void main(String[] args) {
        new MyAWT();
    }
}