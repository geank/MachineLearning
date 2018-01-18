#include "costfunction.h"
#include <math.h>
CostFunction::CostFunction()
{

}
vector<double> CostFunction::logarithm(vector<double> input){
    vector<double> result(input.size());
    for(unsigned i = 0 ; i < input.size(); i++){
        result(i) =  log(input(i));
    }
    return result;
}
double CostFunction::calculate(vector<double> hypothesis, vector<double> outputs){
    scalar_vector<double> ones(outputs.size());

    double size = -1.0 / (hypothesis.size());
    double prod = inner_prod(outputs, logarithm(hypothesis)) + inner_prod(ones - outputs,logarithm(ones - hypothesis));
    return prod * size;
}

