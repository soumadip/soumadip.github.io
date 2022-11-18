import java.lang.*;

class FactorialN{
int factorial(int n)
{
return n<=1?1:n*factorial(n-1);
}
public static void main(String args[])
{
	FactorialN f1=new FactorialN();
	System.out.println("factorial of "+args[0]+" = "+f1.factorial(Integer.parseInt(args[0])));
}
}
