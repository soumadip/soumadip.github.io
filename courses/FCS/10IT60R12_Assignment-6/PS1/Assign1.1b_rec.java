import java.lang.*;
//sum of squares//
class Squares{
int square(int n)
{
	if(n<=0)
	return 0;
	else
	return (n*n+square(n-1));
}
public static void main(String args[])
{
	Squares sq=new Squares();
	int n=10,answer;
	answer=sq.square(n);
	System.out.println("sum of square(10)= "+answer);
}
}
