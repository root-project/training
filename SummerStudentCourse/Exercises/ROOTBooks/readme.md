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
- [Open the exercise notebook in SWAN](https://cern.ch/swanserver/cgi-bin/go?projurl=https://raw.githubusercontent.com/root-project/training/master/BasicCourse/Exercises/ROOTBooks/CreateAHistogram.ipynb)
- [Open the solution notebook in SWAN](https://cern.ch/swanserver/cgi-bin/go?projurl=https://raw.githubusercontent.com/root-project/training/master/BasicCourse/Exercises/ROOTBooks/CreateAHistogram_Solution.ipynb)
- [Open the C++ solution notebook in SWAN](https://cern.ch/swanserver/cgi-bin/go?projurl=https://raw.githubusercontent.com/root-project/training/master/BasicCourse/Exercises/ROOTBooks/CreateAHistogramCpp_Solution.ipynb)


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
