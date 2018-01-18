#include "gradientdescent.h"
#include <boost/numeric/ublas/matrix_proxy.hpp>
#include <iostream>
#include <fstream>
GradientDescent::GradientDescent(double ratio, SetTraining &setTraining)
{
    this->ratio = ratio;
    this->setTraining = setTraining;
    this->thethasMultiClass = vector<vector<double> > (setTraining.getLabels().size());
    initializeThetas();
}
void GradientDescent::initializeThetas(){
    zero_vector<double> scalar(setTraining.getInputs().size2());
    thetas = scalar;
    //
    /*thetas = vector<double>(setTraining.getInputs().size2());
    thetas(0) = -24;
    thetas(1) = 0.2;
    thetas(2) = 0.2;*/
}
vector<double> GradientDescent::calculateTheta(){
    hypothesis.setThetas(thetas);
    matrix<double> x = setTraining.getInputs();
    vector<double> h = hypothesis.calculate(x);
    vector <double> y = setTraining.getOutputs();
    int m = y.size();
    vector<double> result(thetas.size());
    for(unsigned i = 0; i < thetas.size(); i++){
        matrix_column<matrix<double> > mc(x,i);
        vector <double> xi = mc;
        result(i) =  thetas(i) - (ratio  * 1.0/m * inner_prod(h-y,xi));
    }
    return result;
}
std::ofstream myfile;

vector<double> GradientDescent::calculate(std::string label){
    /*hypothesis.setThetas(thetas);
    vector<double>  hh = hypothesis.calculate(setTraining.getInputs());
    double j = costFunction.calculate(hh,setTraining.getOutputs());;*/

    initializeThetas();
    double j = 0;
    int i = 0;
    while (i < 500){
        thetas = calculateTheta();
        hypothesis.setThetas(thetas);
        vector<double>  h = hypothesis.calculate(setTraining.getInputs());
        j = costFunction.calculate(h,setTraining.getOutputs());
        //std::cout << label << ": " << j<< std::endl;
        myfile << label << ": " << j<< std::endl;
        i++;
    }

    return thetas;
}
vector<double> GradientDescent::calculate(){

    //initializeThetas();

    double j = 0;
    int i = 0;
    hypothesis.setThetas(thetas);

    vector<double>  h = hypothesis.calculate(setTraining.getInputs());
    j = costFunction.calculate(h,setTraining.getOutputs());

    std::cout << "J" << ": " << j << std::endl;
    while (i < 2000000){
        thetas = calculateTheta();

        /*hypothesis.setThetas(thetas);

        vector<double>  h = hypothesis.calculate(setTraining.getInputs());
        j = costFunction.calculate(h,setTraining.getOutputs());*/

        std::cout << "Thetas" << ": " << thetas << std::endl;
        //std::cout << "J" << ": " << j << std::endl;
        i++;

    }
    //std::cout << label << ": " << j<< std::endl;
    return thetas;
}
vector<vector<double> > GradientDescent::calculateMultiClass(){
    myfile.open ("example.txt");
    std::vector<std::string> ll = setTraining.getLabels();
    for(unsigned i = 0; i < ll.size(); i++){
        vector<double> ou = getOutput(ll[i]);
        setTraining.setOutput(ou);
        vector<double> thetasmc= calculate(ll[i]);
        thethasMultiClass(i) = thetasmc;
    }
    std::cout << thethasMultiClass << std::endl;
    return thethasMultiClass;
}

vector<double> GradientDescent::getOutput(std::string label){
    std::vector<std::string> ll = setTraining.getInputLabels();
    vector<double> result(ll.size());
    for(unsigned i = 0; i < ll.size(); i++){
            result(i) = ll[i] == label ? 1.0 : 0.0;
    }
    return result;
}

double GradientDescent::predict(vector<double> t, vector<double> data){
    vector<double> input = setTraining.scalingInput(data);
    return hypothesis.obtainClass(data,input);
}
