#include <Arduino.h>
#include "tokeniser.h"

// Tensor weights[] = {
//     createTensorFromValues(new double[4]{1, 2, 3, 4}, 4),
//     createTensorFromValues(new double[4]{1, 2, 3, 4}, 4),
//     createTensorFromValues(new double[4]{1, 2, 3, 4}, 4),
//     createTensorFromValues(new double[4]{1, 2, 3, 4}, 4),
//     createTensorFromValues(new double[4]{1, 2, 3, 4}, 4),
//     createTensorFromValues(new double[4]{1, 2, 3, 4}, 4),
//     createTensorFromValues(new double[4]{1, 2, 3, 4}, 4),
//     createTensorFromValues(new double[4]{1, 2, 3, 4}, 4),
//     createTensorFromValues(new double[4]{1, 2, 3, 4}, 4),
//     createTensorFromValues(new double[4]{1, 2, 3, 4}, 4),
// };

// LinearConfig config = {
//     1,
//     10,
//     weights,
//     new double[10]{0, 1.0, 2, 3, 4, 5, 6, 7, 8, 9},
// };

// Tensor out = createTensorFromShape(new int[5]{
//     10,
// });
// Tensor inp = createTensorFromValues(new double[4]{1, 2, 3, 4}, 4);
char i0[] = "cat";
char i1[] = "dog";
char i2[] = "david";
char i3[] = "coffee";
char i4[] = "car";


TokenPair pairs[] = {
    {0, 4, i0},
    {1, 4, i1},
    {2, 6, i2},
    {3, 7, i3},
    {4, 4, i4},
};

TokeniserConfig config = {
    5,
    pairs};

Tensor out = createTensorFromShape(new int[5]{1});

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  // forward(config, inp, &out);
  // softmax(out, &out);
  char inp[] = "coffee david";
  tokenise(config, inp, 10, &out);
  Serial.printf("Hi [ %2f, %2f]\n", out.data[0],out.data[1]);
  delay(1000);
}
