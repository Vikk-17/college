// Abstract Methods and classes in java

// 1. Abstract Methods
/*abstract class Animal {
  // Abstract method no implementation
  abstract void makeSound();

  // Regular method 
  void sleep(){
    System.out.println("Zzzz");
  }
}
*/ 

// 2. Abstract Classes 
abstract class Shape {
  // abstract method 
  abstract double calculateArea();

  // Regular method
  void display(){
    System.out.println("This is a shape");
  }
}

// 3. Concrete subclass
class Circle extends Shape {
  double radius;

  Circle(double radius){
    this.radius = radius;
  }

  // Implementation of abstract method
  // @Override is not necessary here
  double calculateArea(){
    return Math.PI * radius * radius;
  }
}

public class DemoAbstract{
  public static void main(String args[]){
    // Cannot instance abstract classes
    // Shap shape = new Shape(); // That would cause an error
    Circle circle = new Circle(5);
    System.out.println("Circle area: " + circle.calculateArea());
    circle.display();
  }
}
