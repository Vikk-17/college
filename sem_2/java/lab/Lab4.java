import java.util.*;

class Lab4 {
  public static void main(String args[]){
    Scanner ob = new Scanner(System.in);
    int a, b = 10;
    System.out.println("Enter value of a: ");
    a = ob.nextInt();
    System.out.println("Demonstration of division by zero exception:");
    System.out.println("============================================");
    try{
      int res = b/a;
      System.out.println("Result: " + res);
    } catch(ArithmeticException e) {
        System.out.println("Exception message: " + e);
    }
  }
}
