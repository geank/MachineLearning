#include <QCoreApplication>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>
#include <boost/numeric/ublas/io.hpp>
#include "settraining.h"
#include "gradientdescent.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    using namespace boost::numeric::ublas;

    SetTraining st = SetTraining(2);
    st.loadData("data4.dat",true);

    GradientDescent gd(0.001,st);
    //vector<double> theta = gd.calculate();
    vector<double> theta(3);
    theta(0) =  1.7184;
    theta(1) = 4.01279;
    theta(2) =  3.7438;
    std::cout << "Theta : " << theta << std::endl;//-20.7713, 0.171145, 0.165937 // with scaling 1.7184, 4.01279,3.7438
    vector<double> input(3);


    input(0) = 1;
    input(1) = 74;
    input(2) = 84;

    double pred = gd.predict(theta,input);
    std::cout << pred << std::endl;
    if(pred >= 0.5)
        std::cout << "Predict to : " << input << "is: " << 1 << std::endl;
    else
        std::cout << "Predict to : " << input << "is: " << 0 << std::endl;

    /*vector<vector<double> > result = gd.calculateMultiClass();
    Hypothesis hyp;
    for(unsigned i = 0; i < result.size(); i++){
        vector<double> features(3);
        features(0) = 1;
        features(1) = 30.28671076822607;
        features(2) = 43.89499752400101;

        double prob = hyp.obtainClass(features,result(i));

        std::cout<< "result " << i << ": " << prob << std::endl;
    }*/
    return a.exec();
}
