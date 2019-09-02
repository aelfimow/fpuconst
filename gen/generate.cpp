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

template <typename T>
void gen_function_fld1(std::string const &func_name, r64 &param)
{
    comment("void " + func_name + "(void *p)");
    comment("p is in " + param.name());

    global(func_name);

    section code { ".text" };
    code.start();

    label(func_name);

    FLD1();

    T addr { param };
    FSTP(addr);

    RET();
}

template <typename T>
void gen_function_fldl2t(std::string const &func_name, r64 &param)
{
    comment("void " + func_name + "(void *p)");
    comment("p is in " + param.name());

    global(func_name);

    section code { ".text" };
    code.start();

    label(func_name);

    FLDL2T();

    T addr { param };
    FSTP(addr);

    RET();
}

template <typename T>
void gen_function_fldl2e(std::string const &func_name, r64 &param)
{
    comment("void " + func_name + "(void *p)");
    comment("p is in " + param.name());

    global(func_name);

    section code { ".text" };
    code.start();

    label(func_name);

    FLDL2E();

    T addr { param };
    FSTP(addr);

    RET();
}

template <typename T>
void gen_function_fldlg2(std::string const &func_name, r64 &param)
{
    comment("void " + func_name + "(void *p)");
    comment("p is in " + param.name());

    global(func_name);

    section code { ".text" };
    code.start();

    label(func_name);

    FLDLG2();

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
        gen_function_fld1<m80fp>("fpu_one80", RCX);
        gen_function_fld1<m64fp>("fpu_one64", RCX);
        gen_function_fld1<m32fp>("fpu_one32", RCX);
        gen_function_fldl2t<m80fp>("fpu_ld10_80", RCX);
        gen_function_fldl2t<m64fp>("fpu_ld10_64", RCX);
        gen_function_fldl2t<m32fp>("fpu_ld10_32", RCX);
        gen_function_fldl2e<m80fp>("fpu_ld_e_80", RCX);
        gen_function_fldl2e<m64fp>("fpu_ld_e_64", RCX);
        gen_function_fldl2e<m32fp>("fpu_ld_e_32", RCX);
        gen_function_fldlg2<m80fp>("fpu_lg2_80", RCX);
        gen_function_fldlg2<m64fp>("fpu_lg2_64", RCX);
        gen_function_fldlg2<m32fp>("fpu_lg2_32", RCX);
    }

    if (forLinux)
    {
        gen_function_fldpi<m80fp>("fpu_pi80", RDI);
        gen_function_fldpi<m64fp>("fpu_pi64", RDI);
        gen_function_fldpi<m32fp>("fpu_pi32", RDI);
        gen_function_fldz<m80fp>("fpu_zero80", RDI);
        gen_function_fldz<m64fp>("fpu_zero64", RDI);
        gen_function_fldz<m32fp>("fpu_zero32", RDI);
        gen_function_fld1<m80fp>("fpu_one80", RDI);
        gen_function_fld1<m64fp>("fpu_one64", RDI);
        gen_function_fld1<m32fp>("fpu_one32", RDI);
        gen_function_fldl2t<m80fp>("fpu_ld10_80", RDI);
        gen_function_fldl2t<m64fp>("fpu_ld10_64", RDI);
        gen_function_fldl2t<m32fp>("fpu_ld10_32", RDI);
        gen_function_fldl2e<m80fp>("fpu_ld_e_80", RDI);
        gen_function_fldl2e<m64fp>("fpu_ld_e_64", RDI);
        gen_function_fldl2e<m32fp>("fpu_ld_e_32", RDI);
        gen_function_fldlg2<m80fp>("fpu_lg2_80", RDI);
        gen_function_fldlg2<m64fp>("fpu_lg2_64", RDI);
        gen_function_fldlg2<m32fp>("fpu_lg2_32", RDI);
    }

    return EXIT_SUCCESS;
}
catch (...)
{
    std::cerr << "Error, exception" << std::endl;
    return EXIT_FAILURE;
}
