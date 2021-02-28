/**
 *  Header file for functions C file
 *  Author: Maximilian Hedderich
 *  Created: 28.02.2021
 **/
#include <stdio.h>
#include <stdlib.h>
#define InputRqstYear printf("Please input a year:");
#define InputRqstMonth printf("Please input a month:");
#define InputRqstDay printf("Please input a day:");
#define ErrorMsgYear printf("Wrong Input! Please input a valid year(between 1582 and 2400).\n");
#define ErrorMsgMonth printf("Wrong Input! Please input a valid month(between 1 and 12).\n");
#define ErrorMsgDay printf("Wrong Input! Please input a valid day.\n");

int day_of_the_year(int day, int month, int year)
{
    int result;

    if(exists_date(day, month, year) == 0)
    {
        return -1;
    }
    else
    {
        for(int i = 1; i < month; i++)
        {
            result += get_days_for_month(i, year);
        }
        result += day;

        return result;
    }
}
void input_date(int* day, int* month, int* year)
{
    do
    {
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
    while(exists_date(*day, *month, *year) == 0);
}

int is_leapyear(int year)
{
    if(year < 1582)
    {
        return -1;
    }
    else
    {
        if(year % 4 == 0 && year % 100 != 0)
        {
        return 1;
        }
        if(year % 100 == 0 & year % 400 != 0)
        {
        return 1;
        }
        if(year % 400 == 0)
        {
        return 1;
        }
    }
    return 0;
}

int get_days_for_month(int month, int year)
{
    int dayCount[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if(month < 1 || month > 12)
    {
        return -1;
    }
    if(month == 2)
    {
        return dayCount[month - 1] + is_leapyear(year);
    }
    else
    {
        return dayCount[month -1];
    }
}
int exists_date(int day, int month, int year)
{
    int daysOfMonth = get_days_for_month(month, year);
    int errorCnt = 0;

    if(day > daysOfMonth || day < 1)
    {
        ErrorMsgDay
        errorCnt++;
    }
    if(daysOfMonth == -1)
    {
        ErrorMsgMonth
        errorCnt++;
    }
    if(year > 2400 || year < 1582)
    {
        ErrorMsgYear
        errorCnt++;
    }
    if(errorCnt != 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
