#include <vector>
#include "config.h"
#include <stdlib.h>
#include <assert.h>
#include <cmath>
using namespace std;

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
        Neuron(int i_w, float (*a_f) (float in),int id){
            input_width = i_w;
            activate_function = a_f;
            assert(0<=id && id<i_w);
            this->id = id;
            for (int i = 0; i < input_width; i++){
                weights.push_back(rand()%100/10000.0); // Set the initial weights to a smll value
            }
        }
        float get_output(){
            return output;
        }
        void forward_prop(){
            float sum = 0.0;
            for (int i = 0; i < input_width; i++){
                sum += weights[i]*input[i];
            }
            sum += bias;
            output = activate_function(sum);
        }
        void backward_prop(){

        }
        void set_input(vector<float> in){
            input = in;                           // caution : in STL vector this is deep copy
        }
        void set_bias(float b){
            bias = b;
        }

};