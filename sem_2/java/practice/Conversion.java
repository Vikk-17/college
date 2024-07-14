public class Conversion {
	public static void main(String args[]) {
		byte b;
		int i = 257;
		double d = 323.142;

		System.out.println("\nConversion of int to byte");
		b = (byte) i; // range of byte is 256, so i % 256
		System.out.println("i and b " + i + " " + b);

		System.out.println("\nConversion of double to int");
		i = (int) d; // 323.142, 323
		System.out.println("d and i " + d + " " + i);

		System.out.println("\nConversion of double to byte");
		b = (byte) d; // 323.142 => 323 % 256
		System.out.println("d and b " + d + " " + b);
	} // end of main
} // end of Conversion

