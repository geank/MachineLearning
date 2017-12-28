#ifndef HYPOTHESIS_H
#define HYPOTHESIS_H

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>

using namespace boost::numeric::ublas;

class Hypothesis
{
private:
    vector<double> thetas;
public:
    Hypothesis();
    vector<double> calculate(matrix<double> features);
    void setThetas(vector<double> thetas);
};

#endif // HYPOTHESIS_H
