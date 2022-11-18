// Application with more than one classes   //
//   Edit PeopleApplin.java
      class FirstClass {
          //int intidNo=0;
          static int idNo = 555;
          public static void print( ) {
             System.out.println ( " First Class citizen" + idNo );
          }
      }
class SecondClass {
   // int idNo;
    static int idNo = 111;
    public static void print( ) {
        System.out.println ( " Second Class citizen " + idNo) ;
    }
}
public class PeopleAppln {
   static FirstClass female;
   static SecondClass male;
   public static void main( String args[ ] ) {
      System.out.print("People from Java World");
      female.print( );
      male.print( );
   }
 }

