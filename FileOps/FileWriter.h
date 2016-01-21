#ifndef TOOLS_FILEOPS_FILEWRITER_H
#define TOOLS_FILEOPS_FILEWRITER_H

#include <iostream>
#include <vector>

#include "TCanvas.h"
#include "TFile.h"
#include "TNamed.h"
#include "TObject.h"
#include "TString.h"

class FileWriter {
public:
  static void write(TNamed* obj, TFile& file, const TString& objName = "");
  static void write(TCanvas* can, TFile& file, const TString& canName = "", const TString& option = "root pdf");
  static TString toFileName(const TString& name);
};


TString FileWriter::toFileName(const TString& name) {
  TString fileName(name);
  fileName.ReplaceAll(" ","_");
  fileName.ReplaceAll("__","_");
  fileName.ReplaceAll("(","");
  fileName.ReplaceAll(")","");

  return fileName;
}


#endif
