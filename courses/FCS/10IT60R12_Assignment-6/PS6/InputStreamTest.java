//   Input Stream : Displaying a file   //
import java.io.*;
import java.util.*;
class InputStreamTest   {
   public static void main (String args [ ] ) {
      int size;
      // To open a file input stream.
      FileInputStream fin;
       fin = new FileInputStream (" C: \WINDOWS\SYSTEM\SYSTEM.INI");
       size = fin.available( );                       // returns the number of bytes available
      System.out.println("Total bytes ::" + size);
      System.out.println ( " First 1⁄4 is displayed : Using read( )");
      for (int i = 0; i < size /4 ; i++ )       {
               System.out.println ((char) fin.read( ) );
        }
        System.out.println (" Remaining bytes :" + fin.available( ) );
        System.out.println ("Next 1⁄4 is displayed : Using read( b[ ] )");
        byte b[] = new byte[size/4];
        if (fin.read (b) != b.length )
          System.err.println ("File reading error : ");
        else {
            String temp = new String (b, 0, 0, b.length );
            System.out.println (temp) ;               // display text string
            System.out.println ( " Still available : " + fin.available( ) );
            System.out.println ( " skipping 1⁄4 : Using skip ( )" );
            fin.skip(size/4);
            System.out.println ("File remaining for read:" + fin.available( ) )
        }
    fin.close ( ); // Close the input stream
  }
}

