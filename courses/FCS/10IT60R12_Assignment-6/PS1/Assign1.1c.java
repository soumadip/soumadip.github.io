import java.lang.*;
class Exponent{
int factorial(int n)
{
	if(n==1||n==0)
	return 1;
	else 
	return n*factorial(n-1);
}
public static void main(String args[])
{
	float answer=0;
	Exponent ex=new Exponent();
	for(int i=0;i<50;i++)
	{
		float temp=(float)ex.factorial(i);
		if(temp==0)break;
		answer=answer+(1/temp);
	}
	System.out.println("e to the power 1 = "+answer);
}
}
