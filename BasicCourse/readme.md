# ROOT Basic Course

This course targets scientists and engineers with little or no experience of ROOT.
The basics of the package are covered as well as high level concepts of C++ and
Python.

## Preparation for the Course

Participants of the ROOT basic course need to perform the following preparation actions **prior to the course**.

### Install the ROOT Virtual Machine Image

Participants have at their disposal a virtual machine image where ROOT is installed. With this image, they can instantiate a virtual machine and execute the ROOT examples and exercises that will be shown during the course.

In order to install the ROOT Virtual Machine image in their own machine, participants can follow these steps:
* Download and install VirtualBox:
https://www.virtualbox.org/wiki/Downloads
* Download the ROOT VM appliance from this link:
https://cernbox.cern.ch/index.php/s/ZF5pffhZuZjwgAI
* Import the ROOT VM appliance from VirtualBox:
https://docs.oracle.com/cd/E26217_01/E26796/html/qs-import-vm.html

### Make sure you can log in to SWAN

SWAN (Service for Web-based ANalysis) is a CERN service that allows interactive edition and execution of ROOT programs from a web browser.

In order to be able to connect and use the SWAN service during the course, participants need to make sure that:
* They have a CERN account that is associated to a computing group. They can check if they belong to a computing group at https://account.cern.ch/account/CERNAccount/AccountStatus.aspx. If a participant does not belong to any computing group, she can subscribe to the default computing group following these instructions: https://resources.web.cern.ch/resources/Help/?kbid=067030
* They have created a CERNBox account. In order to create it, they just need to connect and authenticate with their CERN username and password at https://cernbox.cern.ch
* They can log in to SWAN with their CERN username and password: https://swan.cern.ch

## Content

### Day 1

1. Introduction 1h
 - What is ROOT?
 - Usage patterns and example applications
 - Structure and elements of ROOT
 - Setting up the exercise environment

2. The C++ Interpreter 2h
 - C++ Crash course
 - The ROOT prompt
 - ROOT as a calculator and notepad for your C++
 - Interpreter commands
 - Macros
 - Exercises

3. Histograms and Functions 2h
 - Histograms
 - Functions
 - Graphs and time series
 - Creating a nice plot: best practices, axes, legends, styles, colours, markers and fonts
 - Basic interaction with the canvas
 - Basic fitting and parameter estimation
 - Exercises

4. Fitting 1h
 - Likelihood and Chi2 maximisation
 - Introduction to fitting and common fitting problems
 - Building sophisticated fit functions
 - Interface to Minimization
 - Using the ROOT Fit GUI
 - Random number generation
 - Exercises

### Day 2

5. Python Interface 1h
 - Python crash course
 - Mapping C++ to Python with PyROOT: elements of the ROOT Python "bindings"
 - Creating a nice plot with PyROOT
 - Exercises

6. ROOTBooks 2h
 - Complement the macro, prompt and script approach with a web-based solution
 - Create a nice ROOTBook: best practices, plotting
 - Introduction to JSROOT
 - ROOTBooks at CERN
 - Exercises

7. Working with Files 1h
 - The problem of input and output of data
 - Elements of file structure and format
 - Write and read objects
 - The TBrowser
 - Exercises

8. Working with Columnar Data 2h
 - Two storage options: row- and column-wise
 - TDataFrame: the handle on the ROOT (and not only) columnar data
 - Exercises

9. Developing packages using ROOT 30m
 - Setting up the environment
 - Linking libraries, finding headers: the `root-config` script
 - Exercises
