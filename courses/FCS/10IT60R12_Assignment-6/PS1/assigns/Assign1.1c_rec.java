import java.lang.*;
class Exponent{
int factorial(int n)
{
	if(n==1||n==0)
	return 1;
	else 
	return n*factorial(n-1);
}
float calcExp(int n)
{
	float temp=(float)factorial(n);
	if(temp==0)
	return 0;
	else
	return (1/temp)+calcExp(n+1);
}
public static void main(String args[])
{
	Exponent ex=new Exponent();
	float answer=0;
	answer=ex.calcExp(0);
	System.out.println("e to the power 1 (upto 100 terms)= "+answer);
}
}
