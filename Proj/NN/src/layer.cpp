#include "layer.h"
#include "neuron.h"
#include <vector>
using namespace std;
class Layer {
    private:
        vector<Neuron> neurons;
        int neuron_sum;
        void (*classifier) ();

    public:
        Layer(int neuron_sum, int input_width, void (*classifier) ()){
            this->neuron_sum = neuron_sum;
            this->classifier = classifier;
            for (int i = 0; i < neuron_sum; i++){
                neurons.push_back(Neuron(input_width,ACTIVATION,i));
            }
        }
        

};
