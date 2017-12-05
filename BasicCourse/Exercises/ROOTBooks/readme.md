# ROOTbooks
Welcome to the exercises of the "ROOTBooks" learning module!

## Introduction to notebooks and their integration with ROOT
In this exercise we'll explore the ROOT notebooks interface. Click on the link below.
A repository in Github will be cloned to your CERNBox and a SWAN session will be opened for you:

[![Open_in SWAN](https://img.shields.io/badge/Open_in-SWAN-orange.svg)](https://cern.ch/swanserver/cgi-bin/go/?projurl=https://github.com/cernphsft/rootbinder.git)

## Create a graph
Recreate in a Python notebook the graph we built together during the lectures at the ROOT prompt.
Display it using JavaScript graphics (use the ```%jsroot on``` magic).
Remember that for embedding a canvas in the notebook it is necessary to draw the canvas explicitly:
``` c++
c = ROOT.TCanvas()
# Here drawing takes place
c.Draw() # only after this command the plot appears
```
This notebook is only half way complete. What is requested from you is to translate the interactive graph creation example we saw together during the lectures to complete it. Oh, the notebook is in Python and not C++ - some translation will be required!
- [Open the notebook in SWAN](https://cern.ch/swanserver/cgi-bin/go?projurl=https://raw.githubusercontent.com/root-project/training/master/BasicCourse/Exercises/ROOTBooks/graphDraw.ipynb)
- Only when the frustration is unbearable, [Open the solution SWAN](https://cern.ch/swanserver/cgi-bin/go?projurl=https://raw.githubusercontent.com/root-project/training/master/BasicCourse/Exercises/ROOTBooks/graphDraw_Solution.ipynb)

## Revisited Fitting Exercise
We will now revisit the fitting exercise we carried out in the exercises of the PyROOT learning module. The objective is to demonstrate how a notebook allows to display all the intermediate steps of an analysis. In order to open the exercise notebook in SWAN, just follow the first link.
- [Open the notebook in SWAN](https://cern.ch/swanserver/cgi-bin/go?projurl=https://raw.githubusercontent.com/root-project/training/master/BasicCourse/Exercises/ROOTBooks/FittingExample.ipynb)
- Only when the frustration is unbearable, [Open the solution SWAN](https://cern.ch/swanserver/cgi-bin/go?projurl=https://raw.githubusercontent.com/root-project/training/master/BasicCourse/Exercises/ROOTBooks/FittingExample_Solution.ipynb)
