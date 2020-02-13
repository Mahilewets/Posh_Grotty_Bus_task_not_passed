#pragma once
#include "Solver.hpp"
#include "Service.hpp"
#include <fstream>
#include <iomanip>
#include <vector>
#include "Companies.hpp"

class OutputPrinter
{
private:
    bool print(const std::string &s, std::ostream &out)
    {
        try
        {
            out << s;
        }
        catch(std::exception e)
        {
            return false;
        }

        return true;
    }

    bool print_timetable(std::vector<Service> &timetable, std::ostream &out)
    {
        for(auto &service: timetable)
        {
            out << service.get_name() << " " << std::setw(2) << std::setfill('0') << service.get_start_time_hours() <<
            ":" << std::setw(2) << std::setfill('0') << service.get_start_time_minutes() << " " <<
            std::setw(2) << std::setfill('0') << service.get_finish_time_hours() << ":" <<
            std::setw(2) << std::setfill('0') << service.get_finish_time_minutes() << '\n';
        }

        return true;
    }
public:
    bool print_output(Solver &solver)
    {
        std::string path;
        std::cout << "Enter path to the output file: " << std::endl;
        std::cin >> path;

        std::ofstream out;
        out.open(path.c_str());
        if(!out.is_open())
        {
            std::cout << "Could not open file for write" << std::endl;
            return false;
        }

        auto companies = Companies::get_companies();

        for(size_t i = 0; i < companies.size(); ++i)
        {
            auto table = solver.get_timetable(companies[i]);

            if(false == print_timetable(table, out))
            {
                   return false;
            }

            if(i < companies.size() - 1)
            {
                if(false == print("\n", out))
                {
                    return false;
                }
            }
        }

        out.close();

        return true;
    }
};
