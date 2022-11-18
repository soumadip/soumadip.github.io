// Creating and running  threads using sub classing Thread //
      class TestThread extends Thread {
            private String whoAmI ;
            private int delay ;
            TestThread (String s, int  d ) {
                  whoAmI = s;
                  delay = d ;
            }
          public void run( ) {
        try{    sleep (delay);
	}catch(InterruptedException e){}
            System.out.println (" Process is interrupted " );
            System.out.println ( " Hello World ! " +
                  whoAmI + " Slept : " + delay);
          }
      }
      public class MultiThreadTest        {
           public static void main (String[ ] args ) {
            TestThread t1, t2, t3;
            t1 = new TestThread ("Thread1", (int) (Math.random( ) * 2000 ) );
            t2 = new TestThread ("Thread2", (int) (Math.random( ) * 2500 ) );
            t3 = new TestThread ("Thread3", (int) (Math.random( ) * 3000 ) );
            t2.start( );
            t1.start( );
            t3.start( );
                 }
      } // end of class MultThreadTest.

