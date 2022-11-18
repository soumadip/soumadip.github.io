// Craet Card Layout
import java.awt.*;
public class Crads extends java.applet.aApplet {
    CardLayout   layout;
    public void init ( ) {
      layout = new CardLayout ( ) ;
      setLayout (layout );
      add ("1", new Button ("Card1" ));
      add ("2", new Button ("Card2" ));
      add ("3", new Button ("Card3" ));
      add ("4", new Button ("Card4" ));
      add ("5", new Button ("Card5" ));
    }
    public boolean key Down (Even e int key ){
      layout next (this);
      return (true );
    }
}

