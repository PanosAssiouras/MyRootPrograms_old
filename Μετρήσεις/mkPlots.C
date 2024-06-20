#include "Riostream.h"

void mkPlots() {
 
 gROOT->SetStyle("Plain");
// gStyle->SetOptTitle(0);
 gStyle->SetOptStat(0);
 
 ifstream in;
 in.open(Form("decoupling.txt"));
 Float_t x,y,z;
 Int_t 	 nlines = 0;
 
 TFile *f = new TFile("decoupling.root","RECREATE");
 TH1F *Hx = new TH1F("Hx","x distribution",90,135.0,165.0);
 TH1F *Hy = new TH1F("Hy","y distribution",90,135.0,165.0);
 TH1F *Hz = new TH1F("Hz","z distribution",90,135.0,165.0);
 
 TNtuple *ntuple = new TNtuple("ntuple","data from ascii file","x:y:z");
 
 while (1) {
  in >> x >> y >> z;
  if(!in.good()) break;  
  Hx->Fill(x);
  cout << x << endl;
  Hy->Fill(y);
  Hz->Fill(z);
  ntuple->Fill(x,y,z);
  nlines++;
 }

 printf(" found %d points\n",nlines);
 in.close();
 f->Write();
 
 ///////////////////////////////////////////////////////////////////////
 Hx->SetFillStyle(3004); Hx->SetFillColor(2); Hx->SetLineColor(2);
 Hy->SetFillStyle(3005); Hy->SetFillColor(8); Hy->SetLineColor(8);
 Hz->SetFillStyle(3007); Hz->SetFillColor(4); Hz->SetLineColor(4);
 
 ///////////////////////////////////////////////////////////////////////
 TCanvas *cc = new TCanvas("cc","resistors",600,600);
 Hx->SetTitle("Baby sensors: Decouplig capacitance");
 Hx->GetXaxis()->SetTitle("C [pF]");
 Hx->GetYaxis()->SetTitle("Nb of strips per channel");
 gPad->SetTickx();
 gPad->SetTicky();
 gPad->SetGridx();
 gPad->SetGridy();
 Hx->Draw();
 Hy->Draw("same");
 Hz->Draw("same");
 TLegend *l = new TLegend(0.6, 0.7, 0.88, 0.86);
  l->AddEntry(Hx,"p-spray","F");
  l->AddEntry(Hy,"p-stop sn 21","F");
  l->AddEntry(Hz,"p-stop sn 22","F");
  l->Draw("same");

 gPad->Modified();
 gPad->Update();
 //cc->SaveAs("plot.png");
 
}
