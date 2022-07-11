//		MyGenericArrayList.java

// A dynamically allocated array with generics
public class MyGenericArrayList<E> {  // E is the generic type of the elements
   private int size;                  // number of elements
   private Object[] elements;         // Need to use an Object[], not E[]

   public MyGenericArrayList() {  // constructor
      elements = new Object[10];  // allocate initial capacity of 10
      size = 0;
   }

   public void add(E e) {
      if (size >= elements.length) {
         // allocate a larger array and copy over
         Object[] newElements = new Object[size + 10];
         for (int i = 0; i < size; ++i) newElements[i] = elements[i];
         elements = newElements;
      }
      elements[size] = e;
      ++size;
   }

   @SuppressWarnings("unchecked")
   public E get(int index) {
      if (index >= size)
         throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + size);
      return (E)elements[index];   // triggers an "unchecked cast" warning
   }

   public int size() { return size; }
}