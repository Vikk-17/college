class ZeroByDivision {
  public static void main(String args[]){
    try {
      int a = args.length; // give the total number of params
      System.out.println("a = " + a);
      int b = 42 / a;
    } catch (ArithmeticException e) {
      System.out.println("Divide by 0: " + e);
    }
  }
}
