#include <QCoreApplication>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    using namespace boost::numeric::ublas;

    vector<double> v(3);
    for(unsigned i = 0; i < v.size(); i++)
        v(i) = i;

    std::cout << v << std::endl;
    return a.exec();
}
