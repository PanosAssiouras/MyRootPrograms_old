void fillarray()
{
   TFile f("test.root","recreate");
   TTree T("T","a simple test with an array");
   Float_t ed[12][48];
   T.Branch("ed",ed,"ed[12][48]/F");
   //loop on some events
   for (Int_t ev=0;ev<100;ev++) {
      for (Int_t i=0;i<12;i++) {
         for (Int_t j=0;j<48;j++) {
            ed[i][j] = gRandom->Gaus(i,j);
         }
      }
      T.Fill();
   }
   T.Write();
}     
void readarray()
{
   TFile *f = new TFile("test.root");
   TTree *T = (TTree*)f->Get("T");
   Float_t ed[12][48];
   T->SetBranchAddress("ed",ed);
   //read events
   TH1F *hed = new TH1F("hed","ed values",100,-100,100);
   Int_t nevents = Int_t(T->GetEntries());
   for (Int_t ev=0;ev<nevents;ev++) {
      T->GetEntry(ev);
      for (Int_t i=0;i<12;i++) {
         for (Int_t j=0;j<48;j++) {
            hed->Fill(ed[i][j]);
         }
      }
   }
   hed->Draw();
}

