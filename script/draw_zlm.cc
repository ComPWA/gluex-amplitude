#include "AMPTOOLS_AMPS/wignerD.h"
#include "TAxis.h"
#include "TCanvas.h"
#include "TF3.h"
#include "TH3F.h"
#include "TLorentzRotation.h"
#include "TLorentzVector.h"
#include "TMath.h"
#include "TVector3.h"

// complex< GDouble > zlm(Double_t *xs, Int_t *pars)
Double_t zlm(Double_t *xs, Double_t *pars) {
  // Parameters
  Int_t m_j = (Int_t)pars[0];        // spin
  Int_t m_m = (Int_t)pars[1];        // projection
  Int_t m_r = (Int_t)pars[2];        // reflectivity
  Int_t m_s = (Int_t)pars[3];        // sign
  Int_t pAngle = (Int_t)pars[4];     // polarization angle
  GDouble pGamma = (GDouble)pars[5]; // polarization fraction
  GDouble factor = sqrt(1 + m_s * pGamma);
  // cout << "j: " << m_j << endl;
  // cout << "m: " << m_m << endl;
  // cout << "reflectivity: " << m_r << endl;
  // cout << "sign: " << m_s << endl;
  // cout << "pAngle: " << pAngle << endl;
  // cout << "pGamma: " << pGamma << endl;
  // cout << "factor: " << factor << endl;

  // Variables
  GDouble cosTheta = xs[0];
  GDouble phi = xs[1];
  GDouble bigPhi = xs[2];

  // Calculate Intensity
  GDouble zlm = 0;
  complex<GDouble> rotateY = polar((GDouble)1., (GDouble)(-1. * bigPhi));
  if (m_r == 1)
    zlm = real(Y(m_j, m_m, cosTheta, phi) * rotateY);
  if (m_r == -1)
    zlm = imag(Y(m_j, m_m, cosTheta, phi) * rotateY);

  complex<GDouble> amplitude(factor * zlm);
  Double_t intensity = std::norm(amplitude);
  return intensity;
}

int main(int argc, char *argv[]) {
  cout << "Drawing Zlm Amplitude" << endl;
  // Double_t xs[] = {0,0,0};
  // Int_t pars[] = {2,0,1,1,0};
  // cout << zlm(xs, pars) << endl; // Test

  // Define Function
  TF3 *function = new TF3("zlm", zlm, -1, 1, -3.14, 3.14, -3.14, 3.14, 6);
  Int_t m_j = 2;
  Int_t m_m = 0;
  Int_t m_r = 1;
  Int_t m_s = 1;
  Int_t pAngle = 0;
  GDouble pGamma = 1;
  function->SetParameters(m_j, m_m, m_r, m_s, pAngle, pGamma);

  // Draw Function
  TCanvas canvas = new TCanvas("canvas", "canvas", 600, 600);
  int nBins = 50;
  string par_string(
      Form("l:%i m:%i e:%i s:%i a:%i g:%f;cos#theta;#phi [deg];#Phi [deg]", m_j,
           m_m, m_r, m_s, pAngle, pGamma));
  TH3F *fcnHist = new TH3F("zlm", par_string.c_str(), nBins, -1, +1, nBins,
                           -3.14, 3.14, nBins, -3.14, 3.14);
  TAxis *xAxis = fcnHist->GetXaxis();
  TAxis *yAxis = fcnHist->GetYaxis();
  TAxis *zAxis = fcnHist->GetZaxis();
  double x, y, z;
  for (int xBin = 1; xBin < nBins + 1; ++xBin) {
    for (int yBin = 1; yBin < nBins + 1; ++yBin) {
      for (int zBin = 1; zBin < nBins + 1; ++zBin) {
        x = xAxis->GetBinCenter(xBin);
        y = yAxis->GetBinCenter(yBin);
        z = zAxis->GetBinCenter(zBin);
        fcnHist->SetBinContent(xBin, yBin, zBin, function->Eval(x, y, z));
        // cout << function->Eval(x, y, z) << endl;
      }
    }
  }
  fcnHist->SetMinimum(0);
  fcnHist->GetXaxis()->SetTitleOffset(1.5);
  fcnHist->GetYaxis()->SetTitleOffset(2);
  fcnHist->GetZaxis()->SetTitleOffset(1.5);
  fcnHist->Draw("BOX2");
  // canvas.SaveAs("zlm_3d.pdf");
  canvas.SaveAs("zlm_3d.root");
  return 0;
}
