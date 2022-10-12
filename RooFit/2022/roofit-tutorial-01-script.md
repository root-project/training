# RooFit Tutorial

# Introduciton

Welcome to the first tutorial on RooFit, the part of ROOT that you can use for advanced statistical model building and fitting!

My name is Jonas Rembser, and I am the current maintainer and lead developer of RooFit.

RooFit is used by many high-energy physics experiments, most notably by the LHC collaborations.

With RooFit, you can build arbitrarily complicated binned and unbinned likelihood models, fit them to your data, and prepare nice visualizations of your results. You can also use it for example to generate toy datasets, and to run profile likelihood scans.

In this tutorial, I will explain to you the fundamentals of unbinned likelihood fits with examples written in PyROOT, also making use of the newest Python-exclusive interfaces that RooFit provides.

So I hope this tutorial is a good fit for you, and with that being said, let's get started!


## The Basics

Let us start with the basics of statistical model building in RooFit. A statistical model is a expressed by a probability density funciton -- or PDF -- that is usually built up of several components, like parameters, observables, functions, template histograms, or other PDFs.

Each of these mathematical building blocks is represented in RooFit by a C++ class, also called a RooFit argument, that can be used to build any PDF in a tree-like structure.

### Slide 2

Lets start by creating a simple Gaussian PDF, with the observable x and the parameters mu and sigma that have the values +5 and +1 respectively.
Both observables and parameters are represented by the `RooRealVar` class, and to instantiate them you need to pass the parameter or observable range to the constructor.
These parameters follow the "name" and the "title" parameters that are always the first two constructor parameters of a RooFit argument.

The Gaussian PDF is represented by the `RooGaussian` class, which is a specialization of the abstract PDF class called `RooAbsPdf`.

If you call `Print()` on your PDF with the `"t"` argument, which stands for "tree", you can see the tree-like structure of a RooFit PDF.

### Slide 3




Some of the reasons for its popularity are its high modularity -- as each model component is represented by a C++ class --, the RooWorkspace that makes it possible to share statistical models with your colleagues, and the performance optimizations under the hood that make it scale well also for the most advanced combined fits.
