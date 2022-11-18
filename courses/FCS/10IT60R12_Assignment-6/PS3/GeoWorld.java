import java.util.Enumeration;
import java.util.Vector;
import java.lang.Math; // for the definition of pi in area computation
interface Printable {
public void printIt();
}
class GeoObject implements Printable {
protected int baseX;
protected int baseY;
protected int itsArea;
public GeoObject (int x, int y) {
baseX = x;
baseY = y;
itsArea = 0;
}
public void printIt(){
System.out.println("The default print: " + this);
}
}
class Rectangle extends GeoObject {
private int itsWidth;
private int itsHeight;
public Rectangle(int x, int y, int width, int height) {
super(x,y);
if (width<0) {
itsWidth = 0;
}
else itsWidth = width;
if (height<0)
itsHeight = 0;
else
itsHeight = height;
itsArea = itsHeight*itsWidth;
}
public void printIt () {
System.out.println("Rectangle: base = (" +
baseX + ", " + baseY + "), height = " +
itsHeight + ", width = " + itsWidth +
", area = " + itsArea + ".");
}
}
class Circle extends GeoObject {
private int itsRadius;
public Circle(int x, int y, int radius) {
super(x,y);
java.lang.Long results;
itsRadius = radius;
results =
new java.lang.Long(
java.lang.Math.round( 2 * radius
* radius
* java.lang.Math.PI));
itsArea = results.intValue();
}
public void printIt () {
System.out.println("Circle: base = (" +
baseX + ", " + baseY + "), radius = " +
itsRadius + ", area = " + itsArea + ".");
}
}
public class GeoWorld {
public static void main (String args[]) {
System.out.println("Starting GeoWorld");
System.out.println();
System.out.println("Type c to create a circle, " +
"r to create a rectangle, " +
"and q to quite.");
// read in the first character
// if anything goes wrong (including "end of file")
// set the "character" to -99 as a signal that
// this there is no more input available
int in;
try {in = System.in.read();
} catch (Exception e) {
in = -99;
}
int count = 0;
Rectangle r;
Circle c;
Object o;
Vector objects = new Vector();
// check for the end of data, create the objects indicated (if any),
// put the new object on the list, and get the next
// character from the input
while (in != 'q' && in != -99) {
// for an r: create a rectangle and add it to the list
if (in == 'r') {
// In place of the following three lines, I could have typed:
// objects.addObject((Object) new Rectangle(20,30,40,50);
// and this would have the same effect. In that case the
// data field r would be unnecessary. I similar substitution
// would be possible for the circle below.
r = new Rectangle(20,30,40,50);
o = (Object) r;
objects.addElement(o);
System.out.println("Created a Rectangle");
count = count + 1;
}
// for a c: create a circle and add it to the list
if (in == 'c') {
c = new Circle(60,70,80);
objects.addElement((Object) c);
count = count + 1;
System.out.println("Created a Circle");
}
// read in a new character and repeat the while
try {
in = System.in.read();
} catch (Exception e) {
in = -99;
}
} // end of loop that starts with "while (in != -99)..."
// now print out all the object we created
// note that we no longer care what type of object each one is
// as far as we know, at this point, they are all objects
// of the GeoObject class (which implements Printable)
// so we know that they must have a printIt method.
Enumeration theList = objects.elements();
GeoObject element;
for (int i = 1; i <= count; i++) {
element = (GeoObject) theList.nextElement();
System.out.println(
"Printing object number " + i + " from the list");
element.printIt();
System.out.println();
}
}
}

