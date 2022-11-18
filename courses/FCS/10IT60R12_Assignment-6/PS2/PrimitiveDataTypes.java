  /*This application read values from the keyboard,
   * Store them into memory, and
   * Display the values stored in.                  */
import java.io.DataInputStream;
class PrimitiveDataTypes
{
  public static void main(String args[ ] ) {
     DataInputStream in = new DataInputStream(System.in);
     boolean flag=false;
     char c='\0';
     byte b=0;
     short shortInt=0;
     int i=0;
     long longInt=0;
     float x=0;
     double y=0;
try{
     System.out.println("Enter a small integer (say 123): ");
     shortInt = Short.parseShort(in.readLine());
     System.out.println("Enter an Integer (say 12345): ");
     i = Integer.parseInt(in.readLine());
     System.out.println("Enter a Long Integer (say 12345689L): ");
     longInt = Long.parseLong(in.readLine());
     System.out.println("Enter a float number (say 123.45): ");
     x = Float.valueOf(in.readLine()).floatValue();
     System.out.println("Enter a double number (say 9.87e-007): ");
     y = Double.valueOf(in.readLine()).doubleValue();
}catch(Exception e){}
     System.out.println("shortInt = " + shortInt);
     System.out.println("i = " + i);
     System.out.println("longInt = " + longInt);
     System.out.println("x = " + x);
     System.out.println("y = " + y);
  }
}

