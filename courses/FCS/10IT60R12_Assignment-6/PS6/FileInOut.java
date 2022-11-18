// Read from keyboard and copy them into a file //
class FileInOut   {
   public static void main (String args [])     {
      byte buffer = new byte [512] ;                      // A temp buffer to store text
      int i = 0, size = 0;
      String inFile = null;
      String outFile = null;
      //FileInputStream = fin;
      FileOutputStream= fout1, fout2;
      try {
         outFile = args[0];
         int c = 0;
         while (( c = System.in.read ( ) )!=-1 ) {               // Read from keyboard till ctrl+Z
            buffer[i] = (byte) c;
            i++;
         }
         size= i;                               // Number of bytes read
           fout = new FileOutputStream (args[o]);
         fout1.read (buffer);                   // Write whole buffer into the file
         fout1.close ( );
      } catch (ArrayindexOutofBoundException e) {
    }
}

