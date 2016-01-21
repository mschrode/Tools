// Common style file
// --------------------------------------------------------------
// 
// Defines a set of functions to define the plotting style and
// provide commonly used style objects such as histogram title
// and legends. Can be used in compiled code and uncompiled scripts.
//
// Always call TheLook::set(PublicationStatus) in the beginning
// of your plotting script to adjust the gStyle options. Also,
// the behaviour of some other methods of this class depend on
// this, e.g. the histogram title displays "CMS preliminary" etc.
// depending on the PublicationStatus. Call TheLook::set before
// declaring any histograms (or call TH1::UseCurrentStyle()) to
// make sure the style settings are used.
// --------------------------------------------------------------

#ifndef TOOLS_PLOTTING_THELOOKS_H
#define TOOLS_PLOTTING_THELOOKS_H

#include "TCanvas.h"
#include "TColor.h"
#include "TError.h"
#include "TString.h"
#include "TStyle.h"


// Publication status: determines what is plotted in title
enum PublicationStatus { INTERNAL, INTERNAL_SIMULATION, PRELIMINARY, PUBLIC, SIMULATION, UNPUBLISHED };
TString toTString(const PublicationStatus status) {
  TString str = "";
  if(      status == INTERNAL )            str = "internal";
  else if( status == INTERNAL_SIMULATION ) str = "simulation (internal)";
  else if( status == PRELIMINARY )         str = "preliminary";
  else if( status == PUBLIC      )         str = "public";
  else if( status == SIMULATION  )         str = "simulation (public)";
  else if( status == UNPUBLISHED )         str = "unpublished";

  return str;
}


class TheLooks {
public:
  // Adjusts the gStyle settings and store the PublicationStatus
  static void set(const PublicationStatus status);
  static void set() { set(INTERNAL); }
  static PublicationStatus status() { return publicationStatus_; }

  static double margin() { return margin_; }
  static double lineHeight() { return lineHeight_; }
  static double textSize() { return textSize_; }

  static void applyTH2Margins(TCanvas* can);


private:
  static PublicationStatus publicationStatus_;
  static double lineHeight_;
  static double margin_;
  static double textSize_;
};

PublicationStatus TheLooks::publicationStatus_ = INTERNAL;
double TheLooks::lineHeight_ = 0.046;
double TheLooks::margin_ = 0.05;
double TheLooks::textSize_ = 0.04;


// --------------------------------------------------------------
void TheLooks::applyTH2Margins(TCanvas* can) {
  can->SetRightMargin(can->GetRightMargin()+0.08);
  can->SetBottomMargin(can->GetBottomMargin()+0.06);
  can->SetTopMargin(can->GetTopMargin()+0.02);
}


// --------------------------------------------------------------
void TheLooks::set(const PublicationStatus status) {
  // Store the PublicationStatus for later usage, e.g. in the title
  publicationStatus_ = status;

  // Suppress message when canvas has been saved
  gErrorIgnoreLevel = 1001;

  // Zero horizontal error bars
  gStyle->SetErrorX(0);

  //  For the canvas
  gStyle->SetCanvasBorderMode(0);
  gStyle->SetCanvasColor(kWhite);
  gStyle->SetCanvasDefH(800); //Height of canvas
  gStyle->SetCanvasDefW(800); //Width of canvas
  gStyle->SetCanvasDefX(0);   //Position on screen
  gStyle->SetCanvasDefY(0);
  
  //  For the frame
  gStyle->SetFrameBorderMode(0);
  gStyle->SetFrameBorderSize(10);
  gStyle->SetFrameFillColor(kBlack);
  gStyle->SetFrameFillStyle(0);
  gStyle->SetFrameLineColor(kBlack);
  gStyle->SetFrameLineStyle(0);
  gStyle->SetFrameLineWidth(2);
  gStyle->SetLineWidth(3);
    
  //  For the Pad
  gStyle->SetPadBorderMode(0);
  gStyle->SetPadColor(kWhite);
  gStyle->SetPadGridX(false);
  gStyle->SetPadGridY(false);
  gStyle->SetGridColor(0);
  gStyle->SetGridStyle(3);
  gStyle->SetGridWidth(1);
  
  //  Margins
  gStyle->SetPadTopMargin(0.08);
  gStyle->SetPadBottomMargin(0.15);
  gStyle->SetPadLeftMargin(0.18);
  gStyle->SetPadRightMargin(0.05);

  //  For the histo:
  gStyle->SetHistLineColor(kBlack);
  gStyle->SetHistLineStyle(0);
  gStyle->SetHistLineWidth(2);
  gStyle->SetMarkerSize(1.2);
  gStyle->SetEndErrorSize(4);
  gStyle->SetHatchesLineWidth(1);

  //  For the statistics box:
  gStyle->SetOptStat(0);
  
  //  For the axis
  gStyle->SetAxisColor(1,"XYZ");
  gStyle->SetTickLength(0.03,"XYZ");
  gStyle->SetNdivisions(510,"XYZ");
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
  gStyle->SetStripDecimals(kFALSE);
  
  //  For the axis labels and titles
  gStyle->SetTitleColor(1,"XYZ");
  gStyle->SetLabelColor(1,"XYZ");
  gStyle->SetLabelFont(42,"XYZ");
  gStyle->SetLabelOffset(0.007,"XYZ");
  gStyle->SetLabelSize(0.04,"XYZ");
  gStyle->SetTitleFont(42,"XYZ");
  gStyle->SetTitleSize(0.047,"XYZ");
  gStyle->SetTitleXOffset(1.5);
  gStyle->SetTitleYOffset(1.9);

  //  For the legend
  gStyle->SetLegendBorderSize(0);
}

#endif
