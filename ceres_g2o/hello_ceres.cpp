#include<iostream>
#include<opencv2/core/core.hpp>
#include<ceres/ceres.h>

using namespace ceres;
using namespace std;


struct CostFunctor
{
    template<typename T>
    bool operator()(const T* const x,T* residual) const{
        residual[0] = 10.0-x[0];
        return true;
    }
};

int main(int argc, char const *argv[])
{
    double x = 0.5;
    const double init_x = x;

    //build
    ceres::Problem problem;

    ceres::CostFunction* cost_function = new ceres::AutoDiffCostFunction<CostFunctor,1,1>(new CostFunctor);
    problem.AddResidualBlock(cost_function,nullptr,&x);

    //run
    ceres::Solver::Options options;
    options.minimizer_progress_to_stdout = true;
    ceres::Solver::Summary summary;
    ceres::Solve(options,&problem,&summary);
    cout<<summary.BriefReport()<<endl;
    cout<<"x:"<<init_x<<"-->"<<x<<endl;
    return 0;
}


