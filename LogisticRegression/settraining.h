#ifndef SETTRAINING_H
#define SETTRAINING_H

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <string>
#include <vector>
#include <map>
using namespace boost::numeric::ublas;
class SetTraining
{
private:
    int numberFeatures;
    matrix<double> inputs;
    vector<double> outputs;
    std::map<int, std::map<double,double> > scalingVariables;
    //
    std::vector<std::string> labels;
    std::vector<std::string > inputsLabel;
    //
    void scalingFeatures();
    double range(vector<double> f);
    double standarDesviation(vector<double> f, double mean);
    //
    void insertLabel(std::string label);
public:
    SetTraining();
    SetTraining(int numFeatures);
    SetTraining(int numFeatures, int m);
    matrix<double> getInputs();
    vector<double> getOutputs();

    void setOutput(vector<double> output);
    std::vector<std::string> getLabels();
    std::vector<std::string> getInputLabels();

    vector<double> scalingInput(vector<double> input);

    void loadData(std::string nameFile, bool scaling = false);
};

#endif // SETTRAINING_H
