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

    fpuconst_one<float> one_float;
    fpuconst_one<double> one_double;
    fpuconst_one<long double> one_long_double;

    std::cout << "one_float: " << one_float << std::endl;
    std::cout << "one_double: " << one_double << std::endl;
    std::cout << "one_long_double: " << one_long_double << std::endl;

    fpuconst_ld10<float> ld10_float;
    fpuconst_ld10<double> ld10_double;
    fpuconst_ld10<long double> ld10_long_double;

    std::cout << "ld10_float: " << ld10_float << std::endl;
    std::cout << "ld10_double: " << ld10_double << std::endl;
    std::cout << "ld10_long_double: " << ld10_long_double << std::endl;

    return EXIT_SUCCESS;
}
catch (...)
{
    std::cerr << "Error: exception" << std::endl;
    return EXIT_FAILURE;
}
