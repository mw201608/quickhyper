#include <R.h>
#include <Rmath.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
const double TOL=1E-12;
double InvJm(int n,int x,int N, int m);
void hyperquick(int *n, int *x, int *N, int *M, double *p);
