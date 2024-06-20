// Mainframe macro generated from application: /home/panos/root/bin/root.exe
// By ROOT version 6.08/06 on 2017-07-12 18:01:23

#ifndef ROOT_TGDockableFrame
#include "TGDockableFrame.h"
#endif
#ifndef ROOT_TGMenu
#include "TGMenu.h"
#endif
#ifndef ROOT_TGMdiDecorFrame
#include "TGMdiDecorFrame.h"
#endif
#ifndef ROOT_TG3DLine
#include "TG3DLine.h"
#endif
#ifndef ROOT_TGMdiFrame
#include "TGMdiFrame.h"
#endif
#ifndef ROOT_TGMdiMainFrame
#include "TGMdiMainFrame.h"
#endif
#ifndef ROOT_TGMdiMenu
#include "TGMdiMenu.h"
#endif
#ifndef ROOT_TGListBox
#include "TGListBox.h"
#endif
#ifndef ROOT_TGNumberEntry
#include "TGNumberEntry.h"
#endif
#ifndef ROOT_TGScrollBar
#include "TGScrollBar.h"
#endif
#ifndef ROOT_TGComboBox
#include "TGComboBox.h"
#endif
#ifndef ROOT_TGuiBldHintsEditor
#include "TGuiBldHintsEditor.h"
#endif
#ifndef ROOT_TGuiBldNameFrame
#include "TGuiBldNameFrame.h"
#endif
#ifndef ROOT_TGFrame
#include "TGFrame.h"
#endif
#ifndef ROOT_TGFileDialog
#include "TGFileDialog.h"
#endif
#ifndef ROOT_TGShutter
#include "TGShutter.h"
#endif
#ifndef ROOT_TGButtonGroup
#include "TGButtonGroup.h"
#endif
#ifndef ROOT_TGCanvas
#include "TGCanvas.h"
#endif
#ifndef ROOT_TGFSContainer
#include "TGFSContainer.h"
#endif
#ifndef ROOT_TGFontDialog
#include "TGFontDialog.h"
#endif
#ifndef ROOT_TGuiBldEditor
#include "TGuiBldEditor.h"
#endif
#ifndef ROOT_TGColorSelect
#include "TGColorSelect.h"
#endif
#ifndef ROOT_TGButton
#include "TGButton.h"
#endif
#ifndef ROOT_TGFSComboBox
#include "TGFSComboBox.h"
#endif
#ifndef ROOT_TGLabel
#include "TGLabel.h"
#endif
#ifndef ROOT_TGMsgBox
#include "TGMsgBox.h"
#endif
#ifndef ROOT_TRootGuiBuilder
#include "TRootGuiBuilder.h"
#endif
#ifndef ROOT_TGTab
#include "TGTab.h"
#endif
#ifndef ROOT_TGListView
#include "TGListView.h"
#endif
#ifndef ROOT_TGSplitter
#include "TGSplitter.h"
#endif
#ifndef ROOT_TGStatusBar
#include "TGStatusBar.h"
#endif
#ifndef ROOT_TGListTree
#include "TGListTree.h"
#endif
#ifndef ROOT_TGuiBldGeometryFrame
#include "TGuiBldGeometryFrame.h"
#endif
#ifndef ROOT_TGToolTip
#include "TGToolTip.h"
#endif
#ifndef ROOT_TGToolBar
#include "TGToolBar.h"
#endif
#ifndef ROOT_TGuiBldDragManager
#include "TGuiBldDragManager.h"
#endif

#include "Riostream.h"

void testgui()
{

   // main frame
   TGMainFrame *fMainFrame1874 = new TGMainFrame(gClient->GetRoot(),10,10,kMainFrame | kVerticalFrame);
   fMainFrame1874->SetName("fMainFrame1874");
   fMainFrame1874->SetLayoutBroken(kTRUE);

   TGFont *ufont;         // will reflect user font changes
   ufont = gClient->GetFont("-*-helvetica-medium-r-*-*-12-*-*-*-*-*-iso8859-1");

   TGGC   *uGC;           // will reflect user GC changes
   // graphics context changes
   GCValues_t valButton1064;
   valButton1064.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",valButton1064.fForeground);
   gClient->GetColorByName("#e8e8e8",valButton1064.fBackground);
   valButton1064.fFillStyle = kFillSolid;
   valButton1064.fFont = ufont->GetFontHandle();
   valButton1064.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&valButton1064, kTRUE);
   TGTextButton *fTextButton1064 = new TGTextButton(fMainFrame1874,"IV",-1,uGC->GetGC(),ufont->GetFontStruct(),kRaisedFrame);
   fTextButton1064->SetTextJustify(36);
   fTextButton1064->SetMargins(0,0,0,0);
   fTextButton1064->SetWrapLength(-1);
   fTextButton1064->Resize(99,27);
   fMainFrame1874->AddFrame(fTextButton1064, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fTextButton1064->MoveResize(24,96,99,27);
   TGTextButton *fTextButton1222 = new TGTextButton(fMainFrame1874,"CV",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
   fTextButton1222->SetTextJustify(36);
   fTextButton1222->SetMargins(0,0,0,0);
   fTextButton1222->SetWrapLength(-1);
   fTextButton1222->Resize(99,27);
   fMainFrame1874->AddFrame(fTextButton1222, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fTextButton1222->MoveResize(24,144,99,27);

   fMainFrame1874->SetMWMHints(kMWMDecorAll,
                        kMWMFuncAll,
                        kMWMInputModeless);
   fMainFrame1874->MapSubwindows();

   fMainFrame1874->Resize(fMainFrame1874->GetDefaultSize());
   fMainFrame1874->MapWindow();
   fMainFrame1874->Resize(407,360);
}  
