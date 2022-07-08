# Histograms, Graphs and Functions Exercises

Welcome to the exercises of the **Histograms, Graphs and Functions** learning module!

## A macro to build a histogram
Create a macro which builds and draws a histogram with the following features:
- The number of bins is 50 and the x axis ranges from 0 to 10.
- It is filled with random numbers distributed according to an exponential distribution which has a rate = 0.5.
  Suggestion: see the [TRandom](https://root.cern.ch/doc/master/classTRandom.html) for generating random numbers or
  [TH1::FillRandom](https://root.cern.ch/doc/master/classTH1.html#random-numbers)
- Its line width is thicker than the default one.


You can find a solution as notebook [here](SimpleHistogram.ipynb) ([Open in Swan](https://cern.ch/swanserver/cgi-bin/go?projurl=https://raw.githubusercontent.com/root-project/training/master/SummerStudentCourse/2022/Exercises/HistogramsGraphsFunctions/SimpleHistogram.ipynb)) and as C++ macro [here](SimpleHistogram.C).

## A macro to build a graph
Create a macro which builds and draws a graph with the following features:
- The title of the plot is *My graph*.
- The x and y axis have labels `my_{X}` and `my_{Y}` respectively.
- It has three points with the following coordinates (1,0), (2,3), (3,4).
- The marker is a full square. Its coulour is red.
- An orange line joins the points.

You can find a solution as notebook [here](SimpleGraph.ipynb) ([Open in Swan](https://cern.ch/swanserver/cgi-bin/go?projurl=https://raw.githubusercontent.com/root-project/training/master/SummerStudentCourse/2022/Exercises/HistogramsGraphsFunctions/SimpleGraph.ipynb)) and a C++ macro [here](SimpleGraph.C).

## A macro to build a function
Create a macro that follows these steps:
- Create a function with formula *cos(x)* and draw it.
- Create another *cos(x)*, but scale the argument of the cosine by adding a parameter.
- Set a value for the parameter.
- Change the line color of the second function.
- Draw the second function in the same canvas as the first one.

You can find a solution as notebook [here](SimpleFunction.ipynb) ([Open in Swan](https://cern.ch/swanserver/cgi-bin/go?projurl=https://raw.githubusercontent.com/root-project/training/master/SummerStudentCourse/2022/Exercises/HistogramsGraphsFunctions/SimpleFunction.ipynb)) and a C++ macro [here](SimpleFunction.C).
