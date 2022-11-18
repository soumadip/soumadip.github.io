// Use of suspend() and resume() methods
class Thread1 extends Thread {
    public void run( ) {
try{
      System.out.println (" First thread starts running" );
      sleep(10000);
      System.out.println (" First thread finishes running" );
}catch(java.lang.InterruptedException e){}
    }
}
class Thread2 extends Thread {
    public void run( ) {
      System.out.println ( "Second thread starts running");
      System.out.println ( "Second thread is suspended itself ");
      suspend( );
      System.out.println (" Second thread runs again" );
    }
}
class AnotherThreadControl {
    public static void main (String args[ ] ) {
      Thread1 first = new Thread1( );             // It is a newborn thread i.e.in Newborn state
      Thread2 second= new Thread2( );            // another new born thread
      first.start( );               // first is scheduled   for running
      second.start( );              // second is scheduled  for running
      System.out.println("Revive the second thread" ); // If it is suspended
      second.resume( );
      System.out.println ("Second thread went for 10 seconds sleep " );
      try{
	second.sleep (10000);
	}catch(java.lang.InterruptedException e){}
      System.out.println ("Wake up second thread and finishes running" );
      System.out.println ( " Demonstration is finished ");
    }
}

