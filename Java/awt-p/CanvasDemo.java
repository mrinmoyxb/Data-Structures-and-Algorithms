import java.awt.*;

class MyCanvas extends Canvas {
    public void paint(Graphics g) {
        g.drawString("Hello Canvas", 50, 50);
        g.drawRect(50, 70, 100, 50);
    }
}

public class CanvasDemo extends Frame {
    
    CanvasDemo(){
        MyCanvas c = new MyCanvas();
        add(c);
        setSize(300, 300);
        setVisible(true);
    }
    public static void main(String[] args){
        new CanvasDemo();
    }
}
