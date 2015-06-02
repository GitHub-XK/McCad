#include "McCadBndSurface.hxx"

#include <BRepAdaptor_Surface.hxx>
#include <gp_Pnt.hxx>
#include <McCadGTOOL.hxx>
#include <Handle_TColgp_HSequenceOfPnt.hxx>
#include <TColgp_HSequenceOfPnt.hxx>

#include <TopExp_Explorer.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS.hxx>
#include <BRepTools.hxx>


#include <Geom_CylindricalSurface.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>
#include <gp_Cylinder.hxx>
#include <gp_Pln.hxx>
#include <BRep_Tool.hxx>

#include <STEPControl_Writer.hxx>
#include <math.h>
#include <Bnd_Box2d.hxx>

McCadBndSurface::McCadBndSurface()
{
}

McCadBndSurface::McCadBndSurface(const TopoDS_Face &theFace):TopoDS_Face(theFace)
{
    BRepAdaptor_Surface BS(theFace, Standard_True);
    m_AdpSurface = BS.Surface();    

//    TopExp_Explorer exW;            // Trace the face of input solid

//    int i = 0;
//    for (exW.Init(theFace,TopAbs_WIRE); exW.More(); exW.Next())
//    {
//        i++;
//        TopoDS_Wire wire = TopoDS::Wire(exW.Current());
//        BRepTools::Update(wire);
//    }
//    cout<<"      "<<i<<endl;

    STEPControl_Writer wrt;

  if( m_AdpSurface.GetType() == GeomAbs_Cylinder)
  {
        TopLoc_Location loc;
        Handle(Geom_Surface) surface = BRep_Tool::Surface(theFace,loc);

        TopAbs_Orientation ori = theFace.Orientation();

        Standard_Real UMin,UMax, VMin, VMax;
        BRepTools::UVBounds(*this,UMin,UMax, VMin, VMax);

        cout<<UMax<<" "<<UMin<<" "<<VMax<<" "<<VMin<<endl;

       // UMin = 0.0;
       // UMax = 2*M_PI;
       // VMin = 0.0;
       // VMax = 58.0;


        gp_Cylinder gCyl = m_AdpSurface.Cylinder();

        Handle(Geom_CylindricalSurface) cylinder = new Geom_CylindricalSurface(gCyl);
        TopoDS_Face face = BRepBuilderAPI_MakeFace(gCyl);

        Bnd_Box2d BB2;



        BB2.Get(UMin,UMax, VMin, VMax);

        cout<<UMax<<" "<<UMin<<" "<<VMax<<" "<<VMin<<endl;

        BRepTools::AddUVBounds(face,BB2);

        BRepTools::UVBounds(face,UMin,UMax, VMin, VMax);


        cout<<UMax<<" "<<UMin<<" "<<VMax<<" "<<VMin<<endl;



       // TopoDS_Face face = BRepBuilderAPI_MakeFace(surface,UMin,UMax, VMin, VMax,1.e-7);

        wrt.Transfer(face,STEPControl_AsIs);
        wrt.Write("Test4.stp");
}
}








McCadBndSurface::~McCadBndSurface()
{

}


/** ***************************************************************************
* @brief  Calculate the position relationship between face and triangle
* @param  McCadTriangle *& triangle Input triangle
*         POSITION & ePosition      which side of the face the triangle locate
* @return Standard_Boolean          Triangle and face is collied or not
*
* @date 13/05/2015
* @modify 21/05/2015
* @author  Lei Lu
******************************************************************************/
Standard_Boolean McCadBndSurface::TriangleCollision(McCadTriangle *& triangle,
                                                        POSITION & ePosition)
{
    Standard_Boolean bCollision = Standard_False; // The triangle is collied with face or not

    Standard_Integer iPosPnt = 0;   // The number of vertex of triangle locating at positive side of face
    Standard_Integer iNegPnt = 0;   // The number of vertex of triangle locating at negative side of face

    Handle_TColgp_HSequenceOfPnt pnt_list = triangle->GetVexList();
    for (Standard_Integer i = 1; i <= pnt_list->Length(); i++)
    {
        /* Distinguish which side does the point located.*/
        Standard_Real aVal = McCadGTOOL::Evaluate(m_AdpSurface, pnt_list->Value(i));

        if (aVal > 1.0e-5)              // Point located on the positive side of face
        {
            iPosPnt ++;
        }
        else if (aVal < -1.0e-5)        // Point located on the negative side of face
        {
            iNegPnt ++;
        }

        if (iPosPnt > 0 && iNegPnt > 0) // The points are on both sides of face
        {
            bCollision = Standard_True;
            break;
        }
        else
        {
            continue;
        }
    }

    if (iPosPnt > 0 && iNegPnt == 0)        // The triangle on positive side of face
    {
        ePosition = POSITIVE;
    }
    else if (iNegPnt > 0 && iPosPnt == 0)   // The triangle on negative side of face
    {
        ePosition = NEGATIVE;
    }

    return bCollision;
}



/** ***************************************************************************
* @brief  Calculate the position relationship between faces
* @param  McCadBndSurface *& pBndFace  Compared face
*         POSITION & ePosition         Which side of the face the triangle locate
* @return Standard_Boolean             The faces are collied or not
*
* @date 13/05/2015
* @modify 21/05/2015
* @author  Lei Lu
******************************************************************************/
Standard_Boolean McCadBndSurface::FaceCollision(McCadBndSurface *& pBndFace,
                                                POSITION & ePosition)
{
    Standard_Integer iPosTriNum = 0;   // The number of triangles locating at the positive side of face
    Standard_Integer iNegTriNum = 0;   // The number of triangles locating at the negative side of face

    Standard_Boolean bCollision = Standard_False; // If there are collision between two faces.

    for (int i = 0; i < pBndFace->GetTriangleList().size(); i++)
    {
        POSITION eTriPosition = 0; // The positional relationship between triangle and face

        McCadTriangle *pTriangle = pBndFace->GetTriangleList().at(i);
        if (this->TriangleCollision(pTriangle,eTriPosition)) // The triangle is collied with face
        {
            bCollision = Standard_True;
            break;
        }
        else
        {
            if (eTriPosition == POSITIVE)       // The triangle is on the positive side of face
            {
                iPosTriNum++;
            }
            else if(eTriPosition == NEGATIVE)   // The triangle is on the negative side of face
            {
                iNegTriNum++;
            }
        }

        if (iPosTriNum > 0 && iNegTriNum > 0) // If the triangles locate at the both sides of face
        {
            bCollision = Standard_True;
            break;
        }
    }

    if (iPosTriNum > 0 && iNegTriNum == 0)
    {
        ePosition = POSITIVE; // Compared face locate completly at the positive side of this face
    }
    else if (iPosTriNum == 0 && iNegTriNum >0)
    {
        ePosition = NEGATIVE;// Compared face locate completly at the negative side of this face
    }

    return bCollision;
}



/** ***************************************************************************
* @brief
* @param  *
* @return
*
* @date 13/05/2015
* @modify 13/05/2015
* @author  Lei Lu
******************************************************************************/
void McCadBndSurface::AddTriangle(McCadTriangle *& pTriangle)
{
    m_TriangleList.push_back(pTriangle);
}



/** ***************************************************************************
* @brief
* @param  *
* @return
*
* @date 13/05/2015
* @modify 13/05/2015
* @author  Lei Lu
******************************************************************************/
vector<McCadTriangle *> McCadBndSurface::GetTriangleList()
{
    return m_TriangleList;
}



/** ***************************************************************************
* @brief
* @param  *
* @return
*
* @date 13/05/2015
* @modify 13/05/2015
* @author  Lei Lu
******************************************************************************/
void McCadBndSurface::SetSurfNum(Standard_Integer iSurfNum)
{
    m_iSurfNum = iSurfNum;





}



/** ***************************************************************************
* @brief
* @param  *
* @return
*
* @date 13/05/2015
* @modify 13/05/2015
* @author  Lei Lu
******************************************************************************/
Standard_Integer McCadBndSurface::GetSurfNum()
{
    return m_iSurfNum;
}



/** ***************************************************************************
* @brief
* @param  *
* @return
*
* @date 13/05/2015
* @modify 13/05/2015
* @author  Lei Lu
******************************************************************************/
void McCadBndSurface::SetSplitSurfNum(Standard_Integer iSplitSurfNum)
{
    m_iSplitSurfNum = iSplitSurfNum;
}



/** ***************************************************************************
* @brief  Calculate the position relationship between face and triangle
* @param  McCadTriangle *& triangle Input triangle
*         POSITION & ePosition      which side of the face the triangle locate
* @return Standard_Boolean          Triangle and face is collied or not
*
* @date 13/05/2015
* @modify 21/05/2015
* @author  Lei Lu
******************************************************************************/
Standard_Integer McCadBndSurface::GetSplitSurfNum()
{
    return m_iSplitSurfNum;
}
