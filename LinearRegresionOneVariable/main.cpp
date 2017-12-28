#include <QCoreApplication>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>
#include <boost/numeric/ublas/io.hpp>
#include "settraining.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    using namespace boost::numeric::ublas;

    matrix<double> m (3, 3);
    vector<double> v (3);
    for (unsigned i = 0; i < std::min (m.size1 (), v.size ()); ++ i) {
        for (unsigned j = 0; j < m.size2 (); ++ j)
            m (i, j) = 3 * i + j;
        v (i) = i;
    }

    std::cout << m << std::endl;
    std::cout << v << std::endl;
    std::cout << prod(m,v) <<std::endl;

    SetTraining st = SetTraining(8);
    st.loadData("concrete.data");
    return a.exec();
}
