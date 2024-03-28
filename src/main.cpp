#include <Arduino.h>
#include "helpers.c"


int shape1[5] = {1,1};
double data1[] = {1.0, 2.0, 3.0, 120.0};

// Create a new instance of Tensor
struct Tensor t = createTensor(shape1,sizeof(data1)/sizeof(float),data1);


int shape2[5] = {1,1};
double data2[] = {1.0, 2.0, 3.0, 120.0};

// Create a new instance of Tensor
struct Tensor t2 = createTensor(shape2,sizeof(data2)/sizeof(float),data2);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  sum(t2,&t);
  Serial.printf("%2f\n",t.data[0]);
  delay(6e4);
}
