public class LifeTime {
	public static void main(String args[]) {
		int x;
		for(x = 0; x < 3; x++){
			int y = -1;
			System.out.println("The value of y is: " + y);
			y = 100;
			System.out.println("The value of y is now: " + y);
		}
	} // end of main
} // end of LifeTime
