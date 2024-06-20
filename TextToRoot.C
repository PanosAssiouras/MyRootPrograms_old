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
   //TNtuple data("data","CV","Voltage:Capacitance1:Capacitance2:Capacitance3:Capacitance4:Capacitance5:Capacitance6:Capacitance7:Capacitance8: Capacitance9:Capacitance10:Capacitance11:Capacitance12:Capacitance13:Capacitance14:Capacitance15:Capacitance16:Capacitance17:Capacitance18:Capacitance19:Capacitance20:Capacitance21:Capacitance22:Capacitance23:Capacitance24:Capacitance25:Capacitance26:Capacitance27:Capacitance28:Capacitance29:Capacitance30:Capacitance31:Capacitance32:CapacitanceSum");
   cout<<TextDataName<<endl;
//   cout<<"root"<<endl;
	  std:: ifstream inputFile(TextDataName);
	  std::string line="";

  vector<vector<double > > Currents;
  vector<double> Voltages;
  vector<string> names;

      int nrows=0;
	  while(!inputFile.eof()){
      getline(inputFile,line);
        double Current;
      double Voltage;
      string name;
      if (line.length()==0|| line[0] == 'I' || line[0]=='B'||line[0]=='#'||line[0]=='F'
      ||line[0]=='D'||line[0]=='C'||line[0]=='+'||line[0]=='V'){continue;}
    /*  if(){
        stringstream ss;
        ss<< line;
        while(ss){
          ss>>name;
          names.push_back(name);*/
      //  }
      //}
      else{
       stringstream ss;
       ss << line;
       ss >> Voltage;
        Voltages.push_back(Voltage);
        int ncols=1;
        vector<double> rows;
        cout<<line<<endl;
      while (ss>>Current)
          {

        //  ss >> Current;
          rows.push_back(Current);
          cout<<ncols<<" : "<<Current<<endl;
          ncols++;
          }
        Currents.push_back(rows);
       nrows++;
       ncols=1;
       ss.str(std::string());
  }
}



 TCanvas *c1=new TCanvas("c1","IV",300,10,900,500);
 c1->SetGrid();


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


 TMultiGraph* mg1 = new TMultiGraph();
  mg1->SetMinimum(0.0);
  mg1->SetMaximum(3.0);
  mg1->SetTitle("#splitline{IV Strip scans : Baby sensors :}{All 127 strips}");
  gStyle->SetTitleFontSize(0.035);
  gStyle->SetTitleAlign(23);

    TGraph *gr=new TGraph();

    for(int j=0; j<=Currents[0].size()-1; j++){

          TGraph *gr=new TGraph();
        //  TGraph *gr2=new TGraph();
        //    TF1 *fint2 = new TF1("fint2",finter,0,500.00);
      for(int i=0; i<=Currents.size()-1; i++){

      //  cout<<j<<" : "<<Currents[i][j]<<endl;


        if(marker==0||marker==10){
          marker++;
        }
        if(markercolor==0||markercolor==10||markercolor==18||markercolor==17||markercolor==21||markercolor==23||markercolor==25){
          markercolor++;
        }

        if(marker>49){marker=1;}
        if(markercolor>49){markercolor=1;}
        // cout<<Voltages[i]<<",";

      gr->SetPoint(i,abs(Voltages[i]),Currents[i][j]*1e+9);

    gr->SetMarkerStyle(markerstyle);
     gr->SetMarkerColor(markercolor);
     gr->SetLineColor(markercolor);
     gr->SetMarkerSize(0.8);


    }

   markercolor++;
   markerstyle++;


    c1->cd();
        string name="strip_"+to_string(j+1);
//        cout<<name<<endl;
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


 }



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

/*int get_points(TString root_name,TGraph *gr){
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

  return 0;
 }
*/
int TextToRoot()
{


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




      }
     }
     }


    return 0;
}
