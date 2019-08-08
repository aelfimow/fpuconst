#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <sstream>

#include "cppasm.h"

static void gen_function(std::string const &func_name, r64 &param)
{
    comment("void " + func_name + "(void *p)");
    comment("p is in " + param.name());

    global(func_name);

    section code { ".text" };
    code.start();

    label(func_name);

    FLDPI();
    FSTP(param);

    RET();
}

int main(int argc, char *argv[])
try
{
    const std::string usageStr { "Usage: generate windows|linux" };

    if (argc != 2)
    {
        throw std::invalid_argument(usageStr);
    }

    std::string os { argv[1] };

    bool forWindows { os == "windows" };
    bool forLinux { os == "linux" };

    if (!forWindows && !forLinux)
    {
        throw std::invalid_argument(usageStr);
    }

    if (forWindows)
    {
        gen_function("fpu_pi", RCX);
    }

    if (forLinux)
    {
        gen_function("fpu_pi", RDI);
    }

    return EXIT_SUCCESS;
}
catch (...)
{
    std::cerr << "Error, exception" << std::endl;
    return EXIT_FAILURE;
}
