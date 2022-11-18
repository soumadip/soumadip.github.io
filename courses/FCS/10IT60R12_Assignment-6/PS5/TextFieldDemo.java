// To create a text field
import java.awt.*;
import java.applet.* ;
public class TextFieldDemo extends Applet       {
   public void init ( ) {
      add ( new TextField("Type your Name", 20);
      // create a text field window of 20 character widths
      Label login = new Label ( "Login : " , Label.LEFT );
      Label pswd = new Label ( "Password : " , Label.CENTER );
    TextField log = new TextField (8) ;      // Text field for 8 characters
    TextField pas = new TextField (8);
    pas.setEchoCharacter ( '*' );            // echo hide the type pass
    add (login);  add (log);           // add labels in the applet and
    add (pswd );  add (pass );         // add corresponding text fields
  }
}

