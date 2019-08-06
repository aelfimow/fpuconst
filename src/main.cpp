#include <iostream>

int main(int argc, char *argv[])
try
{
    return EXIT_SUCCESS;
}
catch (...)
{
    std::cerr << "Error: exception" << std::endl;
    return EXIT_FAILURE;
}
