/* Write a java program to list the factorial of numbers 1 to 10.
 * To calculate the factorial value use while loop(Hint: fact of 4 = 4 * 3 * 2 * 1)
 * */

class Lab2{
  public static void main(String args[]){
    int fact, i = 1, num = 1;
    while(num<=10){
      fact = 1;
      while(i<=num){
        fact = fact * i;
        i++;
      }
      num ++;
      System.out.println("Factorial of " + num + " is = " + fact);
    }
  }
}
