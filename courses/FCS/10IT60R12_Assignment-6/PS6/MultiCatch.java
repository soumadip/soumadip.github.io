// Using multiple try-catch
class MultiCatch {
   public static void main (String args[ ]) {
     try {
      int i = args.length;
      String myString = new String[ i ];
      // If i = 0 then myString null pointer error
// #1 //
      if(myString[0].equals("Java"));
         System.out.println("First word is Java !");
       System.out.println( " Number of arguments = " + i );
// # 2 //
      int x = 18/ i;
      int y[ ] = {555, 999};
        // y is an array of size 2 and index are 0,1
// #3 //
      y[ i ] = x;
      // Index is out-of-range may occur if i > 1
      }
      catch (ArithmeticException e ) {          // To catch the error at #2
      System.out.println ( " Div by 0 : "+ e );
      }
      catch (NullPointerException e ) {         // To catch the error at #1
      System.out.println ( " A null pointer exception : " + e );
      }
      catch (ArrayIndexOutofBoundsException e ) { // To catch the error at #3
      System.out.println ("Array Index OoB : " + e);
      }
   }
}

