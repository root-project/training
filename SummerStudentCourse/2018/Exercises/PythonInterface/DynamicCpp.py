
import ROOT

# Define a C++ function that counts the characters in a string
cpp_function_code = """
int CountCharacters(const std::string& s)
{
   return s.size();
}
"""

# Make that function available to the ROOT interpreter in a Python module
ROOT.gInterpreter.ProcessLine(cpp_function_code)

# Invoke the function through PyROOT
nchars = ROOT.CountCharacters("This interactivity without bindings is really impressive.")

print("Number of characters: " + str(nchars))
