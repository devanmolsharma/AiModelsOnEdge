#include "helpers.h"

struct LinearConfig
{
    int input_size;
    int output_size;
    struct Tensor *weights;
    double *biases;
};