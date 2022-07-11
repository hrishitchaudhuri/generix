//       GenericBoxTypeTest.java


public class GenericBoxTypeTest {
   public static void main(String[] args) {
      GenericBox<Integer> box1 = new GenericBox<>(123);
      GenericBox<String> box2 = new GenericBox<>("hello");
      System.out.println(box1.getClass() == box2.getClass());  //true (same runtime class)
      System.out.println(box1.getClass());  //class GenericBox
      System.out.println(box2.getClass());  //class GenericBox
   }
}
