#ifndef GRADIENTDESCENT_H
#define GRADIENTDESCENT_H

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>

#include "settraining.h"
#include "costfunction.h"
#include "hypothesis.h"
using namespace boost::numeric::ublas;
class GradientDescent
{
private:
    double ratio;
    vector<double> thetas;
    void initializeThetas();
    SetTraining setTraining;
    CostFunction costFunction;
    Hypothesis hypothesis;
    vector<double> calculateTheta();
public:
    GradientDescent(double ratio, SetTraining &setTraining);
    vector<double> calculate();
};

#endif // GRADIENTDESCENT_H
