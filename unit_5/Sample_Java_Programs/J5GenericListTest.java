import java.util.List;
import java.util.ArrayList;

public class J5GenericListTest {
   public static void main(String[] args) {
      // Set E to String
      List<String> fruitLst = new ArrayList<>();  // JDK 7 supports type inference
      //List<String> fruitLst = new ArrayList<String>();  // Pre-JDK 7
      fruitLst.add("apple");
      fruitLst.add("orange");
      for (String fruit : fruitLst) 
	    System.out.println(fruit);
      //apple
      //orange

      fruitLst.add(123);  // This generic list accepts String only
      //compilation error: incompatible types: int cannot be converted to String
      //fruitLst.add(new StringBuffer("Hello"));
      //compilation error: incompatible types: StringBuffer cannot be converted to String
   }
}