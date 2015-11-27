#ifndef TOOLS_PLOTTING_ERRORBAND_H
#define TOOLS_PLOTTING_ERRORBAND_H

#include <cmath>
#include <vector>

#include "TColor.h"
#include "TGraphErrors.h"
#include "TH1.h"

class ErrorBand {
public:
  static void setFillStyle(const int fillStyle) { fillStyle_ = fillStyle; }
  static void setFillColor(const int fillColor) { fillColor_ = fillColor; }

  static TGraphErrors* get(const TH1* h);


private:
  static int fillColor_;
  static int fillStyle_;
};

int ErrorBand::fillColor_ = kYellow;
int ErrorBand::fillStyle_ = 1001;


TGraphErrors* ErrorBand::get(const TH1* h) {
  std::vector<double> posX;
  std::vector<double> posY;
  std::vector<double> errX;
  std::vector<double> errY;
  for(int bin = 1; bin <= h->GetNbinsX(); ++bin) {
    const double binMin = h->GetXaxis()->GetBinLowEdge(bin);
    const double binMax = h->GetXaxis()->GetBinUpEdge(bin);
    posX.push_back( 0.5*(binMax+binMin) );
    posY.push_back( h->GetBinContent(bin) );
    errX.push_back( std::abs(0.5*(binMax-binMin)) );
    errY.push_back( h->GetBinError(bin) ); 
  }

  TGraphErrors* g = new TGraphErrors( posX.size(),
				      &(posX.front()),
				      &(posY.front()),
				      &(errX.front()),
				      &(errY.front())  );
  g->SetMarkerStyle(0);
  g->SetFillStyle( fillStyle_ );
  g->SetFillColor( fillColor_ );
  g->SetLineColor( fillColor_ );

  return g;
}
#endif
