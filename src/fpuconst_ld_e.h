#ifdef FPUCONST_LD_E_H
#error Already included
#else
#define FPUCONST_LD_E_H

extern "C" void fpu_ld_e_80(void *p);
extern "C" void fpu_ld_e_64(void *p);
extern "C" void fpu_ld_e_32(void *p);

template <typename T> class fpuconst_ld_e
{
    public:
        operator T()
        {
            long double value;
            fpu_ld_e_80(&value);

            return static_cast<T>(value);
        }
};

template <> class fpuconst_ld_e<long double>
{
    public:
        operator long double()
        {
            long double value;
            fpu_ld_e_80(&value);

            return value;
        }
};

template <> class fpuconst_ld_e<double>
{
    public:
        operator double()
        {
            double value;
            fpu_ld_e_64(&value);

            return value;
        }
};

template <> class fpuconst_ld_e<float>
{
    public:
        operator float()
        {
            float value;
            fpu_ld_e_32(&value);

            return value;
        }
};

#endif
