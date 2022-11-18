class TaskRecord {
      TaskAllotmentInfo tai[] = new TaskAllotmentInfo[11];
      void enterInfo(int upperLimit, int arraySize) {
            int tn;
            int found = 0;
            if(upperLimit <=0) {
                   throw new IllegalArgumentException("UpperLimit must be positive: " + upperLimit);
            }
            if (arraySize <=0) {
                         throw new IllegalArgumentException("Size of returned List must be greater than 0.");
            }
            int i = 1;
            Random generator = new Random();
            tai[0] = new TaskAllotmentInfo();
            tai[0].taskNo = generator.nextInt(upperLimit);
            tai[0].taskAssigned = 0;
            while(i < arraySize) {
                  tn = generator.nextInt(upperLimit);
                  for(int j = 0; j <i; j++) {
                        if (tai[j].taskNo == tn) {
                              found = 1;
                              break;
                              }
                        else {
                              found = 0;
                        }
                  }
                  if (found == 0) {
                        tai[i] = new TaskAllotmentInfo();
                        tai[i].taskNo = tn;
                        tai[i].taskAssigned = 0;
                        i = i+1;
                  }
            }
      }
      public boolean searchLocal(int j, int t) {
      int k =0;
            while(k<j) {
                  if(tai[k].taskNo == t)
                        return false;
                  else k++;
            }
            return false;
      }
      public void display() {
            for(int i =0; i < 10; i++) {
                  System.out.println("Task Assigned to Client " +tai[i].taskAssigned + " Task Number: " + tai[i].taskNo);
                  }
      }
      public boolean search() {
            int i = 0;
            while(i<10){
                  if(tai[i].taskAssigned == 0 && (i<10))
                        return true;
                  else i++;
            }
            return false;
      }
      public boolean searchIfTaskAvailable(int n) {
            int i = 0;
            while(i<10){
                  if(tai[i].taskNo == n && (i<10))
                        return true;
                  else i++;
            }
            return false;
      }
      public boolean taskNotAlloted(int j) {
            int i = 0;
            while(tai[i].taskNo != j) {
                  i = i +1;
            }
            if(tai[i].taskAssigned == 0)
                  return true;
            else return false;
      }
      public void alloted(int tn, int ta) {
            int i = 0;
            while(tai[i].taskNo != tn) {
                  i = i +1;
            }
            tai[i].taskAssigned = ta;
            System.out.println("tai[i].taskNo: " + tai[i].taskNo +"tai[i].taskAssigned : " + tai[i].taskAssigned);
      }
}
class Client implements Runnable{
      int jobNo;
      int cName;
      TaskRecord t= new TaskRecord();
      //Thread t2 = new Thread();
      Client(TaskRecord t1,int name){
            t = t1;
            cName = name;
            new Thread(this).start();
            //t2.start();
      }
      void getJobNo(int uLimit) {
            if(uLimit <=0) {
                  throw new IllegalArgumentException("UpperLimit must be positive: " + uLimit);
            }
            Random generator = new Random();
            jobNo = generator.nextInt(uLimit);
            }
      public void run(){
            while(t.search()) {
                  getJobNo(20);
                  if(t.searchIfTaskAvailable(jobNo)) {
                         if(t.taskNotAlloted(jobNo)) {
                               t.alloted(jobNo, cName);
                         }
                  }
            }
      }
}
class TaskAllotmentcurrent {
      public static void main(String args[]) {
      TaskRecord t = new TaskRecord();
      t.enterInfo(20,10);
      t.display();
      Client c1 = new Client(t,1);
      Client c2 = new Client(t,2);
      Client c3 = new Client(t,3);
      Client c4 = new Client(t,4);
      /*System.out.println("Thread one is alive; " +c1.t2.isAlive());
      System.out.println("Thread two is alive; " +c2.t2.isAlive());
      System.out.println("Thread three is alive; " +c3.t2.isAlive());
      System.out.println("Thread four is alive; " +c4.t2.isAlive());*/
      try {
            Thread.sleep(100);
            /*c1.t2.join();
            c2.t2.join();
            c3.t2.join();
            c4.t2.join();*/
      }
      catch (InterruptedException e) {
            System.out.println("Main Thread interrupted");
      }
      /*System.out.println("Thread one is alive; " +c1.t2.isAlive());
      System.out.println("Thread two is alive; " +c2.t2.isAlive());
      System.out.println("Thread three is alive; " +c3.t2.isAlive());
      System.out.println("Thread four is alive; " +c4.t2.isAlive());*/
      t.display();
      }
}

