
#ifndef _NL_SDK_RF_SPLINE_H
#define _NL_SDK_RF_SPLINE_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// STANDARD INCLUDES
#include NL_BEGIN_DISABLE_WARNINGS
#include <vector>
#include NL_END_DISABLE_WARNINGS

// EXTERNAL INCLUDES

// LOCAL INCLUDES
#include "rf_sdk/rf_sdkdefs.h"
#include "rf_sdk/sdk/rfnodetype.h"
#include "rf_sdk/sdk/curve.h"
#include "rf_sdk/sdk/rfsdklibdefs.h"
#include "rf_sdk/sdk/rfnodetype.h"

//
// FORWARD DECLARATIONS
//

namespace nextlimit
{
  namespace realflow
  {
    class Spline;
  }
}

// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{

  namespace rf_sdk
  {

    // FORWARD REFERENCES
    class Scene;
    class NodeAccesor;

    //-----------------------------------------------------------------------------------
    //
    // Spline:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL Spline 
      : public RFNodeType< nl::rf::Spline, nl::rf_sdk::Node_ExpRsc >
    {
      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    private:

      /// Constructor
      Spline( nl::rf::Spline* nativeObjPtr ) 
        : RFNodeType< nl::rf::Spline, 
                      nl::rf_sdk::Node_ExpRsc >( nativeObjPtr ) {}

    public:
      /// Destructor
      virtual ~Spline( void ) {}


      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      /// INTERFACE

      /// sdkExport:  
      /// Write out all the resources that are active in the export central.
      void sdkExport( void );

      /// getType:  
      /// Gets the type of this Realflow Node Object
      /// @return the type of this RealFlow Object
      virtual const NL_UINT64 getType( void ) { return node_type::TYPE_SPLINE; }

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations (control points)
      //  @{ 
    public:
     
	    /// insertControlPoint:  
      /// 
      /// Inserts a new control point for the DSpline daemon.
      ///
      /// @param [in] position / The position of the control point.
      /// @param [in] handleInPosition / The position of the in handle of the control point.
      /// @param [in] handleOutPosition / The position of the out handle of the control point.
      ///
      /// @return : False if the type of the daemon is not the GSpline.
      ///
      bool insertControlPoint(  const Vector& position,
                                const Vector& handleInPosition,
                                const Vector& handleOutPosition );
      
	    /// removeControlPoint:  
      /// 
      /// Removes the current control point for the DSpline daemon. 
      ///
      /// @param [in] index / The index of the control point.
      ///
      /// @return : False if the index of the control point is not valid or if the type
      ///           of the daemon is not the GSpline.
      ///
      bool removeControlPoint( const unsigned int index );
      
	    /// removeAllControlPoints:  
      /// 
      /// Removes all the DSpline daemon control points. 
      ///
      /// @return : False if the type of the daemon is not the GSpline.
      ///
      bool removeAllControlPoints( void );

	    /// getNumberOfControlPoints:  
      /// 
      /// Returns the number of control points of the DSpline daemon. 
      ///
      /// @return :The number of control points. 0 if daemon is not of DSpline type.
      //
      int getNumberOfControlPoints( void );

      /// setControlPointPosition:  
      /// 
      /// Set the position of a control point.
      ///
      /// @param [in] index / The index of the control point.
      /// @param [in] position / The new position of the control point.
      ///
      /// @return : False if the index of the control point is not valid.
      ///
      bool setControlPointPosition( const unsigned int index, 
                                    const Vector& position );

      /// getControlPointPosition:  
      /// 
      /// Get the position of a control point.
      ///
      /// @param [in] index / The index of the control point.
      /// @param [out] position / The position of the control point.
      ///
      /// @return : False if the index of the control point is not valid.
      ///
      bool getControlPointPosition( const unsigned int index, 
                                          Vector& position );

	    /// setControlPointHandleInPosition:  
      /// 
      /// Set the position of the in handle of the control point.
      ///
      /// @param [in] index / The index of the control point.
      /// @param [in] position / The new position of the in handle.
      ///
      /// @return : False if the index of the control point is not valid or if the type
      ///           of the daemon is not the GSpline.
      ///
      bool setControlPointHandleInPosition( const unsigned int index, 
                                            const Vector& position );

	    /// getControlPointHandleInPosition:  
      /// 
      /// Get the position of the in handle of the control point.
      ///
      /// @param [in] index / The index of the control point.
      /// @param [out] position / The position of the in handle.
      ///
      /// @return : False if the index of the control point is not valid.
      ///
      bool getControlPointHandleInPosition( const unsigned int index, 
                                                  Vector& position );

	    /// setControlPointHandleOutPosition:  
      /// 
      /// Set the position of the out handle of the control point.
      ///
      /// @param [in] index / The index of the control point.
      /// @param [in] position / The new position of the out handle.
      ///
      /// @return : False if the index of the control point is not valid or if the type
      ///           of the daemon is not the GSpline.
      ///
      bool setControlPointHandleOutPosition(  const unsigned int index, 
                                              const Vector& position );

	    /// getControlPointHandleOutPosition:  
      /// 
      /// Get the position of the out handle of the control point.
      ///
      /// @param [in] index / The index of the control point.
      /// @param [out] position / The  position of the out handle.
      ///
      /// @return : False if the index of the control point is not valid.
      ///
      bool getControlPointHandleOutPosition(  const unsigned int index, 
                                                    Vector& position );

	    /// setControlPointParameter:  
      /// 
      /// Set value for the parameter of a control point. The parameter name is the one 
      /// that can be seen in the user interface. It is not case sensitive. The value 
      /// can be any type that is accepted for the parameters in the user interface. 
      /// Care must be taken when using this function about the type of the values and 
      /// the parameter names, a hard type and name check is done reporting the 
      /// corresponding errors to the user in any case
      ///
      /// @param [in] index / The index of the control point.
      /// @param [in] name / The control point parameter name.
      /// @param [in] value / The control point parameter value.
      ///
      /// @return : False if the parameter can't be changed, reasons could be:
      ///           - The index of the control point is not valid.
      ///           - The type of the daemon is not the GSpline.
      ///           - The parameter does not exist.
      ///           - The parameter type is not the right one.
      ///
      bool setControlPointParameter(  const unsigned int index, 
                                      const std::string& name, 
                                      const std::string& value );

	    /// setControlPointParameter:  
      /// 
      /// Set value for the parameter of a control point. The parameter name is the one 
      /// that can be seen in the user interface. It is not case sensitive. The value 
      /// can be any type that is accepted for the parameters in the user interface. 
      /// Care must be taken when using this function about the type of the values and 
      /// the parameter names, a hard type and name check is done reporting the 
      /// corresponding errors to the user in any case
      ///
      /// @param [in] index / The index of the control point.
      /// @param [in] name / The control point parameter name.
      /// @param [in] value / The control point parameter value.
      ///
      /// @return : False if the parameter can't be changed, reasons could be:
      ///           - The index of the control point is not valid.
      ///           - The type of the daemon is not the GSpline.
      ///           - The parameter does not exist.
      ///           - The parameter type is not the right one.
      ///
      bool setControlPointParameter(  const unsigned int index, 
                                      const std::string& name, 
                                      const int& value );

	    /// setControlPointParameter:  
      /// 
      /// Set value for the parameter of a control point. The parameter name is the one 
      /// that can be seen in the user interface. It is not case sensitive. The value 
      /// can be any type that is accepted for the parameters in the user interface. 
      /// Care must be taken when using this function about the type of the values and 
      /// the parameter names, a hard type and name check is done reporting the 
      /// corresponding errors to the user in any case
      ///
      /// @param [in] index / The index of the control point.
      /// @param [in] name / The control point parameter name.
      /// @param [in] value / The control point parameter value.
      ///
      /// @return : False if the parameter can't be changed, reasons could be:
      ///           - The index of the control point is not valid.
      ///           - The type of the daemon is not the GSpline.
      ///           - The parameter does not exist.
      ///           - The parameter type is not the right one.
      ///
      bool setControlPointParameter(  const unsigned int index, 
                                      const std::string& name, 
                                      const int64_t& value );

	    /// setControlPointParameter:  
      /// 
      /// Set value for the parameter of a control point. The parameter name is the one 
      /// that can be seen in the user interface. It is not case sensitive. The value 
      /// can be any type that is accepted for the parameters in the user interface. 
      /// Care must be taken when using this function about the type of the values and 
      /// the parameter names, a hard type and name check is done reporting the 
      /// corresponding errors to the user in any case
      ///
      /// @param [in] index / The index of the control point.
      /// @param [in] name / The control point parameter name.
      /// @param [in] value / The control point parameter value.
      ///
      /// @return : False if the parameter can't be changed, reasons could be:
      ///           - The index of the control point is not valid.
      ///           - The type of the daemon is not the GSpline.
      ///           - The parameter does not exist.
      ///           - The parameter type is not the right one.
      ///
      bool setControlPointParameter(  const unsigned int index, 
                                      const std::string& name, 
                                      const float& value );

	    /// setControlPointParameter:  
      /// 
      /// Set value for the parameter of a control point. The parameter name is the one 
      /// that can be seen in the user interface. It is not case sensitive. The value 
      /// can be any type that is accepted for the parameters in the user interface. 
      /// Care must be taken when using this function about the type of the values and 
      /// the parameter names, a hard type and name check is done reporting the 
      /// corresponding errors to the user in any case
      ///
      /// @param [in] index / The index of the control point.
      /// @param [in] name / The control point parameter name.
      /// @param [in] value / The control point parameter value.
      ///
      /// @return : False if the parameter can't be changed, reasons could be:
      ///           - The index of the control point is not valid.
      ///           - The type of the daemon is not the GSpline.
      ///           - The parameter does not exist.
      ///           - The parameter type is not the right one.
      ///
      bool setControlPointParameter(  const unsigned int index, 
                                      const std::string& name, 
                                      const double& value );

	    /// setControlPointParameter:  
      /// 
      /// Set value for the parameter of a control point. The parameter name is the one 
      /// that can be seen in the user interface. It is not case sensitive. The value 
      /// can be any type that is accepted for the parameters in the user interface. 
      /// Care must be taken when using this function about the type of the values and 
      /// the parameter names, a hard type and name check is done reporting the 
      /// corresponding errors to the user in any case
      ///
      /// @param [in] index / The index of the control point.
      /// @param [in] name / The control point parameter name.
      /// @param [in] value / The control point parameter value.
      ///
      /// @return : False if the parameter can't be changed, reasons could be:
      ///           - The index of the control point is not valid.
      ///           - The type of the daemon is not the GSpline.
      ///           - The parameter does not exist.
      ///           - The parameter type is not the right one.
      ///
      bool setControlPointParameter(  const unsigned int index, 
                                      const std::string& name, 
                                      const nl::rf_sdk::Vector& value );

	    /// setControlPointParameter:  
      /// 
      /// Set value for the parameter of a control point. The parameter name is the one 
      /// that can be seen in the user interface. It is not case sensitive. The value 
      /// can be any type that is accepted for the parameters in the user interface. 
      /// Care must be taken when using this function about the type of the values and 
      /// the parameter names, a hard type and name check is done reporting the 
      /// corresponding errors to the user in any case
      ///
      /// @param [in] index / The index of the control point.
      /// @param [in] name / The control point parameter name.
      /// @param [in] value / The control point parameter value.
      ///
      /// @return : False if the parameter can't be changed, reasons could be:
      ///           - The index of the control point is not valid.
      ///           - The type of the daemon is not the GSpline.
      ///           - The parameter does not exist.
      ///           - The parameter type is not the right one.
      ///
      bool setControlPointParameter(  const unsigned int index, 
                                      const std::string& name, 
                                      const nl::rf_sdk::Color& value );     
      
      /// getControlPointParameter:  
      ///
      /// Get the control point value for the parameter. Please read 
      /// "setControlPointParameter" description to know more about this function.
      ///
      /// @param [in] index / The index of the control point.
      /// @param [in] name / The control point parameter name.
      /// @param [out] ok / False if the parameter can't be changed, reasons could be:
      ///                     - The index of the control point is not valid.
      ///                     - The type of the daemon is not the GSpline.
      ///                     - The parameter does not exist.
      ///                     - The parameter type is not the right one.
      ///
      /// @return : The control point parameter's value. 
      ///
      template< class T >
      const T getControlPointParameter( const unsigned int index, 
                                        const std::string& name,
                                              bool& ok ) const;

      /// getControlPointParameterType:  
      ///
      /// Get the control point parameter's type. 
      ///
      /// @param [in] name  / Control point parameter's name. 
      /// @param [out] ok / False if the parameter can't be changed, reasons could be:
      ///                     - The type of the daemon is not the GSpline.
      ///                     - The parameter does not exist.
      ///
      /// @return : The parameter type, values in Param_Type [ TYPE_FLOAT  
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
      //
      sdk_type::SdkParamType getControlPointParameterType(  const std::string& name,
                                                                  bool& ok ) const;

      /// getControlPointParameterCurve:  
      ///
      /// @param [in] index / The index of the control point.
      /// @param [in] name / The control point parameter name.
      /// @param [out] ok / False if the parameter can't be changed, reasons could be:
      ///                     - The index of the control point is not valid.
      ///                     - The type of the daemon is not the GSpline.
      ///                     - The parameter does not exist.
      ///
      /// @return : The control point parameter's curve
      ///
      Curve getControlPointParameterCurve(  const unsigned int index,
                                            const std::string& name,
                                                  bool& ok ) const;

      /// getControlPointAllParameterNames:  
      ///
      /// Gets a list of Tuples < Parameter name, Parameter type >  
      ///     - Parameter names and types existing for the control point
      ///
      /// @param [out] parameterNames / Vector of Tuples < Parameter name, Parameter type > 
      ///
      /// @return : False if the type of the daemon is not the GSpline.
      /// 
      bool getControlPointAllParameterNames( std::vector< std::pair< std::string, int > >& parameterNames ) const;
      
      /// evaluateSpline:
      ///
      /// Returns the point of the spline given by the span and the parameter t.
      ///
      /// @param [in] span / The section of the spline to be evaluated. Must be less than
      ///                    the number of control points of the spline.
      /// @param [in] t / Parameter between 0 and 1 to determine where the spline is
      ///                 evaluated.
      /// @param [out] result / The position of the spline for the given parameters.
      ///
      /// @return : False if the span is out of range.
      ///
      bool evaluateSpline( const unsigned int span,
                          const float t,
                          Vector& result ) const;
      

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Helper methods
      //  @{ 
    protected:

      // getSdkType
      virtual sdk_type::SdkType getSdkType( void ) { return sdk_type::SPLINE_TYPE; }

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Data Members:
      //  @{ 
    private:

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @friend Classes :
      //  @{ 
    private:

      friend class Scene;
      friend class NodeAccesor;

    };

  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _NL_SDK_RF_SPLINE_H...





