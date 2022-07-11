//		MyArrayList.java


import java.util.Arrays;
// A resizable array without generics, which can hold any Java objects
public class MyArrayList {
   private int size;           // number of elements
   private Object[] elements;  // can store all Java objects

   public MyArrayList() {         // constructor
      elements = new Object[10];  // allocate initial capacity of 10
      size = 0;
   }

   // Add an element, any Java object can be upcast to Object implicitly
   public void add(Object o) {
      if (size >= elements.length) {
         // allocate a larger array and copy over
         Object[] newElements = new Object[size + 10];
         for (int i = 0; i < size; ++i) 
		newElements[i] = elements[i];
         elements = newElements;
      }
      elements[size] = o;
      ++size;
   }

   // Retrieves the element at Index. Returns an Object to be downcast back to its original type
   public Object get(int index) {
      if (index >= size)
         throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + size);
      return elements[index];
   }

   // Returns the current size (length)
   public int size() { return size; }

   // toString() to describe itself
   @Override
   public String toString() {
      return Arrays.toString(Arrays.copyOfRange(elements, 0, size));
   }
}