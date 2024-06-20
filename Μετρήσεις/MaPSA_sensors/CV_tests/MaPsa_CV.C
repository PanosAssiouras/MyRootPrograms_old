#include "TFile.h" 
#include "TTree.h"
#include "TString.h"
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>


using namespace std;

int getdir (string dir, vector<string> &files)
{ 
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }
    while ((dirp = readdir(dp)) != NULL) {
		if((string(dirp->d_name)=="MaPsa_CV.C")||(string(dirp->d_name)==".")||(string(dirp->d_name)=="..")){continue;}
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}

 int get_points(string Filename, TGraph *gr)
{      double Voltage=0.0 , Backplane=0.0 ,  C=0.0,Ctotal=0.0; 
	std:: ifstream inputFile(Filename);  
	 int points=0;

	  std::string line;
	  while(getline(inputFile, line)) {

      if (!line.length()|| line[0] == 'C' || line[0]=='B' || line[0]=='V'||line[0]=='#' || line.length()==1)
      {
         continue;
	 }
     else{    
   
      sscanf(line.c_str(), "%lf %lf %lf %lf", &Voltage, &Backplane , &C,&Ctotal);          
      if(Voltage<=250.0){
      points++;
      Backplane=Backplane*1E+12;
      Backplane=Backplane-2.36;
      Backplane=1.0/Backplane;
       Backplane=pow(Backplane,2.0);
      gr->SetPoint(points-1,abs(Voltage),Backplane);
}
  }
   }
   cout<< points <<endl;

   return 0;
   } 

int MaPsa_CV()
{   
    TCanvas *c0=new TCanvas("c0","CV_tests_Backplane_1Mhz/MaPsa",300,10,900,500);
    c0->SetGrid();

     
     
    TCanvas *c1=new TCanvas("c1","CV_tests_Backplane_1Mhz/MaPsa",300,10,900,500);
    c1->Divide(2,2,0.001,0.001);
    c1->SetGrid();
    

  
  
    TMultiGraph *mg = new TMultiGraph();
     mg->SetMinimum();
     mg->SetMaximum();

   TLegend *leg = new TLegend(0.65, 0.15, 0.999, 0.25);
  leg->SetTextColor(kBlue);;
  leg->SetTextAlign(12);
  leg->SetTextAlign(12); 
  

	vector<TGraph> TGraphs;
	
    string dir = string(".");
    vector<string> files1 = vector<string>();
    getdir(dir,files1);
    
    
    int marker=1; 
    int graph_number=0;
    for (unsigned int k = 0;k < files1.size();k++) {
        cout << files1[k] << endl;
        
    string dir = string("./"+files1[k]);	
    vector<string> files = vector<string>();
    getdir(dir,files);
    

    for (unsigned int i = 0;i < files.size();i++) {     
          int pos= files[i].find("1Mhz.txt");
        if(pos==-1){continue;}
	
		graph_number++;
	
 TLegend *leg2= new TLegend(0.75, 0.35, 0.95, 0.45);
  leg2->SetTextColor(kBlue);;
  leg2->SetTextAlign(12);
  leg2->SetTextAlign(12); 
  
			
			marker++;
	
			
	cout << graph_number << endl ;					
			TGraph *gr=new TGraph();
		c0->cd();	
            gr->SetMarkerStyle(marker);
     	    gr->SetMarkerColor(marker+4);
     	    gr->SetLineColor(marker+4);
     	  
   
     	                            
			string s=files1[k]+"/"+files[i];
     	    get_points(s,gr);
     	         	 
     	    string s1=s.substr(0,pos);

   char *name = new char[pos + 1]; // or
   std::strcpy(name, s1.c_str());
      	    
            leg-> SetNColumns(4);
     	    leg->AddEntry(gr,name,"lp");  
  
  
        c1->cd(graph_number);        
          gr->SetTitle("Backplane Capacitance 1Mhz");  
          gr->GetXaxis()->SetTitle("Voltage [V]");
          gr->GetYaxis()->SetTitle("Backplane Capcitance [pF^{-2}]");  
          gr->GetXaxis()->SetNoExponent(kTRUE);
          gr->Draw("apl");
          leg2->AddEntry(gr,name,"lp");   
          leg2->Draw("apl"); 
 
  
     	    
        c0->cd();      
         mg->Add(gr);   
         mg->Draw("apl"); 
         leg->Draw("apl"); 
         

      gPad->Modified();
      gPad->Update();
      
      	
}
  }  

  //TGaxis *myX = (TGaxis*)mg->GetXaxis();
 // myX->SetMaxDigits(2);
  
  TGaxis::SetMaxDigits(2);
  mg->GetXaxis()->SetNoExponent(kTRUE);
 
  
  
  c0->cd();
    mg->GetXaxis()->SetTitle("Voltage [V]");
    mg->GetYaxis()->SetTitle("Backplane Capcitance [pF^{-2}]");  
    gPad->Modified();
    gPad->Update();
      
      
        
      mg->SetTitle("Backplane Capacitance 1Mhz,Variant 1,2,3,4");    

     
      gPad->Modified();
      gPad->Update();
      
    return 0;
}
