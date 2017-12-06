# ROOTbooks
Welcome to the exercises of the **ROOTBooks** learning module!

## Introduction to notebooks and their integration with ROOT
In this exercise we'll explore the ROOT notebooks interface. Click on the link below.
A repository in Github will be cloned to your CERNBox and a SWAN session will be opened for you:

[![Open_in SWAN](https://img.shields.io/badge/Open_in-SWAN-orange.svg)](https://cern.ch/swanserver/cgi-bin/go/?projurl=https://github.com/cernphsft/rootbinder.git)

## Create a histogram
Create a histogram, fill it with gaussian random numbers, set its colour to blue, draw it: all in a Python notebook
 - Can you use the native Python random number generator for this?
 - Can you make your plot interactive using JSROOT?
 - Can you document what you did in markdown?
Repeat the exercise in a C++ notebook

## Create a graph
Recreate in a Python notebook the graph we built together during the lectures at the ROOT prompt.
Display it using JavaScript graphics (use the ```%jsroot on``` magic).
Remember that for embedding a canvas in the notebook it is necessary to draw the canvas explicitly:
```python
c = ROOT.TCanvas()
# Here drawing takes place
c.Draw() # only after this command the plot appears
```
This notebook is only half way complete. What is requested from you is to translate the interactive graph creation example we saw together during the lectures to complete it. Oh, the notebook is in Python and not C++ - some translation will be required!
- [Open the notebook in SWAN](https://cern.ch/swanserver/cgi-bin/go?projurl=https://raw.githubusercontent.com/root-project/training/master/BasicCourse/Exercises/ROOTBooks/graphDraw.ipynb)
- Only when the frustration is unbearable, [open the solution SWAN](https://cern.ch/swanserver/cgi-bin/go?projurl=https://raw.githubusercontent.com/root-project/training/master/BasicCourse/Exercises/ROOTBooks/graphDraw_Solution.ipynb)

## Revisited Fitting Exercise
We will now revisit the fitting exercise we carried out in the exercises of the PyROOT learning module. The objective is to demonstrate how a notebook allows to display all the intermediate steps of an analysis. You can fill the blank cells with the code we reviewed during the "Fitting and Parameters Estimation" learning module exercises.
In order to open the exercise notebook in SWAN, just follow the first link.
- [Open the notebook in SWAN](https://cern.ch/swanserver/cgi-bin/go?projurl=https://raw.githubusercontent.com/root-project/training/master/BasicCourse/Exercises/ROOTBooks/FittingExample.ipynb)
- Only when the frustration is unbearable, [open the solution SWAN](https://cern.ch/swanserver/cgi-bin/go?projurl=https://raw.githubusercontent.com/root-project/training/master/BasicCourse/Exercises/ROOTBooks/FittingExample_Solution.ipynb)

## Central Limit Theorem
This notebook shows numerically the validity of the [Central Limit Theorem](https://en.wikipedia.org/wiki/Central_limit_theorem). As usual, we propose an exercise notebook and its
solution:
- [Open the notebook in SWAN](https://cern.ch/swanserver/cgi-bin/go?projurl=https://raw.githubusercontent.com/root-project/training/master/BasicCourse/Exercises/ROOTBooks/CentralLimitTheorem.ipynb)
- Really if you do not manage to finish, [open the solution SWAN](https://cern.ch/swanserver/cgi-bin/go?projurl=https://raw.githubusercontent.com/root-project/training/master/BasicCourse/Exercises/ROOTBooks/CentralLimitTheorem_Solution.ipynb)

## Fit the Invariant Mass Spectrum of a di-photon system resulting from a Higgs boson decay
This exercise shows how the fit of a simplified mass spectrum can be carried out. We'll see how the presence of a bump which can be spot without any statistical procedure can be quantified. Just [open the notebook in SWAN](https://cern.ch/swanserver/cgi-bin/go?projurl=https://raw.githubusercontent.com/root-project/training/master/BasicCourse/Exercises/ROOTBooks/HiggsBinFit.ipynb). Make sure to upload the **Hgg.txt** input file in SWAN too (you can use the *upload* button on the Jupyter interface).

## Advanced Fitting
Congratulations: it seems you completed quite a lot of exercises during this session! This notebook is a bit more challenging than the previous ones: it's about advanced fitting and bias estimation via toy Monte Carlo techniques.
- [Open the notebook in SWAN](https://cern.ch/swanserver/cgi-bin/go?projurl=https://raw.githubusercontent.com/root-project/training/master/BasicCourse/Exercises/ROOTBooks/GausFit.ipynb)
- Or directly explore its solution: [open it in SWAN](https://cern.ch/swanserver/cgi-bin/go?projurl=https://raw.githubusercontent.com/root-project/training/master/BasicCourse/Exercises/ROOTBooks/GausFit_Solution.ipynb)
