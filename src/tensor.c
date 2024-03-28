#include <stdlib.h>
#include <math.h>

struct Tensor
{
    int shape[5];
    int size;
    double *data;
};

