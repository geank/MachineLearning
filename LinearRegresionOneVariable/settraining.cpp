#include "settraining.h"
#include <fstream>
#include <boost/numeric/ublas/matrix_proxy.hpp>
#include <algorithm>

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
void SetTraining::loadData(std::string nameFile, bool scaling){
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
    if(scaling == true)
        scalingFeatures();
    //std::cout << inputs << std::endl;
}
void SetTraining::scalingFeatures(){
    for(unsigned j = 1; j < inputs.size2(); j ++){
        matrix_column<matrix<double> > mc(inputs,j);
        vector<double> col = mc;
        double mu = (double) (sum(col)/col.size());
        //double r = standarDesviation(col,mu);
        double r = range(col);

        for(unsigned i = 0; i < inputs.size1(); i++){
            inputs(i,j) = (inputs(i,j) - mu) / r;
        }
    }

}
double SetTraining::range(vector<double> f){
    auto result  = std::minmax_element(f.data().begin(),f.data().end());
    return (*result.second - *result.first);
}
double SetTraining::standarDesviation(vector<double> f, double mu){
    scalar_vector<double> sv(f.size());
    vector<double> muv = f - (sv * mu);
    return sqrt((1.0/(f.size() - 1.0))*inner_prod(muv,muv));
}
