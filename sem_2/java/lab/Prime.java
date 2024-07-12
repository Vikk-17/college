import java.util.Scanner;

public class Prime {
	static boolean checkPrime(int n) {
		int count = 0;
		for(int i = 1; i<= n; i++) if(n%i == 0) count++;
		
		if (count == 2) return true;
		else return false;
	} // end of checkPrime
	
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		System.out.print("Enter a number: ");
	       	String n = scan.nextLine();
		int num = Integer.parseInt(n);

		boolean isPrime = checkPrime(num);
		if(isPrime) System.out.println("The number " + num + " is prime");
		else System.out.println("The number " + num + " is not prime");

	} // end of main
} // end of class
