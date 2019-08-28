#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <sstream>

#include "cppasm.h"

template <typename T>
void gen_function_fldpi(std::string const &func_name, r64 &param)
{
    comment("void " + func_name + "(void *p)");
    comment("p is in " + param.name());

    global(func_name);

    section code { ".text" };
    code.start();

    label(func_name);

    FLDPI();

    T addr { param };
    FSTP(addr);

    RET();
}

template <typename T>
void gen_function_fldz(std::string const &func_name, r64 &param)
{
    comment("void " + func_name + "(void *p)");
    comment("p is in " + param.name());

    global(func_name);

    section code { ".text" };
    code.start();

    label(func_name);

    FLDZ();

    T addr { param };
    FSTP(addr);

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
        gen_function_fldpi<m80fp>("fpu_pi80", RCX);
        gen_function_fldpi<m64fp>("fpu_pi64", RCX);
        gen_function_fldpi<m32fp>("fpu_pi32", RCX);
        gen_function_fldz<m80fp>("fpu_zero80", RCX);
        gen_function_fldz<m64fp>("fpu_zero64", RCX);
        gen_function_fldz<m32fp>("fpu_zero32", RCX);
    }

    if (forLinux)
    {
        gen_function_fldpi<m80fp>("fpu_pi80", RDI);
        gen_function_fldpi<m64fp>("fpu_pi64", RDI);
        gen_function_fldpi<m32fp>("fpu_pi32", RDI);
        gen_function_fldz<m80fp>("fpu_zero80", RDI);
        gen_function_fldz<m64fp>("fpu_zero64", RDI);
        gen_function_fldz<m32fp>("fpu_zero32", RDI);
    }

    return EXIT_SUCCESS;
}
catch (...)
{
    std::cerr << "Error, exception" << std::endl;
    return EXIT_FAILURE;
}
