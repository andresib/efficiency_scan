# efficiency_scan
Code to make an efficiency scan adding voltages to the knee.
IMPORTANT: This code need as an input the directory "results" that is produced after running the HV Scan Code.

To run the code you have to do the following steps.

#####I. To create a directory called "data_filtered" (the directory is included by default) and include in it the following files:

barrel_filtered.txt  -> The list of rolls in the barrel that are going to be used for the efficiency scan, the normal procedure will be to include here the rolls after the remotion of the black list. An example file is provided.

endcap_filtered.txt  -> The list of rolls in the endcap that are going to be used for the efficiency scan, the normal procedure will be to include here the rolls after the remotion of the black list. An example file is also provided.

re4_filtered.txt     -> The list of rolls in the RE4 that are going to be used for the efficiency scan, the normal procedure will be to include here the rolls after the remotion of the black list. An example file is also provided.


#####II. To create a directory called "eficiencias" (the directory is included by default) that will store the output of the code. As a result of running the code you will find the following files:

eficiencias_barrel0.txt:

It will contain the following columns: roll name (following the order provided in the file data_filtered/barrel_filtered.txt) , knee efficiency, knee efficiency +20 Volts, knee efficiency +40 Volts, knee efficiency +60 Volts, knee efficiency +80 Volts, knee voltage, knee voltage+ 100 Volts.

eficiencias_endcap0.txt:

It will contain the same information that in the previous case, the difference is that the it will use the rolls provided in the file data_filtered/endcap_filtered.txt.

eficiencias_re40.txt:

It will contain the same information that in the previous case, the difference is that the it will use the rolls provided in the file data_filtered/re4_filtered.txt.

eficiencias_barrel.txt, eficiencias_barrel2.txt, eficiencias_barrel3.txt, eficiencias_barrel4.txt, eficiencias_barrel5.txt:

Those files will contain the same information as in "eficiencias_barrel0.txt" the difference is the following in the columns:
eficiencias_barrel.txt: roll name, knee efficiency + 80, knee efficiency +100 Volts, knee efficiency +120 Volts, knee efficiency +140 Volts, knee efficiency +160 Volts, knee voltage, knee voltage+ 100 Volts.

The other files will continue the increasing in the voltage adding 20 volts every time to the knee efficiency  until the file eficiencias_barrel5.txt, that will contain the following info in the columns:

roll name, knee efficiency + 480, knee efficiency +500 Volts, knee efficiency +520 Volts, knee efficiency +540 Volts, knee efficiency +560 Volts, knee voltage, knee voltage+ 100 Volts.

The same conditions apply for the other files with eficiencias_endcap*.txt and eficiencias_re4*.txt but taking in account this time the rolls for the endcap (provided in the file data_filtered/endcap_filtered.txt) and the rolls for re4 (provided in the file data_filtered/re4_filtered.txt)

#####III. To run the code you have to run the provided files in the main directory, for example, to run the file "eficiencias_sinfit_general0.C" you have to do the following:

root -l

root [0] .x eficiencias_sinfit_general0.C

That file will use the following inputs:

data_filtered/re4_filtered.txt

data_filtered/endcap_filtered.txt

data_filtered/barrel_filtered.txt

The folder "results" that is created after runnign the HV Scan code, that folder contain several folders, one per every roll. As an example the folder with the name "W+2_RB4_S09_Backward". That folder will contain the following files: 

index.html

runsData.txt

CLSvsHV.png

EFFvsHV.png

fitData.txt

fitDataCLS.txt

The file eficiencias_sinfit_general0.C will produce the following outputs:

eficiencias/eficiencias_barrel0.txt

eficiencias/eficiencias_endcap0.txt

eficiencias/eficiencias_re40.txt

The same case will apply for the other files eficiencias_sinfit_general*.C, but in this case it will be a change in the voltage added in the calculation of the efficiency (20 volts in every step) as it was explained in the step II.

#####IV. The code also provide a file to create the plots for all the cases,  for example the file:
eficiencias/histos_eficiencias0.c

That file will produce the plots using the files 

eficiencias/eficiencias_barrel0.txt

eficiencias/eficiencias_endcap0.txt

eficiencias/eficiencias_re40.txt

The plots will be produced in the directory "histogramas_0" with the following names:

effendcap0.png

effRE40.png

effbarrel0.png

knee0.png

The same case will apply for all the other files: eficiencias/histos_eficiencias*.c

#####V. Finally, using the mean of the  plots in the previous step, you can create a plot of Efficiency VS added voltage to the "knee".
That plot will contain voltages from 0 until 560 Volts making steps of 20 volts. You can see an example of the kind of plot that you can create looking at the file eficiencias/efficiency_scan.png







