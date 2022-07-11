string month;
switch (month) // string variables supported
{
    case "Jan":
        monthNum = 1;
    break; // doesn’t allow fall through
    case "Feb":
        monthNum = 2;
    break;
    default:
        Console.WriteLine("Invalid Value");
    break;
}
