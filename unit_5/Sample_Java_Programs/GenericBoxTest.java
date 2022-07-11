//		GenericBoxTest.java

public class GenericBoxTest {
   public static void main(String[] args) {
      GenericBox<String> box1 = new GenericBox<>("hello");  // JDK 7 supports type inference
      String str = box1.getContent();  // no explicit downcasting needed
      System.out.println(box1);
      //GenericBox[content=hello(class java.lang.String)]

      GenericBox<Integer> box2 = new GenericBox<>(123);    // int auto-box to Integer
      int i = box2.getContent();       // Integer auto-unbox to int
      System.out.println(box2);
      //GenericBox[content=123(class java.lang.Integer)]

      GenericBox<Double> box3 = new GenericBox<>(55.66);  // double auto-box to Double
      double d = box3.getContent();    // Double auto-unbox to double
      System.out.println(box3);
      //GenericBox[content=55.66(class java.lang.Double)]
   }
}