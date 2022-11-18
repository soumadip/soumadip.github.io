// Communication using UDP outside   //
import java.net.*;
class DialogUDP {
       public static int hostPort = 999;               // Port No. of the distant machineis assumed
       public static void main (String args [ ] )throws Exception{
              DatagramSocket      ds;
              DatagramPacket      pkt;
              InetAddress hostAddress;
              byte buffer [ ] = new byte [ 1024];
              ds = new DatagramSocket ( );             // Establish a socket in       your       machine
              hostAddress = InetAddress.getByName ("www.iitkgp.ernet.in" );
                                         // If you are ready to send a message for me.
       //   Phase I : To transmit a message
              // Code for loading some message into buffer array    //
              pkt = new DatagramPacket (buffer, buffer.length, hostAddress, hostPort);
                                         // Data gram packet for sending message
              ds.send ( pkt) ;                  // message is transmitted for the hostmachine.
       // Phase II : To receive some message from host.
              pkt = new DatagramPacket (buffer, buffer.length );
              ds. receive (pkt);                // data gram as a receiving packet
              String message = new String (pkt.getData ( ),0);
              System.out.println (" Message : " + message );
              ds.close ( );
       }
}

