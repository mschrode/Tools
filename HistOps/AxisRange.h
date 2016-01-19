#ifndef TOOLS_HISTOPS_AXIS_RANGE_H
#define TOOLS_HISTOPS_AXIS_RANGE_H

#include <vector>

#include "TH1.h"

class AxisRange {
public:
  static double yMax(const std::vector<TH1*>& hists);
  static double yMax(const TH1* hist) {
    return hist->GetBinContent(hist->GetMaximumBin());
  }
};


double AxisRange::yMax(const std::vector<TH1*>& hists) {
  double max = 0.;
  for(auto& hist : hists) {
    const double imax = yMax(hist);
    if( imax > max ) max = imax;
  }

  return max;
}

#endif
