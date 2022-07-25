# Working With Columnar Data
Welcome to the exercises of the **Working With Columnar Data** learning module!

## Analyse a Dataset
Let's start with the *ntuple* dataset that you can find in the file *hsimple.root* [here](./hsimple.root).
Draw a plot of the sum of the *px* and *py* columns for every entry where *pz* is between -2 and 2.
Use `RDataFrame` to complete the tasks, either in C++ or Python (or both, if you have time).

## Work with the CSV Data Source
In this exercise, we will produce a plot of the invariant mass of muon pairs coming from real data of the CMS
experiment (DOI: [10.7483/OPENDATA.CMS.CB8H.MFFA](http://opendata.cern.ch/record/700)).
1) First of all, download the input file:
   ```
   wget https://root.cern.ch/files/tutorials/tdf014_CsvDataSource_MuRun2010B.csv
   ```
   or, on Windows:
   ```
   curl -O https://root.cern.ch/files/tutorials/tdf014_CsvDataSource_MuRun2010B.csv
   ```

2) Create a data frame that reads this CSV file:
   ```
   auto rdf = ROOT::RDF::MakeCsvDataFrame(fileName);
   ```

3) The kinematic properties of the muons are stored in columns.
For the "first" muon they are called
*Q1, E1, px1, py1, pz1, pt1, eta1, phi1*, and for the "second" one *Q2, E2, px2, py2, pz2, pt2, eta2, phi2*.

4) Apply a cut to the entries, selecting the ones that have muons with opposite charge. Charges are stored in the Q1 and Q2 columns.

5) Create a histogram of the invariant mass of the dimuon system. Choose a generous interval, say from 1 to 120 GeV. The formula for the invariant mass can be found [here](https://en.wikipedia.org/wiki/Invariant_mass).

6) What resonances are you seeing?

*Optional*
1) Create a mass window around the *J/psi* mass, which is about 3.097 GeV and display the invariant mass distribution.
2) Try to select only muon pairs in the central part of the detector (|eta| < 2 or 1). What happens to the spectrum? Do you have an idea why?

The solution to this exercise can be found in the file [CMSDimuonMass.C](CMSDimuonMass.C).
