// To create a Panel
import java.awt.* ;
import java.awt.applet.*;
public class MyPanel {
    public static void main ( String args [ ] ) {
      Frame frame = new Frame( "Frame with panel");
      Panel panel = new Panel( );
      frame.resize(200, 200);
      frame setBackground (Color.blue);
      frame.setLayout (null);             // override default layout
      panel.resize (100, 100) ;
      panel.setBackground (Color.yellow );
      frame.add (panel);                   // add the panel into the frame
      frame.show ( );                      // display the panel
    }
}

