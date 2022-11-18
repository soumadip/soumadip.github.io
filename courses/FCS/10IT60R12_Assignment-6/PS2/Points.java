// Encapsulation  :- Defining a class//
    class Point
    {
      int x,y;
      void getPoint ( int a, int b ) {
            x = a;
            y = b;
      }
    }
// definition of another class. This is a main class
    class Points
    {
      static double distance;
      public static void main (String args[ ]) {
          Point p1 = new Point( );
          Point p2 = p1;
          Point p3 = new Point ( );
          Point p4 = new Point ( );
          p1.getPoint (5, 10 );
          p2.getPoint (15, 20);
          p3.getPoint (20, 30);
          p4.getPoint (30, 40);
          System.out.println ("X1 = " + p1.x + "\tY1 = " + p1.y );
          System.out.println ("X2=" + p2.x + "\tY2 = " +p2.y );
          double dx = p3.x - p4. x;                         // X2 - X1
          double dy = p3.y - p4. y;                     // y2 - y1
          distance = Math.sqrt (dx * dx + dy * dy );     // (X2-X1)2 + (Y2-Y1)2
          System.out.println ( " Distance = "+ distance );
      }
     }

