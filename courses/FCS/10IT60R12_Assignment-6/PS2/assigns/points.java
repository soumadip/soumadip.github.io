
    class Point
    {
      int x,y;
      void getPoint ( int a, int b ) {
            x = a;
            y = b;
      }
    }

    class points
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
          System.out.println (" X1 = " + p1.x + "Y1 = " + p1.y );
          System.out.println ("X2=" + p2.x + "Y2 = " +p2.y );
          int dx = p3.x - p4. x;                         // X2 - X1
          int dy = p3.y - p4. y;                     // y2 - y1
          distance = Math.sqrt (dx * dx + dy * dy );     // (X2-X1)2 + (Y2-Y1)2
          System.out.println ( " Distance = "+ distance );
      }
     }
