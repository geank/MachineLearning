#include "gradientdescent.h"
#include <boost/numeric/ublas/matrix_proxy.hpp>
GradientDescent::GradientDescent(double ratio, SetTraining &setTraining)
{
    this->ratio = ratio;
    this->setTraining = setTraining;
    initializeThetas();
}
void GradientDescent::initializeThetas(){
    zero_vector<double> scalar(setTraining.getInputs().size2());
    thetas = scalar;
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
        result(i) = thetas(i) - ratio * (1.0/m) * inner_prod(h-y,xi);
    }
    return result;
}
vector<double> GradientDescent::calculate(){
    /*hypothesis.setThetas(thetas);
    vector<double>  hh = hypothesis.calculate(setTraining.getInputs());
    double j = costFunction.calculate(hh,setTraining.getOutputs());;*/
    double j = 0;
    int i = 0;
    while (i < 1500){
        thetas = calculateTheta();

        hypothesis.setThetas(thetas);
        vector<double>  h = hypothesis.calculate(setTraining.getInputs());
        j = costFunction.calculate(h,setTraining.getOutputs());

        i++;
    }

    return thetas;
}
