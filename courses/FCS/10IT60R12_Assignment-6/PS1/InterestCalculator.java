  /*
   * This is a Java Application to read principalAmount,
   * rateOfInterest and numberOfYears from the standard input
   * and then calculates the simpleInterest
  */
import java.io.*;
import java.lang.*;
class InterestCalculator
{
  public static void main(String args[ ] ) {
     Float principalAmount = new Float(0);
     Float rateOfInterest = new Float(0);
     int numberOfYears = 0;
try{
   DataInputStream in = new DataInputStream(System.in);
   String tempString;
   System.out.print("Enter Principal Amount: ");
   System.out.flush();
   tempString = in.readLine();
   principalAmount = Float.valueOf(tempString);
   System.out.print("Enter Rate of Interest: ");
   System.out.flush();
   tempString = in.readLine();
   rateOfInterest = Float.valueOf(tempString);
   System.out.print("Enter Number of Years: ");
   System.out.flush();
   tempString = in.readLine();
   numberOfYears = Integer.parseInt(tempString);
}catch(Exception e)
{}
   // Input is over: calculate the interest
   float interestTotal = principalAmount.floatValue()*rateOfInterest.floatValue()*numberOfYears;
   System.out.println("Total Interest = " + interestTotal);
  }
}

