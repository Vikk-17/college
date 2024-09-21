// Multilevel constructor calling chain

class Vehicle{
  // defualt constructor
  Vehicle(){
    System.out.println("Vehicle constructor executed");
  }
}

class ElectricVehicle extends Vehicle{
  ElectricVehicle(){
    System.out.println("ElectricVehicle constructor executed");
  }
}

class Tesla extends ElectricVehicle{
  Tesla(){
    System.out.println("Tesla constructor executed");
  }
}

class CallingChain{
  public static void main(String args[]){
    System.out.println("Example of Constructor Calling Chain");
    Tesla tesla = new Tesla();
  }
}
