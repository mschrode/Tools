#ifndef TOOLS_FILEOPS_HISTREADER_H
#define TOOLS_FILEOPS_HISTREADER_H

#include <exception>
#include <iostream>

#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
#include "TString.h"


class HistReader {
public:
  static TH2* getTH2(const TString& fileName, const TString& histName, const TString& newHistName = "", const bool useCurrentStyle = true);
  static TH1* getTH1(const TString& fileName, const TString& histName, const TString& newHistName = "", const bool useCurrentStyle = true);
};


TH2* HistReader::getTH2(const TString& fileName, const TString& histName, const TString& newHistName, const bool useCurrentStyle) {
  TH1* h = getTH1(fileName,histName,newHistName,useCurrentStyle);
  const TString className = h->ClassName();
  if( className != "TH2" ) {
    std::cerr << "\n\nERROR: no TH2 '" << histName << "' in file '" << fileName << "'" << std::endl;
    throw std::exception();
  }

  return static_cast<TH2*>(h);
}


TH1* HistReader::getTH1(const TString& fileName, const TString& histName, const TString& newHistName, const bool useCurrentStyle) {
  TFile file(fileName,"READ");
  TH1* h = 0;
  file.GetObject(histName,h);
  if( h == 0 ) {
    std::cerr << "\n\nERROR: no TH1 '" << histName << "' in file '" << fileName << "'" << std::endl;
    throw std::exception();
  }
  h->SetDirectory(0);
  file.Close();
  if( useCurrentStyle ) h->UseCurrentStyle();
  if( newHistName.Length() ) h->SetName(newHistName);
    
  return h;
}

#endif
