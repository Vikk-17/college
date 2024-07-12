import java.util.Scanner;

public class Circumference {
	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);
		System.out.print("Enter the radius: ");
		String rad = scan.nextLine();
		int radius = Integer.parseInt(rad);
		double pi = 3.14;
		double area, circumference;
	       	area = 3.14 * radius * radius;
		circumference = 2 * 3.14 * radius;
		System.out.println("Area of the circle: " + area);
		System.out.println("Circumference of the circle: " + circumference);
	} // end of main class
} // end of class
