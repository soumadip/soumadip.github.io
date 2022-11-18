// Static binding of a variable or method //
    class StaticClass {
      static int count;
      StaticClass ( ) {
      count ++ ;
  }
  public static void printCount ( ) {             // It is a static method
      System.out.println ( " Count = "  + count );
  }
}
class StaticTest {
 static{ System.out. println ( " Initialization of  Static member " );}
  static int count = 0;
  public static void main ( String args [  ] ) {
      StaticClass x, y;
  //x.printCount ( ) ;
  //y.printCount ( ) ;
  StaticClass.printCount (  );  // A Static method can  be called this way
  x = new StaticClass ( );
  x.printCount ( ) ;
  y = new StaticClass ( ) ;
  y.printCount ( ) ;
        }
  }

