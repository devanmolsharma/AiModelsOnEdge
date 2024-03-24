struct Tensor
{
    int shape[5];
    int size;
    float *data;
};

struct Tensor createTensor(int shape[5], int size, float *data)
{
    struct Tensor t;
    for (int i = 0; i < 5; i++)
    {
        t.shape[i] = shape[i];
    }

    t.data = (float*)malloc(size * (sizeof(float)));
    for (int i = 0; i < size; i++)
    {
        t.data[i] = data[i];
    }
    
    t.size = size;

    return t;
}


struct Tensor setTensor(struct Tensor t,int shape[5], int size, float *data)
{
    for (int i = 0; i < 5; i++)
    {
        t.shape[i] = shape[i];
    }

    for (int i = 0; i < size; i++)
    {
        t.data[i] = data[i];
    }
    
    t.size = size;

    return t;
}

void add(struct Tensor t1, struct Tensor t2, struct Tensor out)
{

    float arr3[t1.size];

    for (int i = 0; i < t1.size; i++)
    {
        arr3[i] = t1.data[i] + t2.data[i];
    }

    setTensor(out,t1.shape, t1.size, arr3);
};

struct Tensor multiply(struct Tensor t1, struct Tensor t2)
{

    float arr3[t1.size];

    for (int i = 0; i < t1.size; i++)
    {
        arr3[i] = (t1.data)[i] * (t2.data)[i];
    }

    return createTensor(t1.shape, t1.size, arr3);
};

struct Tensor divide_tensors(struct Tensor t1, struct Tensor t2)
{

    float arr3[t1.size];

    for (int i = 0; i < t1.size; i++)
    {
        arr3[i] = (t1.data)[i] / (t2.data)[i];
    }

    return createTensor(t1.shape, t1.size, arr3);
};

struct Tensor subtract(struct Tensor t1, struct Tensor t2)
{

    float arr3[t1.size];

    for (int i = 0; i < t1.size; i++)
    {
        arr3[i] = (t1.data)[i] - (t2.data)[i];
    }

    return createTensor(t1.shape, t1.size, arr3);
};
