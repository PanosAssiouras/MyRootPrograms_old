#include "Riostream.h"
void basic() {
//  Read data from an asIii file and create a root file with an histogram and an ntuple.
//   see a variant of this maIro in basic2.C
//Author: Rene Brun


// read file $ROOTSYS/tutorials/tree/basic.dat
// this file has 3 columns of float data
   c0 = new TCanvas("c1","multigraph L3",200,10,700,500);
   c0->SetFrameFillColor(0);
   c0->SetGrid();


   c1 = new TCanvas("c2","multigraph L2",200,10,700,500);
   c1->SetFrameFillColor(0);
   c1->SetGrid();
   c1->SetLogy();

   TMultiGraph *mg = new TMultiGraph();
   TMultiGraph *mg2 = new TMultiGraph();

   mg2->SetTitle("#splitline{Total Current in 12 regions of MSSD structures}{#scale[0.8]{Sensor thickness d=120 nm}}");
   gStyle->SetTitleFontSize(0.03);
   gStyle->SetTitleAlign(23);


   TGraph *gr1 = new TGraph(); gr1->SetLineColor(1);
   TGraph *gr2 = new TGraph(); gr2->SetLineColor(2);
   TGraph *gr3 = new TGraph(); gr3->SetLineColor(3);
   TGraph *gr4 = new TGraph(); gr4->SetLineColor(4);
   TGraph *gr5 = new TGraph(); gr5->SetLineColor(5);
   TGraph *gr6 = new TGraph(); gr6->SetLineColor(6);
   TGraph *gr7 = new TGraph(); gr7->SetLineColor(7);
   TGraph *gr8 = new TGraph(); gr8->SetLineColor(8);
   TGraph *gr10 = new TGraph(); gr10->SetLineColor(28);
   TGraph *gr11 = new TGraph(); gr11->SetLineColor(30);
   TGraph *gr12 = new TGraph(); gr12->SetLineColor(46);

   gr1->SetMarkerStyle(20);
   gr2->SetMarkerStyle(21);
   gr3->SetMarkerStyle(22);
   gr4->SetMarkerStyle(23);
   gr5->SetMarkerStyle(24);
   gr6->SetMarkerStyle(25);
   gr7->SetMarkerStyle(26);
   gr8->SetMarkerStyle(27);
   gr10->SetMarkerStyle(3);
   gr11->SetMarkerStyle(5);
   gr12->SetMarkerStyle(28);

   gr1->SetMarkerSize(0.5);
      gr2->SetMarkerSize(0.5);
    gr3->SetMarkerSize(0.5);
   gr4->SetMarkerSize(0.5);
    gr5->SetMarkerSize(0.5);
    gr6->SetMarkerSize(0.5);
    gr7->SetMarkerSize(0.5);
   gr8->SetMarkerSize(0.5);
   gr10->SetMarkerSize(0.5);
   gr11->SetMarkerSize(0.5);
      gr12->SetMarkerSize(0.5);




   TString dir = gSystem->UnixPathName(__FILE__);
   dir.ReplaceAll("basic.C","");
   dir.ReplaceAll("/./","/");
   ifstream in;
   in.open(Form("%sglobal_current_320_2.dat",dir.Data()));

   float Voltage[71]={} ;
   float I1[71],I2[71],I3[71],I4[71],I5[71],
         I6[71],I7[71],I8[71],I10[71],I11[71],I12[71];
   Float_t x,y,z;
   Int_t nlines = 0;
   TFile *f = new TFile("global_current_320.root","RECREATE");
   TH1F *h1 = new TH1F("h1","x distribution",100,-4,4);
   TNtuple *ntuple = new TNtuple("ntuple","data from asIii file","V:I1:I2:I3:I4:I5:I6:I7:I8:I10:I11:I12");

   while (1) {

      in >> Voltage[nlines] >> I1[nlines] >> I2[nlines] >> I3[nlines] >> I4[nlines]>>I5[nlines]>>
      I6[nlines]>>I7[nlines]>>I8[nlines]>>I10[nlines]>>I11[nlines]>>I12[nlines];

      printf("Voltage=%8f, I1=%8f, I2=%8f,I3=%8f,I4=%8f,I5=%8f,I6=%8f,I7=%8f,I8=%8f,I10=%8f,I11=%8f,I12=%8f\n, ",Voltage[nlines],I1[nlines],I2[nlines],I3[nlines], I4[nlines],I5[nlines],
      I6[nlines],I7[nlines],I8[nlines],I10[nlines],I11[nlines],I12[nlines]);
    //  h1->Fill(x);
    //  ntuple->Fill(x,y,z);

      Voltage[nlines]=TMath::Abs(Voltage[nlines]);
      nlines++;
     if (!in.good()) break;

   }

for (int nlines=0; nlines<=71; nlines++){
  gr1->SetPoint(nlines,Voltage[nlines],I1[nlines]);
  gr2->SetPoint(nlines,Voltage[nlines],I2[nlines]);
  gr3->SetPoint(nlines,Voltage[nlines],I3[nlines]);
  gr4->SetPoint(nlines,Voltage[nlines],I4[nlines]);
  gr5->SetPoint(nlines,Voltage[nlines],I5[nlines]);
  gr6->SetPoint(nlines,Voltage[nlines],I6[nlines]);
  gr7->SetPoint(nlines,Voltage[nlines],I7[nlines]);
  gr10->SetPoint(nlines,Voltage[nlines],I10[nlines]);
  gr11->SetPoint(nlines,Voltage[nlines],I11[nlines]);
  gr12->SetPoint(nlines,Voltage[nlines],I12[nlines]);

}


for (int nlines=0; nlines<=71; nlines++){
    gr8->SetPoint(nlines,Voltage[nlines],I8[nlines]);
}

   printf(" found %d points\n",nlines);
   in.close();
   f->Write();


    mg2->Add(gr12); gr12->SetTitle("I12"); gr12->SetLineWidth(3);
   mg2->Add(gr11); gr11->SetTitle("I11")  ; gr11->SetLineWidth(3);
   mg2->Add(gr10); gr10->SetTitle("I10")    ; gr10->SetLineWidth(3);


  // mg2->Add(gr8); gr8->SetTitle("I8"); gr8->SetLineWidth(3);
   mg2->Add(gr7); gr7->SetTitle("I7")  ; gr7->SetLineWidth(3);
   mg2->Add(gr6); gr6->SetTitle("I6")    ; gr6->SetLineWidth(3);
   mg2->Add(gr5); gr5->SetTitle("I5")  ; gr5->SetLineWidth(3);


   mg2->Add(gr4); gr4->SetTitle("I4"); gr4->SetLineWidth(3);
   mg2->Add(gr3); gr3->SetTitle("I3")  ; gr3->SetLineWidth(3);
   mg2->Add(gr2); gr2->SetTitle("I2")    ; gr2->SetLineWidth(3);
   mg2->Add(gr1); gr1->SetTitle("I1")  ; gr1->SetLineWidth(3);
   c1->cd();
   mg2->Draw("alp");
   mg2->GetXaxis()->SetTitle("Bias Voltage (Volt)");
   mg2->GetYaxis()->SetTitle("Current, (nA)");

   gStyle->SetLegendBorderSize(0);
   gStyle->SetLegendTextSize(0.02);

   gPad->Modified();
   gPad->Update() ;

 TLegend *leg = new TLegend(0.15, 0.45, 0.3, 0.9);
 leg->SetTextColor(kBlue);;
 leg->SetTextAlign(11);
 leg->SetTextAlign(11);

gStyle->SetLegendBorderSize(0);
gStyle->SetLegendTextSize(0.02);



leg->AddEntry(gr1, "Region_{1}", "lp");
leg->AddEntry(gr2, "Region_{2}", "lp");
leg->AddEntry(gr3, "Region_{3}", "lp");
leg->AddEntry(gr4, "Region_{4}", "lp");
leg->AddEntry(gr5, "Region_{5}", "lp");
leg->AddEntry(gr6, "Region_{6}", "lp");
leg->AddEntry(gr7, "Region_{7}", "lp");
leg->AddEntry(gr8, "Region_{8}", "lp");
leg->AddEntry( "Region_{9}", "lp");
leg->AddEntry(gr10, "Region_{10}", "lp");
leg->AddEntry(gr11, "Region_{11}", "lp");
leg->AddEntry(gr12, "Region_{12}", "lp");
leg->Draw();





   mg->Add(gr12); gr12->SetTitle("I12"); gr12->SetLineWidth(3);
   mg->Add(gr11); gr11->SetTitle("I11")  ; gr11->SetLineWidth(3);
   mg->Add(gr10); gr10->SetTitle("I10")    ; gr10->SetLineWidth(3);



   mg->Add(gr8); gr8->SetTitle("I8"); gr8->SetLineWidth(3);
   mg->Add(gr7); gr7->SetTitle("I7")  ; gr7->SetLineWidth(3);
   mg->Add(gr6); gr6->SetTitle("I6")    ; gr6->SetLineWidth(3);
   mg->Add(gr5); gr5->SetTitle("I5")  ; gr5->SetLineWidth(3);


   mg->Add(gr4); gr4->SetTitle("I4"); gr4->SetLineWidth(3);
   mg->Add(gr3); gr3->SetTitle("I3")  ; gr3->SetLineWidth(3);
   mg->Add(gr2); gr2->SetTitle("I2")    ; gr2->SetLineWidth(3);
   mg->Add(gr1); gr1->SetTitle("I1")  ; gr1->SetLineWidth(3);
   c0->cd();
   mg->Draw("a fb l3d");
   gPad->Modified();
   gPad->Update() ;



}
