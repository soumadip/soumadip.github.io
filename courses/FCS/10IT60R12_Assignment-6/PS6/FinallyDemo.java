// Use of finally in try-catch //
class FinallyDemo {
   public static void main (String [ ] args ) {
      int i = 0;
      String greetings [ ] = {
          "Hello Twinkle !",
            "Hello Java !",
          "Hello World ! "
        };
      while ( i < 4) {
        try {
          System.out.println (greetings [i] );
        } catch (Exception e ) {
            System.out.println (e.toString );      // message of exception e in String format
            System.out.println("Quiting the program execution ....");
          }
        finally {
            System.out.println (" Hi !");
               i++;
          }
      }
    }
}

