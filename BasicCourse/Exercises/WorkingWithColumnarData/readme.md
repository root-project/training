# Working With Columnar Data
Welcome to the exercises of the **Working With Columnar Data** learning module!

## Work with the CSV Data Source
In this exercise we will produce a plot of the invariant mass of muons pairs coming from real data of the CMS 
experiment (DOI: [10.7483/OPENDATA.CMS.CB8H.MFFA](http://opendata.cern.ch/record/700)).
First of all, download the input file:
```wget https://root.cern.ch/files/tutorials/tdf014_CsvDataSource_MuRun2010B.csv```
The kinematic properties of the muons are stored in columns. For the "first" muon they are called 
*Q1, E1, px1, py1, pz1, pt1, eta1, phi1* and for the "second" one *Q2, E2, px2, py2, pz2, pt2, eta2, phi2*.
You will use those to create your cuts and plots.

Steps to accomplish:
1) Create a data frame around this csv file ```auto tdf = ROOT::Experimental::TDF::MakeCsvDataFrame(fileName);```
2) Apply a cut to the muon pairs, selecting the ones with opposite charge. Charges are stored in the Q1 and Q2 columns.
3) Create a histogram of the invariant mass of the dimuon system. Choose a generous interval, say from 1 to 120 GeV. The formula for the invariant mass is:
```
M = \sqrt{(E_{1} + E_{2})^{2} + |\bar{p_{1}} + \bar{p_{2}}|^2}
```

Optional

