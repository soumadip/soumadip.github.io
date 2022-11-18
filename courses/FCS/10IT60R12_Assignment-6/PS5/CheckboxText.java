// To create a checkbox  //
import java.awt .*;                  // To import the check bon class.
import java.applet.*;
public class CheckboxText extends  Applet        {
    public void init ( ) {
        Checkbox c1 = new Checkbox (   );         // default constructor without
any label
        Checkbox c2 = new Checkbox ( " Solaris 2.x");   // Check box with default
layout
        Checkbox c3 = new Checkbox ( "Macintosh", null, false);
        Checkbox c4 = new Checkbox ( "Windows 95", null, true);
        add (c1);
        add (c2);
        add (c3);
        add (c4);
    }
}

