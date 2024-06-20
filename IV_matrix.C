#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

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

int getdir (string dir, vector<string> &files)
{   //This function search a folder  (dir) and keeps the names of it's contents to a vector<string>
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl; // returns error if dir folder dosen't open
        return errno;
    }
    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name)); // fills the vector<string> with each name
    }
    closedir(dp);
    return 0;
}

int IV_matrix(){
  gROOT->Reset();
  gROOT->SetStyle("Plain");
  gStyle->SetPalette(1);
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);

  TCanvas *c0=new TCanvas("c0","Current vs Voltage:0 to 350:std_2_15_351136",300,10,900,500);
  c0->SetGrid();
  //TH1F *Hist= new TH1F("Hist","1D",127,0,127);
  TH2D *Hist= new TH2D("Hist","2D",127,0,126,1,0,1);

  string dir = string(".");  // Set the folder for search (".") for parent file
  vector<string> files = vector<string>(); // This vector will contain the names of each file in the folder after getdir function

  getdir(dir,files); // call of getdir(file,vector<string>) function
  sort_string_vector(files);
  for (unsigned int i = 0;i < files.size();i++) {
  size_t pos= files[i].find(".txt");
  if(pos!=-1)
  {
    std:: ifstream inputFile(files[i]);
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

        TLegend *leg = new TLegend(0.75, 0.20, 0.95, 0.65);
       // leg-> SetNColumns(1);
        leg->SetTextColor(kBlue);;
        leg->SetTextAlign(12);
        leg->SetTextAlign(12);
        leg->SetNColumns(2);
        leg->SetTextSize(0.030);

   gStyle->SetTitleFontSize(0.035);
   gStyle->SetTitleAlign(23);


    for(int j=0; j<=Currents[0].size()-1; j++){
      for(int i=0; i<=Currents.size()-1; i++){





        string s1=""+to_string(j+1);
        char *name = new char[pos + 1];
        std::strcpy(name, s1.c_str());
      if(abs(Voltages[i])==300){
        cout<<Voltages[i]<<endl;
        string x1;
        ostringstream convert2;
        convert2<<0;
        x1=convert2.str();
        Hist->GetXaxis()->SetBinLabel(j+1,name);
        Hist->GetYaxis()->SetBinLabel(1,x1.c_str());
    //    Hist->GetYaxis()->SetNdivisions(127,0,0,kFALSE);
        Hist->Fill(name,x1.c_str(),Currents[i][j]*1E+09);
      }
   //        cout<<name<<endl;


     }

   }



       c0->cd();
       TAxis *Xaxis = Hist->GetXaxis();
       TAxis *Yaxis = Hist->GetYaxis();
       Yaxis->SetLabelOffset(999);
    //   Xaxis->SetLabelOffset(999);
       Xaxis->SetNdivisions(1,0,0,kFALSE);
       gPad->Modified();
       gPad->Update();
  //   Yaxis->SetNdivisions(1,kFALSE);
       Hist->GetXaxis()->SetLabelSize(0.02);
       Hist->SetTitle("Current matrix 200V:std_2_15_351136");
       Hist->GetXaxis()->SetTitle("Strip number");
    //   Hist->GetYaxis()->SetTitle("Row");

     gPad->Modified();
     gPad->Update();
       Hist->SetMinimum(0.0);
       Hist->SetMaximum(1.8);
       Hist->Draw("Colz");

       TPaletteAxis *palette = (TPaletteAxis*) Hist->GetListOfFunctions()->FindObject("palette");
         palette->SetLabelSize(0.015);
         palette->SetY2NDC(0.7);
      //  palette->SetLabelSize("0.02");

           gPad->Modified();
           gPad->Update();


  }

  }

  return 0;
}
