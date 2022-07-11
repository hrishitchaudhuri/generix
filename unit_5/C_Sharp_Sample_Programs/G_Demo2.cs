using System;

namespace GenericsDemo
{
    //MyGenericClass is a Generic Class
    class MyGenericClass<T>
    {
        //Generic variable - The data type is generic
        private T genericMemberVariable;

        //Generic Constructor - accepts one parameter of Generic type
        public MyGenericClass(T value)
        {
            genericMemberVariable = value;
        }

        //Generic Method - accepts one Generic type Parameter
        //Method return type also Generic
        public T genericMethod(T genericParameter)
        {
            Console.WriteLine("Parameter type: {0}, value: {1}", typeof(T).ToString(), genericParameter);
            Console.WriteLine("Return type: {0}, value: {1}", typeof(T).ToString(), genericMemberVariable);
            return genericMemberVariable;
        }

    }

    class Program
    {
        static void Main()
        {
            MyGenericClass<int> integerGenericClass = new MyGenericClass<int>(10);

            int val = integerGenericClass.genericMethod(200);
            Console.ReadKey();
        }
    }
}

