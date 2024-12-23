import Shape.*;

class Main {
    public static void main(String args[]) {
        // Circle c = new Circle(10);
        // System.out.println("The area of circle: " + c.area());

        // Triangle t = new Triangle(10);
        // System.out.println("The area of triangle: " + t.area());

        // Rectangle r = new Rectangle(10);
        // System.out.println("The area of rectangle is: " + r.area());
        Circle c = new Circle();
        c.area();

        Triangle t = new Triangle();
        t.area();

        Rectangle r = new Rectangle();
        r.area();
    }
}