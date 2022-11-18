import java.io.*;

class MatrixMultiply
{
	public static void main(String[] args) throws IOException
	{
		DataInputStream in = new DataInputStream(System.in);
    	int A[][] = new int[3][4];
    	int B[][] = new int[4][2];    	
    	int C[][] = new int[3][2];
    	int i,j,k;
    	    		 	    
	    //Input For Matrix A
    	System.out.println("Input For Integer Matrix A : ");
      	for(i=0;i<3;i++) 
      	{
      		for(j=0;j<4;j++) 
      		{
				System.out.println("A["+i+"]["+j+"] : ");
     		    A[i][j] = Integer.parseInt(in.readLine());
      		}		    
	    }
	    
	    //Input For Matrix B	    
	    System.out.println("Input For Integer Matrix B : ");
      	for(i=0;i<4;i++) 
      	{
      		for(j=0;j<2;j++) 
      		{
				System.out.println("B["+i+"]["+j+"] : ");
     		    B[i][j] = Integer.parseInt(in.readLine());
      		}		    
	    }
	    
	    //Code For Matrix Multiplication
	    for(i=0;i<3;i++) 
	    {
		    for(j=0;j<2;j++)
		    {
		        for(k = 0;k<4;k++)
		        {          
			        C[i][j]+=A[i][k]*B[k][j];
        		}
		    }  
     	}
     	
		//Display Matrix A
    	System.out.println("Matrix A : ");
    	System.out.println();
      	for(i=0;i<3;i++) 
      	{
      		for(j=0;j<4;j++) 
      		{
				 System.out.print(" "+A[i][j]);
      		}
      		System.out.println();		    
	    }
	    
	    //Display Matrix B	    
	    System.out.println("Matrix B : ");
	    System.out.println();
      	for(i=0;i<4;i++) 
      	{
      		for(j=0;j<2;j++) 
      		{
				System.out.print(" "+B[i][j]);
      		}
      		System.out.println();		    
	    }
	    
	    //Display Matrix C	    
	    System.out.println("Matrix C= Matrix A * Matrix B : ");
	    System.out.println();
      	for(i=0;i<3;i++) 
      	{
      		for(j=0;j<2;j++) 
      		{
				System.out.print(" "+C[i][j]);
      		}
      		System.out.println();		    
	    }        
	}
}
