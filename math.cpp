#include <cmath>
#include <math.h>
void normalise(double* x, double* y){
	double mag = (double)sqrt((*x)*(*x) + (*y)*(*y));
	*x = (*x)/mag;
	*y = (*y)/mag;
}