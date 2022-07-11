public class UpperBoundedTypeParamAddTest {
   public static <T extends Number> double add(T first, T second) {
      // Need to use only methods defined in Number, such as doubleValue
      // Subtypes Integer and Double inherit and support these methods too.
      return first.doubleValue() + second.doubleValue();
   }

   public static void main(String[] args) {
      System.out.println(add(55, 66));     // int -> Integer. T is Integer.
      System.out.println(add(5.5f, 6.6f)); // float -> Float. T is Float.
      System.out.println(add(5.5, 6.6));   // double -> Double. T is Double.
      System.out.println(add(55, 6.6));    // int -> double -> Double. T is Double.

      //System.out.println(add("apple", "orange"));
      //compilation error: method add in class UpperBoundedTypeParameterTest
      //  cannot be applied to given types;
   }
}