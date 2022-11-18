// Use of throw construct
class UserException extends Exception
{
    UserException(String message)
    {
       super(message);
    }
}
class ThrowExceptionDemo
{
    public static void main(String args[])
    {
       int a = 12; b = 246;
       a = System.in.read();
       b = System.in.read();
        try {
           float x = (float) a/(float) b;
           if (x < 0.05)
             throw new UserException("Invalid divisor");
        }
        catch (UserException e)
        {
          System.out.println("Cuaght the Exception....");
        System.out.println(e.getMessage() );
        }
        finally {
          System.out.println("The ulimate bock is executed");
        }
    }
}

