/*
public class List<E> implements Iterable<E> .... {
   public void forEach(Consumer<? super E> action)
   .......
}
*/

import java.util.List;
import java.util.function.Consumer;  // JDK 8

public class GenericLowerBoundedTypeTest {
   public static void main(String[] args) {
      // Set E to Double to create a List<Double>
      List<Double> dLst = List.of(1.1, 2.2);  // JDK 9 to generate an unmodifiable List

      // Set up a Consumer<Double> that is capable of operating on Double
      // We can only use methods supported by Double, such as Double.doubleToRawLongBits(d)
      Consumer<Double> dConsumer = d -> System.out.printf("%x%n", Double.doubleToRawLongBits(d));
      // Run .forEach() with Consumer<Double> operating on each Double element
      dLst.forEach(dConsumer);
      //3ff199999999999a
      //400199999999999a

      // Set up a Consumer<Number>
      // Number is a supertype of Double, which satisfies <? super E=Double>.
      // We can only use methods supported by Number, such as .intValue()
      Consumer<Number> numConsumer = num -> System.out.println(num.intValue());  // JDK 8
      // Run .forEach() with Consumer<Number> operating on each Double element
      // Since Double is a subtype of Number. It inherits and supports all methods in Number.
      dLst.forEach(numConsumer);
      //1
      //2
   }
}