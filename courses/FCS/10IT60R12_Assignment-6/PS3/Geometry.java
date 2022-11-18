// A simple interface in Java
    interface GeoAnalyzer
    {
      final static double pi = 3.142F;
      double area( );
      double perimeter( );
    }
    class Circle implements GeoAnalyzer
    {
        double radius;
      Circle(double r) {
          radius = r;
      }
      public double area( ) {
            return(pi*radius*radius);
      }
      public double perimeter( ) {
            return(2*pi*radius);
      }
    }
    class Ellipse implements GeoAnalyzer
    {
        double major;
      double minor;
      Ellipse(double m, double n) {
          major = m;
          minor = n;
      }
      public double area( ) {
            return(pi*major*minor);
      }
      public double perimeter( ) {
            return(pi*(major+minor));
      }
    }
    class Rectangle implements GeoAnalyzer
    {    double length;
  double width;
  Rectangle(double l, double w) {
      length = l;
       width = w;
  }
  public double area() {
        return(length*width);
  }
  public double perimeter( ) {
        return(2*(length+width));
  }
}
class Geometry
{
   static void display(double x, double y) {
    System.out.println("Area = " + x + "Perimeter = " + y);
   }
   public static void main(String args[ ]) {
    Circle c = new Circle(5.2);
    Ellipse e = new Ellipse(4.5, 3.6);
    Rectangle r = new Rectangle(6.5, 4.3);
    GeoAnalyzer geoItem;
    geoItem = c;
    display(geoItem.area(), geoItem.perimeter());
    geoItem = e;
    display(geoItem.area(), geoItem.perimeter());
    geoItem = r;
    display(geoItem.area(), geoItem.perimeter());
   }
}

