import java.lang.*;

class SquareN{
int square(int n)
{
return n*n;
}
int sum(int n)
{
return n<=0?0:(square(n)+sum(n-1));
}
public static void main(String args[])
{
	SquareN f1=new SquareN();
	System.out.println("sum of square upto "+args[0]+" = "+f1.sum(Integer.parseInt(args[0])));
}
}
