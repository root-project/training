# Python Interface
Welcome to the exercises of the **Python Interface** learning module!

## Practise Python
In order to put in practise what you have learned in the introductory Python course, create a module that defines two functions:
- *count(text)*: given a string parameter that contains some text, it returns the number of words in that text (hint: use the [split](https://docs.python.org/2/library/string.html#string.split)
 function of Python string).
- *find(text, word)*: given two string parameters, a text and a word, it returns true if the word is in the text (hint: convert the text into a list and iterate on it).

Once the module is finished, either from the Python shell or from a script, invoke the defined functions:
- Count the number of words in *Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat*.
- Look for the word *magna*.

You can find the solution ([here](PythonTutorial.py)).

## Functions

In this exercise you will start practising the creation of ROOT objects with PyROOT. As an example, the following C++ code:
```c++
TH1F h("myTitle", "myHist", 64, -4, 4)
h.FillRandom("gaus")
h.Draw()
```
can be translated to Python like this:
```python
import ROOT
h = ROOT.TH1F("myTitle", "myHist", 64, -4, 4)
h.FillRandom("gaus")
h.Draw()
```
or like this (individual import):
```python
from ROOT import TH1F
h = TH1F("myTitle", "myHist", 64, -4, 4)
h.FillRandom("gaus")
h.Draw()
```
Now practise the creation of a ROOT function object (TF1) with PyROOT, in particular by translating the C++ code below to Python:
```c++
TF1 f("g", "gaus", -8, 8)
f.SetParameters(250, 0, 1)
f.Draw("Same")
```

You can find the solution ([here](FunctionGaus.py)).

## Histograms

In order to complete this exercise about ROOT histograms in PyROOT, please follow these steps:
- Open the Python interpreter.
- Import the ROOT module.
- Create a histogram with 64 bins and a axis ranging from 0 to 16.
- Fill it with random numbers distributed according to a linear function (*pol1*).
- Change its line width with a thicker one.
- Draw it.

You can find the solution ([here](HistoPol1.py)).

## Graphs

In order to complete this exercise about ROOT histograms in PyROOT, please follow these steps:
- Create a new Python module.
- In the module, create a graph (*TGraph*).
- Set its title to *My graph*, its X axis title to *myX* and Y axis title to *myY*.
- Fill it with three points: (1,0), (2,3), (3,4).
- Set a red full square marker.
- Draw an orange line between points.

You can find the solution ([here](Graph.py)).

## Dynamic C++

In this exercise you will practise the interaction between Python and C++ thanks to PyROOT and the ROOT interpreter. These are the steps you need to follow:
- Define a C++ function that counts the characters in an *std::string* (hint: use [http://en.cppreference.com/w/cpp/string/basic_string/size](std::string::size)).
- Make that function known to the ROOT interpreter in a Python module.
- Invoke the function via PyROOT.

If you want to go the extra mile, write three solutions for the exercise: (i) provide a string with the C++ code to the interpreter, (ii) pass a header to the interpreter and (iii) load a library dynamically.

You can find the solution ([here](DynamicCpp.py)).

## Fitting

In this exercise you will combine what you just learnt about invoking dynamic C++ in PyROOT with what you know about fitting and plotting in ROOT. These are the necessary steps to complete the exercise:
- From Python, define the following C++ functions via the ROOT interpreter:
```c++
// Quadratic background function
double background(double *x, double *par) {
  return par[0] + par[1]*x[0] + par[2]*x[0]*x[0];
}

// Lorenzian peak function
double lorentzianPeak(double *x, double *par) {
  return (0.5*par[0]*par[1]/TMath::Pi()) /
    TMath::Max(1.e-10,(x[0]-par[2])*(x[0]-par[2])
    + .25*par[1]*par[1]);
}

// Sum of background and peak function
double fitFunction(double *x, double *par) {
  return background(x, par) + lorentzianPeak(x, &par[3]);
}
```
- Construct and fill a histogram (`TH1F` class) given the following number of bins, bin content data and x range:
```python
nbins = 60
data = [ 6,1,10,12,6,13,23,22,15,21,
         23,26,36,25,27,35,40,44,66,81,
         75,57,48,45,46,41,35,36,53,32,
         40,37,38,31,36,44,42,37,32,32,
         43,44,35,33,33,39,29,41,32,44,
         26,39,29,35,32,21,21,15,25,15 ]
xlow = 0
xup = 3
```
- Create a function (`TF1` class) with the range from 0 to 3 and 6 parameters. Use the `fitFunction` function that you declared in the first step, which is the addition of a polynomial background and a Lorentzian function.
- Try to fit the function with the histogram without setting any parameter. This will result in a good fit for the polynomial function but not for the Lorentzian.
- Play with the values of parameters 4 and 5. What happens if you set 4 to 0.2 and 5 to 1, and fit again?
- Draw the histogram with error bars.
- Using the fitting results, construct TF1s for the background and Lorentzian functions and draw them in the same canvas.
- Create a legend with an entry for each function and the histogram.

You can find the solution ([here](Fitting.py)).
