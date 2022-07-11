// C# program to illustrate the use of Reflection
using System;
namespace ReflectionDemo
{
class Product
    {
        public int Id {  get; set; }
        public string Name { get; set; }
        public string Description { get; set; }
        public double Price { get; set; }
    }
    internal class Program
    {
        static void Main(string[] args)
        {
            Type type = typeof(Product);
            Console.WriteLine("Class: " + type.Name);
            Console.WriteLine("Namespace: " + type.Namespace);
            Console.Read();
        }
    }
}