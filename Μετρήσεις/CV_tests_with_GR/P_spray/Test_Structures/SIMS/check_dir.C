#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

/*function... might want it in some class?*/
int getdir (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }
    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}

int check_dir()
{   
	vector<TGraph> gr=new vector<TGraph>;
	
    string dir = string(".");
    vector<string> files = vector<string>();
    getdir(dir,files);

    for (unsigned int i = 0;i < files.size();i++) {
        int pos= files[i].find(".txt");
        if(pos!=-1)
        { 
			cout<<files[i]<<endl;
	
	    TGraph *gr1= new TGraph();		
		gr.push_back(gr1)
			
/*		
   while(getline(files[i], line)) {

      if (!line.length()|| line[0] == 'I' || line[0]=='B' || line[0]=='V'||line[0]=='#' || line.length()==1)
      {
         continue;
	 }
     else{    
      double Voltage=0.0 , Itotal=0.0 ,  
      sscanf(line.c_str(), "%lf %lf ", &Voltage, Itotal);          
      points++;
      gr->SetPoint(points-1,abs(Voltage),Itotal);

  }
   }		
	}*/
        
    }
    
    return 0;
}

int get_points()
{
	 /* while(getline(inputFile, line)) {

      if (!line.length()|| line[0] == 'I' || line[0]=='B' || line[0]=='V'||line[0]=='#' || line.length()==1)
      {
         continue;
	 }
     else{    
      double Voltage=0.0 , Itotal=0.0 ,  
      sscanf(line.c_str(), "%lf %lf %lf %lf", &Voltage, Itotal);          
      points++;
      gr->SetPoint(points-1,abs(Voltage),Itotal);

  }
   }*/
   }
