/**
 *  Program that outputs the days since the begin of the year
 *  Author: Maximilian Hedderich
 *  Created: 28.02.2021
 **/

//Pre processor instruction to include libraries
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#define ResultMsg printf("Today is the %i. day of the year",
#define End );

//main function
int main()
{
    int day, month, year;

    input_date(&day, &month, &year);
    ResultMsg day_of_the_year(day, month, year) End
}
