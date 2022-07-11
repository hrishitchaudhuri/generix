public class UBPMTest {
   public static <T extends Comparable<T>> T maximum(T x, T y) {
      // Need to restrict T to Comparable and its subtype for .compareTo()
      return (x.compareTo(y) > 0) ? x : y;
   }

   public static void main(String[] args) {
      System.out.println(maximum(55, 66));    // 66
      System.out.println(maximum(6.6, 5.5));  // 6.6
      System.out.println(maximum("Monday", "Tuesday"));  // Tuesday
   }
}
