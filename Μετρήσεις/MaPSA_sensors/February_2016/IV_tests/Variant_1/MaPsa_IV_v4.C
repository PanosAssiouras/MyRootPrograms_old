
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>


using namespace std;


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
int MaPsa_IV_v4()
{   
	
    TCanvas *c0=new TCanvas("c0","MaPSA std2, Variant 1: Individual strips IVs ",300,10,900,500);
    c0->SetGrid();
    
    TCanvas *c1=new TCanvas("c1","Total current, MaPsa std2, Variant:1  ",300,10,900,500);
    c1->SetGrid();

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
        int pos= files[i].find(".txt"); // for each file name check if it is a .txt file 
   
        if(pos!=-1) 
            
        {
			cout<<files[i]<<endl;
			TGraph *gr=new TGraph();
			string s=files[i];
     	    
     	    get_points(s,gr); // call of get_points(string,TGraph) function 
     	    
 
     	    gr->SetMarkerStyle(markerstyle);
     	    gr->SetMarkerColor(markercolor);
     	    gr->SetLineColor(marker);
            gr->SetMarkerSize(0.6);
     	    
     	    //set names for TLegend
     	    int pos=s.find(".");
     	    string s1=s.substr(0,pos);
            char *name = new char[pos + 1];  
            std::strcpy(name, s1.c_str());
      	    
      	        	       	         
      if(files[i].find("Total_current.txt")!=-1) {  //if name is Total_current.txt export graph to canvas c1     
	         c1->cd();
			gr->Draw("apl");
			gr->GetXaxis()->SetTitle("Voltage [V]");
            gr->GetYaxis()->SetTitle("Current [nA]");  
            gr->SetTitle("Total current, MaPsa std2, Variant:1 ");
            gr->SetMarkerStyle(3);
     	    gr->SetMarkerColor(9);
     	    gr->SetLineColor(12);
            gr->SetMarkerSize(0.8);
            
           
	   }
	   else{
     	     
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
            
       }
        }
	}
    
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
    return 0;
}
