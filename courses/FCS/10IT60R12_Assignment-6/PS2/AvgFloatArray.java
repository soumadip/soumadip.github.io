import java.io.*;

class AvgFloatArray
{
	public static void main(String args[]) throws IOException 
	{
		DataInputStream in = new DataInputStream(System.in);
		float vivid[]=new float[10];
	    int i;
	    float sum,avg;
	    sum=0;
	    for(i=0;i<10;i++)
	    {
			System.out.println("Enter a float number (say 123.45) in array vivid[" +i+"]: ");
	     	vivid[i] = Float.valueOf(in.readLine()).floatValue();     	
	     	sum=sum+vivid[i];
	    }
	    
	    avg=sum/i;
	    System.out.println("Avg Of Floating Array Element : " +avg);
	    
	} 	
}

