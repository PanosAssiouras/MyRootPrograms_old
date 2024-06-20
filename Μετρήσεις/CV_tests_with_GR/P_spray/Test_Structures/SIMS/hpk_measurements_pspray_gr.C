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
#include <iomanip> 
#include "TROOT.h"
#include "TSystem.h"
#include "TMath.h"

using namespace std; 

TF1 *f1, *f2;
double finter(double *x, double*par) {
   return TMath::Abs(f1->EvalPar(x,par) - f2->EvalPar(x,par));
}


void hpk_measurements_pspray_gr()
{  
   std::ifstream inputFile1("Circular_Diode.txt");
   std::ifstream inputFile2("Diode.txt");
   std::ifstream inputFile3("Half_Diode.txt");
   std::ifstream inputFile4("Quarter_Diode.txt");

   std::ofstream myfile;
   myfile.open ("Concentration.txt");
        

   std::string line;
   std::vector<float_t> Voltages,Circular_Diode,Diode,Half_diode,Quarter_Diode;
      

    TCanvas *c1=new TCanvas("c1","CV_tests_with_GR/P_spray",300,10,900,500);
    c1->Divide(2,2,0.0001,0.0001);
    c1->SetGrid();
    TCanvas *c0=new TCanvas("c0","CV_tests_with_GR/P_spray",300,10,900,500);
    c0->SetGrid();

    TMultiGraph *mg = new TMultiGraph();
   
    TGraph  *gr1=new TGraph();  
    TGraph *gr2=new TGraph();  
    TGraph *gr3=new TGraph();  
    TGraph *gr4=new TGraph();  
    
    
   gr1->SetMarkerStyle(20); gr1->SetMarkerColor(1);
   gr2->SetMarkerStyle(21); gr2->SetMarkerColor(7);
   gr3->SetMarkerStyle(22); gr3->SetMarkerColor(3);
   gr4->SetMarkerStyle(23); gr4->SetMarkerColor(4);
   
    f1=new TF1("f1","pol1",0.0,160.0);
    f2=new TF1("f2","pol1",170.0,550);


   gStyle->SetLegendBorderSize(1);
   gStyle->SetLegendTextSize(0.025); 
   
  TLegend *leg = new TLegend(0.75, 0.30, 0.999, 0.65);
  leg->SetTextColor(kBlue);;
  leg->SetTextAlign(12);
  leg->SetTextAlign(12); 
  
  
   gStyle->SetLegendBorderSize(1);
   gStyle->SetLegendTextSize(0.035); 
   
  
  TLegend *leg1 = new TLegend(0.75, 0.35, 0.999, 0.45);
  leg1->SetTextColor(kBlue);;
  leg1->SetTextAlign(12);
  leg1->SetTextAlign(12); 
  
  TLegend *leg2 = new TLegend(0.75, 0.35, 0.999, 0.45);
  leg1->SetTextColor(kBlue);;
  leg1->SetTextAlign(12);
  leg1->SetTextAlign(12); 
  
  TLegend *leg3 = new TLegend(0.75, 0.35, 0.999, 0.45);
  leg3->SetTextColor(kBlue);;
  leg3->SetTextAlign(12);
  leg3->SetTextAlign(12); 

  TLegend *leg4 = new TLegend(0.75, 0.35, 0.999, 0.45);
  leg4->SetTextColor(kBlue);;
  leg4->SetTextAlign(12);
  leg4->SetTextAlign(12); 


const double q=1.6*1E-07; //[pF*V]
const double esi=1.04;// [pF/cm]

double slope;

//Circular_Diode.txt 

     double A_cd=M_PI*pow(1.5/2,2.0)*1E-2; // [cm^2]
    
     
     int points=0;
  
   while(getline(inputFile1, line)) {

      if (!line.length()|| line[0] == 'C' || line[0]=='B' || line[0]=='V'||line[0]=='#' || line.length()==1)
      {
         continue;
	 }
     else{    
      double Voltage=0.0 , Backplane_Capacitance=0.0 , Strip_All=0.0 , Strip_Sum=0.0;  
      sscanf(line.c_str(), "%lf %lf %lf %lf", &Voltage, &Backplane_Capacitance , & Strip_All , &Strip_Sum);
          
      Backplane_Capacitance=Backplane_Capacitance*1E+12;
      Backplane_Capacitance=1.0/(Backplane_Capacitance);
      Backplane_Capacitance=pow(Backplane_Capacitance,2.0);
          
     points++;

  //   if(((abs(Voltage)>=180.0)&&(abs(Voltage)<=200.00))){continue;}
   //  else{
      gr1->SetPoint(points-1,abs(Voltage),Backplane_Capacitance);
  // }
  }
   }
   
   
   

    gr1->Fit(f1 ,"R");   
    gr1->Fit(f2,"R+");
    
   slope=gr1->GetFunction("f1")->GetParameter(1);
   cout << slope ;
   ND=2.0/(slope*q*esi*pow(A_cd,2.0));
   
   myfile <<"Circular Diode:"<<" "<<" ND="<<" "<<ND<<" "<<" cm^{-3} "<<" \n";
   
    
   TF1 *fint = new TF1("fint",finter,0,500.00);
   double xint = fint->GetMinimumX();
   double yint=xint*(gr1->GetFunction("f1")->GetParameter(1))+(gr1->GetFunction("f1")->GetParameter(0));
   
   
   
   std::string inter1="("+std:: to_string(xint)+","+std:: to_string(yint)+")";
   char *intersec1 = new char[inter1.length() + 1]; // or
   std::strcpy(intersec1, inter1.c_str());
   
   
       leg->AddEntry(gr1,"Circular Diode","lp");  
       leg->AddEntry(gr1,intersec1,"lp");
       
       leg1->AddEntry(gr1,"Circular Diode","lp");  
       leg1->AddEntry(gr1,intersec1,"lp");
       
    c1->cd(1);  
       gr1->GetXaxis()->SetTitle("Voltage [V]");
       gr1->GetYaxis()->SetTitle("1/C^{2} [pF^{-2}]"); 
       gr1->Draw("ap");
       leg1->Draw("ap");
   
   c0->cd();      
       mg->Add(gr1);
       mg->Draw("ap");  
   

   
   gPad->Modified();
   gPad->Update();
 
//---------------------------------------------------------------------------------------------------

//Diode.txt

   double A_d=25*1E-2 ;// [cm^2]
   
      points=0;
 
   while(getline(inputFile2, line)) {

      if (!line.length()|| line[0] == 'C' || line[0]=='B' || line[0]=='V'||line[0]=='#' || line.length()==1)
      {
         continue;
	 }
     else{    
      double Voltage=0.0 , Backplane_Capacitance=0.0 , Strip_All=0.0 , Strip_Sum=0.0;  
      sscanf(line.c_str(), "%lf %lf %lf %lf", &Voltage, &Backplane_Capacitance , & Strip_All , &Strip_Sum);
          
      Backplane_Capacitance=Backplane_Capacitance*1E+12;
      Backplane_Capacitance=1.0/(Backplane_Capacitance);
      Backplane_Capacitance=pow(Backplane_Capacitance,2.0);
          
     points++;
    // std::cout<<"point["<<points<<"]: ("<<abs(Voltage)<<" , "<<Backplane_Capacitance<<")\n"; 
   //  gr1->SetPoint(points-1,abs(Voltage),Backplane_Capacitance);
  //   if(((abs(Voltage)>=180.0)&&(abs(Voltage)<=200.00))){continue;}
  //   else{
      gr2->SetPoint(points-1,abs(Voltage),Backplane_Capacitance);
  // }
  }
   }
   

     
    gr2->Fit(f1 ,"R");   
    gr2->Fit(f2,"R+");
    
    
   slope=gr2->GetFunction("f1")->GetParameter(1);
   cout << slope ;
   ND=2.0/(slope*q*esi*pow(A_d,2.0));
   
   myfile <<"Diode:"<<" "<<" ND="<<" "<<ND<<" "<<" cm^{-3} "<<" \n";
    
    
          fint = new TF1("fint",finter,0,500.00);
          xint = fint->GetMinimumX();
   
        //   xint= ceil(xint*pow(10,2))/pow(10,2);
          
          yint=xint*(gr2->GetFunction("f1")->GetParameter(1))+(gr2->GetFunction("f1")->GetParameter(0));
      
    
   
   std::string inter2="("+std:: to_string(xint)+","+std:: to_string(yint)+")";
   char *intersec2 = new char[inter2.length() + 1]; // or
   std::strcpy(intersec2, inter2.c_str());
   
       leg->AddEntry(gr2,"Diode","lp");
          leg->AddEntry(gr2,intersec2,"lp");
   
      leg2->AddEntry(gr2,"Diode","lp");
          leg2->AddEntry(gr2,intersec2,"lp");
   
 
     c1->cd(2); 
         gr2->GetXaxis()->SetTitle("Voltage [V]");
         gr2->GetYaxis()->SetTitle("1/C^{2} [pF^{-2}]"); 
         gr2->Draw("ap");
         leg2->Draw("ap");
    
    c0->cd();  
         mg->Add(gr2);
         mg->Draw("ap");  
   
  
   gPad->Modified();
   gPad->Update();
   
//---------------------------------------------------------------------------------------------------
//Half_Diode.txt 
   double  A_hd=2.5*2.5*1E-2 ;// [cm^2]
      
       points=0;
 
   while(getline(inputFile3, line)) {

      if (!line.length()|| line[0] == 'C' || line[0]=='B' || line[0]=='V'||line[0]=='#' || line.length()==1)
      {
         continue;
	 }
     else{    
      double Voltage=0.0 , Backplane_Capacitance=0.0 , Strip_All=0.0 , Strip_Sum=0.0;  
      sscanf(line.c_str(), "%lf %lf %lf %lf", &Voltage, &Backplane_Capacitance , & Strip_All , &Strip_Sum);
          
       Backplane_Capacitance=Backplane_Capacitance*1E+12;
      Backplane_Capacitance=1.0/(Backplane_Capacitance);
      Backplane_Capacitance=pow(Backplane_Capacitance,2.0);
          
     points++;
   //  std::cout<<"point["<<points<<"]: ("<<abs(Voltage)<<" , "<<Backplane_Capacitance<<")\n"; 
   //  gr1->SetPoint(points-1,abs(Voltage),Backplane_Capacitance);
 //    if(((abs(Voltage)>=180.0)&&(abs(Voltage)<=200.00))){continue;}
  //   else{
      gr3->SetPoint(points-1,abs(Voltage),Backplane_Capacitance);
  // }
  }
   }

     
    gr3->Fit(f1 ,"R");   
    gr3->Fit(f2,"R+");
    
    
   slope=gr3->GetFunction("f1")->GetParameter(1);
   cout << slope ;
   ND=2.0/(slope*q*esi*pow(A_hd,2.0));
   
   myfile <<"Half Diode:"<<" "<<" ND="<<" "<<ND<<" "<<" cm^{-3} "<<" \n";
    
    
        
          fint = new TF1("fint",finter,0,500.00);
          xint = fint->GetMinimumX();
          yint=xint*(gr3->GetFunction("f1")->GetParameter(1))+(gr3->GetFunction("f1")->GetParameter(0));
   
   
   
  
   std::string inter3="("+std:: to_string(xint)+","+std:: to_string(yint)+")";
   char *intersec3 = new char[inter2.length() + 1]; // or
   std::strcpy(intersec3, inter3.c_str());
   
   
       leg->AddEntry(gr3,"Half Diode","lp");
        leg->AddEntry(gr3,intersec3,"lp");
    
       leg3->AddEntry(gr3,"Half Diode","lp");
        leg3->AddEntry(gr3,intersec3,"lp");
   
          
    c1->cd(3); 
     gr3->GetXaxis()->SetTitle("Voltage [V]");
     gr3->GetYaxis()->SetTitle("1/C^{2} [pF^{-2}]"); 
    gr3->Draw("ap");
    leg3->Draw();
    
    c0->cd(); 
    mg->Add(gr3);
    mg->Draw("ap");  
    
 
   gPad->Modified();
   gPad->Update();
 
//---------------------------------------------------------------------------------------------------
//Quarter_Diode.txt
      
   double   A_qd=1.25*1.25*1E-2 ;//[cm^2]
      
       points=0;
 
   while(getline(inputFile4, line)) {

      if (!line.length()|| line[0] == 'C' || line[0]=='B' || line[0]=='V'||line[0]=='#' || line.length()==1)
      {
         continue;
	 }
     else{    
      double Voltage=0.0 , Backplane_Capacitance=0.0 , Strip_All=0.0 , Strip_Sum=0.0;  
      sscanf(line.c_str(), "%lf %lf %lf %lf", &Voltage, &Backplane_Capacitance , & Strip_All , &Strip_Sum);
          
      Backplane_Capacitance=Backplane_Capacitance*1E+12;
      Backplane_Capacitance=1.0/(Backplane_Capacitance);
      Backplane_Capacitance=pow(Backplane_Capacitance,2.0);
          
     points++;
   //  std::cout<<"point["<<points<<"]: ("<<abs(Voltage)<<" , "<<Backplane_Capacitance<<")\n"; 
   //  gr1->SetPoint(points-1,abs(Voltage),Backplane_Capacitance);
   //  if(((abs(Voltage)>=180.0)&&(abs(Voltage)<=200.00))){continue;}
    // else{
      gr4->SetPoint(points-1,abs(Voltage),Backplane_Capacitance);
   //}
  }
   }
   
  
    gr4->Fit(f1 ,"R");   
    gr4->Fit(f2,"R+");
    
    
        
   slope=gr4->GetFunction("f1")->GetParameter(1);
   cout << slope ;
   ND=2.0/(slope*q*esi*pow(A_qd,2.0));
   
   myfile <<"Quarter Diode:"<<" "<<" ND="<<" "<<ND<<" "<<" cm^{-3} "<<" \n";
    
        
          fint = new TF1("fint",finter,0,500.00);
          xint = fint->GetMinimumX();
          yint=xint*(gr4->GetFunction("f1")->GetParameter(1))+(gr4->GetFunction("f1")->GetParameter(0));
   
   
   
   std::string inter4="("+std:: to_string(xint)+","+std:: to_string(yint)+")";
   char *intersec4 = new char[inter4.length() + 1]; // or
   std::strcpy(intersec4, inter4.c_str());
   
    
   leg->AddEntry(gr4,"Quarter Diode","lp");
      leg->AddEntry(gr4,intersec4,"lp");
     
        
   leg4->AddEntry(gr4,"Quarter Diode","lp");
      leg4->AddEntry(gr4,intersec4,"lp");
      
    
     c1->cd(4); 
     gr4->GetXaxis()->SetTitle("Voltage [V]");
     gr4->GetYaxis()->SetTitle("1/C^{2} [pF^{-2}]"); 
     gr4->Draw("ap");
     leg4->Draw("ap");
     
     
     c0->cd();
    mg->Add(gr4);
   mg->GetXaxis()->SetTitle("Voltage [V]");
   mg->GetYaxis()->SetTitle("1/C^{2} [pF^{-2}]"); 
    mg->SetMinimum(-0.1);
    mg->SetMaximum(2.0);
    mg->Draw("ap");  
    leg->Draw();
   
   gPad->Modified();
   gPad->Update();
   
//--------------------------------------------------------------------------------------------------
     
}



