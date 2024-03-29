#include <Arduino.h>
#include "linearFunctions.h"

Tensor weights[] = {
    createTensorFromValues(new double[4]{1, 2, 3, 4}, 4),
    createTensorFromValues(new double[4]{1, 2, 3, 4}, 4),
    createTensorFromValues(new double[4]{1, 2, 3, 4}, 4),
    createTensorFromValues(new double[4]{1, 2, 3, 4}, 4),
    createTensorFromValues(new double[4]{1, 2, 3, 4}, 4),
    createTensorFromValues(new double[4]{1, 2, 3, 4}, 4),
    createTensorFromValues(new double[4]{1, 2, 3, 4}, 4),
    createTensorFromValues(new double[4]{1, 2, 3, 4}, 4),
    createTensorFromValues(new double[4]{1, 2, 3, 4}, 4),
    createTensorFromValues(new double[4]{1, 2, 3, 4}, 4),
};

struct LinearConfig config = {
    1,
    10,
    weights,
    new double[10]{0, 1.0, 2, 3, 4, 5, 6, 7, 8, 9}};


Tensor out = createTensorFromShape(new int[5]{10,});
Tensor inp = createTensorFromValues(new double[4]{1,2,3,4},4);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  forward(config,inp,&out);
  Serial.printf("%2f, %2f, %2f, \n",out.data[0],out.data[1],out.data[2],out.data[3]);
  delay(6e5);
}
