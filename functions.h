/**
 *  Header file for functions C file
 *  Author: Maximilian Hedderich
 *  Created: 28.02.2021
 **/
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

int day_of_the_year(int day, int month,int year);
void input_date(int* day, int* month, int* year);
int is_leapyear(int year);
int get_days_for_month(int day, int month);
int exists_date(int day, int month, int year);

#endif // FUNCTIONS_H_INCLUDED
