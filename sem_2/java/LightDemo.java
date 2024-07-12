// Compute distance light travels using long variables

class LightDemo {
  public static void main(String args[]) {
    int lightspeed;
    long days, sec, distance;

    // Approximate speed of light in miles per sec
    lightspeed = 186000;
    days = 1000;
    sec = days * 24 * 60 * 60; // convert to second

    distance = lightspeed * sec;

    System.out.print("In " + days);
    System.out.print(" days light will travel about ");
    System.out.println(distance + " miles.");
  }
}
