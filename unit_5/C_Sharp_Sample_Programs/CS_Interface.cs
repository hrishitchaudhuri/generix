interface IDateCalculator
{
    double DaysBetween(DateTime from,DateTime to);
    double HoursBetween(DateTime from,DateTime to);
} 
class DateCalculator : IDateCalculator
{
    public double DaysBetween(DateTime start,DateTime end)
    {
        double diffInDays = end.Subtract(start).TotalDays;
        return diffInDays;
    } 
    public double HoursBetween(DateTime start,DateTime end)
    {
        double diffInHours = end.Subtract(start).TotalHours;
        return diffInHours;
    }
}
