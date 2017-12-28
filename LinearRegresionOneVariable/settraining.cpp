#include "settraining.h"
#include <fstream>

SetTraining::SetTraining(int numFeatures){
    numberFeatures = numFeatures;
    outputs = vector<double>(0);
    inputs = matrix<double>(0,numFeatures);
}
SetTraining::SetTraining(int numFeatures, int m)
{
    numberFeatures = numFeatures;
    outputs = vector<double>(m);
    inputs = matrix<double>(numFeatures,m);
}

matrix<double> SetTraining::getInputs(){
    return inputs;
}
vector<double> SetTraining::getOutputs(){
    return outputs;
}
void SetTraining::loadData(std::string nameFile){
    std::ifstream infile(nameFile);
    std::string line;
    int numLine = 1;
    while(std::getline(infile,line)){
        inputs.resize(numLine,numberFeatures);
        outputs.resize(numLine);
        std::istringstream iss(line);
        for(int i = 0; i < numberFeatures; i++){
            iss >> inputs(numLine - 1 , i);
        }
        iss >> outputs(numLine - 1);

        numLine++;
    }
    std::cout << outputs << std::endl;
}
