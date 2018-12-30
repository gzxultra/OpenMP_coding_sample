#include <iostream>
#include "omp.h"

using namespace std;

static long num_steps = 10000000;
double step;
int main()
{
    int i;
    double x, pi, sum = 0.0;
    step = 1.0 / (double)num_steps;

#pragma omp parallel for reduction(+ \
                                   : sum)
    for (i = 0; i < num_steps; i++)
    {
        int ID = omp_get_thread_num();
        if (i % 100000 == 0) {
            cout << "ID " << ID << endl;
        }
        x = (i + 0.5) * step;
        sum = sum + 4.0 / (1.0 + x * x);
    }
    pi = step * sum;
    cout << "PI: " << pi << endl;
}


