#pragma once

#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include "Service.hpp"

class Input
{
private:
    std::vector<Service> Services;
public:
    Input()
    {
        Services.clear();
        Services.reserve(100);
    }

    bool read_from_file()
    {
        std::cout << "Enter path to the input file:" << std::endl;

        std::string path;
        std::cin >> path;

        std::ifstream in;

        in.open(path.c_str());
        if(!in.is_open())
        {
            std::cout << "Could not open file!" << std::endl;
            return false;
        }

        std::string name;
        int start_hh, start_mm, finish_hh, finish_mm;
        char start_colon, finish_colon;

        while(in >> name >> start_hh >> start_colon >> start_mm >> finish_hh >> finish_colon >> finish_mm)
        {
            Time24h start_time(start_hh, start_mm), finish_time(finish_hh, finish_mm);
            Service service(name, start_time, finish_time);

            Services.push_back(service);
        }

        in.close();

        return true;
    }

    std::vector<Service> get_data()
    {
        return Services;
    }
};
