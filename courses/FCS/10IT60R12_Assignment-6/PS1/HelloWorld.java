	/*<APPLET CODE = "HelloWorld.class"
                  WIDTH = 200    HEIGHT = 100 >
        </APPLET>*/
//import java.lang.*;
// An applet to print Hello World! //
      import java.awt.Graphics;
      import java.applet.Applet;
      public class HelloWorld extends Applet {
            public void paint (Graphics g ) {
                  g.drawString ( " Hello World!",50, 25 );
            }
      }

