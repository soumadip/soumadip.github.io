import java.io.*;
class InterestCalculator {
      public static void main(String args[]) {
            Float principleAmount = new Float(0);
            Float rateOfInterest = new Float(0);
            int numberOfYears = 0;
            String tempString= " ";
            try {
                  DataInputStream in = new DataInputStream(System.in);
                  System.out.print("Enter Principal Amount: ");
                  System.out.flush();
                  tempString = in.readLine();
                  principleAmount = Float.valueOf(tempString);
                  System.out.print("Enter Rate of interest: ");
                  System.out.flush();
                  tempString = in.readLine();
                  rateOfInterest = Float.valueOf(tempString);
                  System.out.print("Enter no of years: ");
                  System.out.flush();
                  tempString = in.readLine();
                  numberOfYears = Integer.parseInt(tempString);
                  System.out.print("Enter a string: ");
                  System.out.flush();
                  tempString = in.readLine();
            } catch(Exception e) { }
            float interestTotal = (principleAmount.floatValue() *
rateOfInterest.floatValue() * numberOfYears)/100 ;
            System.out.println("Total Interest = " + interestTotal);
            System.out.println(tempString);
      }
}

