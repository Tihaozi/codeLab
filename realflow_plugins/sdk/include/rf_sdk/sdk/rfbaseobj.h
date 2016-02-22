
#ifndef _RF_BASE_OBJ_H
#define _RF_BASE_OBJ_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// EXTERNAL INCLUDES
#include <vector>
#if defined ( _WINDOWS )
# include <stdint.h>
#endif

// LOCAL INCLUDES
  //  BASIC PROJ
#include "rf_sdk/rf_sdkdefs.h"
  //  REST
#include <rf_sdk/util/ptrwrprchkr.h>
#include "rf_sdk/sdk/vector.h"
#include "rf_sdk/sdk/color.h"
//#include "rf_sdk/sdk/nodeaccesor.h"
#include "rf_sdk/sdk/rfsdklibdefs.h"

// FORWARD REFERENCES
namespace nextlimit
{
  class MutexRW;
}

// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{
  namespace rf_sdk
  {
    //class ArrSdkNodeAccesor;

    // FORWARD REFERENCES
    namespace rf_sdk
    {
      class Scene;
    }
    
    namespace sdk_type
    {
      enum SdkType
      {
        NONE_TYPE                     = 0,
        PB_EMITTER_TYPE               ,
        CAMERA_TYPE                   ,
        DEAMON_TYPE                   ,
        CONSTRAINT_TYPE               ,
        OBJECT_TYPE                   ,
        STANDARD_MESH_TYPE            ,
        REAL_WAVE_TYPE                ,
        PARTICLE_TYPE                 ,
        WAVE_TYPE                     ,
        GROUP_TYPE                    ,
        PARTICLE_SOLVER_TYPE          ,
        MIST_TYPE                     ,
        IDOC_TYPE                     ,
        GRID_MESH_TYPE                ,
        RENDERKIT_MESH_TYPE           ,
        GRID_DOMAIN_TYPE              ,
        GB_EMITTER_TYPE               ,
        MULTIBODY_TYPE                ,
        MULTIJOINT_TYPE               ,
        MULTISERVO_POS_LINEAR_TYPE    ,
        MULTISERVO_POS_ANGULAR_TYPE   ,
        MULTISERVO_VEL_LINEAR_TYPE    ,
        MULTISERVO_VEL_ANGULAR_TYPE   ,
        HY_FOAM_TYPE                  ,
        HY_SPLASH_AND_FOAM_TYPE       ,
        HY_SPLASH_TYPE                ,
        HY_WATERLINE_TYPE             ,
        HY_WET_AND_FOAM_TYPE          ,
        HY_WET_TYPE                   ,
        HY_BUBBLES_TYPE               ,
        HY_BUBBLES_AND_FOAM_TYPE      ,
        SPLINE_TYPE                   ,
        VDB_MESH_TYPE                 ,
        GRID_MESH_VDB_TYPE
      };

      enum SdkObjSubType
      {
        CUBE_SUBTYPE            = 0x0001 << 12,
        HEMISPHERE_SUBTYPE      = 0x0001 << 13,
        SPHERE_SUBTYPE          = 0x0001 << 14,
        CROSS_SUBTYPE           = 0x0001 << 15,
        PLANE_SUBTYPE           = 0x0001 << 16,
        ROCKET_SUBTYPE          = 0x0001 << 17,
        CYLINDER_SUBTYPE        = 0x0001 << 18,
        VASE_SUBTYPE            = 0x0001 << 19,
        CONE_SUBTYPE            = 0x0001 << 20,
        TORUS_SUBTYPE           = 0x0001 << 21,
        CAPSULE_SUBTYPE         = 0x0001 << 22,
        CUBE_TOP_OPEN_SUBTYPE   = 0x0001 << 23,
      };

      enum SdkParamType
      {
        PARAM_TYPE_NONE             =  -1,
        PARAM_TYPE_ALL		          =		0,
        PARAM_TYPE_INT		          =		1,
        PARAM_TYPE_FLOAT		        =	  2,
        PARAM_TYPE_BOOL			        =	  3,
        PARAM_TYPE_LONG		          =		4,
        PARAM_TYPE_STATIC		        =	  6,
        PARAM_TYPE_LIST			        =	  7,
        PARAM_TYPE_BUTTON		        =	  8,
        PARAM_TYPE_BROWSE		        =	  9,
        PARAM_TYPE_EDIT			        =	  10,
        PARAM_TYPE_TOGGLE_BUTTON	  =	  11,
        PARAM_TYPE_COLOR		        =	  12,
        PARAM_TYPE_DOUBLE		        =	  13,
        PARAM_TYPE_VECTOR           =   14,
        PARAM_TYPE_COLOR_GRADIENT   =   19,
        PARAM_TYPE_SPLINE           =   20,
      };
    }


    //-----------------------------------------------------------------------------------
    //
    // RFBaseObj:
    //
    //-----------------------------------------------------------------------------------
    template <class T>
    class RF_SDK_EXPORTS_DLL RFBaseObj
    {

    protected:
      typedef T NativeObjType ;

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    protected:

      /// Constructor
      RFBaseObj( T* nativeObj );

      /// Copy Constructors
      explicit RFBaseObj( const RFBaseObj& other );               

      ///
      NL_DISABLE_ASSIGMENT_OPERATOR( RFBaseObj );

    public:
      /// Destructor
      virtual ~RFBaseObj( void );

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      /// getParameter:  
      ///
      /// Gets the value of THIS Node 's Parameter given by its name( name ).
      /// As this is a templatized method you would need to indicate the type of the parameter.
      /// Example:
      /// int valueParameter = thisNode.getParameter<int>( "nameParameter" );
      ///
      /// @param [in] name / Node 's parameter name
      /// 
      /// @return : Node 's parameter value
      //
      template < class X > 
      X getParameter( const std::string& name );

      /// getParameterType:  
      ///
      /// Gets THIS Node 's Parameter type given by its name( paramName ).
      ///
      /// @param [in] paramName / Node 's parameter name
      /// 
      /// @return : Node 's parameter type, values in Param_Type [ TYPE_FLOAT  
      ///                                                          TYPE_DOUBLE 
      ///                                                          TYPE_LIST  
      ///                                                          TYPE_INT   
      ///                                                          TYPE_BOOL
      ///                                                          TYPE_EDIT
      ///                                                          TYPE_CBUTTON
      ///                                                          TYPE_BUTTON
      ///                                                          TYPE_BROWSE
      ///                                                          TYPE_VECTOR
      ///                                                          TYPE_COLOR ]
      ///                                             
      ///
      ///             - If the node has not a parameter with name ( paramName ) then it returns -1;
      //
      sdk_type::SdkParamType getParameterType( const std::string& paramName );

      /// setParameter:  
      ///
      /// Sets THIS Node 's Parameter value given by its name( name ). The parameter 
      /// name is the one that can be seen in the user interface. It is not case sensitive. 
      /// The value can be any type that is accepted for the parameters in the user interface. 
      /// Care must be taken when using this function about the type of the values and the parameter names, 
      /// a hard type and name check is done reporting the corresponding errors to the user in any case.
      ///
      /// @param [in] name / Node 's parameter name
      /// @param [in] value / Node 's parameter new value
      //
      void setParameter( const std::string& name, const std::string& value );

      /// setParameter:  
      ///
      /// Sets THIS Node 's Parameter value given by its name( name ). The parameter 
      /// name is the one that can be seen in the user interface. It is not case sensitive. 
      /// The value can be any type that is accepted for the parameters in the user interface. 
      /// Care must be taken when using this function about the type of the values and the parameter names, 
      /// a hard type and name check is done reporting the corresponding errors to the user in any case.
      ///
      /// @param [in] name / Node 's parameter name
      /// @param [in] value / Node 's parameter new value
      //
      void setParameter( const std::string& name, const int& value );
      
      /// setParameter:
      ///
      /// Sets THIS Node 's Parameter value given by its name( name ). The parameter
      /// name is the one that can be seen in the user interface. It is not case sensitive.
      /// The value can be any type that is accepted for the parameters in the user interface.
      /// Care must be taken when using this function about the type of the values and the parameter names,
      /// a hard type and name check is done reporting the corresponding errors to the user in any case.
      ///
      /// @param [in] name / Node 's parameter name
      /// @param [in] value / Node 's parameter new value
      //
      void setParameter( const std::string& name, const int64_t& value );

      /// setParameter:  
      ///
      /// Sets THIS Node 's Parameter value given by its name( name ). The parameter 
      /// name is the one that can be seen in the user interface. It is not case sensitive. 
      /// The value can be any type that is accepted for the parameters in the user interface. 
      /// Care must be taken when using this function about the type of the values and the parameter names, 
      /// a hard type and name check is done reporting the corresponding errors to the user in any case.
      ///
      /// @param [in] name / Node 's parameter name
      /// @param [in] value / Node 's parameter new value
      //
      void setParameter( const std::string& name, const float& value );

      /// setParameter:  
      ///
      /// Sets THIS Node 's Parameter value given by its name( name ). The parameter 
      /// name is the one that can be seen in the user interface. It is not case sensitive. 
      /// The value can be any type that is accepted for the parameters in the user interface. 
      /// Care must be taken when using this function about the type of the values and the parameter names, 
      /// a hard type and name check is done reporting the corresponding errors to the user in any case.
      ///
      /// @param [in] name / Node 's parameter name
      /// @param [in] value / Node 's parameter new value
      //
      void setParameter( const std::string& name, const double& value );

      /// setParameter:  
      ///
      /// Sets THIS Node 's Parameter value given by its name( name ). The parameter 
      /// name is the one that can be seen in the user interface. It is not case sensitive. 
      /// The value can be any type that is accepted for the parameters in the user interface. 
      /// Care must be taken when using this function about the type of the values and the parameter names, 
      /// a hard type and name check is done reporting the corresponding errors to the user in any case.
      ///
      /// @param [in] name / Node 's parameter name
      /// @param [in] value / Node 's parameter new value
      //
      void setParameter( const std::string& name, const Vector& value );

      /// setParameter:  
      ///
      /// Sets THIS Node 's Parameter value given by its name( name ). The parameter 
      /// name is the one that can be seen in the user interface. It is not case sensitive. 
      /// The value can be any type that is accepted for the parameters in the user interface. 
      /// Care must be taken when using this function about the type of the values and the parameter names, 
      /// a hard type and name check is done reporting the corresponding errors to the user in any case.
      ///
      /// @param [in] name / Node 's parameter name
      /// @param [in] value / Node 's parameter new value
      //
      void setParameter( const std::string& name, const Color& value );

      /// isNull:  
      ///
      /// Returns whether it is associated to a RF Component or not.
      /// 
      /// @return : True if it has a RF Component associated, false otherwise
      //
      bool isNull( void ) const 
      { 
        return ( getNativeObj().isNull() ); 
      };
      
      /// getAllParameterNames:  
      ///
      /// Gets a list of Tuples < Parameter name, Parameter type >  
      ///     - Parameter names and types existing for this node
      ///
      /// @param [out] parameterNames / Vector of Tuples < Parameter name, Parameter type > 
      ///
      void getAllParameterNames
      ( std::vector< std::pair< std::string, int > >& parameterNames ); 
      
      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Helper methods
      //  @{ 
    protected:

      // getParameterT
      int getParameterT( const std::string& name, int* ignore );

      // getParameterT
      int64_t getParameterT( const std::string& name, int64_t* ignore );

      // getParameterT
      bool getParameterT( const std::string& name, bool* ignore );

      // getParameterT
      float getParameterT( const std::string& name, float* ignore );

      // getParameterT
      double getParameterT( const std::string& name, double* ignore );

      // getParameterT
      std::string getParameterT( const std::string& name, std::string* ignore );

      // getParameterT
      Vector getParameterT( const std::string& name, Vector* ignore );

      // getParameterT
      Color getParameterT( const std::string& name, Color* ignore );
      
      // getParameterT
      ArrSdkNodeAccesors getParameterT ( const std::string&name, ArrSdkNodeAccesors* ignore );

      // getSdkType
      virtual sdk_type::SdkType getSdkType( void ) { NL_PURE_VIRTUAL; return sdk_type::NONE_TYPE; };

      //
      PtrWrprChkr<NativeObjType>& getNativeObj()
      {
        return nativeObj_;
      }

      //
      const PtrWrprChkr<NativeObjType>& getNativeObj() const 
      {
        return nativeObj_;
      }

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Data Members:
      //  @{ 
    protected:


      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Data Members:
      //  @{ 
    private:

      PtrWrprChkr<NativeObjType> nativeObj_;

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @friend Classes :
      //  @{ 
    private:

      friend class Scene;
      friend class Ppty;

    };

    //-----------------------------------------------------------------------------------
    //
    // RFNativeBaseObj:
    //
    //-----------------------------------------------------------------------------------
    template <class T>
    class RF_SDK_EXPORTS_DLL RFNativeBaseObj
    {

    protected:
      typedef T NativeObjType ;

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    protected:

      /// Constructor
      RFNativeBaseObj( T* nativeObj );

    public:
      /// Destructor
      virtual ~RFNativeBaseObj( void );

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      /// isNull:  
      ///
      /// Returns whether it is associated to a RF Component or not.
      /// 
      /// @return : True if it has a RF Component associated, false otherwise
      //
      bool isNull( void ) const 
      { 
        return ( getNativeObj().isNull() ); 
      };

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Helper methods
      //  @{ 
    protected:

      // getSdkType
      virtual sdk_type::SdkType getSdkType( void ) { NL_PURE_VIRTUAL; return sdk_type::NONE_TYPE; };

      //
      PtrWrprChkr<NativeObjType>& getNativeObj()
      {
        return nativeObj_;
      }

      //
      const PtrWrprChkr<NativeObjType>& getNativeObj() const 
      {
        return nativeObj_;
      }

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Data Members:
      //  @{ 
    protected:

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Data Members:
      //  @{ 
    private:

      PtrWrprChkr<NativeObjType> nativeObj_;

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @friend Classes :
      //  @{ 
    private:

      friend class Scene;

    };

  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _RF_BASE_OBJ_H...





