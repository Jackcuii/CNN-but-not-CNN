#include <vector>
#include "config.h"
#include "neuron.h"
#include <stdlib.h>
#include <cmath>
using namespace std;

Neuron::Neuron(int i_w, float (*a_f) (float in),int id){
    input_width = i_w;
    activate_function = a_f;
    assert(0<=id && id<i_w);
    this->id = id;
    for (int i = 0; i < input_width; i++){
        weights.push_back(rand()%100/10000.0); // Set the initial weights to a smll value
    }
}

float Neuron::get_output(){
    return output;
}
void Neuron::forward_prop(){
    float sum = 0.0;
    for (int i = 0; i < input_width; i++){
        sum += weights[i]*input[i];
    }
    sum += bias;
    output = activate_function(sum);
}
void Neuron::backward_prop(){

}
void Neuron::set_input(vector<float> in){
    input = in;                           // caution : in STL vector this is deep copy
}
void Neuron::set_bias(float b){
    bias = b;
}