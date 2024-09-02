/* A program that uses the box class.
 * Call this file BoxDemo.java
 * */

// The new operator dynamically allocates memory for an object.
// The general form is: class-var = new classname();

class Box {
	double width;
	double height;
	double depth;
	
	// This is the constructor of the box
	Box() {
		System.out.println("Constructing the box");
		width = 10;
		height = 20;
		depth = 15;
	}

	// Method to calculate the volume and returns it
	double volume(){
		return  width * height * depth;
	}
}

public class BoxDemo {
	public static void main(String args[]){
		Box mybox = new Box();
		/*
		mybox.width = 10;
		mybox.height = 20;
		mybox.depth = 15;
		*/

	
		System.out.println("Volume is " + mybox.volume());
	}
}
