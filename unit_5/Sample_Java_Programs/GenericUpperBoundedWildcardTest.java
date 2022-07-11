import java.util.List;
public class GenericUpperBoundedWildcardTest {
   // Generic method which accepts List<Number>
   //   and Number's subtypes such as Integer, Double
   // Number is an abstract class in Java
   public static double sumList(List<? extends Number> lst) {
      double sum = 0.0;
      for (Number num : lst) {
         sum += num.doubleValue();
      }
      return sum;
   }

   public static void main(String[] args) {
      List<Integer> intLst = List.of(1, 2, 3); // Returns an immutable list containing three elements.
      System.out.println(sumList(intLst));  //6.0

      List<Double> doubleLst = List.of(1.1, 2.2, 3.3);
      System.out.println(sumList(doubleLst));  //6.6

      List<String> strLst = List.of("apple", "orange");
      sumList(strLst);
      //error: incompatible types: List<String> cannot be converted to List<? extends Number>
   }
}