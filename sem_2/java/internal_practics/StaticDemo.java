class MathUtils {
    // Static data
    static double pi = 3.141519;
    static int count = 0;

    // Static metod
    static double calculateArea(double radius){
        count ++;
        return pi * radius * radius;
    }
    static int getCount(){
        return count;
    }
}

public class StaticDemo {
    public static void main(String[] args){
        double area1 = MathUtils.calculateArea(5);
        double area2 = MathUtils.calculateArea(20);

        System.out.println(area1);
        System.out.println(area2);

        System.out.println(MathUtils.pi);
        System.out.println(MathUtils.getCount());
    }
}
