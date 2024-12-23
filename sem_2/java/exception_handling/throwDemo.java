class throwDemo{
  public static void validateAge(int age){
    if(age<=18){
      throw new IllegalArgumentException("Age must be 18 or above");
    }
    System.out.println("Access granted");
  }
  public static void main(String args[]){
    try{
      validateAge(16);
    } catch(IllegalArgumentException e){
        System.out.println("Exception Caught: " + e.getMessage());
    }
  }
}
