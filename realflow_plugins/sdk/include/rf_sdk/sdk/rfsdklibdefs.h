
#ifndef _RF_SDK_LIB_DEFS_H
#define _RF_SDK_LIB_DEFS_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// STANDARD INCLUDES
#include NL_BEGIN_DISABLE_WARNINGS
#include <vector>
#include NL_END_DISABLE_WARNINGS

// LOCAL INCLUDES

//-----------------------------------------------------------------------------------
//
// RF_SDK_TASK_EXPORT_DLL: Used for the creation functions
//
//-----------------------------------------------------------------------------------
# define RF_SDK_LIB_EXPORT_DLL  extern "C" DllExport


// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{

  namespace rf_sdk
  {

    // FORWARD DECLARATIONS
    class Vertex;
    class Object;
    class Vector;
    class Face;
    class PB_Particle;
    class Group;
    class NodeAccesor;
    class Emitter;

    enum Ref_Type
    {
      REF_GLOBAL,
      REF_LOCAL
    };

    // TYPEDEFS
    DECLARE_STD_VECTOR_TYPES( Face, SdkFaces );

    DECLARE_STD_VECTOR_TYPES( Vertex, SdkVertex );

    DECLARE_STD_VECTOR_TYPES( Object, SdkObjects );

    //DECLARE_STD_VECTOR_TYPES( Emitter, SdkEmitters );

    DECLARE_STD_VECTOR_TYPES( PB_Particle, SdkPB_Particles );

    DECLARE_STD_VECTOR_TYPES( Vector, SdkVectors );

    DECLARE_STD_VECTOR_TYPES( Group, SdkGroups );

    DECLARE_STD_VECTOR_TYPES( NodeAccesor, SdkNodeAccesors );



    typedef std::pair< ArrSdkVertex, ArrSdkFaces > Geometry;

    enum Channel
    {
      CHANNEL_RED,
      CHANNEL_GREEN,
      CHANNEL_BLUE,
      NUM_CHANNELS
    };


  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _RF_SDK_LIB_DEFS_H





