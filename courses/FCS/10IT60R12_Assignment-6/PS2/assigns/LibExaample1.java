/*class LibMember {
      String name;
      int IDno;
      String Bookissued[] = new String[10];
      private int tos = -1;
      LibMember(String n, int i) {
            name = n;
            IDno = i;
      }
      void issueRequest(LibBook b) {
            System.out.println("You want to issue a book");
            if(tos < 4)
                  b.issueBook(this);
            else
                  System.out.println("You cannot issue any more book");
      }
      void issueUpdate(LibBook b) {
            System.out.println("The book tittled " + b.nameOfBook +" is entered in your record");
            Bookissued[++tos] = b.nameOfBook;
      }
      void displayBooks() {
            System.out.println("List of books for Library member " + this.name);
            for(int i =0; i<=tos; i++)
                  System.out.println(Bookissued[i]);
      }
}
class LibBook {
      String nameOfBook;
      int ACCno;
      LibBook(String n, int a) {
            nameOfBook = n;
            ACCno = a;
      }
      void issueBook(LibMember l) {
            System.out.println("The book is issued");
            l.issueUpdate(this);
      }
}
class LibraryExample {
      public static void main(String args[]) {
      LibMember l = new LibMember("Tom", 111);
      LibBook b = new LibBook("Math", 1000);
      l.issueRequest(b);
      l.displayBooks();
      System.out.println("Your job is over");
      }
}*/
//Library example to show abstract class and inheritance
abstract class LibBook {
      String nameOfBook;
      int ACCno;
      LibBook(String n, int a) {
            nameOfBook = n;
            ACCno = a;
      }
      abstract void issueBook(LibMember l);
      abstract double computeFine(int i);
}
class TextBook extends LibBook {
      TextBook(String n, int a) {
            super(n,a);
      }
      void issueBook(LibMember l) {
            System.out.println("You can issue for 30 days");
            l.issueUpdate(this);
      }
      double computeFine(int days) {
            return days*2;
      }
}
class RefBook extends LibBook {
      RefBook(String n, int a) {
            super(n,a);
      }
      void issueBook(LibMember l) {
            System.out.println("You can issue for 1 night only");
            l.issueUpdate(this);
      }
      double computeFine(int days) {
            return days*10;
      }
}
class LibMember {
      String name;
      int IDno;
      String Bookissued[] = new String[10];
      int day;
      private int tos = -1;
      LibMember(String n, int i) {
            name = n;
            IDno = i;
      }
      void issueRequest(TextBook b) {
            System.out.println("You want to issue a text book!!");
            if(tos < 4) {
                  day = 30;
                  b.issueBook(this);
                  }
            else
                  System.out.println("You cannot issue any more book");
      }
      void issueRequest(RefBook b) {
            System.out.println("You want to issue a Reference book!!");
            if(tos < 4) {
                  day = 1;
                  b.issueBook(this);
                  }
            else
                  System.out.println("You cannot issue any more book");
      }
      void issueUpdate(LibBook b) {
            System.out.println("The book tittled " + b.nameOfBook +" is entered in your record");
            Bookissued[++tos] = b.nameOfBook;
      }
      void displayBooks() {
            System.out.println("List of books for Library member " + this.name);
            for(int i =0; i<=tos; i++)
                  System.out.println(Bookissued[i]);
      }
      void displayRecords() {
            System.out.print("Name : " + this.name + "     IdNo:  " + IDno + "Issued for: " + day + " days     Books:");
            for(int i =0; i<=tos; i++)
                  System.out.print(Bookissued[i]+ ", ");
            System.out.println();
      }
}
class LibExaample1 {
      public static void main(String args[]) {
      LibMember l1 = new LibMember("Tom", 111);
      LibMember l2 = new LibMember("Harry", 112);
      TextBook b1 = new TextBook("Math", 1000);
      TextBook b2 = new TextBook("Science", 1001);
      RefBook r1 = new RefBook("Journal1", 2000);
      RefBook r2 = new RefBook("Journal2", 2001);
      l1.issueRequest(b1);
      l1.issueRequest(r1);
      l2.displayBooks();
      l1.displayRecords();
      }
}

