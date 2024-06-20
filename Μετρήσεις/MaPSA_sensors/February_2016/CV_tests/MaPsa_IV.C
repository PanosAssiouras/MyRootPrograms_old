
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
		if((string(dirp->d_name)=="MaPsa_IV.C")||(string(dirp->d_name)==".")||(string(dirp->d_name)=="..")){continue;}
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

      if (!line.length()|| line[0] == 'I' || line[0]=='B' || line[0]=='H'||line[0]=='#' || line.length()==1)
      {
         continue;
	 }
     else{    
      double Voltage=0.0 , Itotal=0.0 ,  I=0.0;
      sscanf(line.c_str(), "%lf %lf %lf", &Voltage, &Itotal , &I);          
      if(Voltage<=250.0){
      points++;
      gr->SetPoint(points-1,abs(Voltage),Itotal*1E+9);
}
  }
   }
   return 0;
   } 

int MaPsa_IV()
{   
    TCanvas *c0=new TCanvas("c0","IV_tests_no_GR/MaPsa",300,10,900,500);
    c0->SetGrid();
    c0->SetLogy();

    TMultiGraph *mg = new TMultiGraph();
     mg->SetMinimum(-5);
     mg->SetMaximum(400);

   TLegend *leg = new TLegend(0.65, 0.15, 0.999, 0.45);
  leg->SetTextColor(kBlue);;
  leg->SetTextAlign(12);
  leg->SetTextAlign(12); 
  
	vector<TGraph> TGraphs;
	
    string dir = string(".");
    vector<string> files1 = vector<string>();
    getdir(dir,files1);
    
    
    int marker=0; 
    for (unsigned int k = 0;k < files1.size();k++) {
        cout << files1[k] << endl;
        
    string dir = string("./"+files1[k]);	
    vector<string> files = vector<string>();
    getdir(dir,files);
    

    for (unsigned int i = 0;i < files.size();i++) {     
          int pos= files[i].find("_no_GR.txt");
        if(pos==-1){continue;}
			
			marker++;
						
			TGraph *gr=new TGraph();
            gr->SetMarkerStyle(marker);
     	    gr->SetMarkerColor(marker);
     	    gr->SetLineColor(marker);
     	                            
			string s=files1[k]+"/"+files[i];
     	    get_points(s,gr);
     	         	 
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
