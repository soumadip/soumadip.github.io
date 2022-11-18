// Minimal TCP/IP   client  //
import java.net.*;
import java.io.*;
class SimpleClient {
       public static void main (String args [ ] ) throws IOException {
              int c;
              Socket socket;
              InputStream iStream;
              DataInputStream dataIn;
              try{socket = new Socket ("New Server", 9876 );
                                // Create socket to connect the server “New Server” at port 9876
              iStream = socket.getInputStream ( );
              dataIn = new DataInputStream ( iStream);          // Get an input stream in       binary
              String mag = new String (dataIn.readUTF( ) );   //       Read the string in       Distream
              System.out.println(mag);
		
              // When done just close the connection and exit
              dataIn.close ( );
              iStream.close ( );
              socket.close ( );                // Close the connection
}catch(Exception e){e.printStackTrace();}
       }
}      // SimpleClient program

