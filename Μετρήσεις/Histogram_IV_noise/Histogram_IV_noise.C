#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

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
int Histogram_IV_noise()
{   
	gROOT->Reset();
	
    TCanvas *c0=new TCanvas("c0","Histogram:noise:-5 to -300V",300,10,900,500);
    c0->SetGrid();
    
    TCanvas *c1=new TCanvas("c1","Histogram:noise:200V",300,10,900,500);
    c1->SetGrid();
    
    TCanvas *c2=new TCanvas("c2","Histogram:noise:-5 to -300V:7April",300,10,900,500);
    c2->SetGrid();
   
    TH1F *Hist1= new TH1F("Hist1","2D",15,-50,50);
    TH1F *Hist2= new TH1F("Hist2","2D",15,-50,50);
    TH1F *Hist3= new TH1F("Hist3","2D",20,-0.7,-0.2);
    
    string dir = string(".");  // Set the folder for search (".") for parent file   
    vector<string> files = vector<string>(); // This vector will contain the names of each file in the folder after getdir function
    
    getdir(dir,files); // call of getdir(file,vector<string>) function
    
    int markerstyle=20;
    int markercolor = 1;
    int marker =1 ;
    for (unsigned int i = 0;i < files.size();i++) {
        size_t pos= files[i].find(".txt"); // for each file name check if it is a .txt file 
       if(pos!=-1) 
       {	 
     		 string r=files[i];
     		 if(r=="noise_-5to-300.txt"){
			 r=r.replace(r.begin()+pos,r.end(),".root");
			 char *root_name = new char[pos + 1];  
             std::strcpy(root_name, r.c_str());
	
			float Voltage,Current,I;
			float* row_content;

     	    Convert_TestDataFile_To_RootTree(files[i],r);//convert txt files to root with ntuple
     	    TFile* in_file=new TFile(root_name);
            TNtuple* data=(TNtuple*) in_file->GetObjectChecked("data","TNtuple");
            for(int irow=0; irow<data->GetEntries();++irow)
            {   data->GetEntry(irow);
				row_content=data->GetArgs();
				Voltage=row_content[0];
				Current=row_content[1];
				I=row_content[2];
				
			        Hist1->Fill(Current*1E+12);
				}
			}	
			 if(r=="noise_7April.txt"){
			 r=r.replace(r.begin()+pos,r.end(),".root");
			 char *root_name = new char[pos + 1];  
             std::strcpy(root_name, r.c_str());
	
			float Voltage,Current,I;
			float* row_content;

     	    Convert_TestDataFile_To_RootTree(files[i],r);//convert txt files to root with ntuple
     	    TFile* in_file=new TFile(root_name);
            TNtuple* data=(TNtuple*) in_file->GetObjectChecked("data","TNtuple");
            for(int irow=0; irow<data->GetEntries();++irow)
            {   data->GetEntry(irow);
				row_content=data->GetArgs();
				Voltage=row_content[0];
				Current=row_content[1];
				I=row_content[2];
				
			        Hist3->Fill(Current*1E+12);
				}
			}	
			if(r=="noise@200V.txt")
			{
							 r=r.replace(r.begin()+pos,r.end(),".root");
			 char *root_name = new char[pos + 1];  
             std::strcpy(root_name, r.c_str());
	
			float Voltage,Current,I;
			float* row_content;

     	    Convert_TestDataFile_To_RootTree(files[i],r);//convert txt files to root with ntuple
     	    TFile* in_file=new TFile(root_name);
            TNtuple* data=(TNtuple*) in_file->GetObjectChecked("data","TNtuple");
            for(int irow=0; irow<data->GetEntries();++irow)
            {   data->GetEntry(irow);
				row_content=data->GetArgs();
				Voltage=row_content[0];
				Current=row_content[1];
				I=row_content[2];
				cout<<Current<<endl;
			        Hist2->Fill(Current*1E+12);
					
				}			
				}	    
        }	
	}

    c0->cd();  
     Hist1->SetTitle("Histogram:noise:5 to 200V"); 
     Hist1->Fit("gaus");
     Hist1->GetXaxis()->SetTitle("Current [pA]");
     Hist1->GetYaxis()->SetTitle("Number of strips"); 
     Hist1->Draw();
     gPad->Modified();
     gPad->Update();
        
    c1->cd();
     Hist2->SetTitle("Histogram:noise:200V");
     Hist2->Fit("gaus");   
     Hist2->GetXaxis()->SetTitle("Current [pA]");
     Hist2->GetYaxis()->SetTitle("Number of strips"); 
     Hist2->Draw();
     gPad->Modified();
     gPad->Update();
     
       c2->cd();
     Hist3->SetTitle("Histogram:noise:-5 to 200V:7April");
     Hist3->Fit("gaus");   
     Hist3->GetXaxis()->SetTitle("Current [pA]");
     Hist3->GetYaxis()->SetTitle("Number of strips"); 
     Hist3->Draw();
     gPad->Modified();
     gPad->Update();
     
    return 0;   
}
