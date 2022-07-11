package Example;
// Optional import
import java.lang.*;
// Program class must be in a file called Program.java
// The main method must be defined in a public class
public class Program {
    public static void main(String[] args){
    Car myCar = new Car(); 
    myCar.Drive();
    }
} 
// Abstract base class
abstract class Vehicle{
    public void Drive() {
    // Default implementation
    }
} 
// Car inherits from Vehicle
class Car extends Vehicle {
    // Override default implementation
    public void Drive() {
    System.out.println("Car running");
    }
}