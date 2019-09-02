#ifdef FPUCONST_LD10_H
#error Already included
#else
#define FPUCONST_LD10_H

extern "C" void fpu_ld10_80(void *p);
extern "C" void fpu_ld10_64(void *p);
extern "C" void fpu_ld10_32(void *p);

template <typename T> class fpuconst_ld10
{
    public:
        operator T()
        {
            long double value;
            fpu_ld10_80(&value);

            return static_cast<T>(value);
        }
};

template <> class fpuconst_ld10<long double>
{
    public:
        operator long double()
        {
            long double value;
            fpu_ld10_80(&value);

            return value;
        }
};

template <> class fpuconst_ld10<double>
{
    public:
        operator double()
        {
            double value;
            fpu_ld10_64(&value);

            return value;
        }
};

template <> class fpuconst_ld10<float>
{
    public:
        operator float()
        {
            float value;
            fpu_ld10_32(&value);

            return value;
        }
};

#endif
