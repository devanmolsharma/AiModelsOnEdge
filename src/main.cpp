#include <Arduino.h>
#include "linearFunctions.h"

Tensor weights[] = {
    createTensorFromValues(new double[1]{1}, 1),
};

struct LinearConfig config = {
    1,
    1,
    weights,
    new double[1]{0}};


Tensor out = createTensor(new int[5]{1});
Tensor inp = createTensor(new int[5]{1});

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  forward(config,inp,&out);
  Serial.printf("%2f\n",out.data[0]);
  delay(6e5);
}
