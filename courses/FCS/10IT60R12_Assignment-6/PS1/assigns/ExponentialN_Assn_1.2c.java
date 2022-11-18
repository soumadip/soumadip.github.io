import java.lang.*;
class ExponentialN{
int factorial(int n)
{
	if(n==1||n==0)
	return 1;
	else 
	return n*factorial(n-1);
}
public static void main(String arg[])
{
	float answer=0;
	ExponentialN ex=new ExponentialN();
	int n=Integer.parseInt(arg[0]);
	for(int i=0;i<50;i++)
	{
		float temp=(float)ex.factorial(i);
		if(temp==0)break;
		answer=answer+(n/temp);
	}
	System.out.println("e to the power "+arg[0]+" = "+answer);
}
}
