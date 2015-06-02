#ifndef MCCADTRIANGLE_HXX
#define MCCADTRIANGLE_HXX

#include <TopoDS_Face.hxx>
#include <gp_Pnt.hxx>

#include <vector>
#include <Handle_TColgp_HSequenceOfPnt.hxx>

using namespace std;

class McCadTriangle : public TopoDS_Face
{
public:

    void* operator new(size_t,void* anAddress)
    {
      return anAddress;
    }
    void* operator new(size_t size)
    {
      return Standard::Allocate(size);
    }
    void  operator delete(void *anAddress)
    {
      if (anAddress) Standard::Free((Standard_Address&)anAddress);
    }

public:

    McCadTriangle();
    McCadTriangle(const TopoDS_Face &theFace);
    ~McCadTriangle();

    void AddVertex(gp_Pnt pnt);
    void SetSurfNum(Standard_Integer iSurfNum);
    Handle_TColgp_HSequenceOfPnt GetVexList(){return m_PntList;};

private:
    //vector<gp_Pnt> m_PntList;
    Handle_TColgp_HSequenceOfPnt m_PntList;             /**< vertex of triangle */
    Standard_Integer m_iNumOfPnt;
    Standard_Integer m_iFatherFaceNum;
};

#endif // MCCADTRIANGLE_HXX
