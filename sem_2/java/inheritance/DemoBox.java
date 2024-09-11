// This program uses inheritance to uses box

class Box {
  private double width;
  double height;
  double depth;

  // Constructor with no specific dimension
  Box(){
    width = -1;
    height = -1;
    depth = -1;
  }

  // Constructor with all params specifies
  Box(double w, double h, double d){
    width = w;
    height = h;
    depth = d;
  }

  // Constructor to make a cube
  Box(double len){
    width = height = depth = len;
  }

  // Passing the object as a whole
  Box(Box ob){
    width = ob.width;
    height = ob.height;
    depth = ob.depth;
  }

  // Compute and return volume
  double volume(){
    return width * height * depth;
  }
}

// extending the Box class to add weight
class BoxWeight extends Box {
  double weight;

  BoxWeight(double w, double h, double d, double m){
    super(w);
    height = h;
    depth = d;
    weight = m;
  }
}

class DemoBox {
  public static void main(String args[]){
    BoxWeight box1 = new BoxWeight(10, 20, 30, 34.3);
    BoxWeight box2 = new BoxWeight(1.5, 2.3, 4.5, 0.76);

    System.out.println("Volume of box1: " + box1.volume() + " and weight is: " + box1.weight);
    System.out.println("Volume of box2: " + box2.volume() + " and weight is: " + box2.weight);
  }
}
