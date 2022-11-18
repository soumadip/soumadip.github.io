// To create list //
import java.awt.*;
import java.applet.*;
public class ListDemo extends Applet {
    public void init ( ) {
      setLayout (null );                  // It is a default Layout setting
      int width = Integer.parseInt (getParameter (" width" ) );
            int height = Integer.parseInt (getParameter (" height" ) );
      List os = new List (3, true);     // List object for list of Oss, multiple selection
      List browser = new List (5, false);// List object for Browsers, single choice
      // Add the Items into the lists
        os.addItem ( " Windows 95" );
      os.addItem ("Solaris 2.x " );
      os.addItem (" Mac OS 7.5 " );
      browser.addItem ("Netscape Navigator" );
      browser.addItem ("Internet Explorer" );
      browser.addItem ("Hot Java" );
      browser.addItem ("Mosaic" );
            browser.addItem ("Applet Viewer" );
      browser.select(1) ;     // Second item in the Browser list is selected
    // Add and place the lists onto the applet
    add(os);
    add(browser);
    os.reshape (0, 0, width,   height /2 );
    browser. reshape ( 0, height /2, width, height /2 );
  }
}

