/* Write a program:
 * 1. To find the area of circle and the circumference of the circle by accepting the radius from the user
 * 2. To accept a number and find whether the number is prime or not
 * */

import java.util.*;
import java.io.*;

class Lab3{
  public static void main(String args[]) throws IOException{
    Scanner sc = new Scanner(System.in);
    while(true){
      System.out.println("1. Area of circle");
      System.out.println("2. Circumference of the circle");
      System.out.println("3. Prime number");
      System.out.print("Enter your choice: ");
      int ch = sc.nextInt();
      switch(ch){
        case 1:
          System.out.print("Enter the value for radius:");
          double r = sc.nextDouble();
          double area = Math.PI * r * r;
          System.out.println("=========================");
          System.out.println("Area of circle is: " + area);
          break;
        case 2:
          System.out.print("Enter the value for radius:");
          double R = sc.nextDouble();
          double circumference = 2 * Math.PI * R;
          System.out.println("=========================");
          System.out.println("Circumference of circle is: " + circumference);
          break;
        case 3:
          System.out.print("Enter a value: ");
          int n = sc.nextInt();
          boolean b = true;
          for(int i = 2; i<=n; i++){
            if(n%i == 0){
              b = false;
              break;
            }
          }
          if(b) System.out.println("Entered number is prime number");
          else System.out.println("Entered number is not a prime number");
          break;
        default: System.exit(0);
      }
    }
  }
}
