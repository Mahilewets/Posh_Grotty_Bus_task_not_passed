#pragma once
#include "Time24h.hpp"
#include <vector>
#include <string>
#include <array>
#include "Companies.hpp"

class Service
{
private:
    std::string Name;
    Time24h Start_time, Finish_time;
    bool effective, deleted;

public:
    Service(std::string name, Time24h start_time, Time24h finish_time) :
        Name(name), Start_time(start_time), Finish_time(finish_time)
    {
        effective = true; // default_true;
        deleted = false;
    }

    bool is_effective()
    {
        return effective;
    }

    void set_effective(bool flag)
    {
        effective = flag;
    }

    int get_length_in_minutes()
    {
        return Finish_time.get_total_minutes() - Start_time.get_total_minutes();
    }

    int get_start_time()
    {
        return Start_time.get_total_minutes();
    }

    int get_finish_time()
    {
        return Finish_time.get_total_minutes();
    }

    std::string &get_name()
    {
        return Name;
    }

    bool is_deleted()
    {
        return deleted;
    }

    void set_deleted(bool flag)
    {
        deleted = flag;
    }

    bool operator<(Service &second)
    {
        return (get_start_time() < second.get_start_time()) ||
        (get_start_time() == second.get_start_time() && get_finish_time() < second.get_finish_time()) ||
        (get_start_time() == second.get_start_time() && get_finish_time() == second.get_finish_time()
         && Name == Companies::get_companies()[0]);
    }

    int get_start_time_hours()
    {
        return Start_time.get_hours();
    }

    int get_start_time_minutes()
    {
        return Start_time.get_minutes();
    }

    int get_finish_time_hours()
    {
        return Finish_time.get_hours();
    }

    int get_finish_time_minutes()
    {
        return Finish_time.get_minutes();
    }
};
