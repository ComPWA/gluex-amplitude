#include <complex>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#include "TSystem.h"

#include "AMPTOOLS_AMPS/Zlm.h"

#include "IUAmpTools/AmpToolsInterface.h"
#include "IUAmpTools/ConfigFileParser.h"
#include "IUAmpTools/ConfigurationInfo.h"
#include "IUAmpTools/FitResults.h"
#include "MinuitInterface/MinuitMinimizationManager.h"

int main(int argc, char *argv[]) {

  string configfile;

  for (int i = 1; i < argc; i++) {
    string arg(argv[i]);

    if (arg == "-c") {
      configfile = argv[++i];
    }
  }

  if (configfile.size() == 0) {
    cout << "No config file specified" << endl;
    exit(1);
  }

  ConfigFileParser parser(configfile);
  ConfigurationInfo *cfgInfo = parser.getConfigurationInfo();
  cfgInfo->display();

  AmpToolsInterface::registerAmplitude(Zlm());

  AmpToolsInterface ati(cfgInfo);
  vector<TLorentzVector> p4List;

  // list lab frame p4s, in the order specified in the AmpTools config file
  p4List.push_back(TLorentzVector(0, 0, 8.209470, 8.209470)); // beam photon
  p4List.push_back(TLorentzVector(-0.291810, -0.315238, 0.695296,
                                  1.244320)); // recoil proton
  p4List.push_back(TLorentzVector(0.183147, 0.002392, 0.384435,
                                  0.448137)); // resonance daughter 1
  p4List.push_back(TLorentzVector(0.151104, 0.333728, 1.914300,
                                  1.953710)); // resonance daughter 2

  Kinematics kin(p4List);

  ati.printEventDetails(cfgInfo->reactionList()[0]->reactionName(), &kin);

  return 0;
}
