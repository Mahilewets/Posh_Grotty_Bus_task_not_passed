#include <iostream>

#include "Time24h.hpp"
#include "Service.hpp"
#include "Input.hpp"
#include "Solver.hpp"
#include "Output_Printer.hpp"

int main()
{
    Input input;
    if(!input.read_from_file())
    {
        return 1;
    }

    Solver solver;
    if(!solver.solve(input))
    {
        return 1;
    }

    OutputPrinter output_printer;

    if(!output_printer.print_output(solver))
    {
        return 1;
    }

    return 0;
}
