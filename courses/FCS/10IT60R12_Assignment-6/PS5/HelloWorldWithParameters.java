  public class HelloWorldWithParameters extend Applet
{
   String aString;
   int anInteger;
   public void init()
   {
      aString = getParameter("string");
        anInteger = Integer.parseInt(getParameter("intVal");
      if(aString == null)
            aString = "Hi";
      aString = "Hello" + aString;
   }
  public void paint(Graphics g)
  {
     String intToString;
     g.drawString(aString, 10, 75);
     intToString = String.valueOf(anInteger);
     g.drawString(intToString, 100, 75);
  }
}
<APPLET
    CODE = HelloWorld.class
    WIDTH = 400
    LENGTH = 200
      ALLIGN = RIGHT
    <PARAM NAME = "string" VALUE = "Java">
    <PARAM NAME = "intVal" VALUE = 96 >
>
</APPLET>

