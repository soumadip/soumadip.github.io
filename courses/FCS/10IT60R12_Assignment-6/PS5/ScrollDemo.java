// To create scroll bar  //
import java.awt.*;
import java.applet.*;
public class ScrollDemo extends Applet {
    public void init ( ) {
      setLayout( new Borderlayout ( ) );        // default border layout setting
      int width = Integer.parseInt (getParameter (" width" ));
      int height = Integer.parseInt (getParameter (" height"));
      Scrollbar hScroll = new Scrollbar ( Scrollbar. HORIZONTAL, 50, width /10,
0, 100 );
      Scrollbar vScroll = new Scrollbar ( Scrollbar.VERTICAL, 50, hight /2, 0,
100);
      add (hScroll );
      add (vScroll );
    }
}

