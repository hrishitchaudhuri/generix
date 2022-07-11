// 	GenericMethodTest.java


import java.util.List;
import java.util.ArrayList;

public class GenericMethodTest {
   // A static generic method to append an array to a List
   public static <E> void Array2List(E[] arr, List<E> lst) {
      for (E e : arr) lst.add(e);
   }

   public static void main(String[] args) {
      // Set E to Integer
      Integer[] arr = {55, 66};  // int auto-box to Integer
      List<Integer> lst = new ArrayList<>();
      Array2List(arr, lst);
      System.out.println(lst);   //[55, 66]

      String[] strArr = {"alpha", "beta", "charlie"};
      //Array2List(strArr, lst);
      //compilation error: method Array2List in class GenericMethodTest
      //  cannot be applied to given types
   }
}