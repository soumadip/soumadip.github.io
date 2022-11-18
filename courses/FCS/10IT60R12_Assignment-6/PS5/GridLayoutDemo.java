// Grid Llayout Manager //
import java.awt.*;
import java.applet.Applet;
public class GridLayoutDemo extends Applet {
    Button b1,b2,b3,b4,b5,b6 ;
    public void init ( ) {
      setLayout (new GridLayout (3,2) ) ;    // 3 rows, 2 columns
      b1 = new Button ("B1");
      b2 = new Button ("B2");
      b3 = new Button ("B3" );
      b4 = new Button ("B4" );
      b5 = new Button ("B5" );
      b6= new Button ("B6" );
      add (b1); add (b2); add (b3);
      add (b4); add (b5); add (b6);
    }
}

