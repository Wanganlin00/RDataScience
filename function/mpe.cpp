#include <Rcpp.h>
using namespace Rcpp;



// [[Rcpp::export]]
double mpe(List mod) {
    if (!mod.inherits("lm")) stop("Input must be a linear model");
    
    NumericVector resid = as<NumericVector>(mod["residuals"]);
    NumericVector fitted = as<NumericVector>(mod["fitted.values"]);
    
    int n = resid.size();
    double err = 0;
    for(int i = 0; i < n; ++i) {
        err += resid[i] / (fitted[i] + resid[i]);
    }
    return err / n;
}




/*** R
model <- lm(mpg ~ wt, data = mtcars)
mpe(model)
*/
