// Define a custom exception by extending Exception
class InvalidAgeException extends Exception {
  // Constructor to initialize the exception with a custeom message
  InvalidAgeException(String message){
    // call the parent class's Constructor
    super(message);
  }
}

class customExceptionDemo{
  public static void checkAge(int age) throws InvalidAgeException {
    if(age<=18){
      throw new InvalidAgeException("Age must be 18 or above");
    }
    System.out.println("Granted");
  }

  public static void main(String args[]){
    try{
      checkAge(18);
    } catch(InvalidAgeException e) {
        System.out.println("Exception caught: " + e.getMessage());
    }
  }
}
