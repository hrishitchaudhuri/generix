using System;

namespace CSharpStruct {
	struct Employee {
		public int id;

		public void getId(int id) {
			Console.WriteLine("Employee ID: " + this.id);
		}
	}

	class Program {
		static void Main(string[] args) {
			Employee emp;
			emp.id = 10;

			emp.getId(1);
			Console.ReadLine();
		}
	}
}
