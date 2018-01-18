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
    st.loadData("test2.data",true);
    GradientDescent gd(0.01,st);
    vector<double> thetas = gd.calculate();
    std::cout << thetas << std::endl;
    return a.exec();
}
