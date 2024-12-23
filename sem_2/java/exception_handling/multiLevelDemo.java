class multiLevelDemo{
  public static void main(String args[]){
    // Outer try-catch block
    try{
      int number[] = {10, 20, 30};
      System.out.println("Number: " + number[3]);
      // Inner try-catch block
      try{
        int res = number[1] / 0;
      } catch(ArithmeticException e){
          System.out.println("Exception caught: " + e.getMessage());
      }
    } catch(ArrayIndexOutOfBoundsException e){
        System.out.println("Exception caught: " + e.getMessage());
    }
  }
}
