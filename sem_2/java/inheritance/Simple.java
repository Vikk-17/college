class A {
  int i;
  private int j;

  void setj(int x){
    j = x;
  }

  void showij(){
    System.out.println("i and j: " + i + " " + j);
  }
}

/*class B extends A {
  int k;
  void showk(){
    System.out.println("k: " + k);
  }
  void sum(){
    System.out.println("i + j + k: " + (i + j + k));
  }
}*/

// Driver class 
class Simple {
  public static void main(String args[]){
    A superOb = new A();
    // B subOb = new B();

    // Superclass
    superOb.i = 10;
    // superOb.j = 20;
    superOb.setj(20);
    System.out.println("Contents of superOb: ");
    superOb.showij();
    System.out.println();

    // Subclass
    /*subOb.i = 7;
    subOb.j = 8;
    subOb.k = 9;
    System.out.println("Contents of subOb: ");
    subOb.showij();
    subOb.showk();
    System.out.print("Sum of i, j, k in subOb: ");
    subOb.sum();*/ 
  }
}
