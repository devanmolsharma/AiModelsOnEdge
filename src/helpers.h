#include "tensor.c"

struct Tensor createTensor(int shape[5]);

struct Tensor createTensorFromValues(double * values,int size);

void setTensor(struct Tensor *t, int shape[5], int size, double *data);

void add(struct Tensor t1, struct Tensor t2, struct Tensor *out);

void multiply(struct Tensor t1, struct Tensor t2, struct Tensor *out);

void divide_tensors(struct Tensor t1, struct Tensor t2, struct Tensor *out);

void subtract(struct Tensor t1, struct Tensor t2, struct Tensor *out);

void softmax(struct Tensor t1, struct Tensor *out);

void sigmoid(struct Tensor t1, struct Tensor *out);

void relu(struct Tensor t1, struct Tensor *out);

void sumAll(struct Tensor t1, struct Tensor *out);

void destroy(struct Tensor t);

void add_number(struct Tensor t1, double t2, struct Tensor *out);

void multiply_number(struct Tensor t1, double t2, struct Tensor *out);

void divide_number(struct Tensor t1, double t2, struct Tensor *out);

void subtract_number(struct Tensor t1, double t2, struct Tensor *out);