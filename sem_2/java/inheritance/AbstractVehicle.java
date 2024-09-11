// 1. Abstract class with constructor
abstract class Vehicle{
  String brand;

  Vehicle(String brand){
    this.brand = brand;
  }

  abstract void start();
}

abstract class ElectricVehicle extends Vehicle{
  ElectricVehicle(String brand){
    super(brand);
  }
  abstract void chargeBattery();
}

class Tesla extends ElectricVehicle{
  Tesla(){
    super("Tesla");
  }
  void start(){
    System.out.println("Tesla starting silently");
  }

  void chargeBattery(){
    System.out.println("Tesla charging at supercharger");
  }
}

public class AbstractVehicle{
  public static void main(String args[]){
    Tesla tesla = new Tesla();
    System.out.println("Brand: " +  tesla.brand);
    tesla.start();
    tesla.chargeBattery();
  }
}
