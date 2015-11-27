#ifndef OUTPUT_H
#define OUTPUT_H

#include <string>

#include "TCanvas.h"
#include "TString.h"


class Output {
public:
  Output(const TString& dir, const TString& formats);

  void setDir(const std::string& dir);
  void setDir(const TString& dir) { setDir( std::string(dir.Data()) ); }
  void addPlot(TCanvas* can) const;
  TString dir() const { return dir_.c_str(); }


private:
  std::string dir_;
  bool createEPS_;
  bool createPDF_;
  bool createPNG_;
  bool createC_;

  void init(const TString& dir, TString formats);
  void cleanName(TString &name) const;
};
#endif
