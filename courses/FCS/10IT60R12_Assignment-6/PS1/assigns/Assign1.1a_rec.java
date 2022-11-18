import java.lang.*;
//factorial//
class Factorial{
int factorial(int n)
{
	if(n==1||n==0)
	return 1;
	else 
	return n*factorial(n-1);
}
public static void main(String args[])
{
	int n=10;
	Factorial f1=new Factorial();
	int answer=f1.factorial(n);
	System.out.println("factorial(10)= "+answer);
}
}
