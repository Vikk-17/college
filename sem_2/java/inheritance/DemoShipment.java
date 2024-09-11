class Box {
    private double width;
    private double height;
    private double depth;

    // Constructor with no initialization
    Box() {
      width = -1;
      height = -1;
      depth = -1;
    }

    Box(double w, double h, double d){
      width = w;
      height = h;
      depth = d;
    }

    Box(double len){
      width = height = depth = len; // making of cube;
    }

    // passing a object to the Constructor
    Box(Box ob){
      width = ob.width;
      height = ob.height;
      depth = ob.depth;
    }

    // return volume
    double volume(){
      return width * height * depth;
    }
}

class BoxWeight extends Box {
  double weight;

  BoxWeight(){
    super();
    weight = -1;
  }

  BoxWeight(double w, double h, double d, double m){
    super(w, h, d);
    weight = m;
  }

  BoxWeight(double len, double m){
    super(len);
    weight = m;
  }

  BoxWeight(BoxWeight obj){
    super(obj);
    weight = obj.weight;
  }
}

class Shipment extends BoxWeight {
  double cost;

  Shipment(){
    super();
    cost = -1;
  }

  Shipment(double w, double h, double d, double m, double c){
    super(w, h, d, m);
    cost = c;
  }

  Shipment(double len, double m, double c){
    super(len, m);
    cost = c;
  }

  Shipment(Shipment shipmentOb){
    super(shipmentOb);
    cost = shipmentOb.cost;
  }
}

class DemoShipment {
  public static void main(String args[]){
    Shipment sh1 = new Shipment(10, 20, 15, 10, 3.41);
    Shipment sh2 = new Shipment(2, 3, 4, 0.76, 1.28);

    System.out.println("The volume of sh1 is: " + sh1.volume() + " weight is: " + sh1.weight + " and shipping cost: " + sh1.cost);
    System.out.println("The volume of sh1 is: " + sh2.volume() + " weight is: " + sh2.weight + " and shipping cost: " + sh2.cost);

  }
}
