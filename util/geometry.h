#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <cmath>

#include "TMath.h"
#include "TVector2.h"


//!  Useful classes and methods for geometry-related operations
//!  
//!
//!  \author   Matthias Schroeder (www.desy.de/~matsch)
//!  \date     2013/07/09
// -----------------------------------------------------------------
namespace util {

  //! Azimuthal angle phi in CMS:
  //! https://twiki.cern.ch/twiki/bin/view/CMS/CMSConventions#The_azimuthal_angle_phi_in_CMS
  // --------------------------------------------------
  static double phi(double x, double y) {
    return ( x==0. && y==0. ) ? 0. : atan2(y,x);
  }


  // --------------------------------------------------
  static double theta(double x, double y, double z) {
    return ( x==0. && y==0. && z==0. ) ? 0. : TMath::ATan2(sqrt(x*x + y*y),z);
  }


  // --------------------------------------------------
  static double eta(double x, double y, double z) {
    return ( x==0. && y==0. && z==0. ) ? 0. : -1.*TMath::Log(TMath::Tan(0.5*theta(x,y,z)));
  }


  // --------------------------------------------------
  static double deltaPhi(double phi1, double phi2) {
    return TVector2::Phi_mpi_pi(phi1-phi2);
  }


  //! DeltaR between two vectors
  // --------------------------------------------------
  static double deltaR(double eta1, double eta2, double phi1, double phi2) {
    double dphi = deltaPhi(phi1,phi2);
    double deta = eta1-eta2;

    return sqrt( deta*deta + dphi*dphi );
  }


  // --------------------------------------------------
  static inline double deltaR(double x1, double x2, double y1, double y2, double z1, double z2) {
    return deltaR(eta(x1,y1,z1),eta(x2,y2,z2),phi(x1,y1),phi(x2,y2));
  }

}
#endif
