#ifdef FPUCONST_PI_H
#error Already included
#else
#define FPUCONST_PI_H

extern "C" void fpu_pi80(void *p);
extern "C" void fpu_pi64(void *p);
extern "C" void fpu_pi32(void *p);

extern "C" void fpu_zero80(void *p);
extern "C" void fpu_zero64(void *p);
extern "C" void fpu_zero32(void *p);

template <typename T> class fpuconst_pi
{
    public:
        operator T()
        {
            long double value;
            fpu_pi80(&value);

            return static_cast<T>(value);
        }
};

template <> class fpuconst_pi<long double>
{
    public:
        operator long double()
        {
            long double value;
            fpu_pi80(&value);

            return value;
        }
};

template <> class fpuconst_pi<double>
{
    public:
        operator double()
        {
            double value;
            fpu_pi64(&value);

            return value;
        }
};

template <> class fpuconst_pi<float>
{
    public:
        operator float()
        {
            float value;
            fpu_pi32(&value);

            return value;
        }
};

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
