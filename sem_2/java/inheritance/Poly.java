class Bike{
  void run(){
    System.out.println("Running...");
  }
}

class Ninja extends Bike{
  void run(){
    System.out.println("Ninja started");
  }
}

class Poly{
  public static void main(String args[]){
    Bike b = new Ninja();
    b.run();
  }
}
