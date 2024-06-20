
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
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}

 int get_points(string Filename, TGraph *gr)
{    std:: ifstream inputFile(Filename);  
	 int points=0;
	  std::string line;
	  while(getline(inputFile, line)) {

      if (!line.length()|| line[0] == 'I' || line[0]=='B' || line[0]=='V'||line[0]=='#' || line.length()==1)
      {
         continue;
	 }
     else{    
      double Voltage=0.0 , Backplane_Capacitance=0.0 , Strip_All=0.0 , Strip_Sum=0.0;  
      sscanf(line.c_str(), "%lf %lf %lf %lf", &Voltage, &Backplane_Capacitance , & Strip_All , &Strip_Sum);
                  
      points++;
     
      Backplane_Capacitance=Backplane_Capacitance*1E+12;
      Backplane_Capacitance=1.0/(Backplane_Capacitance);
      Backplane_Capacitance=pow(Backplane_Capacitance,2.0);
      
      gr->SetPoint(points-1,abs(Voltage),Backplane_Capacitance);

  }
   }
   return 0;
   } 

int MSSD_120_fit_points()
{   
    TCanvas *c0=new TCanvas("c0","CV_tests_with_GR/P_stop/Serial_Nb_22",300,10,900,500);
    c0->SetGrid();

    TMultiGraph *mg = new TMultiGraph();
     mg->SetMinimum(-5);
     mg->SetMaximum(100);
	
   TLegend *leg = new TLegend(0.65, 0.35, 0.999, 0.95);
  leg->SetTextColor(kBlue);;
  leg->SetTextAlign(12);
  leg->SetTextAlign(12); 
  
	vector<TGraph> TGraphs;
	
    string dir = string(".");
    vector<string> files = vector<string>();
    getdir(dir,files);
    
    int marker=0; 
    for (unsigned int i = 0;i < files.size();i++) {
        int pos= files[i].find(".txt");
        
        if(pos!=-1)
        { 
			
			marker++;
			cout<<files[i]<<endl;
			TGraph *gr=new TGraph();
			 gr->GetXaxis()->SetTitle("Voltage [V]");
             gr->GetYaxis()->SetTitle("1/C^{2} [pF^{-2}]"); 
			string s=files[i];
     	    get_points(s,gr);
     	    
     	    gr->SetMarkerStyle(marker);
     	    gr->SetMarkerColor(marker);
     	    gr->SetLineColor(marker);
     	    
     	    
     	    
     	    
     	    
     	    
     	    int pos=s.find(".");
     	   string s1=s.substr(0,pos);

   char *name = new char[pos + 1]; // or
   std::strcpy(name, s1.c_str());
      	    
            leg-> SetNColumns(3);
     	    leg->AddEntry(gr,name,"rp");  
     	    
        c0->cd();      
         mg->Add(gr);   
         mg->Draw("apl"); 
         leg->Draw("apl"); 
  
      gPad->Modified();
      gPad->Update();
	}	
	}
    
    mg->GetXaxis()->SetTitle("Voltage [V]");
     mg->GetYaxis()->SetTitle("I [nA]");  
     
      gPad->Modified();
      gPad->Update();
      
    return 0;
}
