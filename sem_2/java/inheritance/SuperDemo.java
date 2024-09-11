class A{
  int i;
}

class B extends A{
  int i; // this i hides the i in A
  B(int a, int b){
    super.i = a; // assigning a value to the i in superclass
    i = b; // i in b
  }
  void show(){
    System.out.println("i in superclass: " + super.i);
    System.out.println("i in subclass: " + i);
  }
}

class SuperDemo{
  public static void main(String args[]) {
    B subOb = new B(10, 20);
    subOb.show();
  }
}
