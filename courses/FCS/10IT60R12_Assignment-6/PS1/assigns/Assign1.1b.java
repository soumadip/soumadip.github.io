import java.lang.*;
//sum of squares//
class Squares{
int square(int n)
{
	return n*n;
}
public static void main(String args[])
{
	Squares sq=new Squares();
	int n=10,answer=0;
	for(int i=0;i<n;i++)
	{
		answer=answer+sq.square(i+1);
	}
	System.out.println("sum of square(10)= "+answer);
}
}
