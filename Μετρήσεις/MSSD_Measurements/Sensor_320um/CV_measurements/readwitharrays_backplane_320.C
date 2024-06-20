#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>

//int main()//uncomment if you prefer to compile as a standalone program.
void readwitharrays_backplane_320()
{  //Diavazei ta 12 txt arxeia kathe perioxhs krataei se pinakes ths teleyataies times 
	//apo to Strip3 kai to StripSum kai ypologizei to Cint
	//Eksagei tis times sto arxeio  "Capacitance.allRegions.320.experimental.stripbystrip.txt"
	
   std::ifstream inputFile1("Region_1/backplane.txt");
   std::ifstream inputFile2("Region_2/backplane.txt");
   std::ifstream inputFile3("Region_3/backplane.txt");
    std::ifstream inputFile4("Region_4/backplane.txt");
     std::ifstream inputFile5("Region_5/backplane.txt");
      std::ifstream inputFile6("Region_6/backplane.txt");
       std::ifstream inputFile7("Region_7/backplane.txt");
        std::ifstream inputFile8("Region_8/backplane.txt");
         std::ifstream inputFile9("Region_9/backplane.txt");
          std::ifstream inputFile10("Region_10/backplane.txt");
           std::ifstream inputFile11("Region_11/backplane.txt");
            std::ifstream inputFile12("Region_12/backplane.txt");
            
            std::ofstream myfile;
            myfile.open ("Backplane.Capacitance.allRegions.320.experimental.txt");
    
   std::string line;
   std::vector<float_t> Voltages,Backplanes,Backplanes2,StripAlls;
   
   

//ftiaxnw pinakes StripSums , Strip3s me tis teleytaies times apo kathe txt arxeio     
   
//Region_1.txt 
      double Voltage = 0., Backplane= 0., Strip=0. , StripAll=0.;
   while(getline(inputFile1, line)) {
      if (!line.length() || line[0] == 'C' || line[0] == 'B' || line[0] == ' ' || line[0] == 'V')
         continue;
   //  double Voltage = 0., Backplane= 0., Strip=0. , StripAll=0.;
      sscanf(line.c_str(), "%lf %lf %lf %lf", &Voltage, &Backplane , &Strip , &StripAll);
     // Backplanes.push_back(Backplane);
     // StripSums.push_back(StripSum);
   }
      Backplanes.push_back(Backplane);
     StripAlls.push_back(StripAll);
//---------------------------------------------------------------------------------------------------
      
//Region_2.txt 
      Voltage = 0., Backplane= 0., Strip=0. , StripAll=0.;
   while(getline(inputFile2, line)) {
      if (!line.length() || line[0] == 'C' || line[0]=='B'|| line[0]==' '||line[0]=='V')
         continue;
   //  double Voltage = 0., Backplane= 0., Strip=0. , StripAll=0.;
      sscanf(line.c_str(), "%lf %lf %lf %lf", &Voltage, &Backplane , &Strip , &StripAll);
    //  Backplanes.push_back(Backplane);
     // StripSums.push_back(StripSum);
   }
      Backplanes.push_back(Backplane);
     StripAlls.push_back(StripAll);
//----------------------------------------------------------------------------------------------------------------         
//Region_3.txt 
      Voltage = 0., Backplane= 0., Strip=0. , StripAll=0.;
   while(getline(inputFile3, line)) {
      if (!line.length() || line[0] == 'C' || line[0]=='B'|| line[0]==' '||line[0]=='V')
         continue;
   //  double Voltage = 0., Backplane= 0., Strip=0. , StripAll=0.;
      sscanf(line.c_str(), "%lf %lf %lf %lf", &Voltage, &Backplane , &Strip , &StripAll);
    //  Backplanes.push_back(Backplane);
     // StripSums.push_back(StripSum);
   }
      Backplanes.push_back(Backplane);
     StripAlls.push_back(StripAll);
//----------------------------------------------------------------------------------------------------------------     
//Region_4.txt 
      Voltage = 0., Backplane= 0., Strip=0. , StripAll=0.;
   while(getline(inputFile4, line)) {
      if (!line.length() || line[0] == 'C' || line[0]=='B'|| line[0]==' '||line[0]=='V')
         continue;
   //  double Voltage = 0., Backplane= 0., Strip=0. , StripAll=0.;
      sscanf(line.c_str(), "%lf %lf %lf %lf", &Voltage, &Backplane , &Strip , &StripAll);
    //  Backplanes.push_back(Backplane);
     // StripSums.push_back(StripSum);
   }
      Backplanes.push_back(Backplane);
     StripAlls.push_back(StripAll);
//----------------------------------------------------------------------------------------------------------------     
 //Region_5.txt 
      Voltage = 0., Backplane= 0., Strip=0. , StripAll=0.;
   while(getline(inputFile5, line)) {
      if (!line.length() || line[0] == 'C' || line[0]=='B'|| line[0]==' '||line[0]=='V')
         continue;
   //  double Voltage = 0., Backplane= 0., Strip=0. , StripAll=0.;
      sscanf(line.c_str(), "%lf %lf %lf %lf", &Voltage, &Backplane , &Strip , &StripAll);
    //  Backplanes.push_back(Backplane);
     // StripSums.push_back(StripSum);
   }
      Backplanes.push_back(Backplane);
     StripAlls.push_back(StripAll);
//----------------------------------------------------------------------------------------------------------------    
   //Region_6.txt 
      Voltage = 0., Backplane= 0., Strip=0. , StripAll=0.;
   while(getline(inputFile6, line)) {
      if (!line.length() || line[0] == 'C' || line[0]=='B'|| line[0]==' '||line[0]=='V')
         continue;
   //  double Voltage = 0., Backplane= 0., Strip=0. , StripAll=0.;
      sscanf(line.c_str(), "%lf %lf %lf %lf", &Voltage, &Backplane , &Strip , &StripAll);
    //  Backplanes.push_back(Backplane);
     // StripSums.push_back(StripSum);
   }
      Backplanes.push_back(Backplane);
     StripAlls.push_back(StripAll);
//----------------------------------------------------------------------------------------------------------------  
   //Region_7.txt 
      Voltage = 0., Backplane= 0., Strip=0. , StripAll=0.;
   while(getline(inputFile7, line)) {
      if (!line.length() || line[0] == 'C' || line[0]=='B'|| line[0]==' '||line[0]=='V')
         continue;
   //  double Voltage = 0., Backplane= 0., Strip=0. , StripAll=0.;
      sscanf(line.c_str(), "%lf %lf %lf %lf", &Voltage, &Backplane , &Strip , &StripAll);
    //  Backplanes.push_back(Backplane);
     // StripSums.push_back(StripSum);
   }
      Backplanes.push_back(Backplane);
     StripAlls.push_back(StripAll);
//----------------------------------------------------------------------------------------------------------------  
   //Region_8.txt 
      Voltage = 0., Backplane= 0., Strip=0. , StripAll=0.;
   while(getline(inputFile8, line)) {
      if (!line.length() || line[0] == 'C' || line[0]=='B'|| line[0]==' '||line[0]=='V')
         continue;
   //  double Voltage = 0., Backplane= 0., Strip=0. , StripAll=0.;
      sscanf(line.c_str(), "%lf %lf %lf %lf", &Voltage, &Backplane , &Strip , &StripAll);
    //  Backplanes.push_back(Backplane);
     // StripSums.push_back(StripSum);
   }
      Backplanes.push_back(Backplane);
     StripAlls.push_back(StripAll);
//----------------------------------------------------------------------------------------------------------------  
   //Region_9.txt 
      Voltage = 0., Backplane= 0., Strip=0. , StripAll=0.;
   while(getline(inputFile9, line)) {
      if (!line.length() || line[0] == 'C' || line[0]=='B'|| line[0]==' '||line[0]=='V')
         continue;
   //  double Voltage = 0., Backplane= 0., Strip=0. , StripAll=0.;
      sscanf(line.c_str(), "%lf %lf %lf %lf", &Voltage, &Backplane , &Strip , &StripAll);
    //  Backplanes.push_back(Backplane);
     // StripSums.push_back(StripSum);
   }
      Backplanes.push_back(Backplane);
     StripAlls.push_back(StripAll);
//----------------------------------------------------------------------------------------------------------------  
   //Region_10.txt 
      Voltage = 0., Backplane= 0., Strip=0. , StripAll=0.;
   while(getline(inputFile10, line)) {
      if (!line.length() || line[0] == 'C' || line[0]=='B'|| line[0]==' '||line[0]=='V')
         continue;
   //  double Voltage = 0., Backplane= 0., Strip=0. , StripAll=0.;
      sscanf(line.c_str(), "%lf %lf %lf %lf", &Voltage, &Backplane , &Strip , &StripAll);
    //  Backplanes.push_back(Backplane);
     // StripSums.push_back(StripSum);
   }
      Backplanes.push_back(Backplane);
     StripAlls.push_back(StripAll);
//----------------------------------------------------------------------------------------------------------------  
   //Region_11.txt 
      Voltage = 0., Backplane= 0., Strip=0. , StripAll=0.;
   while(getline(inputFile11, line)) {
      if (!line.length() || line[0] == 'C' || line[0]=='B'|| line[0]==' '||line[0]=='V')
         continue;
   //  double Voltage = 0., Backplane= 0., Strip=0. , StripAll=0.;
      sscanf(line.c_str(), "%lf %lf %lf %lf", &Voltage, &Backplane , &Strip , &StripAll);
    //  Backplanes.push_back(Backplane);
     // StripSums.push_back(StripSum);
   }
      Backplanes.push_back(Backplane);
     StripAlls.push_back(StripAll);
//----------------------------------------------------------------------------------------------------------------  
   //Region_12.txt 
      Voltage = 0., Backplane= 0., Strip=0. , StripAll=0.;
   while(getline(inputFile12, line)) {
      if (!line.length() || line[0] == 'C' || line[0]=='B'|| line[0]==' '||line[0]=='V')
         continue;
   //  double Voltage = 0., Backplane= 0., Strip=0. , StripAll=0.;
      sscanf(line.c_str(), "%lf %lf %lf %lf", &Voltage, &Backplane , &Strip , &StripAll);
    //  Backplanes.push_back(Backplane);
     // StripSums.push_back(StripSum);
   }
      Backplanes.push_back(Backplane);
     StripAlls.push_back(StripAll);
//----------------------------------------------------------------------------------------------------------------  

//------------------------------------------------------------------------------------------------------------------   
   
   
   std::cout<<"points read:\n";
   for (int i =0; i < int(Backplanes.size()); ++i){
//afairw parasitic 2.36 pF
  Backplanes[i]=Backplanes[i]-2.36e-12;
  Backplanes[i]=Backplanes[i]/32;
//diairw me mhkos 3.045 cm       
   Backplanes2.push_back(Backplanes[i]/3.049);
 
       std::cout<<"point["<<i+1<<"]: ("<<Backplanes[i]<<", "<<Backplanes2[i]<<")\n";        
        myfile <<i+1<<" "<< Backplanes[i]<<" "<<Backplanes2[i] <<" \n";
        
    } 
    
    
    myfile.close();
    

                    
}




