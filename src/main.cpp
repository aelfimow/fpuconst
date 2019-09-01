#include <iostream>

#include "fpuconst.h"


int main(int argc, char *argv[])
try
{
    argc = argc;
    argv = argv;

    fpuconst_pi<float> pi_float;
    fpuconst_pi<double> pi_double;
    fpuconst_pi<long double> pi_long_double;

    std::cout << "pi_float: " << pi_float << std::endl;
    std::cout << "pi_double: " << pi_double << std::endl;
    std::cout << "pi_long_double: " << pi_long_double << std::endl;

    fpuconst_zero<float> zero_float;
    fpuconst_zero<double> zero_double;
    fpuconst_zero<long double> zero_long_double;

    std::cout << "zero_float: " << zero_float << std::endl;
    std::cout << "zero_double: " << zero_double << std::endl;
    std::cout << "zero_long_double: " << zero_long_double << std::endl;

    return EXIT_SUCCESS;
}
catch (...)
{
    std::cerr << "Error: exception" << std::endl;
    return EXIT_FAILURE;
}
