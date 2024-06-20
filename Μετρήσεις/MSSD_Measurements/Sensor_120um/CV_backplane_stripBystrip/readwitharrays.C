#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>

//int main()//uncomment if you prefer to compile as a standalone program.
void readwitharrays()
{  //Diavazei ta 12 txt arxeia kathe perioxhs krataei se pinakes ths teleyataies times 
	//apo to Strip3 kai to StripSum kai ypologizei to Cint
	//Eksagei tis times sto arxeio  "Capacitance.allRegions.120.experimental.stripbystrip.txt"
	
   std::ifstream inputFile1("Region_1.txt");
   std::ifstream inputFile2("Region_2.txt");
   std::ifstream inputFile3("Region_3.txt");
    std::ifstream inputFile4("Region_4.txt");
     std::ifstream inputFile5("Region_5.txt");
      std::ifstream inputFile6("Region_6.txt");
       std::ifstream inputFile7("Region_7.txt");
        std::ifstream inputFile8("Region_8.txt");
         std::ifstream inputFile9("Region_9.txt");
          std::ifstream inputFile10("Region_10.txt");
           std::ifstream inputFile11("Region_11.txt");
            std::ifstream inputFile12("Region_12.txt");
            
            std::ofstream myfile;
            myfile.open ("Capacitance.allRegions.120.experimental.stripbystrip.txt");
    
   std::string line;
   std::vector<float_t> StripSums,Strip3s,Ctot,Cb,Cints;
   
   

//ftiaxnw pinakes StripSums , Strip3s me tis teleytaies times apo kathe txt arxeio     
   
//Region_1.txt 
      double Voltage = 0., Strip1 = 0., Strip2=0. , Strip3=0. , Strip4=0. , Strip5=0. , StripSum=0. , StripAll=0. ;
   while(getline(inputFile1, line)) {
      if (!line.length() || line[0] == 'C' || line[0]=='B')
         continue;
   //  double Voltage = 0., Strip1 = 0., Strip2=0. , Strip3=0. , Strip4=0. , Strip5=0. , StripSum=0. , StripAll=0. ;
      sscanf(line.c_str(), "%lf %lf %lf %lf %lf %lf %lf %lf", &Voltage, &Strip1 , &Strip2 , &Strip3 , &Strip4 , &Strip5 , &StripSum , &StripAll);
     // Strip3s.push_back(Strip3);
     // StripSums.push_back(StripSum);
   }
      Strip3s.push_back(Strip3);
      StripSums.push_back(StripSum);
//---------------------------------------------------------------------------------------------------
      
//Region_2.txt 
      Voltage = 0., Strip1 = 0., Strip2=0. , Strip3=0. , Strip4=0. , Strip5=0. , StripSum=0. , StripAll=0. ;
   while(getline(inputFile2, line)) {
      if (!line.length() || line[0] == 'C' || line[0]=='B')
         continue;
   //  double Voltage = 0., Strip1 = 0., Strip2=0. , Strip3=0. , Strip4=0. , Strip5=0. , StripSum=0. , StripAll=0. ;
      sscanf(line.c_str(), "%lf %lf %lf %lf %lf %lf %lf %lf", &Voltage, &Strip1 , &Strip2 , &Strip3 , &Strip4 , &Strip5 , &StripSum , &StripAll);
    //  Strip3s.push_back(Strip3);
     // StripSums.push_back(StripSum);
   }
      Strip3s.push_back(Strip3);
      StripSums.push_back(StripSum);
//----------------------------------------------------------------------------------------------------------------         
//Region_3.txt 
      Voltage = 0., Strip1 = 0., Strip2=0. , Strip3=0. , Strip4=0. , Strip5=0. , StripSum=0. , StripAll=0. ;
   while(getline(inputFile3, line)) {
      if (!line.length() || line[0] == 'C' || line[0]=='B')
         continue;
   //  double Voltage = 0., Strip1 = 0., Strip2=0. , Strip3=0. , Strip4=0. , Strip5=0. , StripSum=0. , StripAll=0. ;
      sscanf(line.c_str(), "%lf %lf %lf %lf %lf %lf %lf %lf", &Voltage, &Strip1 , &Strip2 , &Strip3 , &Strip4 , &Strip5 , &StripSum , &StripAll);
    //  Strip3s.push_back(Strip3);
     // StripSums.push_back(StripSum);
   }
      Strip3s.push_back(Strip3);
      StripSums.push_back(StripSum);
//----------------------------------------------------------------------------------------------------------------     
//Region_4.txt 
      Voltage = 0., Strip1 = 0., Strip2=0. , Strip3=0. , Strip4=0. , Strip5=0. , StripSum=0. , StripAll=0. ;
   while(getline(inputFile4, line)) {
      if (!line.length() || line[0] == 'C' || line[0]=='B')
         continue;
   //  double Voltage = 0., Strip1 = 0., Strip2=0. , Strip3=0. , Strip4=0. , Strip5=0. , StripSum=0. , StripAll=0. ;
      sscanf(line.c_str(), "%lf %lf %lf %lf %lf %lf %lf %lf", &Voltage, &Strip1 , &Strip2 , &Strip3 , &Strip4 , &Strip5 , &StripSum , &StripAll);
    //  Strip3s.push_back(Strip3);
     // StripSums.push_back(StripSum);
   }
      Strip3s.push_back(Strip3);
      StripSums.push_back(StripSum);
//----------------------------------------------------------------------------------------------------------------     
 //Region_5.txt 
      Voltage = 0., Strip1 = 0., Strip2=0. , Strip3=0. , Strip4=0. , Strip5=0. , StripSum=0. , StripAll=0. ;
   while(getline(inputFile5, line)) {
      if (!line.length() || line[0] == 'C' || line[0]=='B')
         continue;
   //  double Voltage = 0., Strip1 = 0., Strip2=0. , Strip3=0. , Strip4=0. , Strip5=0. , StripSum=0. , StripAll=0. ;
      sscanf(line.c_str(), "%lf %lf %lf %lf %lf %lf %lf %lf", &Voltage, &Strip1 , &Strip2 , &Strip3 , &Strip4 , &Strip5 , &StripSum , &StripAll);
    //  Strip3s.push_back(Strip3);
     // StripSums.push_back(StripSum);
   }
      Strip3s.push_back(Strip3);
      StripSums.push_back(StripSum);
//----------------------------------------------------------------------------------------------------------------    
   //Region_6.txt 
      Voltage = 0., Strip1 = 0., Strip2=0. , Strip3=0. , Strip4=0. , Strip5=0. , StripSum=0. , StripAll=0. ;
   while(getline(inputFile6, line)) {
      if (!line.length() || line[0] == 'C' || line[0]=='B')
         continue;
   //  double Voltage = 0., Strip1 = 0., Strip2=0. , Strip3=0. , Strip4=0. , Strip5=0. , StripSum=0. , StripAll=0. ;
      sscanf(line.c_str(), "%lf %lf %lf %lf %lf %lf %lf %lf", &Voltage, &Strip1 , &Strip2 , &Strip3 , &Strip4 , &Strip5 , &StripSum , &StripAll);
    //  Strip3s.push_back(Strip3);
     // StripSums.push_back(StripSum);
   }
      Strip3s.push_back(Strip3);
      StripSums.push_back(StripSum);
//----------------------------------------------------------------------------------------------------------------  
   //Region_7.txt 
      Voltage = 0., Strip1 = 0., Strip2=0. , Strip3=0. , Strip4=0. , Strip5=0. , StripSum=0. , StripAll=0. ;
   while(getline(inputFile7, line)) {
      if (!line.length() || line[0] == 'C' || line[0]=='B')
         continue;
   //  double Voltage = 0., Strip1 = 0., Strip2=0. , Strip3=0. , Strip4=0. , Strip5=0. , StripSum=0. , StripAll=0. ;
      sscanf(line.c_str(), "%lf %lf %lf %lf %lf %lf %lf %lf", &Voltage, &Strip1 , &Strip2 , &Strip3 , &Strip4 , &Strip5 , &StripSum , &StripAll);
    //  Strip3s.push_back(Strip3);
     // StripSums.push_back(StripSum);
   }
      Strip3s.push_back(Strip3);
      StripSums.push_back(StripSum);
//----------------------------------------------------------------------------------------------------------------  
   //Region_8.txt 
      Voltage = 0., Strip1 = 0., Strip2=0. , Strip3=0. , Strip4=0. , Strip5=0. , StripSum=0. , StripAll=0. ;
   while(getline(inputFile8, line)) {
      if (!line.length() || line[0] == 'C' || line[0]=='B')
         continue;
   //  double Voltage = 0., Strip1 = 0., Strip2=0. , Strip3=0. , Strip4=0. , Strip5=0. , StripSum=0. , StripAll=0. ;
      sscanf(line.c_str(), "%lf %lf %lf %lf %lf %lf %lf %lf", &Voltage, &Strip1 , &Strip2 , &Strip3 , &Strip4 , &Strip5 , &StripSum , &StripAll);
    //  Strip3s.push_back(Strip3);
     // StripSums.push_back(StripSum);
   }
      Strip3s.push_back(Strip3);
      StripSums.push_back(StripSum);
//----------------------------------------------------------------------------------------------------------------  
   //Region_9.txt 
      Voltage = 0., Strip1 = 0., Strip2=0. , Strip3=0. , Strip4=0. , Strip5=0. , StripSum=0. , StripAll=0. ;
   while(getline(inputFile9, line)) {
      if (!line.length() || line[0] == 'C' || line[0]=='B')
         continue;
   //  double Voltage = 0., Strip1 = 0., Strip2=0. , Strip3=0. , Strip4=0. , Strip5=0. , StripSum=0. , StripAll=0. ;
      sscanf(line.c_str(), "%lf %lf %lf %lf %lf %lf %lf %lf", &Voltage, &Strip1 , &Strip2 , &Strip3 , &Strip4 , &Strip5 , &StripSum , &StripAll);
    //  Strip3s.push_back(Strip3);
     // StripSums.push_back(StripSum);
   }
      Strip3s.push_back(Strip3);
      StripSums.push_back(StripSum);
//----------------------------------------------------------------------------------------------------------------  
   //Region_10.txt 
      Voltage = 0., Strip1 = 0., Strip2=0. , Strip3=0. , Strip4=0. , Strip5=0. , StripSum=0. , StripAll=0. ;
   while(getline(inputFile10, line)) {
      if (!line.length() || line[0] == 'C' || line[0]=='B')
         continue;
   //  double Voltage = 0., Strip1 = 0., Strip2=0. , Strip3=0. , Strip4=0. , Strip5=0. , StripSum=0. , StripAll=0. ;
      sscanf(line.c_str(), "%lf %lf %lf %lf %lf %lf %lf %lf", &Voltage, &Strip1 , &Strip2 , &Strip3 , &Strip4 , &Strip5 , &StripSum , &StripAll);
    //  Strip3s.push_back(Strip3);
     // StripSums.push_back(StripSum);
   }
      Strip3s.push_back(Strip3);
      StripSums.push_back(StripSum);
//----------------------------------------------------------------------------------------------------------------  
   //Region_11.txt 
      Voltage = 0., Strip1 = 0., Strip2=0. , Strip3=0. , Strip4=0. , Strip5=0. , StripSum=0. , StripAll=0. ;
   while(getline(inputFile11, line)) {
      if (!line.length() || line[0] == 'C' || line[0]=='B')
         continue;
   //  double Voltage = 0., Strip1 = 0., Strip2=0. , Strip3=0. , Strip4=0. , Strip5=0. , StripSum=0. , StripAll=0. ;
      sscanf(line.c_str(), "%lf %lf %lf %lf %lf %lf %lf %lf", &Voltage, &Strip1 , &Strip2 , &Strip3 , &Strip4 , &Strip5 , &StripSum , &StripAll);
    //  Strip3s.push_back(Strip3);
     // StripSums.push_back(StripSum);
   }
      Strip3s.push_back(Strip3);
      StripSums.push_back(StripSum);
//----------------------------------------------------------------------------------------------------------------  
   //Region_12.txt 
      Voltage = 0., Strip1 = 0., Strip2=0. , Strip3=0. , Strip4=0. , Strip5=0. , StripSum=0. , StripAll=0. ;
   while(getline(inputFile12, line)) {
      if (!line.length() || line[0] == 'C' || line[0]=='B')
         continue;
   //  double Voltage = 0., Strip1 = 0., Strip2=0. , Strip3=0. , Strip4=0. , Strip5=0. , StripSum=0. , StripAll=0. ;
      sscanf(line.c_str(), "%lf %lf %lf %lf %lf %lf %lf %lf", &Voltage, &Strip1 , &Strip2 , &Strip3 , &Strip4 , &Strip5 , &StripSum , &StripAll);
    //  Strip3s.push_back(Strip3);
     // StripSums.push_back(StripSum);
   }
      Strip3s.push_back(Strip3);
      StripSums.push_back(StripSum);
//----------------------------------------------------------------------------------------------------------------  

//------------------------------------------------------------------------------------------------------------------   
   
   
   std::cout<<"points read:\n";
   for (int i = 0; i < int(Strip3s.size()); ++i){
//afairw parasitic 2.36 pF
      Strip3s[i]=Strip3s[i]-2.36e-12;
      StripSums[i]=StripSums[i]-2.36e-12;
//diairw me mhkos 3.045 cm       
      Strip3s[i]=Strip3s[i]/3.049;
      StripSums[i]=StripSums[i]/3.049; 
//diairw backplane me 3 (3 strips)
      StripSums[i]=StripSums[i]/3.0;
//ypologizw Cint apo typo Ctot=2*Cint+[(n-1)/n]*Cb gia n=3
      float_t Cint=(Strip3s[i]-(2.0*StripSums[i]/3.0))/2;
      Cints.push_back(Cint);  
        std::cout<<"point["<<i<<"]: ("<<Strip3s[i]<<", "<<StripSums[i]<<","<<Cints[i]<<")\n";        
        myfile << Strip3s[i]<<" "<<StripSums[i]<<" "<<Cints[i]<<" \n";
    } 
    
    
    myfile.close();
    

                    
}




