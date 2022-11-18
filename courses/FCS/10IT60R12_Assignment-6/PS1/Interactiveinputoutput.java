//Interactiveinputoutput Writing to a file and then reading from a file
import java.util.*;
import java.io.*;
class Interactiveinputoutput {
      public static void main(String args[]) {
            float principleAmount= 0 ;
            float rateOfInterest = 0;
            int numberOfYears = 0;
            String tempString;
            String arrayString[] = new String[3];
            try {
                  for(int i =0; i<2; i++) {
                  DataInputStream din = new DataInputStream(System.in);
                  DataOutputStream dos = new DataOutputStream(new
FileOutputStream("bank.txt"));
                  System.out.print("Enter Principal Amount: ");
                  System.out.flush();
                  tempString = din.readLine();
                  principleAmount = Float.valueOf(tempString).floatValue();
                  System.out.print("Enter Rate of interest: ");
                  System.out.flush();
                  tempString = din.readLine();
                  rateOfInterest = Float.valueOf(tempString).floatValue();
                  System.out.print("Enter no of years: ");
                  System.out.flush();
                  tempString = din.readLine();
                  numberOfYears = Integer.parseInt(tempString);
                  System.out.print("Enter string: ");
                  System.out.flush();
                  tempString = din.readLine();
                  System.out.print("Enter the array of string: ");
                  for(int j =0; j<3; j++) {
                  System.out.flush();
                  arrayString[j] = new String(din.readLine()); }
                  dos.writeFloat(principleAmount);
                  dos.writeFloat(rateOfInterest);
                  dos.writeInt(numberOfYears);
                  dos.writeChars(tempString);
                  for(int k= 0; k<3; k++)
                  {
                        dos.writeChars(arrayString[k]);
                        System.out.println(arrayString[k]);
                  }
                  dos.close();
                  DataInputStream dis = new DataInputStream(new
FileInputStream("bank.txt"));
                  float principleAmount1 = dis.readFloat() ;
                  float rateOfInterest1 = dis.readFloat() ;
                  int numberOfYears1 = dis.readInt();
                  try
                  {
                  String tempString1= dis.readLine();
                  System.out.println(tempString1);
                  }
                  catch(Exception e)
                  {
                  System.out.println("aa");
                  }
                        //String arrayString1= dis.readUTF();
                  //float interestTotal = (principleAmount1* rateOfInterest1*
//numberOfYears1)/100 ;
                  //Writting to console
                  System.out.println();
                  System.out.println("Principle Amount: " + principleAmount1);
                  System.out.println("Rate Of Interest: " + rateOfInterest1);
                  System.out.println("No Of Years: " + numberOfYears1);
          /*System.out.println("Comment: " + tempString1);
          //System.out.println(arrayString1);
          System.out.println();
          System.out.println("Total Interest = " + interestTotal);*/
    }
    } catch(Exception e) {
     System.out.println(e);
     }
  }
}

