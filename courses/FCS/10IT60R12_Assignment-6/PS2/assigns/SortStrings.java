import java.io.*;
import java.util.Arrays;


class SortStrings
{
	public static void main(String args[]) throws IOException 
	{
		DataInputStream in = new DataInputStream(System.in);
		String Name[]= new String[10];
		int i,j;
		String tmp=new String();
		
		for(i=0;i<10;i++)
	    {
			System.out.println("Enter Name "+(i+1)+":");
	     	Name[i] = in.readLine();     		     	
	    }
	    	    
	    for(i=0;i<10;i++)
	    {
	    	for(j=i+1;j<10;j++)
	    	{
	    		if(Name[i].compareTo(Name[j]) > 0)
	    		{
	    			tmp = Name[i];
			        Name[i] = Name[j];
			        Name[j] = tmp;
	    		}
	    	}
	    }
	    
	    for(i=0;i<10;i++)
			System.out.println("Enter Name "+(i+1)+":"+Name[i]);
	}
}
