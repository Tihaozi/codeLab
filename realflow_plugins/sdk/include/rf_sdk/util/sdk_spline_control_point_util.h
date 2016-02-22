
#ifndef _RF_SDK_SPLINE_CONTROL_POINT_UTIL_H_
#define _RF_SDK_SPLINE_CONTROL_POINT_UTIL_H_

// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// LOCAL INCLUDES
#include "rf_sdk/rf_sdkdefs.h"
#include "rf_sdk/sdk/vector.h"
#include "rf_sdk/sdk/color.h"
#include "rf_sdk/sdk/colorgradient.h"
#include "rf_sdk/sdk/curve.h"
#include "rf_sdk/sdk/rfbaseobj.h"

//
// FORWARD DECLARATIONS
//

namespace nextlimit
{
  namespace realflow
  {
    class Particle;
  }
}

// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{
  namespace rf_sdk
  {
    //-----------------------------------------------------------------------------------
    //
    // SdkSplineControlPointUtil:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL SdkSplineControlPointUtil
    {

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    public:

      // Constructor
      SdkSplineControlPointUtil( Nodo* node );

      /// Destructor
      ~SdkSplineControlPointUtil( void );

    private:

      // Constructor
      SdkSplineControlPointUtil(){}

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

	    /// insertControlPoint:  
      bool insertControlPoint(  const Vector& position,
                                const Vector& handleInPosition,
                                const Vector& handleOutPosition );
      
	    /// removeControlPoint:  
      bool removeControlPoint( const unsigned int index );
      
	    /// removeControlPoints:  
      bool removeControlPoints( void );

	    /// removeAllControlPoints:  
      bool removeAllControlPoints( void );

	    /// getNumberOfControlPoints:  
      int getNumberOfControlPoints( void );
	    
      /// setControlPointPosition:  
      bool setControlPointPosition( const unsigned int index, 
                                    const Vector& position );

      /// getControlPointPosition:  
      bool getControlPointPosition( const unsigned int index, 
                                          Vector& position );

	    /// setControlPointHandleInPosition:  
      bool setControlPointHandleInPosition( const unsigned int index, 
                                            const Vector& position );

	    /// getControlPointHandleInPosition:  
      bool getControlPointHandleInPosition( const unsigned int index, 
                                                  Vector& position );

	    /// getControlPointHandleOutPosition:  
      bool getControlPointHandleOutPosition(  const unsigned int index, 
                                                  Vector& position );

	    /// setControlPointHandleOutPosition:  
      bool setControlPointHandleOutPosition(  const unsigned int index, 
                                              const Vector& position );

      /// setControlPointParameter
      bool setControlPointParameter(  const unsigned int index, 
                                      const std::string& name, 
                                      const std::string& value );

      /// setControlPointParameter
      bool setControlPointParameter(  const unsigned int index, 
                                      const std::string& name, 
                                      const int& value );

      /// setControlPointParameter
      bool setControlPointParameter(  const unsigned int index, 
                                      const std::string& name, 
                                      const int64_t& value );

      /// setControlPointParameter
      bool setControlPointParameter(  const unsigned int index, 
                                      const std::string& name, 
                                      const float& value );

      /// setControlPointParameter
      bool setControlPointParameter(  const unsigned int index, 
                                      const std::string& name, 
                                      const double& value );

      /// setControlPointParameter
      bool setControlPointParameter(  const unsigned int index, 
                                      const std::string& name, 
                                      const nl::rf_sdk::Vector& value );

      /// setControlPointParameter
      bool setControlPointParameter(  const unsigned int index, 
                                      const std::string& name, 
                                      const nl::rf_sdk::Color& value );     

      /// setControlPointParameter
      bool setControlPointParameter(  const unsigned int index,
                                    const std::string& name,
                                    const nl::rf_sdk::ColorGradient& value );
      
      /// getControlPointParameter
      bool getControlPointParameter(  const unsigned int index, 
                                      const std::string& name, 
                                            std::string& value );     

      /// getControlPointParameter
      bool getControlPointParameter(  const unsigned int index, 
                                      const std::string& name, 
                                            int& value );

      /// getControlPointParameter
      bool getControlPointParameter(  const unsigned int index, 
                                      const std::string& name, 
                                            int64_t& value );

      /// getControlPointParameter
      bool getControlPointParameter(  const unsigned int index, 
                                      const std::string& name, 
                                            float& value );

      /// getControlPointParameter
      bool getControlPointParameter(  const unsigned int index, 
                                      const std::string& name, 
                                            double& value );

      /// getControlPointParameter
      bool getControlPointParameter(  const unsigned int index, 
                                      const std::string& name, 
                                            nl::rf_sdk::Vector& value );

      /// getControlPointParameter
      bool getControlPointParameter(  const unsigned int index, 
                                      const std::string& name, 
                                            nl::rf_sdk::Color& value );     
      
      /// getControlPointParameter
      bool getControlPointParameter(  const unsigned int index,
                                      const std::string& name,
                                            nl::rf_sdk::ColorGradient& value );

      /// getControlPointParameterType
      bool getControlPointParameterType(  const std::string& name,
                                                nl::rf_sdk::sdk_type::SdkParamType& type ) const;

      /// getControlPointParameterCurve
      bool getControlPointParameterCurve( const unsigned int index,
                                          const std::string& name,
                                                Curve& curve ) const;
      
      /// getControlPointAllParameterNames
      void getControlPointAllParameterNames( std::vector< std::pair< std::string, int > >& parameterNames ) const;

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Data Members:
      //  @{ 
    private:

      Nodo* node_;
    };

  } // NameSpace rf_sdk...
} // NameSpace Nextlimit...
#endif // _RF_SDK_SPLINE_CONTROL_POINT_UTIL_H_...





