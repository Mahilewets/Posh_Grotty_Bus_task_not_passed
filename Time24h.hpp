#pragma once
#define minutes_in_hour 60

class Time24h
{
private:
    int Hours, Minutes, Total_minutes;

public:
    Time24h(int hours, int minutes) : Hours(hours), Minutes(minutes)
    {
        Total_minutes = Minutes + minutes_in_hour * Hours;
    }

    int get_total_minutes()
    {
        return Total_minutes;
    }

    int get_hours()
    {
        return Hours;
    }

    int get_minutes()
    {
        return Minutes;
    }
};
