#include <iostream>
#include "fpuconst_pi.h"

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

    return EXIT_SUCCESS;
}
catch (...)
{
    std::cerr << "Error: exception" << std::endl;
    return EXIT_FAILURE;
}
