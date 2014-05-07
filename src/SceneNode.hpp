#ifndef SCENENODE_HPP
#define SCENENODE_HPP

//
// ABSTRACT BASE CLASS
//   SceneNode
//

#include "types.h"
#include "String.hpp"
#include "geom.hpp"

namespace rgl {

/*
enum TypeID { 
  SHAPE=1, 
  LIGHT, 
  BBOXDECO, 
  USERVIEWPOINT, 
  BACKGROUND,
  SUBSCENE,
  MODELVIEWPOINT
};
*/

#define SHAPE 1
#define LIGHT 2
#define BBOXDECO 3
#define USERVIEWPOINT 4
#define BACKGROUND 6  // 5 was used for the material
#define SUBSCENE 7
#define MODELVIEWPOINT 8
#define MAX_TYPE 8

typedef unsigned int TypeID;
typedef int ObjID;

/* Possible attributes to request */

#define VERTICES 1
#define NORMALS 2
#define COLORS 3
#define TEXCOORDS 4
#define SURFACEDIM 5
#define TEXTS 6
#define CEX 7
#define ADJ 8
#define RADII 9
#define CENTERS 10
#define IDS 11
#define USERMATRIX 12
#define TYPES 13
#define FLAGS 14
#define OFFSETS 15

typedef unsigned int AttribID;

class SceneNode
{
public:
  inline const TypeID getTypeID() const { return typeID; }
  inline const ObjID getObjID() const { return objID; }
  virtual ~SceneNode() { };
  static ObjID nextID;

  /* Some nodes depend on the bbox, so we pass it to all */
  virtual int getAttributeCount(AABox& bbox, AttribID attrib) { return 0; }
  virtual void getAttribute(AABox& bbox, AttribID attrib, int first, int count, double* result) { return; }
  virtual String  getTextAttribute(AABox& bbox, AttribID attrib, int index) { return String(0, NULL); }
protected:
  SceneNode(const TypeID in_typeID) : typeID(in_typeID)
  {  objID = nextID++; };
private:
  const TypeID typeID;
  ObjID objID;
};

/**
 * used in find_if searches, so can't be a method
 */
 
bool sameID(SceneNode* node, int id);

} // namespace rgl

#endif // SCENENODE_HPP
 
