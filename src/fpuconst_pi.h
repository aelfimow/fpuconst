#ifdef FPUCONST_PI_H
#error Already included
#else
#define FPUCONST_PI_H

extern "C" void fpu_pi(void *p);

template <typename T> class fpu_const_windows
{
    public:
        operator T()
        {
            long double value;
            fpu_pi(&value);

            return static_cast<T>(value);
        }
};

#endif
