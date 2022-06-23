import ROOT

# Create a graph
g = ROOT.TGraph()

# Set its title to My graph, its X axis title to myX and Y axis title to myY
g.SetTitle("My graph;myX;myY")

# Fill it with three points: (1,0), (2,3), (3,4)
g.SetPoint(0,1,0)
g.SetPoint(1,2,3)
g.SetPoint(2,3,4)

# Set a red full square marker
g.SetMarkerStyle(ROOT.kFullSquare)
g.SetMarkerColor(ROOT.kRed)

# Draw an orange line between points
g.SetLineColor(ROOT.kOrange)

# Draw the graph
# "A": draw the axis
# "P": draw the points
# "L": draw graph as a simple line
g.Draw("APL")
