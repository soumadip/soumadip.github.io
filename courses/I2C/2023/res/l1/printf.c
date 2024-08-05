#include <stdio.h>

//RUN THE CODE BY COMPILING AND EXECUTING IN YOUR MACHINE
//READ THE COMMENTS IN THE CODE AND UNDERSTAND FROM THE OUTPUT OF THE PROGRAM
int main ()
{
	int i = 9;
	float f = 3.14;
	double d = 3.14;
	char c = 'a';
	
	//how basic printf works
	printf ("Hello ");
	printf ("World\n");

	// how to print a sequence of characters (aka string)
	printf ("%s\n", "Hello World");
	// positioning of a string
	printf ("'%20s'\n", "Hello World");
	printf ("'%-20s'\n", "Hello World");
	// how \t works - horizontal tab
	printf ("'%s'\n", "Hello\tWorld");
	// how \v works - vertical tab
	printf ("'%s'\n", "Hello\vWorld");
	// how \n works
	printf ("%s\n", "Hello\nWorld");
	// how \r works - carriage return
	printf ("%s\n", "OVERWRITEWorld");
	printf ("%s\n", "OVERWRITE\rWorld");
	// how \b works - a backspace
	printf ("%s\n", "Hello X\bWorld");
	// how to print a \ (backslash)
	printf ("%s\n", "C:\\new folder");
	// printing integers, floats and double
	printf ("%d\n", i);	//int one way
	printf ("%i\n", i);	//int another way
	printf ("%f\n", f);	//floats in general
	printf ("%e\n", 213821084.1204801984); //for big numbers
	// printing integer as a float
	printf ("%f\n", i); //the wrong way
	printf ("%f\n", (float)i); //the correct way
	// printing float as integer
	printf ("%d\n", f); //the wrong way
	printf ("%d\n", (int)f); //correct way
	
	// printing integers with specifying width of the print
	printf ("%5d %20d %3d %5d\n", 100, 138473840, 1001929, 10); //right-justified printing
	printf ("%05d %020d %03d %05d\n", 100, 138473840, 1001929, 10); //right-justified printing with zero filling
	printf ("%0+5d %+20d %03d %0+5d\n", 100, 138473840, 1001929, 10); //right-justified printing with zero filling, with and without plus sign
	printf ("%-5d %-20d %-3d %-5d\n", 100, 138473840, 1001929, 10); //left justified printing
	// printing and formatting floats/doubles
	printf ("'%.1f' '%8.2f' '%+8.2f' '%8.5f' '%-8.2f' '%-+8.2f'\n", 10.28138721, 10.28138721, 10.28138721, 10.28138721, 10.28138721, 10.28138721);
	// printing a float or a double to a desired decimal places after the fraction
	printf ("%.20f\n", f);		//check the precision of a float
	printf ("%.20f\n", d);		//check the precision of a double
	
	// printing in different number systems (decimal, octal and hexadecimal)
	printf ("%d %o %x\n", 1234, 1234, 1234);
	// printing characters
	printf ("%c\n", c);
	// printing ascii value of a character
	printf ("%d\n", c);

	//A mixed output
	printf("the %s jumped over the %s, %d times", "cow", "moon", 2);
}
