#ifndef _NL_RF_BASIC_DEFS_H 
#define _NL_RF_BASIC_DEFS_H

//BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE 

// LOCAL INCLUDES
  //  BASIC PROJ
#include <rf_common/rf_commondefs.h>
  //  REST


//-----------------------------------------------------------------------------------
//
// Axis
//
//-----------------------------------------------------------------------------------
#define MATRIX_LW     1
#define MATRIX_MAX    2
#define MATRIX_SOFI   3

//-----------------------------------------------------------------------------------
//
// Platforms
//
//-----------------------------------------------------------------------------------
#define LIGHTWAVE     1
#define STUDIO_MAX    2
#define SOFTIMAGE     3
#define MAYAY         4
#define MAYAZ         5
#define CINEMA        6
#define HOUDINI       7
#define EIMAGE        8

//-----------------------------------------------------------------------------------
//
// Collision Fractions Computation Modes
//
//-----------------------------------------------------------------------------------
#define CFCM_FACE_AREA        0
#define CFCM_SUPERSAMPLING    1

//-----------------------------------------------------------------------------------
//
// Visualization Types
//
//-----------------------------------------------------------------------------------

#define BBOX_VIEW 1
#define WIREFRAME_VIEW 2
#define FLATSHADED_VIEW 3
#define SMOOTHSHADED_VIEW 4



///-----------------------------------------------------------------------------------
///
/// Slider interactivity types.
///
///-----------------------------------------------------------------------------------
namespace nextlimit { namespace realflow
{
  enum PptySliderUpdateMode
  {
    PPTY_SLIDER_UPDATE_ALL,
    PPTY_SLIDER_UPDATE_INTERACTIVE,
    PPTY_SLIDER_UPDATE_NONE
  };
}}

//-----------------------------------------------------------------------------------
//
// NameSpaces:
//
//-----------------------------------------------------------------------------------
namespace nextlimit
{

  namespace realflow
  {
  }

  namespace rf_core
  {
  }

  //-----------------------------------------------------------------------------------
  //
  // Realflow Namespace Alias:
  //
  //-----------------------------------------------------------------------------------
  namespace rf = realflow;

}

//#if defined ( _WINDOWS ) && defined ( _DEBUG )
//# define USE_LEGACY_QNPPTYTABLE
//#else
# define USE_NEW_QNPPTYTABLE
//# define USE_LEGACY_QNPPTYTABLE
//#endif


#if defined ( USE_NEW_QNPPTYTABLE ) && defined ( USE_LEGACY_QNPPTYTABLE )
# error Cannot define both USE_NEW_QNPPTYTABLE and USE_LEGACY_QNPPTYTABLE
#endif

#if defined( USE_LEGACY_QNPPTYTABLE )
class QNPptyTable;
class QNPptyTableItem;
namespace nextlimit { namespace realflow {
  typedef ::QNPptyTable QNPptyTableClass;
  typedef ::QNPptyTableItem QNPptyTableItemClass;
#define QNPptyTableItemPptyNs QNPptyTableItemClass
}}
#elif defined( USE_NEW_QNPPTYTABLE )
namespace nextlimit { namespace realflow {
  namespace qnpptytableitem_ns {}
  class QNPptyTable_v2;
  class QNPptyTableItem_v2;
  typedef QNPptyTable_v2 QNPptyTableClass;
  typedef QNPptyTableItem_v2 QNPptyTableItemClass;
  namespace QNPptyTableItemPptyNs = qnpptytableitem_ns;
}}
#else
# error No USE_LEGACY_QNPPTYTABLE or USE_NEW_QNPPTYTABLE defined
#endif



#endif // _NL_RF_BASIC_DEFS_H...

