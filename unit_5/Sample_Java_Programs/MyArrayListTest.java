//                  MyArrayListTest.java

public class MyArrayListTest {
   public static void main(String[] args) {
      // Create a MyArrayList to hold a list of Strings
      MyArrayList strLst = new MyArrayList();
      // Adding elements of type String
      strLst.add("alpha");   // String upcasts to Object implicitly
      strLst.add("beta");
      System.out.println(strLst);  // toString()
   
      // Retrieving elements: need to explicitly downcast back to String
      for (int i = 0; i < strLst.size(); ++i) {
         // String str = (String)strLst.get(i);
         String str = strLst.get(i);
         System.out.println(str);
      }

      // Inadvertently added a non-String object. Compiler cannot detect this logical error.
      // But triggers a runtime ClassCastException during downcast.
      strLst.add(1234);   
      // int auto-box to Integer, upcast to Object. Compiler/runtime cannot detect this logical error
      String str = (String)strLst.get(2);
      // compile ok
      // runtime ClassCastException: class java.lang.Integer cannot be cast to class java.lang.String
   }
}