#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include "TCanvas.h"
#include "TStyle.h"
#include "TH1.h"
#include "TGaxis.h"
#include "TRandom.h"


void graph_theoretical_experimental()
{
	gROOT->Reset();
	//diabazei ta arxeia me tis theoritikes kai peiramatikes times kai kanei grafikh parastash 
	
   std::ifstream inputFile1("Capacitance.allRegions.120.experimental.stripbystrip.txt");
   std::ifstream inputFile2("Capacitance.allRegions.120.theoretical.txt");
   
  vector<double_t> Ctots_exp,Cbs_exp,Cints_exp,Ctots_theo,Cbs_theo,Cints_theo;
   vector<string> Regions;
   string line ;
   
     TCanvas *c1=new TCanvas("c1","graph",300,10,900,500); 
     
     gStyle->SetOptStat(kFALSE);
     
      gStyle->SetTitleFontSize(0.025);
      gStyle->SetTitleAlign(23);
   
   TH1F *h1exp = new TH1F("h1exp","Capacitance theoretical and experimental strip by strip",12,0,12);
      TH1F *h2exp = new TH1F("h2exp","Capacitance theretical vs Capacitance experimental stripbystrip",12,0,12);
         TH1F *h3exp = new TH1F("h3exp","Capacitance theretical vs Capacitance experimental stripbystrip",12,0,12);
         
    TH1F *h1theo = new TH1F("h1theo","Capacitance theretical vs Capacitance experimental stripbystrip",12,0,12);
      TH1F *h2theo = new TH1F("h2theo","Capacitance theretical vs Capacitance experimental stripbystrip",12,0,12);
         TH1F *h3theo = new TH1F("h3theo","Capacitance theretical vs Capacitance experimental stripbystrip",12,0,12);
           
     
  // TCanvas *c1=new TCanvas("c1","graph",200,10,600,400);
  //  TGraph *gr1=new TGraph();
    
   
   Regions.push_back("1[0.133]");
    Regions.push_back("2[0.142]");
     Regions.push_back("3[0.125]");
      Regions.push_back("4[0.121]");
       Regions.push_back("5[0.233]");
        Regions.push_back("6[0.242]");
         Regions.push_back("7[0.225]");
          Regions.push_back("8[0.221]");
           Regions.push_back("9[0.333]");
            Regions.push_back("10[0.342]");
             Regions.push_back("11[0.325]");
              Regions.push_back("12[0.321]");
   
   
   
         double Ctot = 0., Cb= 0., Cint=0. ;
   while(getline(inputFile1, line)) {
      if (!line.length() || line[0] == 'C' || line[0]=='T')
         continue;
   //  double Voltage = 0., Strip1 = 0., Strip2=0. , Strip3=0. , Strip4=0. , Strip5=0. , StripSum=0. , StripAll=0. ;
      sscanf(line.c_str(), "%lf %lf %lf ", &Ctot, &Cb , &Cint);
      Ctots_exp.push_back(Ctot*1e+12);
      Cbs_exp.push_back(Cb*1e+12);
      Cints_exp.push_back(Cint*1e+12);
   }
   
   
     Ctot = 0., Cb= 0., Cint=0. ;
   while(getline(inputFile2, line)) {
      if (!line.length() || line[0] == 'C' || line[0]=='T')
         continue;
   //  double Voltage = 0., Strip1 = 0., Strip2=0. , Strip3=0. , Strip4=0. , Strip5=0. , StripSum=0. , StripAll=0. ;
      sscanf(line.c_str(), "%lf %lf %lf ", &Ctot, &Cb , &Cint);
      Ctots_theo.push_back(Ctot);
      Cbs_theo.push_back(Cb);
      Cints_theo.push_back(Cint);
   }
   
      std::cout<<"points read:\n";
   for (int i = 0; i < int(Regions.size()); ++i){
        std::cout<<"Regions["<<Regions[i]<<"]: ("<<Ctots_exp[i]<<", "<<Cbs_exp[i]<<","<<Cints_exp[i]<<","<<Ctots_theo[i]<<", "<<Cbs_theo[i]<<","<<Cints_theo[i]<<")\n";
     //   myfile << Strip3s[i]<<" "<<StripSums[i]<<" "<<Cints[i]<<" \n";
   // gr1->SetPoint(i,Regions[i].c_str(),Ctots_exp[i]);
          
          h1exp->SetBinContent(i+1,Ctots_exp[i]);
      h1exp->GetXaxis()->SetBinLabel(i+1,Regions[i].c_str());
          h2exp->SetBinContent(i+1,Cbs_exp[i]);
      h2exp->GetXaxis()->SetBinLabel(i+1,Regions[i].c_str());
          h3exp->SetBinContent(i+1,Cints_exp[i]);
      h3exp->GetXaxis()->SetBinLabel(i+1,Regions[i].c_str());
      
          h1theo->SetBinContent(i+1,Ctots_theo[i]);
      h1theo->GetXaxis()->SetBinLabel(i+1,Regions[i].c_str());
          h2theo->SetBinContent(i+1,Cbs_theo[i]);
      h2theo->GetXaxis()->SetBinLabel(i+1,Regions[i].c_str());
          h3theo->SetBinContent(i+1,Cints_theo[i]);
      h3theo->GetXaxis()->SetBinLabel(i+1,Regions[i].c_str());
      
    } 
   
    h1exp->SetMarkerStyle(3);
    h1exp->GetXaxis()->SetTitle("Region name [w/p]");
    h1exp->GetYaxis()->SetTitle("Capacitance [pF/cm]");
    h1exp->Draw("P");
    h1exp->SetMinimum(0.0);
    h1exp->SetMaximum(1.8);
    h1exp->GetYaxis()->SetNdivisions(-520);
     c1->Update();
       
    h2exp->SetMarkerStyle(4);
    h2exp->Draw("Psame");
    h2exp->SetMinimum(0);
    h2exp->SetMaximum(1.8);
     c1->Update();
     
    h3exp->SetMarkerStyle(5);
    h3exp->Draw("Psame");
    h3exp->SetMinimum(0);
    h3exp->SetMaximum(1.8);
     c1->Update();
     
    h1theo->SetMarkerStyle(3);
    h1theo->SetMarkerColor(kRed);
    h1theo->Draw("Psame");
     c1->Update();
     
   
    h2theo->SetMarkerStyle(4);
    h2theo->SetMarkerColor(kRed);
    h2theo->Draw("Psame");
    h2theo->SetMinimum(0);
    h2theo->SetMaximum(1.8);
     c1->Update();
     
    h3theo->SetMarkerStyle(5);
    h3theo->SetMarkerColor(kRed);
    h3theo->Draw("Psame");
     c1->Update();
     
     
   gStyle->SetLegendBorderSize(1);
   gStyle->SetLegendTextSize(0.025);     
     
 //TLegend *leg = new TLegend(0.15, 0.45, 0.3, 0.9);
  TLegend *leg = new TLegend(0.75, 0.65, 0.999, 1.0);
 
 leg->SetTextColor(kBlue);;
 leg->SetTextAlign(12);
 leg->SetTextAlign(12);
 
 
leg->AddEntry(h1exp, "Total experimental", "lp");
leg->AddEntry(h2exp, "Backplane experimental", "lp");
leg->AddEntry(h3exp, "First neighbor  experimental", "lp");
leg->AddEntry(h1theo, "Total theoretical", "lp");
leg->AddEntry(h2theo, "Backplane theoretical", "lp");
leg->AddEntry(h3theo, "First neighbor theoretical", "lp");

leg->Draw();
 
     

  /* h1b->SetFillColor(4);
   h1b->SetBarWidth(0.4);
   h1b->SetBarOffset(0.1);
   h1b->SetStats(0);
   h1b->SetMinimum(0);
   h1b->SetMaximum(2.0);

    
    h1b->Draw("b");
   
*/

}
