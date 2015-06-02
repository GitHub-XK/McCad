#ifndef MCCADDECOMPOSE_HXX
#define MCCADDECOMPOSE_HXX

#include <Handle_TopTools_HSequenceOfShape.hxx>

#include <vector>
#include <BRepAdaptor_Surface.hxx>
#include <Poly_Array1OfTriangle.hxx>
#include "McCadTriangle.hxx"
#include "McCadBndSurface.hxx"

using namespace std;

class McCadDecompose
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

    McCadDecompose();
    void InputData(Handle_TopTools_HSequenceOfShape & solid_list);
    void GenerateMesh();
    void Add2SurfaceList(TopoDS_Face face, Standard_Integer iFaceNum);
    void GenGeomData(TopoDS_Face &face, Standard_Integer iFaceNum);
    void JudgeDecomposeSurface();

private:

    Handle_TopTools_HSequenceOfShape m_InputSolids;
    vector<McCadBndSurface*> m_FaceList;
    vector<McCadTriangle*> m_TriangleList;

};

#endif // MCCADDECOMPOSE_HXX
