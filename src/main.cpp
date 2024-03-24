#include <Arduino.h>
#include "tensor.c"
int shape1[5] = {2, 3, 4, 5, 6};
float data1[] = {1.0, 2.0, 3.0, 120.0};

// Create a new instance of Tensor
struct Tensor t = createTensor(shape1,sizeof(data1)/sizeof(float),data1);


int shape2[5] = {2, 3, 4, 5, 6};
float data2[] = {1.0, 2.0, 3.0, 120.0};

// Create a new instance of Tensor
struct Tensor t2 = createTensor(shape2,sizeof(data2)/sizeof(float),data2);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  add(t,t2,&t);
  Serial.printf("%2f %2f %2f %2f\n",t.data[0],t.data[1],t.data[2],t.data[3]);
  delay(20000);
}
