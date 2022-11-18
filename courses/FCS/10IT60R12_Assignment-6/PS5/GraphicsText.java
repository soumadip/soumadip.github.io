// Graphics Test   //
import java.awt.*;
import java.applet.*;
public class GraphicsText extends Applet {
    public void init ( ) {
      public void paint (Graphics g) {
      Dimension d = size ( ) ;                   // returns the width and height of the applet
      g.setColor (Color.black );                 // set the drawing color as black
      g.drawRect (0, 0, d.width-1, d.height -1);
      g.setColor (Color.blue);
      g drawRect (10, 10, d.width-10, d.height-10 );             // draw another inner blue Rectangle
      g.setColor (Color.red );
      g.drawOval (15,15, 50,50 );
      g.setColor( Color.yellow );
      g.fillOval ( 20, 20,40, 40 );
      g.setColor (Color.red );
      g.drawArc (230, 10, 50, 50, -90, 270 );
      g.fillArc (190, 10, 50, 50, -90, 270 );
      g.setColor (Color.pink );
      g.drawRoundRect (130, 70, 50, 50, 10, 10 );
      g.fillRoundRect (190, 70, 50, 50, 10, 10 );
      int [ ] xPoints =       { 10,70,120,120,70,10,10 };
      int [ ] yPoints =       { 130, 150, 130, 180, 170, 180, 130 };
      Color myColor = new Color (255,100,150);                // set a RGB color
      // A color can be choosed, R, G, B integers ranges between 0 to 255
      g.setColor (myColor );
      g.drawPolygon (xPoints , yPoints, 7);                   // To draw a polygon with 7 points
      g.setColor (Color.gray );
      g.draw3DRect (10, 190, 50, 50, true );
      g fill3DRect (70, 199, 50, 50, true);
      g.setColor (Color.green );
      g.draw3DRect (130, 190, 50, 50, false );
      g.fill3DRect (190, 190, 50, 50, false );
    }
   }
}

