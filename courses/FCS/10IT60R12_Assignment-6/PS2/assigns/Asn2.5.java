// Automatic initialization - concept of constructor
      class Point {
            int x, y;
            Point ( int x, int y ) {
               this.x = x ;
               this.y = y;
            }
	int getX(){
	return x;
}
	int getY(){
	return y;
}
           void printPoint() {
                System.out.println("X = "+ this.x + " Y= " + this.y);
      }
}
      class PointCreate {
	int calculateArea(Point A,Point B){
		int length = A.getX() - B.getX();
		int bredth = A.getY() - B.getY();
		int area = length*bredth;
		return area<0?-1*area:area;	
}
            public static void main ( String args [  ] ) {
                  Point p1 = new Point (20,5);
		  Point p2 = new Point (5,25);
		  PointCreate pc = new PointCreate();
                  p1.printPoint();
                  p2.printPoint();
		  System.out.println("Area is :: "+pc.calculateArea(p1,p2));
            }
      }
