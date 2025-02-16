
//For intersecting functions it will report the intersecting point.
//For non intersecting functions it will return the point of closest approach between the 2 functions.
#include <iostream>
#include "TROOT.h"
#include "TSystem.h"
#include "TMath.h"
#include "TF1.h"
using namespace std; 

TF1 *f1, *f2;
double finter(double *x, double*par) {
   return TMath::Abs(f1->EvalPar(x,par) - f2->EvalPar(x,par));
}
void fint() {
   f1 = new TF1("f1","1+2*x+0.2*x*x",0,10);
   f2 = new TF1("f2","6+3*x-0.3*x*x",0,10);
   f1->Draw();
   f2->Draw("same");
   TF1 *fint = new TF1("fint",finter,0,10,0);
   double xint = fint->GetMinimumX();
   fint->Draw("lsame");
   TMarker *m = new TMarker(xint,f1->Eval(xint),24);
   m->SetMarkerColor(kRed);
   m->SetMarkerSize(3);
   m->Draw();
   printf("xint=%g\n",xint);
}

