using System;

namespace Generics
{
    class Program
    {
        static void Main(string[] args)
        {
            Logger<string> textLog = new Logger<string>();
            textLog.ConsoleLog();

            Logger<int> numLog = new Logger<int>();
            numLog.ConsoleLog();

            Console.ReadLine();
        }
    }

    class Logger<T>
    {
        public void ConsoleLog(T toLog = default(T))
        {
            Console.WriteLine(toLog);
        }
    }
}