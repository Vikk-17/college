class Outer{
  int a = 10;
  public int b = 20;
  protected int c = 30;
  private int d = 40;
  public void method1(){
    Inner ob = new Inner();
    ob.display();
  }
  class Inner{
    int innerData = 50;
    void display(){
      System.out.println("Outer class default value A: " + a);
      System.out.println("Outer class public value B: " + b);
      System.out.println("Outer class protected value C: " + c);
      System.out.println("Outer class private value D: " + d);
      System.out.println("Inner class default value: " + innerData);

    }
  }
}

class Lab5{
  public static void main(String args[]){
    Outer ob = new Outer();
    ob.method1();
  }
}
