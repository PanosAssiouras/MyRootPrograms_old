#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int Histogram()
{   
	gROOT->Reset();
   std:: ifstream inputFile("two.Gaussians.txt"); 
  
    TCanvas *c0=new TCanvas("c0","Histogram:With rate:With no rate",300,10,900,500);
    c0->SetGrid();
   
      TLegend *leg = new TLegend(0.85, 0.45, 0.999, 0.65); 

    TH1F *Hist1= new TH1F("Hist1","Histogram:With rate:With no rate",51,4.2,5.2);
    TH1F *Hist2= new TH1F("Hist2","Histogram:With rate:With no rate",51,4.2,5.2);

    double with_no_rates,with_rates;
	  cout<<inputFile<<endl;
	  std::string line;
	  int bin_count=1;
      while(getline(inputFile, line)) {
         double time1=0.0,with_no_rate=0.0,time2=0.0,with_rate=0.0 ,  bin_number=0.0;
      if (!line.length()|| line[0] == 'T' || line[0]=='B' || line[0]=='V'||line[0]=='#' || line.length()==1)
      {
         continue;
	 }
     else{    
      sscanf(line.c_str(), "%lf %lf %lf %lf %lf", &time1, &with_no_rate , &time2, &with_rate, &bin_number);                  
			 Hist1->Fill(with_rate);
                         Hist2->Fill(with_no_rate);
      }
      }
  
    leg->SetTextColor(kBlue);;
     leg->SetTextAlign(11);
      leg->SetTextAlign(11);
       
       


    c0->cd();  
     TF1 *f1= new TF1("f1","gaus",4.2,4.5);
     f1->SetLineColor(kRed);  
      
     Hist1->SetTitle("Histogram:With rate:With no rate"); 
  //   Hist1->GetXaxis()->SetTitle("Current [pA]");
  //   Hist1->GetYaxis()->SetTitle("Number of points"); 
       Hist1->SetFillColorAlpha(kBlue, 0.10);
   //    Hist1->SetLineColor(kBlue);
     Hist1->Fit(f1);
    
     
   //   leg->AddEntry(Hist1, "with with_rate", "lp");
      leg->AddEntry(f1,"with rate ","l");  
 
     TF1 *f2= new TF1("f2","gaus",4.8,5.2);
     f2->SetLineColor(kBlue);

    Hist2->SetFillColorAlpha(kGray, 0.10);
   //  Hist2->SetLineColor(kRed);
     Hist2->Fit(f2);
    
  //   leg->AddEntry(Hist2, "no rate", "lp");    
     leg->AddEntry("f2","with no rate","l");

     Hist2->Draw();
     leg->Draw();
     gPad->Modified();
     gPad->Update();
     Hist1->Draw("same");
     leg->Draw();
     gPad->Modified();
     gPad->Update();
   

    return 0;
}  

