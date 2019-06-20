# Graphics Exercises

Welcome to the exercises of the **Graphics** learning module!

## The "Good Plot" Example
In this exercise, you will follow the steps of the "Good Plot" example that is described in the course slides. In particular, these are the steps to follow:
- Create the initial data set by placing the code below in a macro called *macro1*:
```c++
// The number of points in the data set
const int n_points = 10;
// The values along X and Y axis
double x_vals[n_points] = {1,2,3,4,5,6,7,8,9,10};
double y_vals[n_points] = {6,12,14,20,22,24,35,45,44,53};
// The errors on the Y axis
double y_errs[n_points] = {5,5,4.7,4.5,4.2,5.1,2.9,4.1,4.8,5.43};
```
- Create a `TGraphErrors` instance using the aforementioned data.
- Draw the graph data in an error bars plot. Play with the following draw options: *"APE"*, *"APEL"*, *"APEC"*, *"APE4"*.
- Customize the visual aspect of the plot (marker style, marker color, line color).
- Add a function to compare the data with a line. Use the formula *"[0]+x\*[1]"*. Set the parameters to -1 and 5. Play a little with the line style and color and draw the function in the same canvas as the graph. 
- Set the titles for the graph (*"Measurement XYZ;length [cm];Arb.Units"*) and for the axis ("*length [cm]"* and *"Arb.Units"* for x and y). Try to add special latex characters.
- Try to change the number of divisions of the x axis: set the number of primary divisions to 20 and check the result. Did you get that number of divisions?
- Change the label of the x axis corresponding to the maximum deviation by setting its color to red.
- Add a legend to the plot, with one entry for the graph and one for the function.
- Add an arrow (`TArrow`) and some text (`TLatex`) to the canvas.

You can find the solution [here](macro1NoFit.C).
