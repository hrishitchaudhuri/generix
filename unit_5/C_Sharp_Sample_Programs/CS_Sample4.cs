class Program
{
    delegate int Calculation(int a, int b);
    static void Main(string[] args)
    {
        int x = 2;
        int y = 3;
        Calculation add = (a, b) => { return a + b; };
        int answer = add(x, y);
        Console.WriteLine(answer); // output: 5
    }
}
