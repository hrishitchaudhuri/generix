using System;

interface IDateCalculator {
	double DaysBetween(DateTime from, DateTime to);
	double HoursBetween(DateTime from, DateTime to);
}

class DateCalculator: IDateCalculator {
	public double DaysBetween(DateTime start, DateTime end) {
		double DiffDays = end.Subtract(start).TotalDays;
		return DiffDays;
	}

	public double HoursBetween(DateTime start, DateTime end) {
		double DiffHours = end.Subtract(start).TotalHours;
		return DiffHours;
	}
}
