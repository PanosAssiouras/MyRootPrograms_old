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

 int get_points(string Filename, TGraph *gr)
{    //This function sets the points of each graph 
	 std:: ifstream inputFile(Filename);  
	 int points=0;
	  std::string line;
	  while(getline(inputFile, line)) {

      if (!line.length()|| line[0] == 'I' || line[0]=='B' || line[0]=='V'||line[0]=='#' || line.length()==1)
      {
         continue;
	 }
     else{    
      double Voltage=0.0 , Itotal=0.0 ,  I=0.0;
      sscanf(line.c_str(), "%lf %lf %lf", &Voltage, &Itotal , &I);          
      points++;    
      gr->SetPoint(points-1,abs(Voltage),Itotal*1E+9);
  }
   }
   return 0;
   } 
 //---------------------------------------------------------------------------------------------------------------  
int MaPsa_IV_v5()
{   
	
    TCanvas *c0=new TCanvas("c0","MaPSA std2, Variant 1: Individual strips IVs ",300,10,900,500);
    c0->SetGrid();
    
    TCanvas *c1=new TCanvas("c1","Total current, MaPsa std2, Variant:1  ",300,10,900,500);
    c1->SetGrid();
    
    TCanvas *c3=new TCanvas("c3","Current at 200V, MaPsa std2, Variant:1  ",300,10,900,500);
    c3->SetGrid();
     
     TCanvas *c5=new TCanvas("c5","Current at 200V, MaPsa std2, Variant:1  ",300,10,900,500);
     c5->SetGrid();

   

   TH2D *Hist= new TH2D("Hist","2D",48,0,48,6,0,6);

    TMultiGraph *mg = new TMultiGraph();
     mg->SetMinimum(-5);
     mg->SetMaximum(50.0);
	
   TLegend *leg = new TLegend(0.65, 0.35, 0.999, 0.95);
   leg->SetTextColor(kBlue);;
   leg->SetTextAlign(12);
   leg->SetTextAlign(12);
   leg-> SetNColumns(3); 
  
	
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
		     TGraph *gr=new TGraph(); 
     		 string r=files[i];
			 r=r.replace(r.begin()+pos,r.end(),".root");
			 char *root_name = new char[pos + 1];  
             std::strcpy(root_name, r.c_str());
					
	   if(files[i].find("Total_current.txt")==-1)
	   {
			float Voltage,Current,I;
			float* row_content;
	
    	    gr->SetMarkerStyle(markerstyle);
     	    gr->SetMarkerColor(markercolor);
     	    gr->SetLineColor(marker);
            gr->SetMarkerSize(0.6);
     	    
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
		
     	    get_points(files[i],gr); // call of get_points(string,TGraph) function 
     	    
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
            
            
               	    gr->SetMarkerStyle(markerstyle);
     	    gr->SetMarkerColor(markercolor);
     	    gr->SetLineColor(marker);
            gr->SetMarkerSize(0.6);
     	           	    
            c0->cd();        
            mg->Add(gr);
            mg->Draw("apl");
      
         
            leg->Draw("apl");
  
            gPad->Modified();
            gPad->Update();
            marker ++;
            markerstyle ++;
            markercolor ++;
            if(markerstyle == 30) {markerstyle=20;}
            if(markercolor == 9)  {markercolor=1;}
            leg->AddEntry(gr,name,"lp");

      	    
   //   Hist->Fill(x,y,I);
        }	     	       	         
     else{  //if name is Total_current.txt export graph to canvas c1     
	         c1->cd();
	         get_points(files[i],gr); // call of get_points(string,TGraph) function  
			gr->Draw("apl");
			gr->GetXaxis()->SetTitle("Voltage [V]");
            gr->GetYaxis()->SetTitle("Current [nA]");  
            gr->SetTitle("Total current, MaPsa std2, Variant:1 ");
            gr->SetMarkerStyle(3);
     	    gr->SetMarkerColor(9);
     	    gr->SetLineColor(12);
            gr->SetMarkerSize(0.8);
	   }
        }
	}
    
   
  TLine *line1 = new TLine(16,0,16,6);
  line1->SetLineColor(kBlack);
  
    TLine *line2 = new TLine(32,0,32,6);
  line2->SetLineColor(kBlack);
 
    
       mg->SetTitle("MaPSA std2, Variant 1: Individual strips IVs");
        gStyle->SetTitleFontSize(0.03);
        gStyle->SetTitleAlign(23); 
       mg->GetXaxis()->SetTitle("Voltage [V]");
       mg->GetYaxis()->SetTitle("Current [nA]");  
     
      gPad->Modified();
      gPad->Update();
      
       mg->SetTitle("MaPSA std2, Variant 1: Individual strips IVs");
      
      gPad->Modified();
      gPad->Update();
      
  


  gROOT->SetStyle("Plain");
  gStyle->SetPalette(1);
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
 
   TF1 *f=new TF1("f","x",1,4);
     TGaxis *A = new TGaxis(0,6,48,6,"f",3,"-M",10.0);
    f=new TF1("f","x",1,17);
   TGaxis *A1 = new TGaxis(0,0,16,0,"f",16,"+M",10.0);
  // TF1 *f2=new TF1("f2","x",1,17);
   TGaxis *A2 = new TGaxis(16,0,32,0,"f",16,"+M",10.0);
 //  TF1 *f3=new TF1("f3","x",1,17);
   TGaxis *A3 = new TGaxis(32,0,48,0,"f",16,"+M",10.0);
   A1->SetLabelSize(0.02);
   A2->SetLabelSize(0.02);
   A3->SetLabelSize(0.02);
 //  A1->SetGrid(); 
   A2->SetTitle("");
   A2->SetTitle("");
   A1->SetTitle("");
   A3->SetTitle("");
      A->SetLabelSize(0.03);
  //   A->SetGrid(); 
     A->SetTitle("");



    c3->cd();
    TAxis *Xaxis = Hist->GetXaxis();
    TAxis *Yaxis = Hist->GetYaxis();
    Xaxis->SetNdivisions(3,kTRUE);
    Yaxis->SetNdivisions(9,kTRUE);
     Xaxis->SetLabelOffset(999);    
     Hist->Draw("Colz");
     line1->Draw();
     line2->Draw();
     A->Draw();
     A1->Draw();
     A2->Draw();
     A3->Draw();
      gPad->Modified();
      gPad->Update();
     
         
        c5->cd();   
       Xaxis->SetLabelOffset(999);
       Hist->Draw("TEXT90");
       line1->Draw();
       line2->Draw();
       A1->Draw();
         A2->Draw();
         A3->Draw();
         A->Draw();
      gPad->Modified();
      gPad->Update();
      
  
 
     
    return 0;   
}
