# Fitting and parameter estimation
Welcome to the exercises of the **Fitting and parameter estimation** learning module!

## Your First fit with ROOT
The macro **firstFit.C** is only half-way complete. In the code a fit of a histogram is performed
and the parameters of the fitted model are inspected.
Try to complete the code putting to a good use what you learned during the lectures.
The solution is available in the [firstFit_Solution.C](firstFit_Solution.C) macro.

## Correlation of Parameters
The **correlatedParameters.C** is a simple macro which fits an exponential to a histogram. It seems that there is a problem. While the fit parameters look ok, the correlation matrix shows something fishy. Can you say what is going wrong and why?

## Likelihood and Chi-Square estimators
Run the macro **fitPanel.C** with this command
```
root -l fitPanel.C
```
This leaves open a window with a histogram drawn. The entries are distributed according to a Gauss but the bins are narrow and the number of entries low. Right click on the histogram line (or with two fingers if you have a mac). Select *FitPanel* to open a fit panel. Now fit the histogram selecting the Chi-Square and Likelihood estimators.
What changes to the parameter values? And to their uncertainties?

## Example of fitting an histogram with a Gaussian function

This notebook shows how to fit an histogram using ROOT with a simple function such as a Gaussian. We show how to use the default chi-square method and the binned likelihood method for fitting histograms. We show also how to plot the fit residual using the TRatioPlot and to compute the chi2 for a goodness of fit test.
The notebook is avaliable [here](GausFit.ipynb) ([Open in Swan](https://cern.ch/swanserver/cgi-bin/go?projurl=https://raw.githubusercontent.com/root-project/training/master/SummerStudentCourse/2022/Exercises/Fitting/GausFit.ipynb)).

## Example of fitting in Python

This notebook shows how to fit an histogram in Python (using PYROOT) with a user defined function that is implemented in C++ for better CPU efficiency.

The notebook is avaliable [here](FittingExample.ipynb) ([Open in Swan](https://cern.ch/swanserver/cgi-bin/go?projurl=https://raw.githubusercontent.com/root-project/training/master/SummerStudentCourse/2022/Exercises/Fitting/FittingExample.ipynb)).
