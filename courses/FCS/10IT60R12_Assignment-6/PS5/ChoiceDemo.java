//  To create Choice component    //
import java.awt.*;
import java.applet.*;
public class ChoiceDemo extends Applet {
    public void init ( ) {
      int width = Integer.parseInt (getParameter( " width" ));
      int height = Integer.parseInt (getParameter(" height"));
                               // To get the width and height of the applet.
      Choice os = new Choice ( );          // os is an instance of choice class.
      Choice browser = new Choice ( );     // browser is the another instance.
      os.addItem ( " Windows 95" );
      os.addItem ( " Solaris 2.x " );
      os.addItem ( " Mac OS 7.5 ");
      browser.addItem (" Netscape Navigator 2.0");
      browser.addItem ( "Internet Explorer 4.0" );
      browser.addItem ("Hot Java ") ;
      add (os);
      add (browser );
      os.reshape ( 0, 0, width/2, height/2 );
      browser.reshape (0, height/2, width, height);
    }
}

