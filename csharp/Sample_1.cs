using System;

namespace Example {
	class Program {
		static void Main(string[] args) {
			Car myCar = new Car();
			myCar.Drive();
		}
	}


	abstract class Vehicle {
		public virtual void Drive() {
			// default implementation
		}
	}

	class Car: Vehicle {
		public override void Drive() {
			Console.WriteLine("Car is running");
		}
	}
}
