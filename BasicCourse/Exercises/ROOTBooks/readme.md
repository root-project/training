# ROOTbooks
Welcome to the exercises of the "ROOTBooks" learning module!

## Introduction to notebooks and their integration with ROOT
In this exercise we'll explore the ROOT notebooks interface. Click on the link below.
A repository in Github will be cloned to your CERNBox and a SWAN session will be opened for you:
### [Start Here](https://cern.ch/swanserver/cgi-bin/go/?projurl=https://github.com/cernphsft/rootbinder.git)
We'll explore the notebooks together.


## Create a graph
Recreate in a Python notebook the graph we built together during the lectures at the ROOT prompt.
Display it using JavaScript graphics (use the ```%jsroot on``` magic).
Remember that for embedding a canvas in the notebook it is necessary to draw the canvas explicitly:
``` c++
c = ROOT.TCanvas()
# Here drawing takes place
c.Draw() # only after this command the plot appears
```

## Revisited Fitting Exercise
