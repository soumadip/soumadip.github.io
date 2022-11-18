//  To create a button  //
import java.applet.Applet;
import java.awt.*;                         // To import the Button class
public class ButtonTest extends Applet {
    public void init( ) {
        Button    b1,b2;                   // Create two Button objects
        b1 = new Button ("Welcome");             // One button is initialized
        add(b1);                     // Add it into the applet
        b2 = new Button ( );                     // Second default button
        add(b2);                     // Add second button to the applet
    }
}

