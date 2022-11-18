// Sever Side Program (Simple Web Sever)//
import java.io.*;
import java.net.*;
import java.lang.*;
class SimpleWebServer
{
       public static void main(String args[])
       {
              ServerSocket serverSocket = null;
              Socket clientSocket = null;
              ServiceClient sock;
              int connects = 0;
              try
              {
                     // Create the server socket
                     serverSocket = new ServerSocket(2000, 5);
                     System.out.println("server started");
                     while (connects < 5)
                     {
                            clientSocket = serverSocket.accept();
                            sock = new ServiceClient(clientSocket);
                            sock.start();
                            connects++;
                     }
                     System.out.println("Closing server");
                     serverSocket.close();
              }
              catch (IOException ioe)
              {
                     System.out.println("Error in SimpleWebServer: " + ioe);
              }
       }
}
class ServiceClient extends Thread
{
              Socket client;
               DataInputStream inbound ;
         DataOutputStream outbound ;
         ServiceClient(Socket clnt)
         {
                client=clnt;
         }
    public void run()
    {           inbound = null;
                      outbound = null;
         try
         {
                // Acquire the streams for IO
                inbound = new DataInputStream( client.getInputStream());
                outbound = new DataOutputStream( client.getOutputStream());
                int num1, num2,result;
                while(true)
                {
                        //Accept two numbers
                num1 = inbound.readInt();
                num2 = inbound.readInt();
                result=num1+num2;
                //Send the result to client
                outbound.writeInt(result);
                }
  }
  catch(Exception e)
                {
                // Clean up
                System.out.println("Cleaning up connection: " + client);
                        try
                        {
                outbound.close();
                inbound.close();
                client.close();
                        }
                        catch(Exception r)
                        {
                        }
                }
             }
}

