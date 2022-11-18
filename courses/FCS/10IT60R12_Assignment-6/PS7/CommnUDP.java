// Communication using UDP //
import java.lang.*;
import java.io.*;
import java.net.*;          // Include the java.net package
class CommnUDP {
       public static int serverPort = 666;            // A port 666 is decided as severport
       public static int clientPort = 999;            // Another port 999 is decided asclient port .
       public static int size = 1024 ;          // For the buffer limit
       public static DatagramSocket ds;         // Socket instance for communication
       public static byte buffer [ ] = new byte [size] ;      // buffer is to store     acontent
       public static void theServer( ) {
              int i =0,c=0;
             try{ 

		while (true)     {                 // run till the end of session
                     c = System.in.read();             // read from keyboard
			
             		 switch ( c) {
     	             		   case -1 :
          	                  System.out.println (" Server quits : ");
    		                        return;
            			         case '\n' :         // Message entered for transmission
        	                    ds.send (new DatagramPacket(buffer,i, InetAddress.getLocalHost( ), clientPort ));
                 	           i = 0;
                      		      break;
                 		    default :
                    	        buffer [i++ ] = (byte)c;
                     }
              }
	}catch(IOException e){}
       }
       public static void theClient ( ) {
              while(true) {
                     DatagramPacket pkt = new DatagramPacket (buffer, buffer.length);
                   try{  ds.receive (pkt) ;}catch(IOException e){}
                     System.out.println(new String(pkt.getData ( ),0,pkt.getLength( )));
              }
       }
       public static void main (String args [ ] )      {
	try{
		    if (args.length == 1) {
                     ds = new DatagramSocket (serverPort );
                     theServer ( );                    // sending message from server
              } 
	else {
                     ds = new DatagramSocket (clientPort );
      			theClient ( ); // Receiving message in client
		}	
	}catch(SocketException e){e.printStackTrace();}
    }
  }


