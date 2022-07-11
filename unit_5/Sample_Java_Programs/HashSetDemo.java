// Java program to demonstrate working of HashSet
import java.util.*;
  
class HashSetDemo {
  
    // Main Method
    public static void main(String[] args)
    {
        HashSet<String> h = new HashSet<>();
  
        // Adding elements into HashSet usind add()
        h.add("Bangalore");
        h.add("Mysore");
        h.add("Udupi");
        h.add("Mysore"); // adding duplicate elements
  
        // Displaying the HashSet
        System.out.println(h);
        System.out.println("List contains Mysore or not:"
                           + h.contains("Mysore"));
  
        // Removing items from HashSet using remove()
        h.remove("Bangalore");
        System.out.println("List after removing Bangalore:"
                           + h);
  
        // Iterating over hash set items
        System.out.println("Iterating over list:");
        Iterator<String> i = h.iterator();
        while (i.hasNext())
            System.out.println(i.next());
    }
}