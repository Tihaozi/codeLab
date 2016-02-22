/////////////////////////////////////////////////////////////////////////////////////////
//
//  NEXT LIMIT
//
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef NL_BASIC_CONFIG_H_
#define NL_BASIC_CONFIG_H_

#define _DEBUG_RESERVE_MEMORY_ALLOWED // undef when you want to study where is your program reserving memory


//-----------------------------------------------------------------------------------
//
// DEVELOPER_IS_CARONTE
//
//-----------------------------------------------------------------------------------
#if ( defined(DEVELOPER_IS_AGUS)||defined(DEVELOPER_IS_NURIA)||defined(DEVELOPER_IS_JAVIER)||defined(DEVELOPER_IS_EMILIO) )

#define DEVELOPER_IS_CARONTE

#endif


#ifdef DEVELOPER_IS_CARONTE
  #ifdef _DEBUG_WITH_ASSERTS
    #define _DEBUG_VECTOR3
    #define _DEBUG_QUATERNION
    #define _DEBUG_MATRIX2
    #define _DEBUG_MATRIX_SYM2
    #define _DEBUG_MATRIX3
    #define _DEBUG_MATRIX3x4
    #define _DEBUG_MATRIX_SYM3
    #define _DEBUG_MATRIX_SYM_NXM
    #define _DEBUG_CUT_CONVEX_CONTOUR_ON
  #endif
#endif

#if defined ( DEVELOPER_IS_AGUS )
#endif

#if defined ( DEVELOPER_IS_NURIA )
#endif

#if defined ( DEVELOPER_IS_JAVIER )
#endif

//-----------------------------------------------------------------------------------
//
// DEVELOPER_IS_HECTOR_CUEVAS
//
//-----------------------------------------------------------------------------------
#if DEVELOPER_IS_HECTOR_CUEVAS

  #if defined( _DEBUG )
   #define HEC_TEST_NEW_TEXTURE_RW_CALCULATION
   // #define _DEBUG_VECTOR3
  #endif

  #if _DEVELOPMENT_HEC
    #define _TO_BE_REMOVED_BECAUSE_MOVING_RF_TOOLS
    #define _WHILE_FEATURE_RFSDK_NOT_COMPLETED
  #endif

#endif

//-----------------------------------------------------------------------------------
//
// DEVELOPER_IS_ATT
//
//-----------------------------------------------------------------------------------
#if DEVELOPER_IS_ATT

# ifndef DEVELOPER_IS_ANGEL
# define DEVELOPER_IS_ANGEL
# endif

#endif

//-----------------------------------------------------------------------------------
//
// DEVELOPER_IS_ET
//
//-----------------------------------------------------------------------------------
#if DEVELOPER_IS_ET

# ifndef DEVELOPER_IS_ENRIQUE
# define DEVELOPER_IS_ENRIQUE
# endif

#endif

//-----------------------------------------------------------------------------------
//
// DEVELOPER_IS_REALFLOW
//
//-----------------------------------------------------------------------------------

#if (     defined( DEVELOPER_IS_ANGEL )   \
      ||  defined( DEVELOPER_IS_ENRIQUE ) \
      ||  defined( DEVELOPER_IS_ALEX )    \
      ||  defined( DEVELOPER_IS_HECTOR )  \
      ||  defined( DEVELOPER_IS_IVAN ) )
# define DEVELOPER_IS_REALFLOW
#endif

//-----------------------------------------------------------------------------------
//
// DEVELOPER_IS_XFLOW
//
//-----------------------------------------------------------------------------------
#if ( defined(DEVELOPER_IS_JAVIER)||defined(DEVELOPER_IS_RUBEN)||defined(DEVELOPER_IS_HECTOR_CUEVAS)||\
      defined(DEVELOPER_IS_MIGUELANGEL)||defined(DEVELOPER_IS_DAVID)||defined(DEVELOPER_IS_FRAN) )
#define DEVELOPER_IS_XFLOW
#endif

//-----------------------------------------------------------------------------------
//
// NL_ENABLE_ARRAY_COPY_CONSTRUCTOR, NL_ENABLE_ARRAY_ASSIGMENT_OPERATOR
// NL_ENABLE_ARRAY_BIT_COPY_CONSTRUCTOR, NL_ENABLE_ARRAY_CORE_COPY_CONSTRUCTOR
// NL_ENABLE_ARRAY_CORE_ASSIGMENT_OPERATOR, NL_ENABLE_ARRAY_OF_PTR_COPY_CONSTRUCTOR
// NL_ENABLE_ARRAY_OF_PTR_ASSIGMENT_OPERATOR
//
//-----------------------------------------------------------------------------------
#if defined ( DEVELOPER_IS_REALFLOW )
# define NL_ENABLE_ARRAY_COPY_CONSTRUCTOR
# define NL_ENABLE_ARRAY_ASSIGMENT_OPERATOR
# define NL_ENABLE_ARRAY_OF_PTR_COPY_CONSTRUCTOR
# define NL_ENABLE_ARRAY_OF_PTR_ASSIGMENT_OPERATOR
# define NL_ENABLE_ARRAY_BIT_COPY_CONSTRUCTOR
# define NL_ENABLE_ARRAY_CORE_COPY_CONSTRUCTOR
# define NL_ENABLE_ARRAY_CORE_ASSIGMENT_OPERATOR
#endif

#endif // NL_BASIC_CONFIG_H_
