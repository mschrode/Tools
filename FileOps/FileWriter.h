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
};

  void HistReader::toFiles(TNamed* obj, TFile* file, const TString& objName) {
    if( file->IsZombie() ) {
      std::cerr << "ERROR: unable to write to file '" << file->GetName() << std::endl;
      exit(1);
    } else {
      TString name = obj->GetName();
      TString title = obj->GetTitle();
      if( objName != "" ) {
	obj->SetName(objName);
	obj->SetTitle(objName);
      }
      file->WriteTObject(obj);
      obj->SetName(name);
      obj->SetTitle(title);
    }
  }
  

  void HistReader::toFiles(TCanvas* can, TFile* file, const TString& canName, const TString& option) {
    if( file->IsZombie() ) {
      std::cerr << "ERROR: unable to write to file '" << file->GetName() << std::endl;
      exit(1);
    } else {
      TString name = can->GetName();
      if( canName != "" ) name = canName;
      if( option.Contains("root") ) file->WriteTObject(can,name);
      if( option.Contains("eps") ) can->SaveAs(name+".eps","eps");
    }
  }

#endif
