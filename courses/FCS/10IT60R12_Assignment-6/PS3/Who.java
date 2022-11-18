// Method resolution during execution //
   class A {
      void callMe ( ) {
          System.out. println ( " I am from A ") ;
      }
   }
   class B extends A {
      void callMe ( ) {
         System.out.println ( " I am from B ");
      }
   }
   class Who {
      public static void main (String args []){
         A a = new B ( ) ;
         a.callMe (   );
      }
   }

