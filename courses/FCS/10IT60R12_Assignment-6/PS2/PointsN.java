// An Practice of inheritance //
      class Point {
            int x;
            int y;
            Point ( ) {             // A  default constructor
               this (0,0);
            }
            Point (int x, int y ) {       // Overloaded constructor
               this.x = x;
               this.y = y;
            }
      }
      class Point3D extends Point {
            int z;                      // another ordinate for  a 3D Point //
            Point3D ( ) {
                this ( 0, 0, 0);
            }
            Point3D(int x, int y, int z ) {
                super (x, y );            // called the superclass constructor
                this.z = z;
            }
      void display ( )     {              // A method definition
            System.out.println (" X = "+ x + " Y = "+ y + " Z = " + z );
      }
}
      class Points {                // Main class
            public static void main ( String args[] ) {
                Point p1 = new Point(4, 6) ;                      // A 2-D point
                Point3D p2 = new Point3D(2,3,5);           // A 3-D point
                Point3D p3 = new Point3D( );              // Another 3-D point
    System.out.println ("P1 : X = " + p1.x + " Y =" + p2.y ) ;
    p2.display ( ) ;
    p3.display ( ) ;
  }
}

