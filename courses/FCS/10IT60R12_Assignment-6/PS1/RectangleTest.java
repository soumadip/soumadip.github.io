/*
< applet code = " RectangleTest" width = 150 height = 100 >
< param name = xValue value = 20 >
< param name = yValue value = 40 >
< param name = wValue value = 100>
< param name = hValue value = 50 >
< /applet >
*/
// Use of  init( ) to pass value through HTML to applet //
   import java .awt . *;
   import java.applet. * ;
    public class RectangleTest extends Applet {
      int x, y, w, h;
      public void init ( ) {
         x = Integer.parseInt(getParameter(" xValue" ));
         y = Integer.parseInt(getParameter(" yValue" ));
         w = Integer.parseInt(getParameter(" wValue" ));
         h = Integer.parseInt(getParameter(" hValue" ));
      }
      public void paint ( Graphics g ) {
         g.drawRect (x, y, w, h );
        }
    }

