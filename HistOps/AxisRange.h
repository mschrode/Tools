#ifndef TOOLS_HISTOPS_AXIS_RANGE_H
#define TOOLS_HISTOPS_AXIS_RANGE_H

#include <vector>

#include "TH1.h"

class AxisRange {
public:
  static void setYMax(std::vector<TH1*>& hists, const double scale);
  static double yMax(const std::vector<TH1*>& hists);
  static double yMax(const TH1* hist) {
    return hist->GetBinContent(hist->GetMaximumBin());
  }
};


void AxisRange::setYMax(std::vector<TH1*>& hists, const double scale) {
  const double max = scale * AxisRange::yMax(hists);
  for(auto& hist: hists) {
    hist->GetYaxis()->SetRangeUser(0,max);
  }
}


double AxisRange::yMax(const std::vector<TH1*>& hists) {
  double max = 0.;
  for(auto& hist : hists) {
    const double imax = yMax(hist);
    if( imax > max ) max = imax;
  }

  return max;
}

#endif
