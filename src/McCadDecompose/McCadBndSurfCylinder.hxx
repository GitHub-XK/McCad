#ifndef MCCADBNDFACECYLINDER_HXX
#define MCCADBNDFACECYLINDER_HXX

#include "McCadBndSurface.hxx"

class McCadBndSurfCylinder : public McCadBndSurface
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

    McCadBndSurfCylinder();
    McCadBndSurfCylinder(const McCadBndSurface & theFace);

public:
    void GenCylSurf();

private:

    TopoDS_Face m_cylSurf;




};

#endif // MCCADBNDFACECYLINDER_HXX
