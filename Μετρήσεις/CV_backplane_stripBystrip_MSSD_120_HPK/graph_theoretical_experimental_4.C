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


void graph_theoretical_experimental_4()
{
	gROOT->Reset();
	//diabazei ta arxeia me tis theoritikes kai peiramatikes times 
	
   std::ifstream inputFile1("Capacitance.allRegions.120.experimental.stripbystrip.txt");
   std::ifstream inputFile2("Capacitance.theoretical.pitch.120.thickness.120.txt");
   //----------------------------------------------------------------------------------------------
   //dhlwsh metablhtwn
   vector<double_t> Ctots_exp,Cbs_exp,Cints_exp,Ctots_theo,Cbs_theo,Cints_theo,wp;
   vector<double_t> Regions,Regions2,Regions3;
   string line ;
   int pitch=120.0;
   
     TCanvas *c1=new TCanvas("c1","graph",300,10,900,500); 
      c1->SetGrid();
     
     gStyle->SetOptStat(kFALSE);
     gStyle->SetTitleFontSize(0.03);
     gStyle->SetTitleAlign(23);
      
   TMultiGraph *mg = new TMultiGraph();
   mg->SetTitle("#splitline{Total Capacitance theoretical and experimental vs w/p}{#scale[0.8]{Sensor thickness d=120 nm, pitch=120 um}}");    

   
   TGraph *gr1 = new TGraph(); gr1->SetLineColor(3); 
   TGraph *gr2 = new TGraph(); gr2->SetLineColor(4);
   TGraph *gr3 = new TGraph(); gr3->SetLineColor(5);
   TGraph *gr4 = new TGraph(); gr4->SetLineColor(6);
   
   gr1->SetMarkerStyle(20);
   gr2->SetMarkerStyle(21);
   gr3->SetMarkerStyle(22);
   gr4->SetMarkerStyle(23);
  //------------------------------------------------------------------------------------------------ 
     

    
   
   Regions.push_back(0.133);
    Regions.push_back(0.142);
     Regions.push_back(0.125);
      Regions.push_back(0.121);
       Regions.push_back(0.233);
        Regions.push_back(0.242);
         Regions.push_back(0.225);
          Regions.push_back(0.221);
           Regions.push_back(0.333);
            Regions.push_back(0.342);
             Regions.push_back(0.325);
              Regions.push_back(0.321);
              
              
   Regions2.push_back(0.142);
    Regions2.push_back(0.146);
     Regions2.push_back(0.138);
      Regions2.push_back(0.136);
       Regions2.push_back(0.242);
        Regions2.push_back(0.246);
         Regions2.push_back(0.238);
          Regions2.push_back(0.236);
           Regions2.push_back(0.342);
            Regions2.push_back(0.346);
             Regions2.push_back(0.338);
              Regions2.push_back(0.336);
              
                    
   Regions3.push_back(29.0/pitch);
    Regions3.push_back(47.0/pitch);
     Regions3.push_back(23.0/pitch);
      Regions3.push_back(21.5/pitch);
       Regions3.push_back(41.0/pitch);
        Regions3.push_back(71.0/pitch);
         Regions3.push_back(31.0/pitch);
          Regions3.push_back(28.5/pitch);
           Regions3.push_back(53.0/pitch);
            Regions3.push_back(95.0/pitch);
             Regions3.push_back(39.0/pitch);
              Regions3.push_back(35.5/pitch);
              
                        
   
   
//filling arrays with theoritical data   
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
//----------------------------------------------------------------------------------------------

   
//filling arrays with experimental data   
    double resolution=0., seperation=0. , width=0.,thikness=0.,length=0.,total=0.,backplane=0.,first=0.,second=0.;
   while(getline(inputFile2, line)) {
      if (!line.length() || line[0] == '#' || line[0]=='#')
         continue;
   //  double Voltage = 0., Strip1 = 0., Strip2=0. , Strip3=0. , Strip4=0. , Strip5=0. , StripSum=0. , StripAll=0. ;
      sscanf(line.c_str(), "%lf %lf %lf %lf %lf %lf %lf %lf %lf  ", &resolution, &seperation , &width,&thikness,&length,&total,&backplane,&first,&second);
      wp.push_back(width/pitch);
      Ctots_theo.push_back(total/3.049);
      Cbs_theo.push_back(backplane/3.049);
      Cints_theo.push_back(first/3.049);
   }
//-------------------------------------------------------------------------------------------------   
 
 //Set points graph theoritical  
      std::cout<<"points read:\n";
   for (int i = 0; i < int(wp.size()); ++i){
        std::cout<<"Regions["<<wp[i]<<"]: ("<<Ctots_theo[i]<<", "<<Cbs_theo[i]<<","<<Cints_theo[i]<<")\n";
          gr1->SetPoint(i,wp[i],Ctots_theo[i]);         
    } 
  //----------------------------------------------------------------------------------------------------------------- 
  //display on terminal experimental data only Regions with pitch=80
         std::cout<<"points read:\n";
   for (int i = 0; i < int(Regions.size()); ++i){
          if((i==0)||(i==4)||(i==8)){
		       std::cout<<"Regions["<<Regions[i]<<"]: ("<<Ctots_exp[i]<<", "<<Cbs_exp[i]<<","<<Cints_exp[i]<<")\n";	  
	  }      
    } 
//--------------------------------------------------------------------------------------------------------------
//Set points graph experimental only Regions with pitch=120
   gr2->SetPoint(0,Regions[0],Ctots_exp[0]);
     gr2->SetPoint(1,Regions[4],Ctots_exp[4]);
       gr2->SetPoint(2,Regions[8],Ctots_exp[8]);
       
   gr3->SetPoint(0,Regions2[0],Ctots_exp[0]);
     gr3->SetPoint(1,Regions2[4],Ctots_exp[4]);
       gr3->SetPoint(2,Regions2[8],Ctots_exp[8]);
       
    gr4->SetPoint(0,Regions3[0],Ctots_exp[0]);
     gr4->SetPoint(1,Regions3[4],Ctots_exp[4]);
       gr4->SetPoint(2,Regions3[8],Ctots_exp[8]);
       
//--------------------------------------------------------------------------------------------       
         
       
       
 //Fitting     

       gr1->Fit("pol1");
         gr1->GetFunction("pol1")->SetLineColor(3);
       gr2->Fit("pol1");
          gr2->GetFunction("pol1")->SetLineColor(4);       
       gr3->Fit("pol1");
         gr3->GetFunction("pol1")->SetLineColor(5);
       gr4->Fit("pol1");
          gr4->GetFunction("pol1")->SetLineColor(6);       ;
 //---------------------------------------------------------------------------------------            
 //TMultigraph
   mg->Add(gr1); gr1->SetTitle("Capacitance_theoretical"); gr1->SetLineWidth(3);
   mg->Add(gr2); gr1->SetTitle("Capacitance_experimental"); gr2->SetLineWidth(3);
   mg->Add(gr3); gr3->SetTitle("Capacitance_experimental")  ; gr3->SetLineWidth(3);
   mg->Add(gr4); gr4->SetTitle("Capacitance_experimental_width_Al")  ; gr4->SetLineWidth(3);
    mg->SetMinimum(0);
    mg->SetMaximum(2.0);
    mg->Draw("ap"); 
         
   mg->GetXaxis()->SetTitle("width pitch ratio w/p");
   mg->GetYaxis()->SetTitle("Total capacitance per cm [pF/cm]"); 
     

   gPad->Modified();
   gPad->Update();
    

//-----------------------------------------------------------------------------------------------
//Metatroph double se string kai string se char gia to Tlegend

     std::string y1="a1="+std:: to_string(gr1->GetFunction("pol1")->GetParameter(0))+","
                    "b1="+std:: to_string(gr1->GetFunction("pol1")->GetParameter(1));
      char *ya1 = new char[y1.length() + 1]; // or
     std::strcpy(ya1, y1.c_str());
     
     std::string y2="a2="+std:: to_string(gr2->GetFunction("pol1")->GetParameter(0))+","
                    "b2="+std:: to_string(gr2->GetFunction("pol1")->GetParameter(1));
      char *ya2= new char[y2.length() + 1]; // or
     std::strcpy(ya2, y2.c_str());
   
   
          
     std::string y3="a3="+std:: to_string(gr3->GetFunction("pol1")->GetParameter(0))+","
                    "b3="+std:: to_string(gr3->GetFunction("pol1")->GetParameter(1));
      char *ya3= new char[y3.length() + 1]; // or
     std::strcpy(ya3, y3.c_str());
     
               
     std::string y4="a4="+std:: to_string(gr4->GetFunction("pol1")->GetParameter(0))+","
                    "b4="+std:: to_string(gr4->GetFunction("pol1")->GetParameter(1));
      char *ya4= new char[y4.length() + 1]; // or
     std::strcpy(ya4, y4.c_str());
     
 //------------------------------------------------------------------------------------------------------    

     
//TLegend

     
   gStyle->SetLegendBorderSize(1);
   gStyle->SetLegendTextSize(0.025);     
     
 //  TLegend *leg = new TLegend(x1, y1, x2, y2);
  TLegend *leg = new TLegend(0.75, 0.15, 0.999, 0.50);
 
 leg->SetTextColor(kBlue);;
 leg->SetTextAlign(12);
 leg->SetTextAlign(12);
 
leg->AddEntry(gr1, "Theoretical", "lp");
leg->AddEntry(gr2, "Experimental width min", "lp");
leg->AddEntry(gr3, "Experimental width max", "lp");
leg->AddEntry(gr4, "Experimental width Al", "lp"); 
 
leg->AddEntry(gr1->GetFunction("pol1"),ya1, "lp");
leg->AddEntry(gr2->GetFunction("pol1"),ya2, "lp");
leg->AddEntry(gr3->GetFunction("pol1"),ya3, "lp");
leg->AddEntry(gr4->GetFunction("pol1"),ya4, "lp");


leg->Draw();
//-------------------------------------------------------------------------------------------------------------- 
     

}
