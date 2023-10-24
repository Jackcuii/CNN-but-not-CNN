#ifndef GLOBAL_H
#define GLOBAL_H
#include <vector>
struct Classifier
{
    float (*origin) (std::vector<float> in,int id);
    float (*derivative) (std::vector<float> in, int id); 
};

float ReLU(float in);
float softmax(std::vector<float> in,int id);
float softmax_derivative(std::vector<float> in, int id);


#endif