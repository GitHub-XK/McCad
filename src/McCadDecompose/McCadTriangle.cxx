#include "McCadTriangle.hxx"
#include <TColgp_HSequenceOfPnt.hxx>

McCadTriangle::McCadTriangle()
{
}

McCadTriangle::McCadTriangle(const TopoDS_Face &theFace):TopoDS_Face(theFace)
{
    m_iNumOfPnt = 0;
    m_iFatherFaceNum = 0;

    m_PntList = new TColgp_HSequenceOfPnt();
}

void McCadTriangle::AddVertex(gp_Pnt pnt)
{    
    m_PntList->Append(pnt);
    m_iNumOfPnt++;
}

void McCadTriangle::SetSurfNum(Standard_Integer iSurfNum)
{
    m_iFatherFaceNum = iSurfNum;
}
