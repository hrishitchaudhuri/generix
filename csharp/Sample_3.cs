using System;

namespace EnumExample {
	enum year {
		January,
		February,
		March
	}

	class Program {
		static void Main(string[] args) {
			Console.WriteLine(year.January);
			Console.WriteLine(year.February);
			Console.WriteLine(year.March);
		}
	}
}
