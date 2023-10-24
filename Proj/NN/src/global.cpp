#include<config.h>
#include<global.h>
#include<cmath>
using namespace std;

float ReLU(float in){
    return (in>0.0)?in:0.0;
}

float softmax(vector<float> in,int id){
    float sum = 0.0;
    for (int i = 0; i < in.size(); i++){
        sum += exp(in[i]);
    }
    return exp(in[id])/sum;
}

float softmax_derivative(vector<float> in, int id){
    float sum = 0.0;
    for (int i = 0; i < in.size(); i++){
        sum += exp(in[i]);
    }
    return (exp(in[id])*sum-exp(in[id])*exp(in[id]))/(sum*sum);
}

Classifier Softmax = {softmax,softmax_derivative};
