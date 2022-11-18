import java.lang.*;
import java.io.*;
// Practice of Interface sharing member elements //
interface Gender {
      int FEMALE = 0;
      int MALE = 1;
int ask();
}
class Enquire implements Gender {
      
	public int ask(){
            System.out.println ( "Type your gender : :   Female = 0 or Male = 1") ;
	int type =0;
	try{
		type = System.in.read()-48;
		System.out.flush();
	}catch(IOException e){}
	return type;
      }

}
abstract class Response implements Gender {
      static void reply (int type ) {
//System.out.println(type);
            switch (type ) {
                   case MALE :
                         System.out .println (" Hello Sir !");
                         break;
                   case FEMALE :
                         System.out.println ( " Hi Mam !! " );
                         break;
                   default : System.out. println ( " Oh God ! " ) ;
            }
      }
      public static void main ( String args []){

            Enquire e = new Enquire();
            Gender person = e;
            reply (person.ask());               // Ask to first kind
            reply (person.ask());              // Ask to second kind
            reply (person.ask());            // Ask to third kind

      }
}
interface Constants {
    double velOfLight = 3.0e+10;	
    String unitVelOfLight = "m/s";
  //  .... .... .... ....
}
interface Physics {
    void quantumLaw();
   // ... ... ... ...
}
interface lawOfPysics extends Constants, Physics
{
   // ..... ..... ...... .....
   // ..... ..... ...... .....
}

