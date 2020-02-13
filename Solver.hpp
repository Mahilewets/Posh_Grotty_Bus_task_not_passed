#pragma once
#include "Input.hpp"
#include "Service.hpp"

class Solver
{
private:
    std::vector<Service> data;
public:
    bool solve(Input &input);
    std::vector<Service> get_timetable(const std::string &param);
};
