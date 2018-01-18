#ifndef GRADIENTDESCENT_H
#define GRADIENTDESCENT_H

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <string>
#include <vector>

#include "settraining.h"
#include "costfunction.h"
#include "hypothesis.h"
using namespace boost::numeric::ublas;
class GradientDescent
{
private:
    double ratio;
    vector<double> thetas;
    vector<vector<double> > thethasMultiClass;
    void initializeThetas();
    SetTraining setTraining;
    CostFunction costFunction;
    Hypothesis hypothesis;
    vector<double> calculateTheta();
    vector<double> getOutput(std::string label);
public:
    GradientDescent(double ratio, SetTraining &setTraining);
    vector<double> calculate(std::string label);
    vector<double> calculate();
    vector<vector<double> > calculateMultiClass();
    double predict(vector<double> t, vector<double> data);
};

#endif // GRADIENTDESCENT_H
