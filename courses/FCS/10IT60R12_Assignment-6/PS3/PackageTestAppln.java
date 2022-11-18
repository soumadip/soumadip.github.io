// Save this listing in file called MyClass.java.
// This file should be located in a subdirectory named MyPackage
// Compile the MyClass.java to get MyClass.class
// Import the so created package with the following code.
    import MyPackage.MyClass;
    class PackageTestAppln {
      public static void main ( String args [ ] ) {
          MyClass theClass = new MyClass ( );
            theClass.test ( );
      }
    }

