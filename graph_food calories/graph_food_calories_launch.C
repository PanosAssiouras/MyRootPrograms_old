#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include "TCanvas.h"
#include "TStyle.h"
#include "TH1.h"
#include "TGaxis.h"
#include "TRandom.h"
#include <stdlib.h>

void graph_food_calories_launch()
{
	gROOT->Reset();
	//diabazei ta arxeia me tis theoritikes kai peiramatikes times kai kanei grafikh parastash 
	
	 std::ifstream inputFile2("lunch2.txt");

  vector<double_t> intake_cals, cals_suggested;
   vector<string> foods,times;
   string line ;
   
     TCanvas *c1=new TCanvas("c1","graph",300,10,1000,700); 
       c1->SetBottomMargin(0.5);
       c1->SetGrid();
     
     gStyle->SetOptStat(kFALSE);
     
      gStyle->SetTitleFontSize(0.025);
      gStyle->SetTitleAlign(23);
   
   TH1F *h1= new TH1F("h1exp","#splitline{Calories intake and calories suggested}{Daily launch} ",43,0,43);
      TH1F *h2= new TH1F("h2exp","Capacitance theretical vs Capacitance experimental stripbystrip",43,0,43);

     
  // TCanvas *c1=new TCanvas("c1","graph",200,10,600,400);
  //  TGraph *gr1=new TGraph();
    
  /* 
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
   
   */
         cout << "starting";      
             
         double intake_cal = 0., cal_suggested= 0. ;
         string food , time;
   while(getline(inputFile2, line)) {
	   cout << "starting";
      if (!line.length() || line[0] == 't' || line[0]=='#')
         continue;
       
          
			     int pos1=line.find(";");
                 times.push_back(line.substr(0,pos1));
                 string s=line.substr(pos1+1);
                 cout << s<<"\n";
            //     int pos2=s.find("/");
             //    s=s.substr(pos2+1);
                cout<<s<<"\n";
                 int pos3=s.find(";");
                 food=s.substr(0,pos3);
                 foods.push_back(food);
                 s=s.substr(pos3+1);
                 cout<<s<<"\n";
               
                 int pos4=s.find(";");
                 intake_cal=atof(s.substr(0,pos4).c_str());
                intake_cals.push_back(intake_cal);
                s=s.substr(pos4+1);
                cout<<s<<"\n";
                int pos5=s.find(" ");
             
                 cal_suggested=atof(s.substr(0,pos5-1).c_str());
               
                 cals_suggested.push_back(cal_suggested);
                 
                 
                 
          }
   
/*   
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
   */
     std::cout << "time" <<", "<< "food" <<", "<< "cals intake"<<", " << "cals suggested"<<", "<< "\n" ;
   for (int i = 0; i < int(foods.size()); ++i){
      
  
      std::cout << times[i] <<", "<< foods[i] <<", "<< intake_cals[i]<<", " << cals_suggested[i]<<", "<< "\n"  ; 
       
       
             h1->SetBinContent(i+1,intake_cals[i]);
      h1->GetXaxis()->SetBinLabel(i+1,foods[i].c_str());
    //         h1->SetBinContent(i+2,null);
    //  h1->GetXaxis()->SetBinLabel(i+1,null);
          h2->SetBinContent(i+1,cals_suggested[i]);
      h2->GetXaxis()->SetBinLabel(i+1,foods[i].c_str());


    } 
 
    h1->SetMarkerStyle(3);
    h1->GetXaxis()->SetTitle("Food");
    h1->GetYaxis()->SetTitle("Calories [cal]");
    h1->LabelsOption("v");
    h1->Draw("P");
    h1->SetMinimum(50);
    h1->SetMaximum(800);
 //   h1exp->GetYaxis()->SetNdivisions(-520);
  
     c1->Update();
    
    h2->SetMarkerStyle(4);
    h2->Draw("Psame");
    h2->SetMinimum(50);
    h2->SetMaximum(700);
    h2->SetMarkerColor(kRed);
     c1->Update();

   gStyle->SetLegendBorderSize(1);
   gStyle->SetLegendTextSize(0.025);     
     
 //TLegend *leg = new TLegend(0.15, 0.45, 0.3, 0.9);
  TLegend *leg = new TLegend(0.75, 0.88, 0.999, 1.0);
 
 leg->SetTextColor(kBlue);;
 leg->SetTextAlign(12);
 leg->SetTextAlign(12);
 
 
leg->AddEntry(h1, "Intake calories", "lp");
leg->AddEntry(h2, "Suggested calories", "lp");


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
