import java.awt.*;

public class FirstAWT {
    public static void main(String[] args){
        Frame f = new Frame("MY first AWT App");

        Button b = new Button("Click Me");
        b.setBounds(100, 100, 100, 100);

        f.add(b);

        f.setSize(300, 300);
        f.setLayout(null);
        f.setVisible(true);
    }
}
