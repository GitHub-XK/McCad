#ifndef MCCADBNDSURFACE_HXX
#define MCCADBNDSURFACE_HXX

#include <TopoDS_Face.hxx>
#include <GeomAdaptor_Surface.hxx>

#include <Standard.hxx>
#include "McCadTriangle.hxx"
#include <vector>

/** The positional relationship between triangle and face or two faces
    1 is positive, -1 is negative, 0 is on the face*/
enum POSITION{POSITIVE = 1, NEGATIVE = -1, MIDDLE = 0};

class McCadBndSurface : public TopoDS_Face
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

    McCadBndSurface();
    McCadBndSurface(const TopoDS_Face &theFace);
    ~McCadBndSurface();

    void SetSurfNum(Standard_Integer iSurfNum);
    Standard_Integer GetSurfNum();
    Standard_Boolean TriangleCollision(McCadTriangle *& pTri, POSITION & ePosition);
    Standard_Boolean FaceCollision(McCadBndSurface *& pBndFace, POSITION & ePosition);

    void AddTriangle(McCadTriangle *& pTriangle);
    vector<McCadTriangle *> GetTriangleList();

    void SetSplitSurfNum(Standard_Integer iSurfNum);
    Standard_Integer GetSplitSurfNum();

protected:

    Standard_Integer m_iSurfNum;
    GeomAdaptor_Surface m_AdpSurface;

    vector<McCadTriangle*> m_TriangleList;

    Standard_Integer m_iSplitSurfNum; // How many surfaces this surface will split.

};

#endif // MCCADBNDSURFACE_HXX
