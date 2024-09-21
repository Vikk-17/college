package Shape;

public class Circle {
  public double radius;

  Circle() {
    this.radius = -1;
  }

  Circle(double rad) {
    this.radius = rad;
  }

  public double area() {
    return 3.1419 * radius * radius;
  }
}
