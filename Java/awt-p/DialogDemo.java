import java.awt.*;
import java.awt.event.*;

public class DialogDemo extends Frame implements ActionListener {
    Button b;
    Dialog d;

    DialogDemo(){
        b = new Button("Open Dialog");
        b.setBounds(100, 100, 120, 30);
        add(b);

        setSize(300, 300);
        setLayout(null);
        setVisible(true);

        b.addActionListener(this);
    }

    public void actionPerformed(ActionEvent e){
        d = new Dialog(this, "Dialog Box", true);
        d.setSize(200, 150);
        d.setLayout(new FlowLayout());

        Label l = new Label("Hello from Dialog");
        Button close = new Button("Close");

        d.add(l);
        d.add(close);

        close.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e){
                d.setVisible(false);
            }
        });

        d.setVisible(true);
    }

    public static void main(String[] args){
        new DialogDemo();
    }
}
