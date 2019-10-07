#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// Type definition representing a time (hour and minute)
typedef struct
{
    int hour;
    int minute;
} Time;

int IsEarlier(Time a, Time b);

int main(void)
{
    Time t1, t2;
    t1.hour = 14;
    t1.minute = 30;
    t2.hour = 16;
    t2.minute = 45;
    if (IsEarlier(t1, t2))
    {
        printf("(%d,%d)", t1.hour, t1.minute);
        printf(" is earlier than ");
        printf("(%d,%d)", t2.hour, t2.minute);
    }
    else
    {
        printf("(%d,%d)", t2.hour, t2.minute);
        printf(" is earlier than ");
        printf("(%d,%d)", t1.hour, t1.minute);
    }
    return 0;
}
int IsEarlier(Time a, Time b)
{
    if (a.hour == b.hour)
    {
        return (a.hour>b.hour);
    }
    else
    {
        return (a.hour<b.hour);
    }
}