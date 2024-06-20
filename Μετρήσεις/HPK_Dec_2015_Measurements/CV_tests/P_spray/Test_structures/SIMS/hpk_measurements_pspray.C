#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include "TCanvas.h"
#include "TStyle.h"
#include "TH1.h"
#include "TGaxis.h"
#include "TRandom.h"
#include <sstream>
#include <cstring>
#include <string>
#include <stdio.h>    
#include <math.h>
#include "TROOT.h"
#include "TSystem.h"
#include "TMath.h"
using namespace std; 

TF1 *f1, *f2;
//int main()//uncomment if you prefer to compile as a standalone program.


double finter(double *x, double*par) {
   return TMath::Abs(f1->EvalPar(x,par) - f2->EvalPar(x,par));
}


void hpk_measurements_pspray()
{  
	
   std::ifstream inputFile1("Circular_Diode.txt");
   std::ifstream inputFile2("Diode.txt");
   std::ifstream inputFile3("Half_Diode.txt");
    std::ifstream inputFile4("Quarter_Diode.txt");
    
   std::ofstream myfile;
      myfile.open ("Concentration.txt");

   std::string line;
   std::vector<float_t> Voltages,Circular_Diode,Diode,Half_diode,Quarter_Diode;
   

   TCanvas *c1=new TCanvas("c1","graph",300,10,900,500);
   c1->SetGrid();
 
    TMultiGraph *mg = new TMultiGraph();
   
   TGraph  *gr1=new TGraph();  
    TGraph *gr2=new TGraph();  
    TGraph *gr3=new TGraph();  
    TGraph *gr4=new TGraph();  
    
    
   gr1->SetMarkerStyle(20); gr1->SetMarkerColor(1);
   gr2->SetMarkerStyle(21); gr2->SetMarkerColor(7);
   gr3->SetMarkerStyle(22); gr3->SetMarkerColor(3);
   gr4->SetMarkerStyle(23); gr4->SetMarkerColor(4);
   
     f1=new TF1("f1","pol1",0.0,190.0);
    f2=new TF1("f2","pol1",170.0,550);


   gStyle->SetLegendBorderSize(1);
   gStyle->SetLegendTextSize(0.025); 
   
    TLegend *leg = new TLegend(0.75, 0.35, 0.999, 0.70);
 
  leg->SetTextColor(kBlue);;
  leg->SetTextAlign(12);
  leg->SetTextAlign(12); 
   



     int points=0;
  
   while(getline(inputFile1, line)) {

      if (!line.length()|| line[0] == 'C' || line[0]=='B' || line[0]=='V'||line[0]=='#' || line.length()==1)
      {
         continue;
	 }
     else{    
      double Voltage=0.0 , Backplane_Capacitance=0.0 , Strip_All=0.0 , Strip_Sum=0.0;  
      sscanf(line.c_str(), "%lf %lf %lf %lf", &Voltage, &Backplane_Capacitance , & Strip_All , &Strip_Sum);
          
      Backplane_Capacitance=Backplane_Capacitance*1E+12-2.54;
    //   Backplane_Capacitance=Backplane_Capacitance*1E+15-2.54*1E+3;
     //  Backplane_Capacitance=Backplane_Capacitance-2.54*1E-12;
      
      Backplane_Capacitance=1.0/(Backplane_Capacitance);
      Backplane_Capacitance=pow(Backplane_Capacitance,2.0);
          
     points++;

     if(((abs(Voltage)>=180.0)&&(abs(Voltage)<=200.00))){continue;}
     else{
      gr1->SetPoint(points-1,abs(Voltage),Backplane_Capacitance);
   }
  }
   }
   
   
   

    gr1->Fit(f1 ,"R");   
    gr1->Fit(f2,"R+");
    
   TF1 *fint = new TF1("fint",finter,0,500.00);
   double xint = fint->GetMinimumX();
   double yint=xint*(gr1->GetFunction("f1")->GetParameter(0))+(gr1->GetFunction("f1")->GetParameter(1));
   
   
   
   std::string inter1="("+std:: to_string(xint)+","+std:: to_string(yint)+")";
   char *intersec1 = new char[inter1.length() + 1]; // or
   std::strcpy(intersec1, inter1.c_str());
   
   

    leg->AddEntry(gr1,"Circular Diode","lp");
       leg->AddEntry(gr1,intersec1,"lp");
    mg->Add(gr1);
//    mg->SetMinimum(0);
//    mg->SetMaximum(1.0);
    mg->Draw("ap");  
   
   
   gPad->Modified();
   gPad->Update();
 
//---------------------------------------------------------------------------------------------------

//Diode.txt
   
      points=0;
 
   while(getline(inputFile2, line)) {

      if (!line.length()|| line[0] == 'C' || line[0]=='B' || line[0]=='V'||line[0]=='#' || line.length()==1)
      {
         continue;
	 }
     else{    
      double Voltage=0.0 , Backplane_Capacitance=0.0 , Strip_All=0.0 , Strip_Sum=0.0;  
      sscanf(line.c_str(), "%lf %lf %lf %lf", &Voltage, &Backplane_Capacitance , & Strip_All , &Strip_Sum);
          
      Backplane_Capacitance=Backplane_Capacitance*1E+12-2.54;
     //       Backplane_Capacitance=Backplane_Capacitance*1E+15-2.54*1E+3;
      //       Backplane_Capacitance=Backplane_Capacitance-2.54*1E-12;
             
      Backplane_Capacitance=1.0/(Backplane_Capacitance);
      Backplane_Capacitance=pow(Backplane_Capacitance,2.0);
          
     points++;
    // std::cout<<"point["<<points<<"]: ("<<abs(Voltage)<<" , "<<Backplane_Capacitance<<")\n"; 
   //  gr1->SetPoint(points-1,abs(Voltage),Backplane_Capacitance);
     if(((abs(Voltage)>=180.0)&&(abs(Voltage)<=200.00))){continue;}
     else{
      gr2->SetPoint(points-1,abs(Voltage),Backplane_Capacitance);
   }
  }
   }
   

     
    gr2->Fit(f1 ,"R");   
    gr2->Fit(f2,"R+");
    
    
          fint = new TF1("fint",finter,0,500.00);
          xint = fint->GetMinimumX();
          yint=xint*(gr2->GetFunction("f1")->GetParameter(0))+(gr2->GetFunction("f1")->GetParameter(1));
   
   
   
   std::string inter2="("+std:: to_string(xint)+","+std:: to_string(yint)+")";
   char *intersec2 = new char[inter2.length() + 1]; // or
   std::strcpy(intersec2, inter2.c_str());
   
   

    
    mg->Add(gr2);
 //   mg->SetMinimum(0);
 //   mg->SetMaximum(1.0);
    mg->Draw("ap");  
   
     leg->AddEntry(gr2,"Diode","lp");
          leg->AddEntry(gr2,intersec2,"lp");
   
   gPad->Modified();
   gPad->Update();
   
//---------------------------------------------------------------------------------------------------
//Half_Diode.txt 
      
       points=0;
 
   while(getline(inputFile3, line)) {

      if (!line.length()|| line[0] == 'C' || line[0]=='B' || line[0]=='V'||line[0]=='#' || line.length()==1)
      {
         continue;
	 }
     else{    
      double Voltage=0.0 , Backplane_Capacitance=0.0 , Strip_All=0.0 , Strip_Sum=0.0;  
      sscanf(line.c_str(), "%lf %lf %lf %lf", &Voltage, &Backplane_Capacitance , & Strip_All , &Strip_Sum);
          
       Backplane_Capacitance=Backplane_Capacitance*1E+12-2.54;
       //  Backplane_Capacitance=Backplane_Capacitance*1E+15-2.54*1E+3;
           
        //   Backplane_Capacitance=Backplane_Capacitance-2.54*1E-12;
      Backplane_Capacitance=1.0/(Backplane_Capacitance);
      Backplane_Capacitance=pow(Backplane_Capacitance,2.0);
          
     points++;
   //  std::cout<<"point["<<points<<"]: ("<<abs(Voltage)<<" , "<<Backplane_Capacitance<<")\n"; 
   //  gr1->SetPoint(points-1,abs(Voltage),Backplane_Capacitance);
     if(((abs(Voltage)>=180.0)&&(abs(Voltage)<=200.00))){continue;}
     else{
      gr3->SetPoint(points-1,abs(Voltage),Backplane_Capacitance);
   }
  }
   }

     
    gr3->Fit(f1 ,"R");   
    gr3->Fit(f2,"R+");
    
        
          fint = new TF1("fint",finter,0,500.00);
          xint = fint->GetMinimumX();
          yint=xint*(gr3->GetFunction("f1")->GetParameter(0))+(gr3->GetFunction("f1")->GetParameter(1));
   
   
   
   std::string inter3="("+std:: to_string(xint)+","+std:: to_string(yint)+")";
   char *intersec3 = new char[inter2.length() + 1]; // or
   std::strcpy(intersec3, inter3.c_str());
    
    
    mg->Add(gr3);
 //   mg->SetMinimum(0);
 //   mg->SetMaximum(1.0);
    mg->Draw("ap");  
    
    leg->AddEntry(gr3,"Half Diode","lp");
        leg->AddEntry(gr3,intersec3,"lp");
   
   gPad->Modified();
   gPad->Update();
 
//---------------------------------------------------------------------------------------------------
//Quarter_Diode.txt
      
       points=0;
 
   while(getline(inputFile4, line)) {

      if (!line.length()|| line[0] == 'C' || line[0]=='B' || line[0]=='V'||line[0]=='#' || line.length()==1)
      {
         continue;
	 }
     else{    
      double Voltage=0.0 , Backplane_Capacitance=0.0 , Strip_All=0.0 , Strip_Sum=0.0;  
      sscanf(line.c_str(), "%lf %lf %lf %lf", &Voltage, &Backplane_Capacitance , & Strip_All , &Strip_Sum);
          
        Backplane_Capacitance=Backplane_Capacitance*1E+12-2.54;
      //   Backplane_Capacitance=Backplane_Capacitance*1E+15-2.54*1E+3;
    //   Backplane_Capacitance=Backplane_Capacitance-2.54*1E-12;
      Backplane_Capacitance=1.0/(Backplane_Capacitance);
      Backplane_Capacitance=pow(Backplane_Capacitance,2.0);
          
     points++;
   //  std::cout<<"point["<<points<<"]: ("<<abs(Voltage)<<" , "<<Backplane_Capacitance<<")\n"; 
   //  gr1->SetPoint(points-1,abs(Voltage),Backplane_Capacitance);
     if(((abs(Voltage)>=180.0)&&(abs(Voltage)<=200.00))){continue;}
     else{
      gr4->SetPoint(points-1,abs(Voltage),Backplane_Capacitance);
   }
  }
   }
   //  f1=new TF1("f1","pol1",0.0,100.0);

    gr4->Fit(f1 ,"R");   
    gr4->Fit(f2,"R+");
    
    
        
          fint = new TF1("fint",finter,0,500.00);
          xint = fint->GetMinimumX();
          yint=xint*(gr4->GetFunction("f1")->GetParameter(0))+(gr4->GetFunction("f1")->GetParameter(1));
   
   
   
   std::string inter4="("+std:: to_string(xint)+","+std:: to_string(yint)+")";
   char *intersec4 = new char[inter4.length() + 1]; // or
   std::strcpy(intersec4, inter4.c_str());
   
    
   leg->AddEntry(gr4,"Quarter Diode","lp");
      leg->AddEntry(gr4,intersec4,"lp");
     
    
    
    mg->Add(gr4);
   mg->GetXaxis()->SetTitle("Voltage [V]");
   mg->GetYaxis()->SetTitle("1/C^{2} [pF^{-2}]"); 
    mg->SetMinimum(-0.1);
    mg->SetMaximum(0.9);
    mg->Draw("ap");  
    leg->Draw();
   
   gPad->Modified();
   gPad->Update();
   
//--------------------------------------------------------------------------------------------------
     
}



