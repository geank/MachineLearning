#ifndef COSTFUNCTION_H
#define COSTFUNCTION_H

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>

using namespace boost::numeric::ublas;
class CostFunction
{
private:
    vector<double> logarithm(vector<double> input);
public:
    CostFunction();
    double calculate(vector<double> hypothesis, vector<double> outputs);
};

#endif // COSTFUNCTION_H
