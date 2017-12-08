# Working With Columnar Data
Welcome to the exercises of the **Working With Columnar Data** learning module!

## Analyse a Dataset
Consider the *ntuple* dataset that you can find in the *hsimple.root* file in the *tutorials directory*.
Starting from it, draw a plot of the sum of the *px* and *py* column for every value of *pz* between -2 and 2.
Exercise the ROOT knowledge you gained carrying out the exercise in the following ways:
 - Using C++
 - Using Python
 - Using TBrowser if possible
 - Using *TNtuple::Draw*

## A Random Dataset
With a method of your choice, create a TTree with three columns filled with random numbers. The columns should be done as follows:
 - **Column 1**: Poisson numbers with mu = 4
 - **Column 2**: Gaussian numbers with mean = 3 and sigma = 1.5
 - **Column 3**: Exponential numbers between 0 and 20

Write the dataset in a TFile and then study it with TBrowser.
Can you fit the distributions and recover the original values of the parameters?

## Work with the CSV Data Source
In this exercise we will produce a plot of the invariant mass of muons pairs coming from real data of the CMS 
experiment (DOI: [10.7483/OPENDATA.CMS.CB8H.MFFA](http://opendata.cern.ch/record/700)).
First of all, download the input file:
```
wget https://root.cern.ch/files/tutorials/tdf014_CsvDataSource_MuRun2010B.csv
```
The kinematic properties of the muons are stored in columns. For the "first" muon they are called 
*Q1, E1, px1, py1, pz1, pt1, eta1, phi1* and for the "second" one *Q2, E2, px2, py2, pz2, pt2, eta2, phi2*.
You will use those to create your cuts and plots.

Steps to accomplish:
1) Fetch the input file from the web:
```
wget https://root.cern.ch/files/tutorials/tdf014_CsvDataSource_MuRun2010B.csv
```
2) Create a data frame around this CSV file:
```
auto tdf = ROOT::Experimental::TDF::MakeCsvDataFrame(fileName);
```
3) Apply a cut to the muon pairs, selecting the ones with opposite charge. Charges are stored in the Q1 and Q2 columns.
4) Create a histogram of the invariant mass of the dimuon system. Choose a generous interval, say from 1 to 120 GeV. The formula for the invariant mass can be found [here](https://en.wikipedia.org/wiki/Invariant_mass).
5) What resonances are you seeing?

*Optional*
1) Create a mass window around the *J/psi* mass, which is about 3.097 GeV and display the invariant mass distribution.
2) Try to select only muon pairs in the central part of the detector (|eta| < 2 or 1). What happens to the spectrum? Do you have an idea why?

The solution to this exercise can be found in the file [CMSDimuonMass.C](CMSDimuonMass.C).
