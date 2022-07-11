// Bring System namespace into scope - contains the Console class
using System;
namespace Example
{
    // Program does not have to be in Program.cs
    // Main method does not have to be in a public class
    class Program
    {
        // Main method has a capital “M”
        static void Main(string[] args)
        {
            Car myCar = new Car();
            myCar.Drive();
        }
    } 
    // Abstract base class
    abstract class Vehicle
    {
        public virtual void Drive()
        {
            // Default implementation
        }
    } 
    // Car inherits from Vehicle
    class Car : Vehicle
    {
        // Override default implementation
        public override void Drive()
        {
            Console.WriteLine("Car running");
        }
    }
}
