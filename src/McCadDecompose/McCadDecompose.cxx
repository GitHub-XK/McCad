#include "McCadDecompose.hxx"

#include <BRepTools.hxx>
#include <BRep_Tool.hxx>
#include <BRepBndLib.hxx>
#include <Bnd_Box.hxx>
#include <BRepMesh.hxx>
#include <BRepAdaptor_Surface.hxx>

#include <Handle_Geom_Surface.hxx>

#include <TopoDS.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Solid.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Wire.hxx>
#include <TopExp_Explorer.hxx>
#include <TopTools_HSequenceOfShape.hxx>
#include <TCollection_AsciiString.hxx>

#include <TColgp_Array1OfPnt.hxx>
#include <Poly_Triangulation.hxx>

#include <BRepBuilderAPI_MakePolygon.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>

#include "McCadBndSurfCylinder.hxx"

#include <STEPControl_Writer.hxx>
#include <assert.h>

#include "../McCadTool/McCadMathTool.hxx"

#include <gp_Ax3.hxx>
#include <gp_Cylinder.hxx>


McCadDecompose::McCadDecompose()
{
}


/** ***************************************************************************
* @brief  Load the models, if the model is compound solid, separate it firstly
* @param  Handle_TopTools_HSequenceOfShape & pSolidList
* @return void
*
* @date 13/05/2015
* @modify 13/05/2015
* @author  Lei Lu
******************************************************************************/
void McCadDecompose::InputData( Handle_TopTools_HSequenceOfShape & pSolidList )
{
    cout<<"Load the input models ";
    m_InputSolids = new TopTools_HSequenceOfShape;

    for (Standard_Integer i=1; i<= pSolidList->Length(); i++)
    {
        if ((pSolidList->Value(i)).ShapeType() == TopAbs_COMPSOLID || (pSolidList->Value(i)).ShapeType() == TopAbs_COMPOUND)
        {
            TopExp_Explorer ex;
            for (ex.Init(pSolidList->Value(i), TopAbs_SOLID); ex.More(); ex.Next())
            {
                TopoDS_Solid tmpSol = TopoDS::Solid(ex.Current());
                m_InputSolids->Append(tmpSol);
                cout<<".";
            }
        }
        else if ((pSolidList->Value(i)).ShapeType() == TopAbs_SOLID)
        {
            m_InputSolids->Append(pSolidList->Value(i));
            cout<<".";
        }
    }
    cout<<endl;
}



/** ***************************************************************************
* @brief  Generate the mesh of the whole solid
* @param
* @return Void
*
* @date 13/05/2015
* @modify 13/05/2015
* @author  Lei Lu
******************************************************************************/
void McCadDecompose::GenerateMesh()
{    
    STEPControl_Writer wrt;
    Standard_Integer iFaceNum = 0;  // Face number
    TopExp_Explorer exF;            // Trace the face of input solid

    for (exF.Init(m_InputSolids->Value(1),TopAbs_FACE); exF.More(); exF.Next())
    {
        iFaceNum++;       
        TopoDS_Face face = TopoDS::Face(exF.Current());
        BRepTools::Update(face);

        GenGeomData(face,iFaceNum);    // Generate the meshes of face

        //Add2SurfaceList(face,iFaceNum);
    }


    JudgeDecomposeSurface();                // Judge the faces are decomposition face or not

//    for (int i = 0; i < m_TriangleList.size(); i++)
//    {
//        McCadTriangle *pTri = m_TriangleList.at(i);
//        wrt.Transfer(*pTri, STEPControl_AsIs);
//    }

   // wrt.Write("MeshModel.stp");

}





/** ***************************************************************************
* @brief  Judge the faces in the solid are decomposition face or not
* @param
* @return void
*
* @date 13/05/2015
* @modify 13/05/2015
* @author  Lei Lu
******************************************************************************/
void McCadDecompose::JudgeDecomposeSurface()
{
    McCadBndSurface* pFirFace = NULL;
    McCadBndSurface* pSecFace = NULL;
    STEPControl_Writer wrt;

    for (int i = 0; i <  m_FaceList.size(); i++)
    {
        Standard_Integer iPosFace = 0;  // Number of the faces on the positive side
        Standard_Integer iNegFace = 0;  // Number of the faces on the negative side

        pFirFace = m_FaceList.at(i);
        assert(pFirFace);

        Standard_Boolean bIsDecomposeFace = Standard_False; // If it is decomposition face
        Standard_Integer iSplitSurfNum = 0; // How many other faces has collision with this face

        for (int j = 0; j < m_FaceList.size(); j++)
        {
            pSecFace = m_FaceList.at(j);

            if(i == j) //If the two compared surface are not same surface
            {
                continue;
            }

            POSITION ePosition = 0; // The relationship between faces

            if (pFirFace->FaceCollision(pSecFace,ePosition))
            {
                iSplitSurfNum ++;
                bIsDecomposeFace = Standard_True;
            }
            else
            {
                if (ePosition == POSITIVE)
                {
                    iPosFace++;
                }
                else if(ePosition == NEGATIVE)
                {
                    iNegFace++;
                }
            }
        }

        if (iPosFace > 0 && iNegFace > 0)
        {
            bIsDecomposeFace = Standard_True;
        }

        if (bIsDecomposeFace)
        {
            wrt.Transfer(*pFirFace, STEPControl_AsIs);
            pFirFace->SetSplitSurfNum(iSplitSurfNum);
            cout<<"SplitSurfNum  "<<iSplitSurfNum<<endl;
        }
    }

    wrt.Write("Test.stp");
}



void McCadDecompose::Add2SurfaceList(TopoDS_Face face, Standard_Integer iFaceNum)
{
    McCadBndSurface *pBndSurf = new McCadBndSurface(face);
    pBndSurf->SetSurfNum(iFaceNum);



  //  if (pBndSurf->GetSurfType() == gp_Cylinder)
    {
        McCadBndSurfCylinder * pBndSurfCyl = new McCadBndSurfCylinder(*pBndSurf);
    }

    m_FaceList.push_back(pBndSurf);
}


/** ***************************************************************************
* @brief  Generate the geometry data,including the face and mesh triangles of face
* @param  TopoDS_Face face           input face
*         Standard_Integer iFaceNum  sorted face number
* @return void
*
* @date 13/05/2015
* @modify 13/05/2015
* @author  Lei Lu
******************************************************************************/
void McCadDecompose::GenGeomData(TopoDS_Face &face, Standard_Integer iFaceNum)
{
    McCadBndSurface *pBndSurf = new McCadBndSurface(face);
    // Handle(Geom_Surface) theSurf = BRep_Tool::Surface(face,loc);

    //Standard_Real UMin,UMax,VMin, VMax;
    //BRepTools::UVBounds(face,UMin,UMax,VMin,VMax);

    Handle(Poly_Triangulation) mesh;
    BRepAdaptor_Surface BS(face,Standard_True);
    gp_Trsf T = BS.Trsf();

    /** Calculate the boundary box of face **/
    Bnd_Box theBB;
    BRepBndLib::Add(face,theBB);
    theBB.SetGap(0.0);
    Standard_Real Xmin, Ymin, Zmin, Xmax, Ymax, Zmax;
    theBB.Get(Xmin, Ymin, Zmin, Xmax, Ymax, Zmax);

    /** Generate the meshes of face **/
    TopLoc_Location loc;
    Standard_Real aDeflection // The tolerance setting of the mesh
             = McCadMathTool::MaxValue((Xmax-Xmin),(Ymax-Ymin),(Zmax-Zmin))/100.0;  // Set deflection value
    BRepMesh::Mesh(face, aDeflection);
    mesh = BRep_Tool::Triangulation(face,loc);

    if (!mesh.IsNull())
    {
        Standard_Integer nNodes = mesh->NbNodes();
        TColgp_Array1OfPnt meshPnts(1,nNodes);
        meshPnts = mesh->Nodes();

        Standard_Integer nbTriangles = mesh->NbTriangles();

        Standard_Integer n1, n2, n3;                                // For getting mesh points
        const Poly_Array1OfTriangle& Triangles = mesh->Triangles(); // Get the triangle

        for (int i = 1; i <= nbTriangles; i++)
        {
            Poly_Triangle tri = Triangles(i);
            tri.Get(n1, n2, n3);
            gp_Pnt P1 = (meshPnts(n1)).Transformed(T);
            gp_Pnt P2 = (meshPnts(n2)).Transformed(T);
            gp_Pnt P3 = (meshPnts(n3)).Transformed(T);

            /** Generate a new face using the points of triangle **/
            TopoDS_Wire wire = BRepBuilderAPI_MakePolygon(P1,P2,P3,Standard_True);
            TopoDS_Face face = BRepBuilderAPI_MakeFace(wire,Standard_True);

            McCadTriangle *pTri = new McCadTriangle(face);
            pTri->AddVertex(P1);
            pTri->AddVertex(P2);
            pTri->AddVertex(P3);

            pTri->SetSurfNum(iFaceNum);
            pBndSurf->SetSurfNum(iFaceNum);
            pBndSurf->AddTriangle(pTri);

            m_TriangleList.push_back(pTri);
        }
        m_FaceList.push_back(pBndSurf);
    }
    else
    {
        delete pBndSurf;
        pBndSurf = NULL;

        cout << "Face triangulation failed !!" << endl;
    }
}





