#ifdef FPUCONST_LG2_H
#error Already included
#else
#define FPUCONST_LG2_H

extern "C" void fpu_lg2_80(void *p);
extern "C" void fpu_lg2_64(void *p);
extern "C" void fpu_lg2_32(void *p);

template <typename T> class fpuconst_lg2
{
    public:
        operator T()
        {
            long double value;
            fpu_lg2_80(&value);

            return static_cast<T>(value);
        }
};

template <> class fpuconst_lg2<long double>
{
    public:
        operator long double()
        {
            long double value;
            fpu_lg2_80(&value);

            return value;
        }
};

template <> class fpuconst_lg2<double>
{
    public:
        operator double()
        {
            double value;
            fpu_lg2_64(&value);

            return value;
        }
};

template <> class fpuconst_lg2<float>
{
    public:
        operator float()
        {
            float value;
            fpu_lg2_32(&value);

            return value;
        }
};

#endif
