// To create Flow layout
import java.awt.*;
import java.applet.*;
import java.util.*;
public class FlowLayoutDemo extends Applet {
    public void init ( )       {
      setLayout (new FlowLayout (FlowLayout.RIGHT, 10, 3));
      String val = " Data is not Information" +
                         " is not knowledge is not wisdom";
      StringTokenizer str = new StringTokenizer (val ); // Read a token from the String val
      while (str. hasMoreTokens ( ) ) {
          add (new Button (str.nextToken( ) ) ); // For one token add a label into the panel
      }
    }
}

