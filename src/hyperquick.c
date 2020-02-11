/*Modified from a C++ implementation at https://github.com/CarloNicolini/Hyperquick*/
#include "hyperquick.h"

double InvJm(int n,int x,int N, int m)
{
    //return (1.0-double(x)/(double(m)+1.0))/(1.0-(double(n)-1.0-double(x))/(double(N)-1.0-double(m)));
    return ( 1.0 - (0.0+x) / (1.0 + m) ) / (1.0-(n-x-1.0)/(N-m-1.0) );
}
//Given N balls, M of which are black and the rest are white, what is the probability that out of n balls selected uniformly at random without replacement, at most x are black
void hyperquick(int *n, int *x, int *N, int *M, double *p)
{
    double s=1.0;
    for (int k = *x; k <= *M - 2; ++k)
    {
        s = s*InvJm(*n, *x, *N, k)+1.0;
    }
    double ak=s;
    double bk=s;
    int k = (*M) - 2;
    double epsk = 2*TOL;
    while ( ( k < (*N - (*n - *x) - 1) ) && epsk > TOL )
    {
        double ck = ak / bk;
        k = k + 1;
        double jjm = InvJm( *n, *x, *N, k);
        bk = bk * jjm + 1.0;
        ak = ak * jjm;
        epsk = ( *N - (*n - *x) - 1 - k)*(ck - ak / bk);
    }
    *p = 1 -(ak / bk - epsk / 2);
    return;
}
