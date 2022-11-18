// To create a frame
import java.awt.*;
import java.awt.applet.*;
public class MyFrame {
    public static void main (String args[ ] ) {
      Frame frame = new Frame ( " Frame in Java " );
      frame.resize (500, 500);           // component method to resize the frame
      frame.setBackground (Color.blue ); // Background of the frame will be blue
      frame.show ( )                   // Method to show the frame on the screen
    }
}

