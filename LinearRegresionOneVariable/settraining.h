#ifndef SETTRAINING_H
#define SETTRAINING_H

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <string>
using namespace boost::numeric::ublas;
class SetTraining
{
private:
    int numberFeatures;
    matrix<double> inputs;
    vector<double> outputs;
public:
    SetTraining(int numFeatures);
    SetTraining(int numFeatures, int m);
    matrix<double> getInputs();
    vector<double> getOutputs();
    void loadData(std::string nameFile);
};

#endif // SETTRAINING_H
