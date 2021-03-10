/**
 *  Header file for functions C file
 *  Author: Maximilian Hedderich
 *  Created: 28.02.2021
 **/
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

//date structure which consists of day, month and year, each of the type int
struct date
{
    int day;
    int month;
    int year;
};

//function prototypes
int day_of_the_year(struct date inputDate);
void input_date(struct date *pointer);
int is_leapyear(int year);
int get_days_for_month(int month, int year);
int exists_date(struct date input_date);

#endif // FUNCTIONS_H_INCLUDED
