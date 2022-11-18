//    To create label       //
import.java.awt.*;
import.java.applet.*;
public class LabelDemo extends Applet {
    public void init ( ) {
      setLayout (null );
      int width = Integer.parseInt ( getParameter ("width" ));
      int height = Integer.parseInt (get.Parameter (" height" ));
      Label left = new Label ( );                   // default alighment is left )
      Label center = new label ( " Center", Label.CENTER); // For Centered alignment
      Label right = new Label("Right", Label.RIGHT);               // for Right justified label
      // Add the labels on the applet //
      add(left);
      add (right );
      add (center );
      // Place the label properly on the applet; otherwise deafault placing will occur //
      left.reshape ( 0, 0, width, height/3);
      right.reshape(0, height/3, width, height/3);
      center.reshape (0, 2 * hight/3 , width, height/3);
    }
}

