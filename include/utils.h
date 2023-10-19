#ifndef UTILS_H
#define UTILS_H
#include <date.h>
#include <trip.h>

bool before(Date d1, Date d2);

int difference(Date d1, Date d2);

int duration(Date d1, Date d2);

bool operator<(Date &d1,Date d2);

int operator-(Date &d1,Date d2);


#endif
