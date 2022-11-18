//Randomly fill the array, sort it, add a number to the sorted list and delete a
//number. All the process should be done concurrently.
import java.util.*;
class Numbers {
      public int result[] = new int[20];
      void displayListOfNos() {
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
            System.out.println("Numbers stored in the array:");
            displayListOfNos();
      }
      void sortAscending() {
            for(int i=0; i<9; i++) {
                  for(int j=i+1; j<10; j++) {
                        if(result[i] > result[j]) {
                              int temp = result[i];
                              result[i] = result[j];
                              result[j] = temp;
                        }
                  }
            }
            System.out.println("Array after sorting:");
            displayListOfNos();
      }
      synchronized void deleteANumber(int aUpperLimit, int aArraySize) {
            if (aUpperLimit <=0) {
                   throw new IllegalArgumentException("UpperLimit must bepositive: " + aUpperLimit);
            }
             Random generator = new Random();
             int num = generator.nextInt(aUpperLimit);
             int i = 0;
             while(i < aArraySize && num != result[i]){
                  i = i+1;
             }
             if (i== aArraySize)
                  System.out.println("Number " + num + " not found in thearray");
             else {
                  for(int j = i; j< aArraySize-1; j++)
                        result[j] = result[j+1];
                        result[aArraySize - 1] = 0;
                        System.out.println("Number " + num + " found in thearray and deleted");
            }
            System.out.println("Array after deletion");
            displayListOfNos();
      }
      synchronized void addANumber(int aUpperLimit, int aArraySize) {
            if (aUpperLimit <=0) {
                   throw new IllegalArgumentException("UpperLimit must bepositive: " + aUpperLimit);
            }
             Random generator = new Random();
             int num = generator.nextInt(aUpperLimit);
             int i =0;
             while(i < aArraySize && num > result[i]){
                  i = i+1;
             }
             if (i== aArraySize)
                  result[aArraySize] = num;
            else {
                  for(int j = aArraySize; j>i; j--)
                        result[j] = result[j-1];
                        result[i] = num;
            }
            System.out.println("Array after addition of " +num );
            displayListOfNos();
            System.out.println(result[aArraySize]);
      }
}
class AddingANumber implements Runnable {
      int ul;
      int as;
      Numbers n1 ;
      AddingANumber(Numbers n,int upperLimit, int arraySize) {
            n1 = n;
            ul = upperLimit;
            as = arraySize;
            new Thread(this).start();
      }
      public void run() {
            n1.addANumber(ul,as);
      }
}
class DeletingANumber implements Runnable {
      int ul;
      int as;
      Numbers n2;
      DeletingANumber(Numbers n,int upperLimit, int arraySize) {
            n2 = n;
            ul = upperLimit;
            as = arraySize;
            new Thread(this).start();
      }
      public void run() {
            n2.deleteANumber(ul,as);
      }
}
class AddAndDelete {
      public static void main(String args[]) {
      Numbers n = new Numbers();
      n.fillTheArray(20,10);
      n.sortAscending();
      AddingANumber a1 = new AddingANumber(n, 20, 10);
      DeletingANumber d1 = new DeletingANumber(n, 20, 10);
      }
}

