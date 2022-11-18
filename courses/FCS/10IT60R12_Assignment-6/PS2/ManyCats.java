// Code sharing through super concept //
  class Cat {
      void speak ( )     {
      System.out.println("Meaon ! ");
  }
}
  class PetCat extends Cat {        // PetCat is one type of Cat
      void speak ( ) {
            System.out.println ( " Meow ! " );
      }
  }
  class MagicCat extends Cat {            // MagicCat is another kind of Cat
      static boolean noOne ;
      void speak ( ) {
            if (noOne )
                   super.speak ( );       // use the super class definition
            else System.out.println ( " Hello World !");
      }
   }
  class ManyCats {
      public static void main ( String args[ ]){
            PetCat c1 = new PetCat ( );
            MagicCat c2 = new MagicCat( );
            c2.noOne = true;
            c2.speak ( );
            c1.speak ( );
            c2.noOne = false ;
            c2.speak ( );
      }
   }

