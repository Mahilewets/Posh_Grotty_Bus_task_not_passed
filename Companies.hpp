#pragma once
#include <vector>
#include <string>

class Companies
{
public:
    static std::vector<std::string> get_companies()
    {
        return {"Posh", "Grotty"};
    }
};
