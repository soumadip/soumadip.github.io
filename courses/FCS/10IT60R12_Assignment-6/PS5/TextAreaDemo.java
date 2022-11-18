// To create text area  //
import java.awt.*;
import java.applet.*;
public class TextAreaDemo extends Applet {
   TextArea text;
   String multiLineText =
      " To learn Java, you will first"
            + " need to obtain \ n   two different pieces of "
            + "softwares : \ n "
            + " The first is the JDK (Java Development Kit"
            + "and \n the second piece of software "
            + "is a Java capable browser."
            + " \n JDK software is needed for Writing, "
            + " Compiling, and Testing Java applet \n and
            + " Applications.\n \n" ;
    public void init ( ) {
        setLayout(null);
      text = new TextArea (multiLineText, 20, 40);
      add (text);
    }
}

