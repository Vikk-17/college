class Box {
	double width, height, depth;

	// Constructor used when all dimensions specified
	Box(double w, double h, double d) {
		width = w;
		height = h;
		depth = d;
	}

	// Constructor used when no dimensions specifed
	Box(){
		// Use -1 to indicate an uninitialized box
		width = -1;
		height = -1;
		dept = -1;
	}

	// Constructor used when cube is create
	Box(double len) {
		width = height = depth = len;
	}

	// Compute the return volume
	double volume(){
		return width * height * depth;
	}
}
