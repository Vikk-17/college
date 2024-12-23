package Shape;

class Rectangle{
  double length, breadth;
  Rectangle(){
    this.length = this.breadth = -1;
  }
  Rectangle(double l, double d){
    this.length = l;
    this.breadth = d;
  }
  Rectangle(double len){
    this.length = len;
    this.breadth = len;
  }
  double area(){
    return length * breadth;
  }
}
