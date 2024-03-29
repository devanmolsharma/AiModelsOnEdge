#include "linear.cpp"

void forward(struct LinearConfig config, struct Tensor inputs, struct Tensor *out)
{

    for (int i = 0; i < config.output_size; i++)
    {
        struct Tensor temp = createTensorFromShape(inputs.shape);
        struct Tensor layerWeights = config.weights[i];
        double layerBias = config.biases[i];

        multiply(layerWeights, inputs, &temp);
        sumAll(temp, &temp);
        out->data[i] = temp.data[0] + layerBias;
        destroy(temp);
    }
}
