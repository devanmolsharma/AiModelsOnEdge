#include "linearFunctions.h"

struct RNNConfig
{
    int input_size;
    struct Tensor *weightsForInput;
    struct Tensor *weightsForHidden;
    struct Tensor *weightsForOutput;
    double *biases;
};