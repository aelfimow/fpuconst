#ifdef FPUCONST_ZERO_H
#error Already included
#else
#define FPUCONST_ZERO_H

extern "C" void fpu_zero80(void *p);
extern "C" void fpu_zero64(void *p);
extern "C" void fpu_zero32(void *p);

template <typename T> class fpuconst_zero
{
    public:
        operator T()
        {
            long double value;
            fpu_zero80(&value);

            return static_cast<T>(value);
        }
};

template <> class fpuconst_zero<long double>
{
    public:
        operator long double()
        {
            long double value;
            fpu_zero80(&value);

            return value;
        }
};

template <> class fpuconst_zero<double>
{
    public:
        operator double()
        {
            double value;
            fpu_zero64(&value);

            return value;
        }
};

template <> class fpuconst_zero<float>
{
    public:
        operator float()
        {
            float value;
            fpu_zero32(&value);

            return value;
        }
};

#endif
