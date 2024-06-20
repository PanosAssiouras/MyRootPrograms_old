
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>


using namespace std; 

TF1 *f1, *f2;
double finter(double *x, double*par) {
   return TMath::Abs(f1->EvalPar(x,par) - f2->EvalPar(x,par));
}


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
      if (!line.length() || line[0] == 'C' || line[0]=='B'|| line[0]=='T'||line[0]=='V' || line.length()==1)
         continue;
     double Voltage = 0., Backplane= 0., Strip=0. , StripAll=0.;
      sscanf(line.c_str(), "%lf %lf %lf %lf", &Voltage, &Backplane , &Strip , &StripAll);
      Backplane =Backplane*1E+12;
   
      Backplane=Backplane-2.36;
      Backplane=Backplane/32;
    
      Backplane=Backplane/3.049;
      
      Backplane =1.0/(Backplane);
      Backplane =pow(Backplane,2.0);    
     points++;

      gr->SetPoint(points-1,abs(Voltage),Backplane);
     

   }
   
   return 0;
   } 

int MaPsa_IV()
{   
   std::ofstream myfile;
    myfile.open ("Intersections.points.txt");
	
    TCanvas *c0=new TCanvas("c0","IV_tests_no_GR/MaPsa",300,10,900,500);
    c0->SetGrid();

   f1=new TF1("f1","pol1",0.0,160.0);
   f2=new TF1("f2","pol1",170.0,500);

    
    
   //
   
   // f1=new TF1("f1","pol1");
   // f2=new TF1("f2","pol1")

    TMultiGraph *mg = new TMultiGraph();
     mg->SetMinimum(0.0);
     mg->SetMaximum(2.5);

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
          int pos= files[i].find("backplane.txt");
        if(pos==-1){continue;}
			
			cout<<files[i]<<endl;
	
			
			marker++;
						
			TGraph *gr=new TGraph();
            gr->SetMarkerStyle(marker);
     	    gr->SetMarkerColor(marker);
     	    gr->SetLineColor(marker);
     	                            
			string s=files1[k]+"/"+files[i];
     	    get_points(s,gr);

 cout<< "fit of the rising edge"<<endl;     	    
   gr->Fit(f1 ,"R");   
 cout<< "fit of the horizontal edge"<<endl; 
   gr->Fit(f2,"R+");
    
 //   double slope; 
    
 //  slope=gr->GetFunction("f1")->GetParameter(1);
 //  cout << slope ;
//   ND=2.0/(slope*q*esi*pow(A_cd,2.0));
   
  // myfile <<files1[i]<<":"<<" C="<<ND<<" "<<" cm^{-3} "<<" \n";;
  
    
   TF1 *fint = new TF1("fint",finter,0,500.00);
   double xint = fint->GetMinimumX();
   double yint=xint*(gr->GetFunction("f1")->GetParameter(1))+(gr->GetFunction("f1")->GetParameter(0));
   
   
   
   std::string inter1="("+std:: to_string(xint)+","+std:: to_string(yint)+")";
   char *intersec1 = new char[inter1.length() + 1]; // or
   std::strcpy(intersec1, inter1.c_str());
   
   
  
   std::string Rag_name=files1[k];
   char *Ragion_name = new char[Rag_name.length() + 1]; // or
   std::strcpy(Ragion_name, inter1.c_str());
   
   
  //     leg->AddEntry(gr1,"Circular Diode","lp"); 
      
            leg->SetNColumns(3);
             
     
       
       leg->AddEntry(gr,Ragion_name,"lp");  
       leg->AddEntry(gr,intersec1,"lp");
       
      
  /*  c0->cd(1);  
       gr->GetXaxis()->SetTitle("Voltage [V]");
       gr->GetYaxis()->SetTitle("1/C^{2} [pF^{-2}]"); 
       gr->Draw("ap");
       leg->Draw("ap");
   
    
   */

   


   gPad->Modified();
   gPad->Update();
     	    
     	         	 
     	    string s1=s.substr(0,pos);

   char *name = new char[pos + 1]; // or
   std::strcpy(name, s1.c_str());
      	
    // 	    leg->AddEntry(gr,name,"rp");  
     	    
        c0->cd();      
         mg->Add(gr);   
         mg->Draw("apl"); 
         leg->Draw("apl"); 
  
      gPad->Modified();
      gPad->Update();

}
  
}       mg->GetXaxis()->SetTitle("Voltage [V]");
       mg->GetYaxis()->SetTitle("1/C^{2} [pF^{-2}]"); 
      gPad->Modified();
      gPad->Update();
      
    return 0;
}
