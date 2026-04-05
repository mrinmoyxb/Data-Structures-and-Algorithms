import java.awt.*;

public class PanelDemo extends Frame {

    Panel p1, p2;

    PanelDemo(){
        setLayout(new FlowLayout());
        
        p1 = new Panel();
        p1.add(new Label("Name"));
        p1.add(new TextField(10));

        p2 = new Panel();
        p2.setLayout(new GridLayout(1, 2));
        p2.add(new Button("OK"));
        p2.add(new Button("Cancel"));

        add(p1);
        add(p2);
    }

    public static void main(String[] args){
        new PanelDemo();
    }
}
