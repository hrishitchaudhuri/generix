import java.util.List;
import java.util.ArrayList;
public class GenericLowerBoundedWildcardTest {
   // Generic method which accepts List<Integer>
   //   and Integer's supertypes such as Number and Object
   public static void addIntToList(List<? super Integer> lst, int num) {
      lst.add(num);
   }

   public static void main(String[] args) {
      List<Integer> intLst = new ArrayList<>(); // modifiable List
      intLst.add(1);
      intLst.add(2);
      System.out.println(intLst);  //[1, 2]
      addIntToList(intLst, 3);
      System.out.println(intLst);  //[1, 2, 3]

      List<Number> numLst = new ArrayList<>();
      numLst.add(1.1);
      numLst.add(2.2);
      System.out.println(numLst);  //[1.1, 2.2]
      addIntToList(numLst, 3);
      System.out.println(numLst);  //[1.1, 2.2, 3]

      List<String> strLst = new ArrayList<>();
      //addIntToList(strLst, "hello");
      //error: incompatible types: List<String> cannot be converted to List<? super Integer>
   }
}