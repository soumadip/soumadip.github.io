//Version 2: Another version of Librray Information System taking the current
//date to calculate fine as well as to issue a book
import java.util.*;
import java.io.*;
class Date1 {
      int day;
      int month;
      int year;
      Date1 getDate() {
                  String tempString;
                  try {
                         DataInputStream din = new DataInputStream(System.in);
                         System.out.print("Enter Current Day: ");
                         //System.out.flush();
                         tempString = din.readLine();
                         day = Integer.parseInt(tempString);
                         System.out.print("Enter Current Month: ");
                         //System.out.flush();
                         tempString = din.readLine();
                         month = Integer.parseInt(tempString);
                         System.out.print("Enter Current Year: ");
                         //System.out.flush();
                         tempString = din.readLine();
                         year = Integer.parseInt(tempString);
                  }
                  catch(Exception e) {
                         System.out.println("Here is the error");
                  }
                  return(this);
      }
}
abstract class LibBook {
      String nameOfBook;
      int ACCno;
      String issuedTo;
      LibBook(String n, int a, String m) {
            nameOfBook = n;
            ACCno = a;
            issuedTo = m;
      }
      boolean search(LibBook b) {
            if(b.issuedTo == "NULL") return true;
            else return false;
      }
      void returnBook(LibMember l) {
            issuedTo = "NULL";
            l.returnUpdate(this);
            }
      abstract void issueBook(LibMember l);
      abstract int computeFine(int i);
}
class TextBook extends LibBook {
      TextBook(String n, int a, String m) {
            super(n,a, m);
      }
      void issueBook(LibMember l) {
            if(search(this)) {
                  System.out.println("You can issue for 30 days");
                  issuedTo = l.name;
                  l.issueUpdate(this);
                  }
            else
                  System.out.println("The book is issued to someone else");
      }
      int computeFine(int days) {
            return days*2;
      }
      void displayTextBook() {
            System.out.println("Book: " +nameOfBook + "         AccNo: " + ACCno
+ "         Issued To : " + issuedTo);
      }
}
class RefBook extends LibBook {
      RefBook(String n, int a, String m) {
            super(n,a, m);
      }
      void issueBook(LibMember l) {
            if(search(this)) {
                  System.out.println("You can issue for 1 night only");
                  issuedTo = l.name;
                  l.issueUpdate(this);
                  }
            else
                  System.out.println("The book is issued to someone else");
      }
      int computeFine(int days) {
            return days*10;
      }
      void displayRefBook() {
            System.out.println("Book: " +nameOfBook + "          AccNo: " +
ACCno + "        Issued To : " + issuedTo);
      }
}
class LibMember {
      String name;
      int IDno;
      String bookissued[] = new String[10];
      Date1 curDate = new Date1();
      Date1 retDate = new Date1();
      Date1 retDate1[] = new Date1[10];
      private int tos = -1;
LibMember(String n, int i) {
      name = n;
      IDno = i;
}
void issueRequest(TextBook b) {
      System.out.println("You want to issue a text book!!");
      if(tos < 3) {
            curDate.getDate();
            retDate.day = curDate.day+30;
            if(retDate.day > 30) {
            retDate.day = retDate.day - 30;
            retDate.month = curDate.month + 1;
            }
            else
            retDate.month = curDate.month;
            retDate.year = curDate.year;
            b.issueBook(this);
            }
      else
            System.out.println("You cannot issue any more book");
}
void issueRequest(RefBook b) {
      System.out.println("You want to issue a Reference book!!");
      if(tos < 3) {
            curDate.getDate();
            retDate.day = curDate.day+1;
            if(retDate.day > 30) {
            retDate.day = retDate.day - 30;
            retDate.month = curDate.month + 1;
            }
            else
            retDate.month = curDate.month;
            retDate.year = curDate.year;
            b.issueBook(this);
            }
      else
            System.out.println("You cannot issue any more book");
}
void issueUpdate(LibBook b) {
      tos++;
      retDate1[tos] = new Date1();
      retDate1[tos].day = retDate.day;
      retDate1[tos].month = retDate.month;
      retDate1[tos].year = retDate.year;
      bookissued[tos] = b.nameOfBook;
}
void returnUpdate(LibBook b) {
      curDate.getDate();
      int i =0, j =0;
      while(bookissued[i] != b.nameOfBook) {
            i = i+1;
      }
            j = curDate.month - retDate1[i].month;
            if (j > 0)
            System.out.println("Total fine : "+ b.computeFine(j));
            else
            System.out.println("No fine");
            bookissued[i] = "NULL";
            retDate1[i].day = 0;
            retDate1[i].month = 0;
            retDate1[i].year = 0;
      }
      void displayRecords() {
            System.out.println("Name : " + this.name + "    IdNo: " + IDno );
            System.out.println("   Return Date: " + "     Books: ");
            for(int i =0; i<=tos; i++){
                  System.out.println("    "+ retDate1[i].day + "/" +
retDate1[i].month + "/" + retDate1[i].year +"         " +bookissued[i]);
            System.out.println();
            }
      }
}
class LibExaample2 {
      public static void main(String args[]) {
      LibMember l1 = new LibMember("Tom", 111);
      LibMember l2 = new LibMember("Harry", 112);
      TextBook b1 = new TextBook("Math   ", 1000, "NULL");
      TextBook b2 = new TextBook("Science", 1001, "NULL");
      TextBook b3 = new TextBook("English", 1002, "NULL");
      RefBook r1 = new RefBook("Journal1", 2000, "NULL");
      RefBook r2 = new RefBook("Journal2", 2001, "NULL");
      RefBook r3 = new RefBook("Journal3", 2002, "NULL");
      l1.issueRequest(b1);
      l1.issueRequest(r1);
      l1.issueRequest(b2);
      //l1.issueRequest(b3);
      //l1.issueRequest(r2);
      //l2.issueRequest(b1);
      //l2.issueRequest(r1);
      //l2.issueRequest(b2);
      //l2.issueRequest(b3);
      //l2.issueRequest(r2);
      //b1.displayTextBook();
      //r1.displayRefBook();
  l1.displayRecords();
  b1.returnBook(l1);
  l1.displayRecords();
  r1.returnBook(l1);
  //l1.returnRequest(b2);
  l1.displayRecords();
  //l2.displayRecords();
  }
}

