import java.io.*;

class throwsSig{
  public static void readFile(String path) throws IOException{
    if(path == null){
      throw new IllegalArgumentException("File path can't be null");
    }
    FileReader file = new FileReader(path);
    BufferedReader br = new BufferedReader(file);
    System.out.println(br.readLine());
    br.close();
  }

  public static void main(String args[]){
    try{
      readFile(null);
    } catch(IllegalArgumentException e){
        System.out.println("Exception caught: " + e.getMessage());
    }
    catch(IOException e){
        System.out.println("Exception caught: " + e.getMessage());
    }
  }
}
