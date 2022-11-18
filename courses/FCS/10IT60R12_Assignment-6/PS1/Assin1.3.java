import java.io.*;
import java.lang.*;
class StudentInfo
{
  public static void main(String args[ ] ) {
     String name = new String();
     String roll = new String();
     int totalMarks = 0;
try{
   DataInputStream in = new DataInputStream(System.in);
   System.out.print("Enter NAME: ");
   System.out.flush();
   name = in.readLine();
   System.out.print("Enter ROLL: ");
   System.out.flush();
   roll = in.readLine();
   System.out.print("Enter TOTALMARKS: ");
   System.out.flush();
   totalMarks = Integer.parseInt(in.readLine());
}catch(Exception e)
{}
   // Input is over: calculate the interest
   System.out.println("INFORMATION"+"\n"+"NAME: "+name+"\n"+"ROLL: "+roll+"\n"+"TOTALMARKS: "+totalMarks);
  }
}
