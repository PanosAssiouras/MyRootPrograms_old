#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdio>




using namespace std;

TF1 *f1, *f2;
double finter(double *x, double*par) {
   return TMath::Abs(f1->EvalPar(x,par) - f2->EvalPar(x,par));
}



int sort_string_vector(vector<string> &stringVec)
{
 for (vector<string>::size_type i = 0; i != stringVec.size(); ++i)
    {
    // Sorting the string vector
    sort(stringVec.begin(), stringVec.end());
    // Ranged Based loops. This requires a C++11 Compiler also
    // If you don't have a C++11 Compiler you can use a standard
    // for loop to print your vector.

    cout << stringVec[i] << endl;

}
 return 0;
}
void Convert_TestDataFile_To_RootTree(TString TextDataName, TString RootDataName)
{
   TFile *f = new TFile(RootDataName,"RECREATE");
   TTree *T = new TTree("TRee","data from ascii file");
   TNtuple data("data","CV","Voltage:Capacitance1:Capacitance2:Capacitance3:Capacitance4:Capacitance5:Capacitance6:Capacitance7:Capacitance8: Capacitance9:Capacitance10:Capacitance11:Capacitance12:Capacitance13:Capacitance14:Capacitance15:Capacitance16:Capacitance17:Capacitance18:Capacitance19:Capacitance20:Capacitance21:Capacitance22:Capacitance23:Capacitance24:Capacitance25:Capacitance26:Capacitance27:Capacitance28:Capacitance29:Capacitance30:Capacitance31:Capacitance32:CapacitanceSum");
   cout<<TextDataName<<endl;
   cout<<"root"<<endl;
	 std:: ifstream inputFile(TextDataName);
	  std::string line="";

    vector<TGraph*>  grs;
  vector<vector<double > > Capacitances;
  vector<double> Voltages;

  double yint, xint;

      string temp;
    double V;
      int nrows=0;
	  while(getline(inputFile,line)){
         double Voltage=0.0,  Capacitance1=0.0 ,  Capacitance2 ,  Capacitance3, Capacitance4 ,  Capacitance5 ,  Capacitance6 ,  Capacitance7,  Capacitance8;
    //   if(line.empty()){continue;}
    cout<<line.empty()<<endl;
         if (line.length()==0|| line[0] == 'I' || line[0]=='B' ||
           line[0]=='V'||line[0]=='#'  || line.length()==0
           ||line[0]=='F'||line[0]=='O'||line[0]=='C'||line[0]=='+')
           {  continue; }
   else{

       stringstream ss;
       ss << line;
       ss >> Voltage;
//     cout << Voltage << " "<<endl;;
        Voltages.push_back(Voltage);
        int ncols=0;
        vector<double> rows;
   while (ss)
          {
          ss >> Capacitance1;
      //    cout<< Capacitance1<<" "<<endl;
          rows.push_back(Capacitance1);

          ncols++;

        }
        Capacitances.push_back(rows);

       nrows++;
      cout << "ncols = " << ncols<<endl;

      ncols=0;

  }

  //  ss.clear();
}
 cout<<Capacitances.size()<<endl;
 cout<<Capacitances[0].size()<<endl;
 cout<<Capacitances[29][34]<<endl;

 TCanvas *c1=new TCanvas("c1","CV",300,10,900,500);
 c1->SetGrid();

 TCanvas *c2=new TCanvas("c2","CV",300,10,900,500);
 c2->SetGrid();


  TCanvas *c3=new TCanvas("c3","CV",300,10,900,500);
  c3->SetGrid();

  TCanvas *c4=new TCanvas("c4","CV",300,10,900,500);
  c4->SetGrid();







        int markerstyle=20;
        int markercolor =1;
        int marker =1;


        TLegend *leg = new TLegend(0.75, 0.20, 0.95, 0.65);
       // leg-> SetNColumns(1);
        leg->SetTextColor(kBlue);;
        leg->SetTextAlign(12);
        leg->SetTextAlign(12);
        leg->SetNColumns(2);
        leg->SetTextSize(0.030);


                TLegend *leg2= new TLegend(0.75, 0.20, 0.95, 0.65);
               // leg-> SetNColumns(1);
                leg2->SetTextColor(kBlue);;
                leg2->SetTextAlign(12);
                leg2->SetTextAlign(12);
                leg2->SetNColumns(2);






 TMultiGraph* mg1 = new TMultiGraph();
  mg1->SetMinimum(0.0);
 mg1->SetMaximum(0.9*1e-3);
 mg1->SetTitle("#splitline{Total Capacitance : Preshower sensor  :}{All 32 strips}");
  gStyle->SetTitleFontSize(0.035);
  gStyle->SetTitleAlign(23);


   TMultiGraph* mg2 = new TMultiGraph();
  //  mg2->SetMinimum(0.0);
  // mg2->SetMaximum(0.9*1e-3);
   mg2->SetTitle("#splitline{Total Capacitance : Preshower sensor  :}{All 32 strips}");
    gStyle->SetTitleFontSize(0.035);
    gStyle->SetTitleAlign(23);

    f1 = new TF1("f1","pol1",50,250);
    f2 = new TF1("f2","pol1",0,40);

    TF1 *fint = new TF1("fint",finter,0,500.00);

  TH1F *h1 = new TH1F("h1", "h1 title",20, 38, 45);

    TGraph *gr1=new TGraph();

    for(int j=0; j<=Capacitances[0].size()-4; j++){
          TGraph *gr=new TGraph();
          TGraph *gr2=new TGraph();
            TF1 *fint2 = new TF1("fint2",finter,0,500.00);
      for(int i=0; i<=Capacitances.size()-1; i++){

        if(marker==0||marker==10){
          marker++;
        }
        if(markercolor==0||markercolor==10||markercolor==18||markercolor==17||markercolor==21||markercolor==23||markercolor==25){
          markercolor++;
        }

        if(marker>49){marker=1;}
        if(markercolor>49){markercolor=1;}
  //   cout<<Capacitances[i][j]<<",";
     gr->SetPoint(i,Voltages[i],1/TMath::Power(Capacitances[i][j]*1e+12,2));
     gr1->SetPoint(i,Voltages[i],1/TMath::Power(Capacitances[i][32]*1e+12,2));
     gr2->SetPoint(i,Voltages[i],Capacitances[i][j]*1e+12);



    // grs.push_back(gr);

    gr->SetMarkerStyle(markerstyle);
    gr->SetMarkerColor(markercolor);
    gr->SetLineColor(markercolor);
    gr->SetMarkerSize(0.8);

    gr2->SetMarkerStyle(markerstyle);
    gr2->SetMarkerColor(markercolor);
    gr2->SetLineColor(markercolor);
    gr2->SetMarkerSize(0.8);

    f1->SetLineColor(markercolor);
    f2->SetLineColor(markercolor);
    }



    c1->cd();
           gr->Fit("f1","R");
           gr->Fit("f2","R+");
          //   fint2 = new TF1("fint",finter,0,500.00);
             xint = fint2->GetMinimumX();
            yint=xint*(gr->GetFunction("f1")->GetParameter(1))+(gr->GetFunction("f1")->GetParameter(0));
        //     cout<<xint<<" "<<yint<<endl;
        string name="strip_"+to_string(j+1);
        cout<<name<<endl;
       mg1->Add(gr);
       mg1->Draw("apl");
       mg1->GetXaxis()->SetTitle("Voltage [V]");
       mg1->GetYaxis()->SetTitle("1/C^{2} [pF^{-2}]");
       gPad->Modified();
       gPad->Update();
       leg->AddEntry(gr,name.c_str(),"lp");
       leg->Draw("apl");
          gPad->Modified();
          gPad->Update();


       c4->cd();
             gr2->Fit("f1","R");

            mg2->Add(gr2);
          mg2->Draw("apl");
          mg2->GetXaxis()->SetTitle("Voltage [V]");
          mg2->GetYaxis()->SetTitle("Capacitance [pF]");
          gPad->Modified();
          gPad->Update();
          leg2->AddEntry(gr2,name.c_str(),"lp");
          leg2->Draw("apl");
          gPad->Modified();
          gPad->Update();



     h1->Fill(TMath::Sqrt(1/yint));

     marker++;
     markerstyle++;
     markercolor++;


    cout<<"strip_"<<j<<"="<<gr->GetFunction("f1")->GetParameter(0)<<endl;
 }


c2->cd();
h1->SetTitle("Total Capacitance Histogram");
h1->GetXaxis()->SetTitle("Total Capacitance");
h1->GetYaxis()->SetTitle("Number of strips");
h1->Draw();
h1->SetBarWidth(0.01);
h1->SetBarOffset(0.1);
h1->SetFillColor(1);
h1->SetLineColor(1);
gPad->Modified();
gPad->Update();




c3->cd();
gr1->SetMarkerStyle(5);
gr1->SetMarkerColor(3);
gr1->SetLineColor(3);
gr1->SetMarkerSize(1.0);
       gr1->SetTitle("Backplane Capacitance : Preshower Sensor");
       gr1->GetXaxis()->SetTitle("Voltage");
       gr1->GetYaxis()->SetTitle("1/C^{2} [pF^{2}]");
       gr1->Fit("f1","R");
       gr1->Fit("f2","R+");
       gr1->Draw("apl");
         f1->SetLineColor(markercolor);
         fint = new TF1("fint",finter,0,500.00);
         xint = fint->GetMinimumX();
         yint=xint*(gr1->GetFunction("f1")->GetParameter(1))+(gr1->GetFunction("f1")->GetParameter(0));
         cout<<xint<<" "<< TMath::Sqrt(1/yint)/32<<endl;
//  mg1->Add(gr);

//   mg1->GetXaxis()->SetTitle("Voltage [V]");
//   mg1->GetYaxis()->SetTitle("1/C^{2} [pF^{-2}]");



 //gPad->Updated();
// gPad->Modified();

  // data.Write();
   //T->Write();
   //f->Write();
   //f->Close();


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
		if((string(dirp->d_name)=="CV_Diodes.C")||(string(dirp->d_name)=="TextToRoot.C"||(string(dirp->d_name)=="test.txt"))
    ||(string(dirp->d_name)==".")||(string(dirp->d_name)==".."||string(dirp->d_name).find(".root")!=-1)){continue;}
        files.push_back(string(dirp->d_name));
      //  cout<<string(dirp->d_name)<<endl;
    }
    closedir(dp);
    return 0;
}

int get_points(TString root_name,TGraph *gr){
  gROOT->Reset();


  TFile* in_file=new TFile(root_name);

    float Voltage,Capacitance;
    float* row_content;


       int markerstyle=20;
       int markercolor =1;
       int marker =1;

                   if(marker==0||marker==10){
                     marker++;
                   }
                   if(markercolor==0||markercolor==10){
                     markercolor++;
                   }

                   if(marker>49){marker=1;}
                   if(markercolor>49){markercolor=1;}

     TNtuple* data=(TNtuple*) in_file->GetObjectChecked("data","TNtuple");
/*     for(int irow=0; irow<data->GetEntries();++irow)
     {   data->GetEntry(irow);
         row_content=data->GetArgs();
         Voltage=row_content[0];
         Capacitance1=row_content[1];
         Capacitance2=row_content[2];
         Capacitance3=row_content[3];
         Capacitance4=row_content[4];
         Capacitance5=row_content[5];
         Capacitance6=row_content[6];
         Capacitance7=row_content[7];
         Capacitance8=row_content[8];
         if(abs(Voltage)<300){
         gr1->SetPoint(irow,abs(Voltage),Capacitance1*1E+12);
         gr2->SetPoint(irow,abs(Voltage),Capacitance2*1E+12);
         gr3->SetPoint(irow,abs(Voltage),Capacitance3*1E+12);
         gr4->SetPoint(irow,abs(Voltage),Capacitance4*1E+12);
         gr5->SetPoint(irow,abs(Voltage),Capacitance5*1E+12);
         gr6->SetPoint(irow,abs(Voltage),Capacitance6*1E+12);
         gr7->SetPoint(irow,abs(Voltage),Capacitance7*1E+12);
         gr8->SetPoint(irow,abs(Voltage),Capacitance8*1E+12);
         cout<<TMath::Power(1/(Capacitance*1E+12),2)<<endl;
       }
   }*/

  return 0;
 }

int TextToRoot()
{
/*  TCanvas *c0=new TCanvas("c0","CV",300,10,900,500);
  c0->SetGrid();

  TMultiGraph *mg = new TMultiGraph();
  mg->SetMinimum(0.0);
  mg->SetMaximum(4e-3);
  mg->SetTitle("#splitline{Backplane Capacitance : PS-p light std  :}{All Variants}");
   gStyle->SetTitleFontSize(0.035);
   gStyle->SetTitleAlign(23);


   int markerstyle=20;
   int markercolor =1;
   int marker =1;

   TLegend *leg = new TLegend(0.75, 0.20, 0.95, 0.65);
  // leg-> SetNColumns(1);
   leg->SetTextColor(kBlue);;
   leg->SetTextAlign(12);
   leg->SetTextAlign(12);
   leg->SetNColumns(1);
   leg->SetTextSize(0.035);

*/

    string dir = string(".");  // Set the folder for search (".") for parent file
    vector<string> files = vector<string>(); // This vector will contain the names of each file in the folder after getdir function
    getdir(dir,files);

    sort_string_vector(files);

    cout<<files.size()<<endl;
        for (unsigned int k = 0; k<files.size();k++) {

      TGraph *gr=new TGraph();


    size_t pos1= files[k].find(".root");
    if(pos1==-1){
      size_t pos= files[k].find(".txt");
      cout << files[k] << endl;
      if(pos!=-1){
      string r=files[k];
      r=r.replace(r.begin()+pos,r.end(),".root");
      char *root_name = new char[pos + 1];
      std::strcpy(root_name, r.c_str());
      Convert_TestDataFile_To_RootTree(files[k],r);



/*
               if(marker==0||marker==10){
                 marker++;
               }
               if(markercolor==0||markercolor==10){
                 markercolor++;
               }

               if(marker>49){marker=1;}
               if(markercolor>49){markercolor=1;}


      gr->SetMarkerStyle(markerstyle);
      gr->SetMarkerColor(marker);
      gr->SetLineColor(marker);
      gr->SetMarkerSize(0.8);

     TF1 *f1=new TF1("f1","pol1",0.0,2.0);

        c0->cd();
        TPad pad;
        TStyle st;
        pad.SetTitle("Inter-strip Capacitance  ");
        pad.DrawFrame(0,0,300,1e-4);
        get_points(r,gr);    // call of get_points(string,TGraph) function
      //  gr->Fit("f1");
    //    gr->GetFunction("f1")->SetLineColor(marker);
    //    double slope=gr->GetFunction("f1")->GetParameter(1);
    //    double Rbias=1/slope;
    //    string s="slope="+to_string(slope);
    //    string R="Rbias="+to_string(Rbias);


      TGaxis::SetMaxDigits(3);

        gr->GetXaxis()->SetTitle("Voltage [V]");
        gr->GetYaxis()->SetTitle("Current [uA]");
        gr->GetXaxis()->SetRangeUser(0,300);
        gr->GetYaxis()->SetDecimals(1);
        pad.Modified();
        pad.Update();
         // call of get_points(string,TGraph) function




        mg->Add(gr);
        mg->Draw("ap");
        mg->GetXaxis()->SetTitle("Voltage [V]");
        mg->GetYaxis()->SetTitle("1/C^{2} [pF^{-2}]");
        leg->AddEntry(gr,files[k].substr(0,26).c_str(),"lp");
  //      leg->AddEntry(gr,s.c_str(),"lp");
  //      leg->AddEntry(gr,R.c_str(),"lp");
        leg->Draw("apl");
        pad.Modified();
        pad.Update();

        marker++;
        markerstyle++;
        markercolor++;
*/
      }
     }
     }

  //   c0->SaveAs("BackplaneCapacitance_PS_p_light.png");

    return 0;
}
