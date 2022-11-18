import java.util.Random;


class Customer {

      private int balance;
      private int custNo;

	Customer(int custNo,int balance)
	{
		this.custNo=custNo;
		this.balance=balance;
		System.out.println("Account Created:: Customer#  "+this.custNo+"   AND Balance:: "+this.balance);
	}

	void displayBalance() 
	{
		System.out.println("Customer#  " + custNo + "    Balance: " +balance+"\n");
	}

	void deposit(int amount) 
	{
		balance = balance + amount;
		System.out.println( amount + " is deposited");
		displayBalance();
	}
	
	void withdraw(int amount) 
	{
		if(balance<amount)
			System.out.println("your account balance is less ("+amount+")");
		else
		{
			balance = balance - amount;
			System.out.println( amount + " is withdrawn");
		}
			displayBalance();
	}

}


class TransactionDeposit extends Transaction implements Runnable 
{

	int randCust;
	Random randomGenerator = new Random();

	TransactionDeposit(int noOfCustomers) 
	{
		this.randCust=noOfCustomers;
		new Thread(this).start();
	}

	public void run() 
	{
		while(true)
		{
			int customerNo=randomGenerator.nextInt(randCust);
			int amountToDeposit=randomGenerator.nextInt(100);
			c[customerNo].deposit(amountToDeposit);
			try
				{
					Thread.sleep(500);
				}
				catch(InterruptedException e){}
		}
	}

}


class TransactionWithdraw extends Transaction implements Runnable 
{

	int randCust;
	Random randomGenerator = new Random();

	TransactionWithdraw(int noOfCustomers) 
	{
	this.randCust = noOfCustomers;
	new Thread(this).start();
	}
	
	public void run() 
	{
		while(true)
		{
			int customerNo=randomGenerator.nextInt(randCust);
			int amountToWithdraw=randomGenerator.nextInt(100);
			c[customerNo].withdraw(amountToWithdraw);
			try
				{
					Thread.sleep(300);
				}
				catch(InterruptedException e){}	
		}
	}

}


class Transaction 
{

	static int SIZE=10;
	public static Customer[] c=new Customer[SIZE];

	public static void main(String args[]) 
	{
		Random randomGenerator = new Random();
		for(int i=0;i<SIZE;i++)
		{
			c[i]=new Customer((i+1),randomGenerator.nextInt(1000));
		}
		TransactionDeposit t1;
		TransactionWithdraw t2;
		t1 = new TransactionDeposit(SIZE);
		t2 = new TransactionWithdraw(SIZE);

	}
}

