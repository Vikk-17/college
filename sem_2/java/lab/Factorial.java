// Write a program to list the factorial of the numbers 1 to 10 using while loop.
// Fact of 4 = 4 * 3 * 2 * 1

class Factorial {
	public static void main(String args[]) {
		long fact;
		for(int i = 1; i<= 10; i++){
			fact = 1;
			for(int j = i; j >= 1 ; j--){
				fact = fact * j;
			}
			System.out.println("Fact of " + i + " is " + fact);
		}
	} // end of main
} // end of class
