import java.awt.*;

public class PanelLayoutExample extends Frame {

    Panel top, bottom;

    PanelLayoutExample() {

        setLayout(new BorderLayout());

        // Top panel
        top = new Panel();
        top.setLayout(new FlowLayout());
        top.add(new Label("Name:"));
        top.add(new TextField(15));

        // Bottom panel
        bottom = new Panel();
        bottom.setLayout(new GridLayout(1, 2));
        bottom.add(new Button("OK"));
        bottom.add(new Button("Cancel"));

        add(top, BorderLayout.NORTH);
        add(bottom, BorderLayout.SOUTH);

        setSize(300, 200);
        setVisible(true);
    }

    public static void main(String[] args) {
        new PanelLayoutExample();
    }
}