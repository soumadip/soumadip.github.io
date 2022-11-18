// Using the class RandomAccessFile
import java.io.*;
class RandomAccessTest
{
    public static void main(String args[])
    {
        RandomAccessFile file;
        try {
          file = new RandomAccessFile("aFile.txt", "rw");
            file.writeChar('A');
        file.writeInt(123);
        file.writeDouble(1.2345);
        file.seek(0);
          System.out.println(file.readChar());
          System.out.println(file.readInt());
        System.out.println(file.readDouble());
        file.seek(2);
        System.out.println(file.readInt());
        file.seek(file.length());
        file.writeBoolean(false);
        file.seek(file.length());
        System.out.println(file.readBoolean());
    } catch (IOException e) {System.out.println(e);}
      finally {
        file.close();
      }
  }
}

