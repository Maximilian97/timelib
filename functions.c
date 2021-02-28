/**
 *  Header file for functions C file
 *  Author: Maximilian Hedderich
 *  Created: 28.02.2021
 **/

 //pre processor commmands to include libraries
#include <stdio.h>
#include <stdlib.h>
//defining output messages for better clarity of the code
#define InputRqstYear printf("Please input a year:");
#define InputRqstMonth printf("Please input a month:");
#define InputRqstDay printf("Please input a day:");
#define ErrorMsgYear printf("Wrong Input! Please input a valid year(between 1582 and 2400).\n");
#define ErrorMsgMonth printf("Wrong Input! Please input a valid month(between 1 and 12).\n");
#define ErrorMsgDay printf("Wrong Input! Please input a valid day.\n");

/**
 * Function gets a date and returns what day of the year it is, if it is a valid date
 *
 * @param day: day part of the date
 * @param month: month part of the date
 * @param year: year part of the date
 * @return result or -1 if date doesnt exist
 **/
int day_of_the_year(int day, int month, int year)
{
    //variable declaration
    int result;

    //checking if date is valid
    if(exists_date(day, month, year) == 0)
    {
        //return value if month is invalid
        return -1;
    }
    else
    {
        //calculating days of month by iterating through months up to month of the date and adding the amount of days
        //to the result each iteration step
        for(int i = 1; i < month; i++)
        {
            result += get_days_for_month(i, year);
        }
        //adding days of current month to result
        result += day;

        //returning result
        return result;
    }
}
/**
 * Function requests and reads a date and stops when a valid date is given
 *
 * @param day: day part of the date
 * @param month: month part of the date
 * @param year: year part of the date
 **/
void input_date(int* day, int* month, int* year)
{
    //do while loop for continous input request if a invalid date is given
    do
    {
        //requesting input, reading input and flush for correct reading in next step
        InputRqstDay
        scanf("%i", day);
        fflush(stdin);

        InputRqstMonth
        scanf("%i", month);
        fflush(stdin);

        InputRqstYear
        scanf("%i", year);
        fflush(stdin);
    }
    //exit condition for the do while loop: date must exist or loop will continue
    while(exists_date(*day, *month, *year) == 0);
}

/**
 * Function gets a date and returns whether it is a leapyear or not if it is a valid year
 *
 * @param day: day part of the date
 * @param month: month part of the date
 * @param year: year part of the date
 * @return -1 if the year is invalid, 1 if the given year is a leapyear, 0 if the given year is not a leapyear
 **/
int is_leapyear(int year)
{
    //checking if year is valid
    if(year < 1582)
    {
        return -1;
    }
    else
    {
        //checking for leapyear
        if(year % 4 == 0 && year % 100 != 0 || year % 100 == 0 && year % 400 != 0 || year % 400 == 0)
        {
            //return value if is leapyear
            return 1;
        }
    }
    //return value if its not a leapyear
    return 0;
}
/**
 * Function gets a date and returns the amount of days the month has
 *
 * @param day: day part of the date
 * @param month: month part of the date
 * @param year: year part of the date
 * @return amount of days the month of the given date has
 **/
int get_days_for_month(int month, int year)
{
    //declaration of dayCount array which contains the amount of days for each month
    int dayCount[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    //checking if month is valid
    if(month < 1 || month > 12)
    {
        //return value if month is invalid
        return -1;
    }
    //checking if month is february
    if(month == 2)
    {
        //return amount of day and check for leapyear
        return dayCount[month - 1] + is_leapyear(year);
    }
    else
    {
        //return day count of given month if not february
        return dayCount[month -1];
    }
}
/**
 * Function gets a date and returns if it is a valid date or not
 *
 * @param day: day part of the date
 * @param month: month part of the date
 * @param year: year part of the date
 * @return returns 1 if the date is invalid and 0 if it is valid
 **/
int exists_date(int day, int month, int year)
{
    //variable decalration of daysOfMonth and errorCnt
    int daysOfMonth = get_days_for_month(month, year);
    int errorCnt = 0;

    //checking if day is valid
    if(day > daysOfMonth || day < 1)
    {
        ErrorMsgDay
        errorCnt++;
    }
    //checking if month is valid
    if(daysOfMonth == -1)
    {
        ErrorMsgMonth
        errorCnt++;
    }
    //checking if year is valid
    if(year > 2400 || year < 1582)
    {
        ErrorMsgYear
        errorCnt++;
    }
    //return 0 if invalid and 1 if valid
    if(errorCnt != 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
