#include <iostream>
#include <fstream>
#include <sstream>
#include <complex>
#include <string>
#include <vector>
#include <utility>
#include <map>

#include "TSystem.h"

#include "AMPTOOLS_AMPS/Zlm.h"
#include "AMPTOOLS_AMPS/ROOTDataReader.h"

#include "MinuitInterface/MinuitMinimizationManager.h"
#include "IUAmpTools/AmpToolsInterface.h"
#include "IUAmpTools/FitResults.h"
#include "IUAmpTools/ConfigFileParser.h"
#include "IUAmpTools/ConfigurationInfo.h"

int main( int argc, char* argv[] ){

	string configfile;

	for ( int i = 1; i < argc; i++ ){
		string arg( argv[i] );
		if ( arg == "-c" ){ configfile = argv[++i]; }
	}

	if( configfile.size() == 0 ){
		cout << "No config file specified" << endl;
		exit(1);
	}

	ConfigFileParser parser(configfile);
	ConfigurationInfo* cfgInfo = parser.getConfigurationInfo();
  string reactionName=cfgInfo->reactionList()[0]->reactionName();

	//cfgInfo->display();

	AmpToolsInterface::registerAmplitude( Zlm() );
  AmpToolsInterface::registerDataReader( ROOTDataReader() );

	AmpToolsInterface ati( cfgInfo );

  int iDataSet=0; // if use used {data, accmc, genmc datasets}, we can choose one of them here

  //////////////////////////////////////////////////////////////////////////
  ///       TESTING PURPOSES
	//vector< TLorentzVector > p4List;
	////// list lab frame p4s, in the order specified in the AmpTools config file
  //p4List.push_back( TLorentzVector(0.000000,0.000000,8.419198,8.419198) );
  //p4List.push_back( TLorentzVector(-0.105035,0.014094,1.106842,1.454883) );
  //p4List.push_back( TLorentzVector(-0.330669,-0.777849,0.458704,0.971092) );
  //p4List.push_back( TLorentzVector(0.435704,0.763756,6.855184,6.933026) );
	//Kinematics kin_test( p4List );
	//ati.printIntensity( reactionName, &kin_test );
  //////////////////////////////////////////////////////////////////////////

  // Have to loadEvents before using kinematics (and numEvents) but cannot run processEvents.
  //   To use the intensity method, we need to processEvents first
  Kinematics kin;
  ati.loadEvents(ati.dataReader(reactionName),iDataSet);
  int nentries=ati.numEvents(iDataSet);
  printf("Number of entries: %i\n",nentries);
  //cout << ati.processEvents(reactionName,iDataSet) << endl;
  for (int i=0; i<nentries; ++i){
    kin = *ati.kinematics(i,iDataSet);
    //for (auto four_vector: kin.particleList()){
    //    four_vector.Print();
    //}
    ati.printIntensity(reactionName, &kin);
  }

	return 0;
}
