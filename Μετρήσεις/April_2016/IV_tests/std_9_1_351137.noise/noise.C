#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;



Double_t
poissonf(Double_t*x,Double_t*par)                                         
{                                                                              
  return par[0]*TMath::Poisson(x[0],par[1]);
}    


void Convert_TestDataFile_To_RootTree(TString TextDataName, TString RootDataName)
{
   TFile *f = new TFile(RootDataName,"RECREATE");

   TTree *T = new TTree("TRee","data from ascii file");
   
   TNtuple data("data","MaPsa_Current","Voltage:Current:null");

	 std:: ifstream inputFile(TextDataName); 
	  cout<<TextDataName<<endl;
	  std::string line;
	  while(getline(inputFile, line)) {
         double Voltage=0.0 , Itotal=0.0 ,  I=0.0;
      if (!line.length()|| line[0] == 'I' || line[0]=='B' || line[0]=='V'||line[0]=='#' || line.length()==1)
      {
         continue;
	 }
     else{    
      Voltage=0.0 , Itotal=0.0 ,  I=0.0;
      sscanf(line.c_str(), "%lf %lf %lf", &Voltage, &Itotal , &I);          
    //  T->Fill();
      data.Fill(Voltage,Itotal,I); 
  }
   }
   data.Write();
   T->Write();
   f->Write();
   f->Close();
}
//----------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------  
int getdir (string dir, vector<string> &files)
{   //This function search a folder  (dir) and keeps the names of it's contents to a vector<string> 
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl; // returns error if dir folder dosen't open
        return errno;
    }
    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name)); // fills the vector<string> with each name 
    }
    closedir(dp);
    return 0;
}
//----------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------  
int noise()
{   
	gROOT->Reset();
	
    TCanvas *c0=new TCanvas("c0","noise:0 to -350V:std_9_1_351137",300,10,900,500);
    c0->SetGrid();
    
    TCanvas *c1=new TCanvas("c1","Histogram:noise:std_9_1_351137",300,10,900,500);
    c1->SetGrid();
    
    TCanvas *c2=new TCanvas("c2","Histogram:noise:std_9_1_351137",300,10,900,500);
    c1->SetGrid();
 
 
    TGraph *gr= new TGraph();
    TH1F *Hist= new TH1F("Hist","",20,-150,150);
    TH1F *Hist1= new TH1F("Hist1","",20,0,150);
     
     
    vector<double_t> Voltage,Current;
    float* row_content,I;
    vector<double> dI;
     
    string dir = string(".");  // Set the folder for search (".") for parent file   
    vector<string> files = vector<string>(); // This vector will contain the names of each file in the folder after getdir function
    getdir(dir,files); // call of getdir(file,vector<string>) function
    for (unsigned int i = 0;i < files.size();i++) {
        size_t pos= files[i].find(".txt"); // for each file name check if it is a .txt file 
       if(pos!=-1) 
       {	 
     		 string r=files[i];
			 r=r.replace(r.begin()+pos,r.end(),".root");
			 char *root_name = new char[pos + 1];  
             std::strcpy(root_name, r.c_str());
	
             
     	    Convert_TestDataFile_To_RootTree(files[i],r);//convert txt files to root with ntuple
     	    TFile* in_file=new TFile(root_name);
            TNtuple* data=(TNtuple*) in_file->GetObjectChecked("data","TNtuple");
            for(int irow=0; irow<data->GetEntries();++irow)
            {   data->GetEntry(irow);
				row_content=data->GetArgs();
				Voltage.push_back(row_content[0]);
				Current.push_back(row_content[1]*1E+15);
				I=row_content[2];
	            gr->SetPoint(irow,abs(Voltage[irow]),Current[irow]);
	            
             }
      } 
     } 
    
           TF1 *f1=new TF1("f1","pol1",0.0,350.0);
     
    c0->cd();  
     gr->SetMarkerStyle(20); gr->SetMarkerColor(4); gr->SetLineColor(1); 
     gr->SetTitle("noise:0 t0 -350V:std_9_1_351137"); 
     gr->Fit("f1");
     gr->GetXaxis()->SetTitle("Voltage [V]");
     gr->GetYaxis()->SetTitle("Current[fA]"); 
     gr->Draw("alp");
     gPad->Modified();
     gPad->Update();
     
       double slope,b;
       slope=gr->GetFunction("f1")->GetParameter(1);
       b=gr->GetFunction("f1")->GetParameter(0);
       
     
        for(int i=0; i<Current.size();++i)
       {       
		      cout<<slope*abs(Voltage[i])+b<<endl;
		     // cout<<Current[i]<<endl;
		      dI.push_back(Current[i]-(slope*abs(Voltage[i])+b));
		      //cout<<dI[i]<<endl;
		      Hist->Fill(dI[i]);
		      Hist1->Fill(dI[i]);
		      
		   }
      
   
       
    c1->cd();
     Hist->SetTitle("Histogram:noise:std_9_1_351137");
     Hist->Fit("gaus");   
     Hist->GetXaxis()->SetTitle(" Current-yi  [fA]");
     Hist->GetYaxis()->SetTitle("Number of points"); 
     Hist->Draw();
     gPad->Modified();
     gPad->Update();
     
     c2->cd();
     Hist1->SetTitle("Histogram:noise:std_9_1_351137");
     Hist1->Fit("pois");   
     Hist1->GetXaxis()->SetTitle("#lbar Current-yi #lbar [fA]");
     Hist1->GetYaxis()->SetTitle("Number of points"); 
     Hist1->Draw();
     gPad->Modified();
     gPad->Update();
   
    return 0;   
}
