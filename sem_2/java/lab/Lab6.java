class Add{
  int a, b;
  Add(){
    System.out.println("Default constructor");
    a = 10;
    b = 20;
  }
  Add(int a, int b){
    System.out.println("Parameterzied constructor");
    this.a = a;
    this.b = b;
  }
  void addition(){
    System.out.println("========================");
    System.out.println("A: " + a);
    System.out.println("B: " + b);
    System.out.println("A+B: " + (a+b));
    System.out.println("========================");
  }
  void addition(Add ob){
    System.out.println("========================");
    System.out.println("A: " + ob.a);
    System.out.println("B: " + ob.b);
    System.out.println("A+B: " + (ob.a+ob.b));
    System.out.println("========================");
  }
}

class Lab6{
  public static void main(String args[]){
    System.out.println("Demonstration of constructor overloading and method overloading");
    System.out.println("===============================================================");
    Add ob = new Add();
    ob.addition();
    Add ob1 = new Add(2, 3);
    ob1.addition(ob1);
  }
}
