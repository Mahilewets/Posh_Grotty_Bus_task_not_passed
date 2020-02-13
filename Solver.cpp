#include "Solver.hpp"
#include <iomanip>
#include <algorithm>

bool Solver::solve(Input &input)
{
    data = input.get_data();

    std::sort(data.begin(), data.end());

    // delete buses that are too slow
    for(size_t i = 0; i < data.size(); ++i)
    {
        if(data[i].get_length_in_minutes() > minutes_in_hour)
        {
            data[i].set_deleted(true);
        }
    }

    // delete duplicates
    for(size_t i = 0; i + 1 < data.size(); ++i)
    {
        Service &service_a = data[i];
        Service &service_b = data[i + 1];

        if(service_a.get_start_time() == service_b.get_start_time() &&
            service_a.get_finish_time() == service_b.get_finish_time())
        {
            service_b.set_deleted(true);
        }
    }

    // find ineffective services
    for(size_t i = 0; i < data.size(); ++i)
    {
        Service &service_a = data[i];

        if(service_a.is_deleted())
        {
            continue;
        }

        for(size_t j = 0; j < data.size(); ++j)
        {
            if(i == j)
            {
                    continue;
            }

            Service &service_b = data[j];

            if(service_b.get_start_time() > service_a.get_start_time() &&
                   service_b.get_finish_time() < service_a.get_finish_time())
            {
                service_a.set_effective(false);
                service_a.set_deleted(true);

                break;
            }

            if(service_b.get_start_time() == service_a.get_start_time() &&
                service_b.get_finish_time() < service_a.get_finish_time())
            {
                service_a.set_effective(false);
                service_a.set_deleted(true);

                break;
            }

            if(service_b.get_start_time() > service_a.get_start_time() &&
                   service_b.get_finish_time() == service_a.get_finish_time())
            {
                service_a.set_effective(false);
                service_a.set_deleted(true);
                break;
            }
        }
    }

    return true;
}

std::vector<Service> Solver::get_timetable(const std::string &param)
{
    std::vector<Service> timetable;

    for(auto it: data)
    {
        if(!it.is_deleted() && (param == it.get_name()))
        {
            timetable.push_back(it);
        }
    }

    return timetable;
}
