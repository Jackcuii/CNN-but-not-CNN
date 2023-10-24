#include "layer.h"
#include "neuron.h"
#include <vector>
#include "global.h"
using namespace std;
class Layer {
    private:
        vector<Neuron> neurons;
        int neuron_sum;
        Classifier classifier;
        //dataflow
        vector<float> neuron_outputs;
        vector<float> loss;
        void pack();
        void calculate_loss(){
            
        }
        void forward_prop(){
            for (int i = 0; i < neuron_sum; i++){
                neurons[i].forward_prop();
            }
        }

    public:
        Layer(int neuron_sum, int input_width, Classifier classifier);
        void update();

};
Layer::Layer(int neuron_sum, int input_width, Classifier classifier){
    this->neuron_sum = neuron_sum;
    this->classifier = classifier;
    for (int i = 0; i < neuron_sum; i++){
        neurons.push_back(Neuron(input_width,ACTIVATION,i));
    }
}

void Layer::pack(){
    for (int i = 0; i < neuron_sum; i++){
        neuron_outputs.push_back(neurons[i].get_output());
    }
    return;
}

void Layer::calculate_loss(){
    for(int i = 0; i < neuron_sum; i++){
        loss.push_back(classifier.origin(neuron_outputs,i));
    }
}

void Layer::update(){
    for (int i = 0; i < neuron_sum; i++){
        neurons[i].backward_prop();
    }
    pack();
    calculate_loss();
}
