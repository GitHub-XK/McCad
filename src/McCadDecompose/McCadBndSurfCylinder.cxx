#include "McCadBndSurfCylinder.hxx"

#include <Geom_CylindricalSurface.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>
#include <gp_Cylinder.hxx>

#include <TopAbs_Orientation.hxx>
#include <TopLoc_Location.hxx>
#include <STEPControl_Writer.hxx>

McCadBndSurfCylinder::McCadBndSurfCylinder()
{
}

McCadBndSurfCylinder::McCadBndSurfCylinder(const McCadBndSurface &theFace):McCadBndSurface(theFace)
{
    //BRepAdaptor_Surface BS(theFace, Standard_True);
    //m_AdpSurface = BS.Surface();
cout<<"Construct"<<endl;
   // GenCylSurf();
}


void McCadBndSurfCylinder::GenCylSurf()
{
   // TopAbs_Orientation ori = theFace.Orientation();
  //  TopLoc_Location loc;

//    Standard_Real UMin,UMax, VMin, VMax;
//    BRepTools::UVBounds(*this,UMin,UMax, VMin, VMax);
//    BRepAdaptor_Surface BSF(*this,Standard_True);
//    gp_Trsf T = BSF.Trsf(); //the surfaces coordinate system

//    if ( fabs(UMax - UMin)<= gp::Resolution() || fabs(VMax - VMin)<= gp::Resolution())
//    {
//        return;
//    }

//    gp_Pnt P1 = (theFaceSurface->Value(UMin,VMin)).Transformed(T); //get extremal points in the surfaces coord sys.
//    gp_Pnt P2 = (theFaceSurface->Value(UMin,VMax)).Transformed(T);
//    gp_Pnt P3 = (theFaceSurface->Value(UMax,VMin)).Transformed(T);
//    gp_Pnt P4 = (theFaceSurface->Value(UMax,VMax)).Transformed(T);

//    gp_Pnt pnt_mid = (theFaceSurface->Value(UMin+(UMax-UMin)/2.0,VMin+(VMax-VMin)/2.0)).Transformed(T);

//    gp_Vec v1, v2, v3;

//    // handle closed faces
//    if( adaptedFaceSurface.GetType() == GeomAbs_Cylinder)// closed cylinder doesn't need resultant
//    {
//        if (Abs((UMax-UMin)-2*M_PI) < 1e-7)
//        {
//            return seqResultant;
//        }

//        v1 = gp_Vec::gp_Vec(P2,P1);
//        v2 = gp_Vec::gp_Vec(P3,P1);
//        v3 = v2 ^ v1;
//    }
//    else if(adaptedFaceSurface.GetType() == GeomAbs_Sphere) // u-closed && v-closed sphere
//    {
//        if(Abs(Abs(UMax - UMin)-2*M_PI) < 1.e-5)
//        {
//           return seqResultant;
//        }

//        P3 = (theFaceSurface->Value(UMin,VMin+((VMax - VMin)/2.0)) ).Transformed(T);
//        P4 = (theFaceSurface->Value(UMax,VMin+((VMax - VMin)/2.0)) ).Transformed(T);

//        v1 = gp_Vec::gp_Vec(P2,P1);
//        v2 = gp_Vec::gp_Vec(P3,P4);
//        v3 = v2 ^ v1;
//    }


//    v3.Normalize();
//    gp_Dir plane_dir(v3);

//    //gp_Pnt pnt(P1.X()+v3.X()*0.0001,P1.Y()+v3.Y()*0.0001,P1.Z()+v3.Z()*0.0001);
//    Handle(Geom_Plane) plane = new Geom_Plane(P1,plane_dir);
//    TopoDS_Face face = BRepBuilderAPI_MakeFace(plane->Pln());

//    Standard_Real orientVal = McCadGTOOL::Evaluate(plane->Pln(),pnt_mid);
//    TopAbs_Orientation ori_plane;

//    if(orientVal < 0.0 )
//    {
//        ori_plane = TopAbs_FORWARD;
//    }
//    else if (orientVal > 0.0 )
//    {
//        ori_plane = TopAbs_REVERSED;
//    }

//    face.Orientation(ori_plane); // this orientation will be used !!!
//    seqResultant->Append(face);
STEPControl_Writer wrt;

    if( m_AdpSurface.GetType() == GeomAbs_Cylinder)
    {
        gp_Cylinder gCyl = m_AdpSurface.Cylinder();

        Handle(Geom_CylindricalSurface) cylinder = new Geom_CylindricalSurface(gCyl);
        TopoDS_Face face = BRepBuilderAPI_MakeFace(gCyl);

        cout<<"Generate a Cylinder"<<endl;
        wrt.Transfer(face, STEPControl_AsIs);

    }
 wrt.Write("Test.stp");

}
