#include "hypothesis.h"
#include <math.h>
#include <boost/numeric/ublas/matrix_proxy.hpp>
Hypothesis::Hypothesis()
{

}
void Hypothesis::setThetas(vector<double> thetas){
    this->thetas = thetas;
}
vector<double> Hypothesis::calculate(matrix<double> features){
    vector<double> result = prod(features, thetas);
    return result;
}
