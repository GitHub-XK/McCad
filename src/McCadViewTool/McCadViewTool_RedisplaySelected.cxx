#include <McCadViewTool_RedisplaySelected.ixx>
#include <V3d_View.hxx>
#include <AIS_InteractiveContext.hxx>
#include <AIS_InteractiveObject.hxx>
#include <AIS_ListOfInteractive.hxx>
#include <AIS_ListIteratorOfListOfInteractive.hxx>
#include <QMcCad_Application.h>
#include <QMcCadGeomeTree_TreeWidget.hxx>

#include <StdSelect_FaceFilter.hxx>
#include <GeomAdaptor_Surface.hxx>


McCadViewTool_RedisplaySelected::McCadViewTool_RedisplaySelected(const Handle(McCadCom_CasDocument)& theDoc,const Handle(McCadCom_CasView)& theView,const McCadTool_State theState,const Standard_Boolean theUndoState,const Standard_Boolean theRedoState)
{
	myDoc = theDoc;
	myView = theView;
	myState = theState;
	myUndoState = theUndoState;
	myRedoState = theRedoState;
	myID = McCadTool_RedispSelected;
}

Standard_Boolean McCadViewTool_RedisplaySelected::IsNull()
{
	return Standard_False;
}

 void McCadViewTool_RedisplaySelected::Destroy()
{
}

 void McCadViewTool_RedisplaySelected::Execute()
{
     /*AIS_ListOfInteractive ioList;
	 QMcCad_Application::GetAppMainWin()->GetTreeWidget()->GetSelected(ioList);

	 Handle(AIS_InteractiveContext) theIC = myDoc->GetContext();

	 AIS_ListIteratorOfListOfInteractive it(ioList);

	 for(; it.More(); it.Next())
	 	theIC->Display(it.Value(), Standard_False);

	 theIC->UpdateCurrentViewer();

     Done();*/ //LeiLu 11/2014

     Start();

     Handle(AIS_InteractiveContext) theContext = myDoc->GetContext();
     theContext->ClearSelected(Standard_True);
     theContext->CloseAllContexts();
     theContext->OpenLocalContext();
     theContext->ActivateStandardMode(TopAbs_FACE);

//     AIS_ListOfInteractive aDisplayList;
//     Standard_Boolean aNeutralPointOnly = Standard_True;
//     theContext->DisplayedObjects(aDisplayList,aNeutralPointOnly);
//     AIS_ListIteratorOfListOfInteractive anIter(aDisplayList);

//     for(;anIter.More();anIter.Next())
//     {
//         Handle(AIS_Shape) aShape = Handle(AIS_Shape)::DownCast(anIter.Value());
//         if(!aShape.IsNull())
//         {
//            TopExp_Explorer anExp(aShape->Shape(),TopAbs_FACE);
//            for(;anExp.More();anExp.Next())
//            {
//               QMcCad_Application::GetAppMainWin()->Mcout("Test1111");
//               theContext->AddOrRemoveSelected(anExp.Current(),Standard_False);
//            }
//         }
//     }                

//     for (theContext->InitCurrent(); theContext->MoreCurrent(); theContext->NextCurrent() )
//     {
//         QMcCad_Application::GetAppMainWin()->Mcout("Solid");
//     }


//     AIS_ListOfInteractive objects;
//     theContext->DisplayedObjects(objects);
//     AIS_ListIteratorOfListOfInteractive iobjects(objects);
//     while(iobjects.More())
//     {
//         theContext->Deactivate(iobjects.Value(),0);
//         theContext->Activate(iobjects.Value(),4);

//         //theContext->SetHilightColor(Quantity_NOC_WHITE);
//         //theContext->SetTransparency(iobjects.Value(),0.3);
//         //theContext->Display(iobjects.Value(),1,-1,Standard_True,Standard_True);
//         Handle(StdSelect_FaceFilter) Fil1 = new StdSelect_FaceFilter(StdSelect_AnyFace);
//         //Handle(StdSelect_FaceFilter) Fil2 = new StdSelect_FaceFilter(StdSelect_Plane);

//         theContext->Redisplay(iobjects.Value());

//         theContext->AddFilter(Fil1);
//         //theContext->AddFilter(Fil2);

//         iobjects.Next();

//     }

//     for (theContext->InitCurrent(); theContext->MoreCurrent(); theContext->NextCurrent() )
//     {
//         QMcCad_Application::GetAppMainWin()->Mcout("Surface Selected");

//         Handle(AIS_InteractiveObject) curIO = theContext->Current();

//         theContext->SetShapeDecomposition(curIO,Standard_True);

//         Handle(AIS_Shape) aisShp = Handle(AIS_Shape)::DownCast(curIO);

//         TopoDS_Shape shape = aisShp->Shape();
//         if(shape.ShapeType() == TopAbs_FACE)
//         {
//             QMcCad_Application::GetAppMainWin()->Mcout("No3");
//         }
//     }

     theContext->UpdateCurrentViewer();
     Done();
}

 void McCadViewTool_RedisplaySelected::UnExecute()
{
}

 void McCadViewTool_RedisplaySelected::Suspend()
{
}

 void McCadViewTool_RedisplaySelected::Resume()
{
}

void McCadViewTool_RedisplaySelected::MousePressEvent(const QMouseEvent& e)
{
    Handle(AIS_InteractiveContext) theContext = myDoc->GetContext();
//    theContext->InitSelected();

//    TopoDS_Shape shape = theContext->DetectedShape();
//    if (shape.ShapeType() == TopAbs_SOLID)
//    {
//         QMcCad_Application::GetAppMainWin()->Mcout("S1");
//    }

//    for (theContext->InitCurrent(); theContext->MoreCurrent(); theContext->NextCurrent() )
//    {
//        QMcCad_Application::GetAppMainWin()->Mcout("S2");

//        Handle(AIS_InteractiveObject) curIO = theContext->Current();
//        Handle(AIS_Shape) aisShp = Handle(AIS_Shape)::DownCast(curIO);


//        TopoDS_Shape shape = aisShp->Shape();

//        if(shape.ShapeType() == TopAbs_SOLID)
//        {
//            QMcCad_Application::GetAppMainWin()->Mcout("No3");
//        }
//    }

//    AIS_ListOfInteractive ioList;

//    theContext->DisplayedObjects(ioList);
//    AIS_ListIteratorOfListOfInteractive it(ioList);

//    for(; it.More(); it.Next())
//    {
//        if(!theContext->IsSelected(it.Value()))
//        {
//             Handle(AIS_Shape) aShape = Handle(AIS_Shape)::DownCast(it.Value());
//             TopoDS_Shape theShp = aShape->Shape();

//             if(theShp.ShapeType() == TopAbs_SOLID)
//             {
//                 QMcCad_Application::GetAppMainWin()->Mcout("No3");
//             }
//        }
//    }

    QMcCad_Application::GetAppMainWin()->Mcout("Mouse Cliked");
}

 void McCadViewTool_RedisplaySelected::MouseReleaseEvent(const QMouseEvent& e)
{
     QMcCad_Application::GetAppMainWin()->Mcout("Mouse Release");
}


 void McCadViewTool_RedisplaySelected::MouseLeaveEvent()
{
}

 void McCadViewTool_RedisplaySelected::MouseEnterEvent()
{
}

