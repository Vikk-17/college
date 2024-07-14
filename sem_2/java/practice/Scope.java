public class Scope {
	public static void main(String args[]) {
		int x;
		x = 10;
		if (x == 10) {
			int y = 20;
			x = y * 2;
		
			System.out.println("The value of y is: " + y);
			System.out.println("The value of x is: " + x);
		}
		System.out.println("The value of x is: " + x);	
	} // end of main

} // end of Scope
