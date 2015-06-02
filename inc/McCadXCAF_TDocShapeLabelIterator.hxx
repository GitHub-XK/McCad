/*
 * McCadXCAF_TDocShapeLabelIterator.hxx
 *
 *  Created on: Mar 5, 2009
 *      Author: grosse
 */

#ifndef MCCADXCAF_TDOCSHAPELABELITERATOR_HXX_
#define MCCADXCAF_TDOCSHAPELABELITERATOR_HXX_

#include <TDocStd_Document.hxx>
#include <XCAFDoc_ShapeTool.hxx>
#include <XCAFDoc_DocumentTool.hxx>
#include <TDF_LabelSequence.hxx>
#include <TDF_ChildIterator.hxx>
#include <TDF_Tool.hxx>


//! \brief Shape iterator for a TDocStd_Document

/** Purpose
 *
 * Iterates through the free TopLevel Shapes and their children (recursively) of the given document structure
 * and looks for shapes.
 */

class McCadXCAF_TDocShapeLabelIterator
{

public:

	//ctor
	McCadXCAF_TDocShapeLabelIterator() ;
	McCadXCAF_TDocShapeLabelIterator(const Handle_TDocStd_Document& theTDoc) ;

	void Initialize(const Handle_TDocStd_Document& theTDoc) ;
	Standard_Boolean More() ;
	void Next() ;
	TDF_Label Current() ;
	TDF_Label Value() ; // same as Current
	TDF_Label Previous() ;
    Standard_Integer NumberOfShapes();
    TDF_Label GetAt(int index);

private:
	//functions
    //Standard_Integer NumberOfShapes();
	TDF_Label Traverse(const TDF_Label& theLab, Standard_Integer& theInt, const Standard_Integer& stop = 0);

	//fields
	Handle_XCAFDoc_ShapeTool mySTool;
	TDF_LabelSequence myFreeShapes;
	Standard_Integer myCurrentCnt;
	Standard_Integer myEnd;
	TDF_Label myPrevious;
	TDF_Label myCurrent;
};

#endif /* MCCADXCAF_TDOCSHAPELABELITERATOR_HXX_ */
