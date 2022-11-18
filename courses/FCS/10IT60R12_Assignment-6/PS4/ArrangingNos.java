//Generate n numbers between x and y randomly and store them in an array.
// Concurremtly do the following:
// -- Sort the numbers in ascending order and print the result.
// -- Sort the numbers in descending order and print the result.
// Next, concurrently do the following.
// -- Generate a random number between x and y and insert it into the original
//    list, whether it is there or not.
// -- Generate a random number between x and y and delete the number from the
//    list if it is there.
import java.util.*;
class Numbers {
      public int result[] = new int[10];
      void displayListOfNos() {
            System.out.println("Numbers stored in the array:");
            for( int idx=0; idx<10; ++idx) {
                  System.out.println(result[idx]);
            }
      }
      void fillTheArray(int aUpperLimit, int aArraySize) {
            if (aUpperLimit <=0) {
                  throw new IllegalArgumentException("UpperLimit must bepositive: " + aUpperLimit);
            }
            if (aArraySize <=0) {
                        throw new IllegalArgumentException("Size of returnedList must be greater than 0.");
            }
              Random generator = new Random();
            for( int idx=0; idx<aArraySize; ++idx) {
                        result[idx] = generator.nextInt(aUpperLimit);
            }
            displayListOfNos();
      }
      synchronized void sortAscending() {
            for(int i=0; i<9; i++) {
                  for(int j=i+1; j<10; j++) {
                        if(result[i] < result[j]) {
                              int temp = result[i];
                              result[i] = result[j];
                              result[j] = temp;
                        }
                  }
            }
            displayListOfNos();
      }
      synchronized void sortDescending() {
            for(int i=0; i<9; i++) {
                  for(int j=i+1; j<10; j++) {
                        if(result[i] > result[j]) {
                              int temp = result[i];
                              result[i] = result[j];
                              result[j] = temp;
                        }
                  }
            }
            displayListOfNos();
      }
}
class ArrangementAscending implements Runnable {
      Numbers n1 ;
      ArrangementAscending(Numbers n) {
      n1 = n;
            new Thread(this).start();
      }
      public void run() {
            n1.sortAscending();
      }
}
class ArrangementDescending implements Runnable {
      Numbers n2;
      ArrangementDescending(Numbers n) {
      n2 = n;
            new Thread(this).start();
      }
      public void run() {
            n2.sortDescending();
      }
}
class ArrangingNos {
      public static void main(String args[]) {
      Numbers n = new Numbers();
      n.fillTheArray(20,10);
      ArrangementAscending a1 = new ArrangementAscending(n);
      ArrangementDescending d1 = new ArrangementDescending(n);
      }
}

