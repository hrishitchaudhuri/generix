/*
As an example, the ArrayList<E> has a method addAll() with the following signature:

public class ArrayList<E> implements List<E> .... {
   public boolean addAll(Collection<? extends E> c)
   .......
}
The addAll() accepts a Collection of E and E's subtypes. Via substitution, it also accepts subtypes of Collection.
*/

import java.util.List;
import java.util.ArrayList;
import java.util.Collection;
import java.util.LinkedList;
import java.util.Set;
import java.util.HashSet;

public class GenericUpperBoundedTest {
   public static void main(String[] args) {
      // Set E to Number.
      // Number is supertype of Integer, Double and Float
      List<Number> numLst = new ArrayList<>();
      numLst.add(1.1f);   // primitive float auto-box to Float, upcast to Number
      System.out.println(numLst);  //[1.1]

      // Integer is a subtype of Number, which satisfies <? extends E=Number>
      Collection<Integer> intColl = new LinkedList<>();
      intColl.add(2);  // primitive int auto-box to Integer
      intColl.add(3);
      System.out.println(intColl);  //[2, 3]
      // Try .addAll(Collection<? extends E>)
      numLst.addAll(intColl);
      System.out.println(numLst);   //[1.1, 2, 3]

      // Double is a subtype of Number, which satisfies <? extends E=Number>
      // Set is a subtype of Collection. Set<Double> is a subtype of Collection<Double>
      Set<Double> numSet = new HashSet<>();
      numSet.add(4.4);   // primitive double auto-box to Double
      numSet.add(5.5);
      System.out.println(numSet);  //[5.5, 4.4]
      // Try .addAll(Collection<? extends E>)
      numLst.addAll(numSet);
      System.out.println(numLst);  //[1.1, 2, 3, 5.5, 4.4]
   }
}