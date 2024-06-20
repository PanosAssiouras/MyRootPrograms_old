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
   gROOT->Reset();
   
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
 //---------------------------------------------------------------------------------------------------------------  
int MaPsa_IV_lego()
{   

     TCanvas *c4=new TCanvas("c4","Current at 200V, MaPsa std2, Variant:1  ",300,10,900,500);
     c4->SetGrid();
     
 
   TH2D *Hist= new TH2D("Hist","2D",48,0,48,6,0,6);
  
	
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
			 r=r.replace(r.begin()+pos,r.end(),".root");
			 char *root_name = new char[pos + 1];  
             std::strcpy(root_name, r.c_str());
					
	   if(files[i].find("Total_current.txt")==-1)
	   {
			float Voltage,Current,I;
			float* row_content;
		
		
     	    
     	    //abstract numbers from each file name region and strip number 
     	    int pos=files[i].find(".");
     	    string s1=files[i].substr(0,pos);
            char *name = new char[pos + 1];  
            std::strcpy(name, s1.c_str());
         
            int pos1=s1.find("_");
            string s2=s1.substr(pos1+1,pos);
            int pos2=s2.find("_");
            string region1=s2.substr(0,pos2);
            string strip_number1=s2.substr(pos2+1,pos);
      	    int region=atoi(region1.c_str());
      	    int strip_number=atoi(strip_number1.c_str());
      	    //------------------------------------------
      	    //for each region and strip number find the position in x and y axis 
      	    int x,y;    
      	    if(region<=3){
			x=1	;
      	    y= strip_number+16*(region-1);
		    }
      	    else if((region>=3)&&(region<=6)){
				x=2;
				 y=strip_number+16*(region-4);
				}
			else if((region>6)&&(region<=9)){
				x=3;
				y=strip_number+16*(region-7);
				}
			else if((region>9)&&(region<=12)){
				x=4;
			y= strip_number+16*(region-10);
			}
			else if((region>12)&&(region<=15)){
				x=5;
			y= strip_number+16*(region-13);
			}
			else if((region>15)&&(region<=18)){
				x=6;
			y= strip_number+16*(region-16);
				}		
			//-------------------------------------------------------------------------	
     	    //Set Bin label
      	    for(int i=1;i<=48;i++){ 
			//convert integer to string	  
            string x;         
            ostringstream convert;   
            convert << i;      
            x= convert.str();
            //--------------------------
            Hist->GetXaxis()->SetBinLabel(i,x.c_str());
		    }
		
		    for(int i=1;i<=6;i++){
			//convert integer to string	
            string y;          
            ostringstream convert;   
            convert <<7-i; //7-i so 1 goes up
            y= convert.str();
            //-------------------------
            Hist->GetYaxis()->SetBinLabel(i,y.c_str());
		    }
		    //------------------------------------------------------------------------
		
     	    
     	    Convert_TestDataFile_To_RootTree(files[i],r);//convert txt files to root with ntuple
     	    TFile* in_file=new TFile(root_name);
            TNtuple* data=(TNtuple*) in_file->GetObjectChecked("data","TNtuple");
            for(int irow=0; irow<data->GetEntries();++irow)
            {   data->GetEntry(irow);
				row_content=data->GetArgs();
				Voltage=row_content[0];
				Current=row_content[1];
				if(Current<0){
					continue;
					}
				I=row_content[2];
				if((abs(Voltage)==200)){	
					string y1;
					ostringstream convert1;
					convert1<<y;
					y1=convert1.str();
					//string y1;
					//convert_integer_to_string(y,y1);
					string x1;
					ostringstream convert2;
					convert2<<x;
					x1=convert2.str();
					
			        Hist->Fill(y1.c_str(),x1.c_str(),Current*1E+09);
					}
							
			//	cout<<Voltage<<"\t"<<Current<<endl;
				}    	    
            

        }	     	       	         
        }
	}
    
   
  TLine *line1 = new TLine(16,0,16,6);
   line1->SetLineColor(kBlack);
  
    TLine *line2 = new TLine(32,0,32,6);
  line2->SetLineColor(kBlack);
 

  gROOT->SetStyle("Plain");
  gStyle->SetPalette(1);
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
 


   
      c4->cd();    
    TAxis *Xaxis1 = Hist->GetXaxis();
    TAxis *Yaxis1= Hist->GetYaxis();
    Xaxis1->SetNdivisions(3,kTRUE);
    Yaxis1->SetNdivisions(9,kTRUE);
    Xaxis1->SetLabelOffset(0);
      Hist->Draw("Lego2");
        line1->Draw();
        line2->Draw();
      gPad->Modified();
      gPad->Update();
 
  
 
     
    return 0;   
}

