// To Create Border Layout Manager
import java.awt.*;
import java.applet.*;
import java.util.*;
public calss BorderLayoutDemo extends Applet {
    public void intit ( ) {
      Frame frame = new Frame ( );
      frame.setLayout ( new BorderLayout (20,40));
      Button buttonN, buttonS, buttonE, buttonW, buttonC;
      buttonN = new Button ( " NORTH " );
      buttonS = new Button ( " SOUTH" );
      buttonE = new Button ( " EAST" );
      buttonW = new Button (" WEST" );
      buttonC = new Button("CENTER");
      frame.resize (250,250);        // resize the frame is height = 250 pixels , width 250 pixels
      frame.add ( "North", buttonN );
      frame.add (" South ", buttons );
      frame.add ( "East", buttonE );
      frame.add (" West" , buttonW );
      frame.add("Center",buttonC);
      frame.show ( );
     }
}

