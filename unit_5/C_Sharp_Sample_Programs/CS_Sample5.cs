class Circle
{
    private double radiusCM;
    public double RadiusMeters
    {
        get { return radiusCM / 100; }
        set { radiusCM = value * 100; }
    }
} 

class Program
{
    static void Main(string[] args)
    {
        Circle myCircle = new Circle();
        myCircle.RadiusMeters = 50;
        double radius = myCircle.RadiusMeters;
    }
}
