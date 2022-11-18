import java.lang.*;
//factorial//
class Factorial{
public static void main(String args[])
{
	int n=10,answer=1;
	for(int i=0;i<n;i++)
	{
		answer=answer*(i+1);
	}
	System.out.println("factorial(10)= "+answer);
}
}
