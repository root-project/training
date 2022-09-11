## Task description

There is a ROOT file accessible as `http://root.cern/files/teaching/Run2012BC_DoubleMuParked_Muons_reduced20x.root` which contains a TTree dataset named `Events`. It contains a slimmed down version of a real CMS OpenData dataset with muon candidates from the LHC data taking of 2012.

The original full dataset is accessible at [DOI: 10.7483/OPENDATA.CMS.YLIC.86ZZ](http://opendata.cern.ch/record/6004) and [DOI: 10.7483/OPENDATA.CMS.M5AD.Y3V3](http://opendata.cern.ch/record/6030).

After opening the dataset with `RDataFrame`:

1. Select events that contain exactly 2 muons.
2. Select events for which the 2 muons have opposite charge.
3. Define a new quantity representing the invariant mass of the muons. There is a useful `RVec` helper function that can help at this step, [`InvariantMass(pt_vec, eta_vec, phi_vec, mass_vec)`](https://root.cern.ch/doc/master/group__vecops.html#ga2c531eae910edad48bbf7319cc6d7e58).
4. Fill a histogram with the invariant mass of the dimuon system and plot the resulting distribution. Tip: the plot will look better using logarithmic scales for the axes.

What resonances do you recognize?

**Note**: if reading the dataset via HTTP takes too long, consider downloading it using a command line tool such as `wget` or `curl` and then read it from your local disk. The file is roughly 100MB in size.
