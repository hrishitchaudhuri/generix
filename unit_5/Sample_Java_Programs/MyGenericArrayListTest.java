//		MyGenericArrayListTest.java

public class MyGenericArrayListTest {
   public static void main(String[] args) {
      // type-safe to hold a list of Strings
      MyGenericArrayList<String> strLst = new MyGenericArrayList<>();  // JDK 7 diamond operator
      strLst.add("alpha");   // compiler checks if argument is of type String
      strLst.add("beta");

      for (int i = 0; i < strLst.size(); ++i) {
         String str = strLst.get(i);   // compiler inserts the downcasting operator (String)
         System.out.println(str);
      }

      //strLst.add(123);  // compiler detected argument is NOT String, issues compilation error
      //compilation error: incompatible types: int cannot be converted to String
   }
}