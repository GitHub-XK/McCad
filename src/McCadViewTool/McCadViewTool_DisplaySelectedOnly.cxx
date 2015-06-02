#include <McCadViewTool_DisplaySelectedOnly.ixx>
#include <V3d_View.hxx>
#include <AIS_InteractiveContext.hxx>
#include <AIS_InteractiveObject.hxx>
#include <AIS_ListOfInteractive.hxx>
#include <AIS_ListIteratorOfListOfInteractive.hxx>

#include <QMcCad_Application.h>
#include <QMcCadGeomeTree_TreeWidget.hxx>

McCadViewTool_DisplaySelectedOnly::McCadViewTool_DisplaySelectedOnly(const Handle(McCadCom_CasDocument)& theDoc,const Handle(McCadCom_CasView)& theView,const McCadTool_State theState,const Standard_Boolean theUndoState,const Standard_Boolean theRedoState)
{
	myDoc = theDoc;
	myView = theView;
	myState = theState;
	myUndoState = theUndoState;
	myRedoState = theRedoState;
	myID = McCadTool_DispSelOnly;
}

Standard_Boolean McCadViewTool_DisplaySelectedOnly::IsNull()
{
	return Standard_False;
}

 void McCadViewTool_DisplaySelectedOnly::Destroy()
{
}

 void McCadViewTool_DisplaySelectedOnly::Execute()
{
     Handle(AIS_InteractiveContext) theContext = myDoc->GetContext();
//	 AIS_ListOfInteractive ioList;

//	 theIC->DisplayedObjects(ioList);
//	 AIS_ListIteratorOfListOfInteractive it(ioList);

//	 for(; it.More(); it.Next())
//	 {
//         if(!theIC->IsSelected(it.Value()))
//             theIC->Erase(it.Value(),0,1);
//	 }

//	 theIC->UpdateCurrentViewer();

//	 Done();

     AIS_ListOfInteractive ioList;

     theContext->DisplayedObjects(ioList);
     AIS_ListIteratorOfListOfInteractive it(ioList);

     for(; it.More(); it.Next())
     {
         if(!theContext->IsHilighted(it.Value()))
         {
             theContext->Erase(it.Value(),0,1);
             QMcCad_Application::GetAppMainWin()->Mcout("Noeee5");
             Handle(AIS_Shape) aShape = Handle(AIS_Shape)::DownCast(it.Value());
              TopoDS_Shape theShp = aShape->Shape();

              TopAbs::Print(theShp.ShapeType(),cout);cout << endl;

              if(theShp.ShapeType() == TopAbs_FACE)
              {
                  QMcCad_Application::GetAppMainWin()->Mcout("No5555");
              }
         }
     }

     theContext->UpdateCurrentViewer();\
     Done();
}

 void McCadViewTool_DisplaySelectedOnly::UnExecute()
{
}

 void McCadViewTool_DisplaySelectedOnly::Suspend()
{
}

 void McCadViewTool_DisplaySelectedOnly::Resume()
{
}

 void McCadViewTool_DisplaySelectedOnly::MousePressEvent(const McCadWin_MouseEvent& e)
{
}

 void McCadViewTool_DisplaySelectedOnly::MouseReleaseEvent(const McCadWin_MouseEvent& e)
{
}

 void McCadViewTool_DisplaySelectedOnly::MouseLeaveEvent()
{
}

 void McCadViewTool_DisplaySelectedOnly::MouseEnterEvent()
{
}

