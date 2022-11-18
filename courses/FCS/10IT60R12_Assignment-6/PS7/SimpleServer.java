import java.net.*;
import java.io.*;
class SimpleServer {
       public static void main (String args [ ] )      {
       ServerSocket server;
       Socket socket;
       String msg = "Hello Net world !";
       OutputStream oStream;
       DataOutputStream dataOut;
       try {                       // To create a ServerSocket object
              server = new ServerSocket (9876);
                     //     Run the Server to attend the clients for ever
       while (true) {
              
                     socket = server.accept ( );       // Wait here and listen for aconnection.
                     oStream = socket.getOutputStream( ); //Get a communication stream		for output
                     dataOut = new DataOutputStream(oStream);        // DataStream out inbinary
                     dataOut.writeUTF(msg);             // Send message to the client
                     dataOut.close ( );            // Close the Stream object when messageis transmitted
                     oStream.close ( );         // Close the output Stream or the currentsocket
                     socket.close ( );          // Close the current socket connection
              } 
                    // listen for other clients if any
} catch (IOException e )    {e.printStackTrace(); }
       }      // main ( )
}      // Simple Server

