#include "hypothesis.h"
#include <math.h>
#include <boost/numeric/ublas/matrix_proxy.hpp>
Hypothesis::Hypothesis()
{

}
void Hypothesis::setThetas(vector<double> thetas){
    this->thetas = thetas;
}
double Hypothesis::sigmoide(double vt){
    return 1.0 / (1.0 + exp(-1.0 * vt));
}
vector<double> Hypothesis::calculate(matrix<double> features){
    vector<double> pr = prod(features, thetas);
    vector<double> result(pr.size());
    for(unsigned i = 0; i < pr.size(); i++){
        result(i) = sigmoide(pr(i));
    }
    return result;
}
double Hypothesis::obtainClass(vector<double> input, vector<double> theta){
    double result = inner_prod(input, theta);
    return sigmoide(result);
}
