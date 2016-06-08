// This code implementation is the intellectual property of
// the RD44 GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4LogicalSurface.hh,v 2.0 1998/07/02 16:56:49 gunter Exp $
// GEANT4 tag $Name: geant4-00 $
//
////////////////////////////////////////////////////////////////////////
// G4LogicalSurface Definition
////////////////////////////////////////////////////////////////////////
//
// File:        G4LogicalSurface.hh
// Description: An abstraction of a geometrical surface, it is an abstract 
//                base class for different implementations of surfaces.
//                Its primary function is to hold pointers 
//                to objects that describe the surface's physical properties.
//                For example it holds a pointer to a surface's optical
//                properties, and because of this it is used in processes like
//                G4OpBoundaryProcess. 
//
// Version:     1.0
// Created:     1997, June, 4th to 17th
// Author:      John Apostolakis, (with help of Peter Gumplinger)
// mail:        japost@mail.cern.ch
// Modified:    1997, June 26th  John Apostolakis
//
// Id tag:      
////////////////////////////////////////////////////////////////////////

#ifndef G4LogicalSurface_h
#define G4LogicalSurface_h 1

/////////////
// Includes
/////////////

#include "globals.hh"
#include "templates.hh"

class G4OpticalSurface;
class G4TransitionRadiationSurface;

/////////////////////
// Class Definition
/////////////////////

class G4LogicalSurface
{
	////////////
	// Methods
        ////////////
public:
        G4OpticalSurface*  GetOpticalSurface() const
					       { return theOpticalSurface; } 

        void       SetOpticalSurface(G4OpticalSurface* ptrOpticalSurface) 
                                 { theOpticalSurface= ptrOpticalSurface; } 

	G4String GetName() const { return theName; }
	void     SetName(const G4String& name){theName = name;}

        G4TransitionRadiationSurface*  GetTransitionRadiationSurface() const
					       { return theTransRadSurface; } 
        void SetTransitionRadiationSurface( G4TransitionRadiationSurface* transRadSurf )
					 { theTransRadSurface= transRadSurf; } 

        ////////////////////////////////
        // Constructors and Destructor
        ////////////////////////////////

protected:
        // There should be no instances of this class


	G4LogicalSurface(const G4String&         name,
		               G4OpticalSurface* opticalSurface); 
        // Is the name more meaningful for the properties or the logical
        //  surface ?  

public:
	virtual ~G4LogicalSurface();

private:
        G4LogicalSurface(const G4LogicalSurface &right); // Copying restricted

        //////////////
        // Operators
        //////////////
public:
	G4int operator==(const G4LogicalSurface &right) const;
	G4int operator!=(const G4LogicalSurface &right) const;

private:
	const G4LogicalSurface& operator=(const G4LogicalSurface& right);

	// ------------------
	// Basic data members ( To define a 'logical' surface)
	// ------------------

private:
	G4String theName;		// Surface name

        G4OpticalSurface*              theOpticalSurface;
        G4TransitionRadiationSurface*  theTransRadSurface;
};

////////////////////
// Inline methods
////////////////////

#include "G4LogicalSurface.icc"

#endif /* G4LogicalSurface_h */