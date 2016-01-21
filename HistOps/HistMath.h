#ifndef TOOLS_HISTOPS_HIST_MATH_H
#define TOOLS_HISTOPS_HIST_MATH_H

#include "TH1.h"
#include "TMath.h"

class HistMath {
public:
  static double median(const TH1* h);
};

double HistMath::median(const TH1* h) {
  const int nBins = h->GetNbinsX();
  std::vector<double> xs(nBins,0);
  std::vector<double> ys(nBins,0);
  for(int bin = 1; bin <= nBins; ++bin) {
    xs.at(bin-1) = h->GetBinCenter(bin);
    ys.at(bin-1) = h->GetBinContent(bin);
  }

  return TMath::Median(nBins,&(xs.front()),&(ys.front()));
}

#endif
