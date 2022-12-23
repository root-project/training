# RooFit Tutorial

# Introduciton

Welcome to the first tutorial on RooFit, the part of ROOT that you can use for advanced statistical model building and fitting!
My name is Jonas Rembser, and I am the current maintainer and lead developer of RooFit.
RooFit is used by many high-energy physics experiments, most notably by the LHC collaborations.
With RooFit, you can build arbitrarily complicated binned and unbinned likelihood models, fit them to your data, and prepare nice visualizations of your results. You can also use it for example to generate toy datasets, and to run profile likelihood scans.
In this tutorial, I will explain to you the fundamentals of unbinned likelihood fits with examples written in PyROOT, also making use of the newest Python-exclusive interfaces that RooFit provides.
So I hope this tutorial is a good fit for you, and with that being said, let's get started!

## The Basics

So, what are with the basics of statistical model building in RooFit.
A statistical model is a expressed by a probability density funciton -- or PDF -- that is usually built up of several components, such as parameters, observables, functions, template histograms, or other PDFs.
Each of these mathematical building blocks is represented in RooFit by a C++ class, also called a RooFit argument, that can be used to build any PDF in a tree-like structure.

### Slide 2

Lets start by creating a simple Gaussian PDF, with the observable x and the parameters mean and sigma that have the values +5 and +1 respectively.
Both observables and parameters are represented by the `RooRealVar` class, and to instantiate them you need to pass the initial value as well as the minimum and maximum possible value.
These parameters follow the "name" and the "title" parameters that are always the first two constructor parameters of a RooFit argument.
The Gaussian PDF is represented by the `RooGaussian` class, which is a specialization of the abstract PDF class called `RooAbsPdf`.
If you call `Print()` on your PDF with the `"t"` argument, which stands for "tree", you can see the tree-like structure of a RooFit PDF.

### Slide 3

One thing you can do with your PDF is to sample observables values to create a toy dataset.
Here we are sampling 9000 values of the observable x according to our Gaussian PDF.
If you print the dataset object, your will see its C++ type, its name, and some brief information on the content.
Even though we are using Python, it is useful to know which class your objects are, such that you can look up how they are used in the ROOT reference guide.

### Slide 4

Let's now execute the central operation in RooFit: fitting a model to data.
This is done with the the `RooAbsPdf::fitTo` function, that can take a long list of keyword arguments to configure your fit.
Here, we are using the `PrintLevel` option to silence the output, and the `Save` option to return a `RooFitResult` object that we can inspect after the fit has completed.
It you Print the fit result object, you get a brief summary of the fit.
It includes some status flags, where the `MINIMIZE` flag tells you if the fit converged.
The `HESSE` status lets you know if the Hessian matrix of the parameters at the minimum could be computed, which is necessary to estimate parameter errors.
Status zero means all went fine!
Naturally, you also see the best fit parameter values and their uncertainties.
To get more information on your fit, you can also inspect the correlation of the parameters the minimum.

This tells you whether the best fit value of one parameter depends on the best fit value of another parameter.
In a Gaussian fit, the `mean` and `sigma` parameters are maximally uncorrelated, but in other models it can happen that some parameters are correlated so much that the fit doesn't converge.
So if your fit fails to converge and you see strong correlation terms in this matrix, it might be good to reformulate your model in such a way that the parameters are less correlated.

### Slide 5
For now we just looked at numbers and output text, so let's make some nice plot that shows the toy dataset together with the fit model for comparison.
RooFit has its own plot class, the `RooPlot`, and you can create a RooPlot for a given variable with the `frame` method.
Here, we create a RooPlot for the observable `x`, and directly set its title with a keyword argument.
Next, we add both the data and the model to the `RooPlot`.
Finally, you need to draw your `RooPlot` on a `TCanvas`, just in the same way you would draw a ROOT histogram -- for example a TH1.
As expected the model fits the data perfectly, because in our case the data was sampled from that model to begin with.

### Slide 6
Before showing you another class of PDFs, I want to demonstrate the interoperability between RooFit datasets and NumPy arrays or Pandas dataframes.
For example, you can take your RooDataSet, and call the `to_pandas()` method on it to create a pandas DataFrame with the dataset.
The Pandas dataframe representation is not only useful for data manipulation, but also for some quick inspection.

### Slide 7
Now let's talk about another class of RooFit PDFs: composite PDFs.
A composite PDF is a model with multiple components, for example signal and background.
But before creating a composite model, let's create a composite toy dataset for our studies.
To highlight the interoperability between RooFit and Numpy, we are creating the composite dataset with both libraries.
For the signal, let's take the Gaussian dataset we have already created and turn it into a NumPy array.
For the background, let's sample random values according to an exponential PDF using NumPy.
The composite dataset is the concatenation of the two NumPy arrays.
To use the composite dataset in RooFit, let's call `RooDataSet.from_numpy()`.
It takes a dictionary of NumPy arrays and a set of RooFit variables where the names should match the dictionary keys.
You can print the dataset object and verify that it has a reasonable number of events.

### Slide 8
To further validate the dataset, let's create yet another RooPlot with only the toy data.
You can clearly see that there is a Gaussian component, let's say it's the signal, and an exponential components that looks like a background.

### Slide 9
Now that we have the composite dataset, let's create the composite model to fit to the data.
We first start by modeling the background component, where we use a RooExponential PDF.
It only has one parameter, which is the decay constant. Here, I called it "tau".

Then, we need to define two more parameters that represent the expected number of events for the signal and background components.

Finally, we are instantiating the composite model as a `RooAddPdf`.
Besides the usual name and title parameters, the RooAddPdf constructor takes a list of component PDFs, and a list with coefficients.
If the sum of the coefficients is greater than one, a Poisson term is automatically added to the likelihood, which constrains the total number of expected events according to the number of events observed in data.
This is called an extended likelihood fit.

### Slide 10
Finally, let's fit the model to the composite toy dataset that we have created before.
In the fit result, you will see the two additional parameters for the number of signal and background events, and the `tau` parameter for the exponential shape.
Indeed, the best-fit-value for tau is compatible with -0.18, which was the value we used when sampling the background data with NumPy.

### Slide 11
Next, I want to show you how you can nicely visualize your composite model and compare it to data.
Let's create the usual RooPlot for the observable x, but this time we add the PDF three times:
in one line we add the full PDF, and in the other calls to `plotOn` we isolate the signal and background components with the `Components` keyword argument.
Next, we add a legend, as required for any good plot.
In the `AddEntry` calls, we have to use the same names that we have passed to the keyword arguments we passed to `plotOn`.

But we don't want to leave it at that!
Here, we create another RooPlot, where we add the residuals from the first RooPlot.
The residuals are the difference between the data and the model, which we want to see to understand if the fit is good.
If it is, the residuals should be compatible with zero within the statistical uncertainty of the data in each bin of the RooPlot.

### Slide 12
In the next step, I create a TCanvas to draw the RooPlots on.
The TCanvas is divided into two drawing pads using `TCanvas::Divide()`.
Let's plot the main RooPlot on the first pad, and adjust the dimensions of the pad to take 80 percent of the full canvas.
Next, we are drawing the residuals on the remaining 20 percent of the canvas, where we have to scale up the label and title sizes to get a consistent style.

### Slide 13
Finally, when you draw the canvas, you will see a plot that looks almost poblication-ready!
Note that the components of the PDF are plotted correctly normalized by the dashed lines.
