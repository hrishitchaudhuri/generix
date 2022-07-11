interface IDateCalculator {
    double DaysBetween(Date from,Date to);
    double HoursBetween(Date from,Date to);
} 
class DateCalculator implements IDateCalculator
{
    public double DaysBetween(Date start,Date end) {
    long startTimeMs = start.getTime();
    long endTimeMs = end.getTime();
    long diffInMs = endTimeMs - startTimeMs;
    double diffInDays = diffInMs / (24 * 60 * 60 * 1000);
    return diffInDays;
    } 
    public double HoursBetween(Date start,Date end) {
    long startTimeMs = start.getTime();
    long endTimeMs = end.getTime();
    long diffInMs = endTimeMs - startTimeMs;
    double diffInHours = diffInMs / (60 * 60 * 1000);
    return diffInHours;
    }
}