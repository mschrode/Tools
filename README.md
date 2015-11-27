The tools in Tools assume that you have added the path to Tools
to your g++ include path. To use with CINT do, e.g. in your .rootlogon.C

  gInterpreter->AddIncludePath("<path to Tools>");
