package Shape;

class Triangle {
  double length, breadth;

  Triangle() {
    this.length = -1;
    this.breadth = -1;
  }

  Triangle(double l, double b) {
    this.length = l;
    this.breadth = b;
  }

  Triangle(double len) {
    this.length = this.breadth = len;
  }

  double area() {
    return 0.5 * length * breadth;
  }
}
