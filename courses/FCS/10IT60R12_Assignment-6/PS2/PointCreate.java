// Automatic initialization - concept of constructor
      class Point {
            int x, y;
            Point ( int x, int y ) {
               this.x = x ;
               this.y = y;
            }
           void printPoint() {
                System.out.println("X = "+ this.x + " Y= " + this.y);
      }
}
      class PointCreate {
            public static void main ( String args [  ] ) {
                  Point p = new Point (10, 20 );
                  p.printPoint();
            }
      }

