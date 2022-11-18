// Overloading constructor: Initializing object in several ways.
class Point {
            int x, y;
            Point(int a, int b) {         // Constructor for integer coordinates
                x = a;
                y = b;
            }
      Point(float x, float y) {     // Constructor for real coordinates
          this.x = (int)x;
          this.y = (int)y;
      }
     void printPoint() {
          System.out.println("X = "+ this.x + " Y= " + this.y);
}
}
class PointCreate {
      public static void main ( String args [  ] ) {
            Point p1 = new Point (10, 20 );
            p1.printPoint();
            Point p2 = new Point (5.5f, 4.2f );
            p2.printPoint();
      }
}

