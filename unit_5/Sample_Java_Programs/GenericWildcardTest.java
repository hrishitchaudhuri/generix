//		GenericWildcardTest.java

import java.util.List;
import java.util.ArrayList;
public class GenericWildcardTest {
   // Accepts List<Object>, NOT list<String>, List<Integer>, etc.
   public static void printList(List<Object> lst) {
      for (Object o : lst) System.out.println(o);
   }

   public static void main(String[] args) {
      List<Object> objLst = new ArrayList<>();  // ArrayList<Object> inferred
      objLst.add(11);  // int auto-box to Integer, upcast to Object
      objLst.add(22);
      printList(objLst);
      // 11
      // 22

      List<String> strLst = new ArrayList<>();  // ArrayList<String> inferred
      strLst.add("one");
      printList(strLst);  // only accept List<Object>
      //error: incompatible types: List<String> cannot be converted to List<Object>
   }
}