import java.io.*;
class assign_21a
{
    public static void main(String[] args)
    {
        try
        {
            int i,rec;
            rec=2;
            float avg=(float)0.0;
            String tempString;
            Float vivid[] = new Float[10];
             DataInputStream in = new DataInputStream(System.in);
            System.out.print("Enter the values:");
            for(i=0;i<rec;i++)
            {
                 System.out.flush();
                 tempString = in.readLine();
                 vivid[i] = Float.valueOf(tempString);
                 
            }  
           for(i=0;i<rec;i++)
            {
                 System.out.println("value : "+vivid[i]);
                 
            }
            for(i=0;i<rec;i++)
            {
                avg=avg+vivid[i];
            }
            avg=avg/(float)rec;
            System.out.println("Average : "+avg);
         }
         catch(Exception e)
         {}     
    }
}
