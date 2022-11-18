/******************* Client-side code **********************/
import java.io.*;
import java.net.*;
/**
 * An application that opens a connection to a Web server and adds two numbers from the
server connection.
*/
public class SimpleWebClientN {
       static DataOutputStream outbound;
       static DataInputStream inbound;
       static InputStreamReader reader;
       static BufferedReader br;
    public static void main(String args[])
    {
        try
        {
            // Open a client socket connection
            Socket clientSocket1 = new Socket("localhost", 2000);
            System.out.println("Client1: " + clientSocket1);
                     String choice="y";
                     reader = new InputStreamReader(System.in);
                     br = new java.io.BufferedReader(reader);
           outbound = new DataOutputStream(
                 clientSocket1.getOutputStream() );
            inbound = new DataInputStream(
                 clientSocket1.getInputStream() );
                     while(choice.equals("y"))
                     {
                            int num1, num2, result;
                            System.out.println("Enter first Number");
                            num1 = Integer.parseInt(br.readLine());
                            System.out.println("Enter second Number");
                            num2 = Integer.parseInt(br.readLine());
                            outbound.writeInt(num1);
                            outbound.writeInt(num2);
                    result = inbound.readInt();
                            System.out.println("Sum = " + result);
                            System.out.print("Want to add more (y/n) : ");
                            choice=br.readLine();
                     }
                            // Clean up
                            outbound.close();
                            inbound.close();
                            clientSocket1.close();
        }
        catch (UnknownHostException uhe)
        {
            System.out.println("UnknownHostException: " + uhe);
        }
        catch (IOException ioe)
        {
            System.err.println("IOException: " + ioe);
        }
  }
}

