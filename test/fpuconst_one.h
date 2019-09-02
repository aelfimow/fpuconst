#ifdef FPUCONST_ONE_H
#error Already included
#else
#define FPUCONST_ONE_H

extern "C" void fpu_one80(void *p);
extern "C" void fpu_one64(void *p);
extern "C" void fpu_one32(void *p);

template <typename T> class fpuconst_one
{
    public:
        operator T()
        {
            long double value;
            fpu_one80(&value);

            return static_cast<T>(value);
        }
};

template <> class fpuconst_one<long double>
{
    public:
        operator long double()
        {
            long double value;
            fpu_one80(&value);

            return value;
        }
};

template <> class fpuconst_one<double>
{
    public:
        operator double()
        {
            double value;
            fpu_one64(&value);

            return value;
        }
};

template <> class fpuconst_one<float>
{
    public:
        operator float()
        {
            float value;
            fpu_one32(&value);

            return value;
        }
};

#endif
