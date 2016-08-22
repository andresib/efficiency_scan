#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <math.h>


	Double_t amano(double hv,double S,double emax,double hv50 )
	{
  	return emax / (1.0 + TMath::Exp( S *( hv - hv50 ) ) );
	}

	void eficiencias_sinfit_general2()
	{
  	//Being defined the variables and constants
	int ii=0; 
  	string rollName;
  	ifstream rollsend, rollsbar, rollsre4;
  	ifstream fitData;
	ofstream efi_end, efi_bar, efi_re4;

	
	string clswp, clsWpDef;
	double efi, efi1, efi2, efi3, efi4, knee;
  	double wp, slope50, chi2,  effwp, wpDef, effWpDef, effmaxerror, Serror, hv50error;
 	double parameters[3];



  	rollsend.open("data_filtered/endcap_filtered.txt");
  	rollsend>>rollName;
	efi_end.open("eficiencias/eficiencias_endcap2.txt");
 

  		while (!rollsend.eof() ) 
		{

			ii++;	
                  	fitData.open(("results/"+rollName+"/fitData.txt").c_str());

			fitData>>wp>>slope50>>parameters[0]>>parameters[2]>>chi2>>clswp>>effwp>>wpDef>>effWpDef>>clsWpDef>>effmaxerror>>Serror>>hv50error>>parameters[1];
	
			knee= wp-0.120;
 
				efi=amano(knee+0.180,parameters[1],parameters[0],parameters[2]);
				efi1=amano(knee+0.200,parameters[1],parameters[0],parameters[2]);
				efi2=amano(knee+0.220,parameters[1],parameters[0],parameters[2]);
				efi3=amano(knee+0.240,parameters[1],parameters[0],parameters[2]);
				efi4=amano(knee+0.260,parameters[1],parameters[0],parameters[2]);
				

			efi_end<<rollName<<" "<<efi<<" "<<efi1<<" "<<efi2<<" "<<efi3<<" "<<efi4<<" "<<knee<<" "<<knee+0.1<<endl;

    			fitData.close();



		    	rollsend>>rollName;

  		}

		

	efi_end.close(); 
	rollsend.close();

  	rollsbar.open("data_filtered/barrel_filtered.txt");
  	rollsbar>>rollName;
	efi_bar.open("eficiencias/eficiencias_barrel2.txt");
 

  		while (!rollsbar.eof() ) 
		{

			ii++;	
                  	fitData.open(("results/"+rollName+"/fitData.txt").c_str());

			fitData>>wp>>slope50>>parameters[0]>>parameters[2]>>chi2>>clswp>>effwp>>wpDef>>effWpDef>>clsWpDef>>effmaxerror>>Serror>>hv50error>>parameters[1];
	
			knee= wp-0.100;
 
				efi=amano(knee+0.180,parameters[1],parameters[0],parameters[2]);
				efi1=amano(knee+0.200,parameters[1],parameters[0],parameters[2]);
				efi2=amano(knee+0.220,parameters[1],parameters[0],parameters[2]);
				efi3=amano(knee+0.240,parameters[1],parameters[0],parameters[2]);
				efi4=amano(knee+0.260,parameters[1],parameters[0],parameters[2]);
				

			efi_bar<<rollName<<" "<<efi<<" "<<efi1<<" "<<efi2<<" "<<efi3<<" "<<efi4<<" "<<knee<<" "<<knee+0.1<<endl;

    			fitData.close();



		    	rollsbar>>rollName;

  		}

		

	efi_bar.close(); 
	rollsbar.close();

	rollsre4.open("data_filtered/re4_filtered.txt");
  	rollsre4>>rollName;
	efi_re4.open("eficiencias/eficiencias_re42.txt");
 

  		while (!rollsre4.eof() ) 
		{

			ii++;	
                  	fitData.open(("results/"+rollName+"/fitData.txt").c_str());

			fitData>>wp>>slope50>>parameters[0]>>parameters[2]>>chi2>>clswp>>effwp>>wpDef>>effWpDef>>clsWpDef>>effmaxerror>>Serror>>hv50error>>parameters[1];
	
			knee= wp-0.120;
 
				efi=amano(knee+0.180,parameters[1],parameters[0],parameters[2]);
				efi1=amano(knee+0.200,parameters[1],parameters[0],parameters[2]);
				efi2=amano(knee+0.220,parameters[1],parameters[0],parameters[2]);
				efi3=amano(knee+0.240,parameters[1],parameters[0],parameters[2]);
				efi4=amano(knee+0.260,parameters[1],parameters[0],parameters[2]);
				

			efi_re4<<rollName<<" "<<efi<<" "<<efi1<<" "<<efi2<<" "<<efi3<<" "<<efi4<<" "<<knee<<" "<<knee+0.1<<endl;

    			fitData.close();



		    	rollsre4>>rollName;

  		}

		

	efi_re4.close(); 
	rollsre4.close();



  
   	exit(0);
	}




