// Two processes thread using Runnable interface //
      class Brother implements Runnable {
            int age = 0;
            String name;
            Brother(int age, String name ) {
                  this.age = age ;
                  this.name = name;
            }
          public void run( ) {
          try{  
		Thread.sleep(age * 1000);
		}catch(InterruptedException e){}
            System.out.println ( "Brother " +name + "age :" +age + "seconds" );
          }
      }
class Sister implements Runnable {
      int spring;
      String sweety;
      Sister (int a, String b ) {
            spring = a;
            sweety = b;
      }
    public void run ( ) {
      System.out.println ("Hi Sweety" + sweety + "!");
           try{ Thread.sleep ( spring * 1000);}catch(InterruptedException e){}
            System.out.println("Spring " + spring + "elapsed !");
    }
}
class RunnableThreads {
    public static void main(String[ ] args) {
      Brother ravi = new Brother (16, "Ravi");
      Thread t1 = new Thread (ravi);
      t1.start ( ) ;
      Sister bobby = new Sister(10, "Bobby" );
      Thread t2= new Thread (bobby);
      t2.start ( );
    }
}

