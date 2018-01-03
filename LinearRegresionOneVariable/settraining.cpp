#include "settraining.h"
#include <fstream>

SetTraining::SetTraining(){}
SetTraining::SetTraining(int numFeatures){
    numberFeatures = numFeatures;
    outputs = vector<double>(0);
    inputs = matrix<double>(0,0);
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
        inputs.resize(numLine,numberFeatures + 1);
        outputs.resize(numLine);
        std::istringstream iss(line);
        inputs(numLine - 1 , 0) = 1;
        for(int i = 1; i <= numberFeatures; i++){
            iss >> inputs(numLine - 1 , i);
        }
        iss >> outputs(numLine - 1);

        numLine++;
    }
    //std::cout << inputs << std::endl;
}
