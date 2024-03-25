#include <stdlib.h>
#include <math.h>
struct Tensor
{
    int shape[5];
    int size;
    double *data;
};

struct Tensor createTensor(int shape[5], int size, double *data)
{
    struct Tensor t;

    int total_size = 0;

    for (int i = 0; i < 5; i++)
    {
        int s = shape[i];
        t.shape[i] = s;
        if (s != 0)
        {
            total_size *= s;
        }
    }

    if (total_size != size)
    {
        // Handle this somehow
    }

    t.data = (double *)malloc(size * (sizeof(double)));
    for (int i = 0; i < size; i++)
    {
        t.data[i] = data[i];
    }

    t.size = size;

    return t;
}

void setTensor(struct Tensor *t, int shape[5], int size, double *data)
{
    for (int i = 0; i < 5; i++)
    {
        t->shape[i] = shape[i];
    }

    for (int i = 0; i < size; i++)
    {
        t->data[i] = data[i];
    }

    t->size = size;
}

void add(struct Tensor t1, struct Tensor t2, struct Tensor *out)
{

    double arr3[t1.size];

    for (int i = 0; i < t1.size; i++)
    {
        arr3[i] = t1.data[i] + t2.data[i];
    }

    setTensor(out, t1.shape, t1.size, arr3);
};

void multiply(struct Tensor t1, struct Tensor t2, struct Tensor *out)
{

    double arr3[t1.size];

    for (int i = 0; i < t1.size; i++)
    {
        arr3[i] = (t1.data)[i] * (t2.data)[i];
    }

    setTensor(out, t1.shape, t1.size, arr3);
};

void divide_tensors(struct Tensor t1, struct Tensor t2, struct Tensor *out)
{

    double arr3[t1.size];

    for (int i = 0; i < t1.size; i++)
    {
        arr3[i] = (t1.data)[i] / (t2.data)[i];
    }

    setTensor(out, t1.shape, t1.size, arr3);
};

void subtract(struct Tensor t1, struct Tensor t2, struct Tensor *out)
{

    double arr3[t1.size];

    for (int i = 0; i < t1.size; i++)
    {
        arr3[i] = (t1.data)[i] - (t2.data)[i];
    }

    setTensor(out, t1.shape, t1.size, arr3);
};

void softmax(struct Tensor t1, struct Tensor *out)
{

    double arr3[t1.size];
    double sum = 0;
    const double E = 2.71828;

    for (int i = 0; i < t1.size; i++)
    {
        double e_x = pow(E, (t1.data)[i] * -1);
        arr3[i] = e_x;
        sum += e_x;
    }

    for (int i = 0; i < t1.size; i++)
    {
        arr3[i] /= sum;
    }

    setTensor(out, t1.shape, t1.size, arr3);
};

void sigmoid(struct Tensor t1, struct Tensor *out)
{

    double arr3[t1.size];
    const double E = 2.71828;

    for (int i = 0; i < t1.size; i++)
    {
        double e_x_plus_one = 1 + pow(E, (t1.data)[i] * -1);
        arr3[i] = ((double)1) / e_x_plus_one;
    }

    setTensor(out, t1.shape, t1.size, arr3);
};

void destroy(struct Tensor t)
{
    free(t.data);
}

void add_number(struct Tensor t1, double t2, struct Tensor *out)
{

    double arr3[t1.size];

    for (int i = 0; i < t1.size; i++)
    {
        arr3[i] = t1.data[i] + t2;
    }

    setTensor(out, t1.shape, t1.size, arr3);
};

void multiply_number(struct Tensor t1, double t2, struct Tensor *out)
{

    double arr3[t1.size];

    for (int i = 0; i < t1.size; i++)
    {
        arr3[i] = (t1.data)[i] * t2;
    }

    setTensor(out, t1.shape, t1.size, arr3);
};

void divide_number(struct Tensor t1, double t2, struct Tensor *out)
{

    double arr3[t1.size];

    for (int i = 0; i < t1.size; i++)
    {
        arr3[i] = (t1.data)[i] / t2;
    }

    setTensor(out, t1.shape, t1.size, arr3);
};

void subtract_number(struct Tensor t1, double t2, struct Tensor *out)
{

    double arr3[t1.size];

    for (int i = 0; i < t1.size; i++)
    {
        arr3[i] = (t1.data)[i] - t2;
    }

    setTensor(out, t1.shape, t1.size, arr3);
};