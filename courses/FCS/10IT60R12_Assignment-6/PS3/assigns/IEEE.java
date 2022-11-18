interface memberIEEE
{
	void memberProfile();
}

class Employee
{
	String name;
	int id;
	
	Employee(String s,int n)
	{
		name=s;
		id=n;
	}
}

class Teacher extends Employee implements memberIEEE
{
	int yearMembership,regionIEEE;
	Teacher(String S,int k,int x,int s)
	{
		super(S,k);
		yearMembership=x;
		regionIEEE=s;
		
	}
	
	public void memberProfile()
	{
		System.out.println("Teacher record : Year joined = " + yearMembership + "Place = " + regionIEEE);
	}
}

class Student implements memberIEEE
{
	int yearMembership,regionIEEE;
	Student(int x,int s)
	{
		yearMembership=x;
		regionIEEE=s;
	}
	
	public void memberProfile()
	{
		System.out.println("Student record : Year joined = " + yearMembership + "Place = " + regionIEEE);
	}
}

class IEEE
{
/*	static void display(float x, float y)
	{
		System.out.println("AREA " + x + "PERIMETER " + y);
	}
	*/
	public static void main(String args[])
	{
		Teacher t= new Teacher("XYZ",12908,1993,56);
		
		Student s=new Student(2007,75);
		
		memberIEEE mIEEE;
		
		mIEEE=t;
		mIEEE.memberProfile();
		
		mIEEE=s;
		mIEEE.memberProfile();
	}
}
