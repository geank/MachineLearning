#include "costfunction.h"

CostFunction::CostFunction()
{

}
double CostFunction::calculate(vector<double> hypothesis, vector<double> outputs){
    double size = 1.0 / (2 * hypothesis.size());
    vector<double> difference = hypothesis - outputs;
    double prod = inner_prod(difference,difference);
    return prod * size;
}

