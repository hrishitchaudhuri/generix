// The struct (structure) is like a class in C# that is used to store data. 
// However, unlike classes, a struct is a value type.

using System;
namespace CsharpStruct {
 
  // defining struct
  struct Employee {
    public int id;

    public void getId(int id) {
      Console.WriteLine("Employee Id: " + id);
    }
  }
 
  class Program {
    static void Main(string[] args) {
 
      // declare emp of struct Employee
      Employee emp;
      
      // accesses and sets struct field
      emp.id = 1;

      // accesses struct methods
      emp.getId(emp.id);

      Console.ReadLine();
    }
  }
}