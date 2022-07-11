using System;

namespace Inheritance {
	class Animal {
		public string name;

		public void display() {
			Console.WriteLine("I am an animal.");
		}
	}

	class Dog: Animal {
		public void getName() {
			Console.WriteLine("My name is " + name);
		}
	}

	class Program {
		static void Main(string[] args) {
			Dog labrador = new Dog();

			labrador.name = "Bozo";
			labrador.display();

			labrador.getName();
			Console.ReadLine();
		}
	}
}
