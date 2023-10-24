#ifndef NEURON_H
#define NEURON_H
#include "config.h"
#include <assert.h>
#include <stdlib.h>
class Neuron {
    private:
        static int input_width;
        int id;
        float (*activate_function) (float in);    // function pointer of the activation function
        //parameters
        vector<float> weights;
        float bias;
        //dataflow
        vector<float> input;
        float output;
        //delta
        vector<float> local_gradients;
        

    public:
        Neuron(int i_w, float (*a_f) (float in),int id);
        float get_output();
        void forward_prop();
        void backward_prop();
        void set_input(vector<float> in);
        void set_bias(float b);

};

#endif