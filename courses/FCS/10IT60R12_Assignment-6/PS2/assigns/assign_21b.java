import java.io.*;
class assign_21b
{
    public static void main(String[] args)
    {
        try
        {
            int i,j,k,rec;
            rec=2;
            float avg=(float)0.0;
            String tempString;
            Float A[][] = new Float[3][4];
            Float B[][] = new Float[4][2];
            Float C[][] = new Float[3][2];
             DataInputStream in = new DataInputStream(System.in);
            System.out.print("Enter the matrix A");
            for(i=0;i<3;i++)
            {
                for(j=0;j<4;j++)
                {
                     System.out.flush();
                     tempString = in.readLine();
                     A[i] = Float.valueOf(tempString);
                }
            } 
            System.out.print("Enter the matrix B");
            for(i=0;i<4;i++)
            {
                for(j=0;j<2;j++)
                {
                     System.out.flush();
                     tempString = in.readLine();
                     B[i] = Float.valueOf(tempString);
                 }
            }   
           for(i=0;i<3;i++)
           {
                for(j=0;j<2;j++)
                {
                    C[i][j]=0;
                    for(k=0;k<4;k++)
                    {
                        C[i][j]=c[i][j]+A[i][k]*B[k][j];
                    }   
                }
           }
           for(i=0;i<3;i++)
            {
                for(j=0;j<2;j++)
                {
                     System.out.print(" "+C[i][j]);
                 }
                                      System.out.print("\n");
            } 
         }
         catch(Exception e)
         {}     
    }
}
