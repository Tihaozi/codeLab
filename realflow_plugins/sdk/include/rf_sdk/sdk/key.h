
#ifndef _NL_RFSDK_KEY_H
#define _NL_RFSDK_KEY_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// STANDARD INCLUDES
#include NL_BEGIN_DISABLE_WARNINGS
#include <string>
#include NL_END_DISABLE_WARNINGS

// LOCAL INCLUDES
#include "rf_sdk/rf_sdkdefs.h"
#include <rf_sdk/util/ptrwrprchkr.h>

// FORWARD DECLARATIONS
struct PointInfo;


// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{

  namespace rf_sdk
  {

    //-----------------------------------------------------------------------------------
    //
    // Key:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL_STATIC Key
    {
      typedef PointInfo NativeObjType ;

    public:

      static const int KEY_TYPE_LINEAR;
      static const int KEY_TYPE_BEZIER;
      static const int KEY_TYPE_TCB;
      static const int KEY_TYPE_STEP;
      
      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    protected:

      /// Constructor
      Key( NativeObjType* nativeObj ):nativeObj_( nativeObj ) {};

    public:
      /// Destructor
      ~Key( void ) {};


      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      /// INTERFACE

      /// newObj:  
      ///
      /// Create a new Key with KEY_TYPE_TCB type by default and 0.0 value set for all the member variables
      /// 
      /// @return : new Key
      static Key newObj();

      /// getTime:  
      ///
      /// Get the Key 's time in second
      ///
      /// @return : Key 's time
      double getTime( void );

      /// getValue:  
      ///
      /// Get the Key 's value
      ///
      /// @return : Key 's value
      double getValue( void );

      /// getType:  
      ///
      /// Get the Key 's type. Valid values are KEY_TYPE_LINEAR, 
      ///                                       KEY_TYPE_BEZIER and 
      ///                                       KEY_TYPE_TCB.
      ///
      /// @return : Key 's type
      int getType( void );

      /// getTcbEaseTo:  
      ///
      /// Gets the Key 's 'Ease To' value for Keys of type KEY_TYPE_TCB
      /// The 'Ease To' value parameter is also known as 'Ease In' in other softwares.
      ///
      /// @return : Key 's 'Ease To' value
      double getTcbEaseTo( void );

      /// getTcbEaseFrom:  
      ///
      /// Gets the Key 's 'Ease From' value for Keys of type KEY_TYPE_TCB
      /// The 'Ease From' value parameter is also known as 'Ease Out' in other softwares.
      ///
      /// @return : Key 's 'Ease From' value
      double getTcbEaseFrom( void );

      /// getTcbTension:  
      ///
      /// Gets the Key 's tension value for Keys of type KEY_TYPE_TCB
      ///
      /// @return : Key 's tension value
      double getTcbTension( void );

      /// getTcbContinuity:  
      ///
      /// Gets the Key 's continuity value for Keys of type KEY_TYPE_TCB
      ///
      /// @return : Key 's continuity value
      double getTcbContinuity( void );

      /// getTcbBias:  
      ///
      /// Gets the Key 's bias value for Keys of type KEY_TYPE_TCB
      ///
      /// @return : Key 's bias value
      double getTcbBias( void );

      /// getBezierIncoming:  
      ///
      /// Gets the Key 's incoming value for Keys of type KEY_TYPE_BEZIER
      ///
      /// @return : Key 's incoming value
      double getBezierIncoming( void );

      /// getBezierOutgoing:  
      ///
      /// Gets the Key 's outgoing value for Keys of type KEY_TYPE_BEZIER
      ///
      /// @return : Key 's outgoing value
      double getBezierOutgoing( void );

      /// setTime:
      ///
      /// Sets the Key 's time
      ///
      /// @param [in] time / time in seconds
      void setTime( double time );

      /// setValue:
      ///
      /// Sets the Key 's value
      ///
      /// @param [in] value / new Key 's value
      void setValue( double value );

      /// setType:  
      ///
      /// Sets the Key 's type. Valid values are KEY_TYPE_LINEAR, 
      ///                                        KEY_TYPE_BEZIER and 
      ///                                        KEY_TYPE_TCB.
      ///
      /// @param [in] type / new Key 's type
      void setType( int type );

      /// setTcbTension:  
      ///
      /// Sets the Key 's tension value for Keys of type KEY_TYPE_TCB
      ///
      /// @param [in] tension / new Key 's tension
      void setTcbTension( double tension );

      /// setTcbContinuity:  
      ///
      /// Sets the Key 's continuity value for Keys of type KEY_TYPE_TCB
      ///
      /// @param [in] continuity / new Key 's continuity
      void setTcbContinuity( double continuity );

      /// setTcbBias:  
      ///
      /// Sets the Key 's bias value for Keys of type KEY_TYPE_TCB
      ///
      /// @param [in] bias / new Key 's bias
      void setTcbBias( double bias );

      /// setBezierIncoming:  
      ///
      /// Sets the Key 's incoming value for Keys of type KEY_TYPE_BEZIER
      ///
      /// @param [in] incoming / new Key 's incoming
      void setBezierIncoming( double incoming );

      /// setBezierOutgoing:  
      ///
      /// Sets the Key 's outgoing value for Keys of type KEY_TYPE_BEZIER
      ///
      /// @param [in] outgoing / new Key 's outgoing
      void setBezierOutgoing( double outgoing );

      /// setTcbEaseTo:  
      ///
      /// Sets the Key 's 'Ease To' value for Keys of type KEY_TYPE_TCB
      /// The 'Ease To' value parameter is also known as 'Ease In' in other softwares.
      ///
      /// @param [in] easeTo / new Key 's 'Ease To' value
      void setTcbEaseTo( double easeTo );

      /// setTcbEaseFrom:  
      ///
      /// Sets the Key 's 'Ease From' value for Keys of type KEY_TYPE_TCB
      /// The 'Ease From' value parameter is also known as 'Ease Out' in other softwares.
      ///
      /// @param [in] easeFrom / new Key 's 'Ease From' value
      void setTcbEaseFrom( double easeFrom );

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Helper methods
      //  @{ 
    protected:

      PtrWrprChkr<NativeObjType>& getNativeObj()
      {
        return nativeObj_;
      }

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @private Methods:
      //  @{ 
    private:

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Data Members:
      //  @{ 
    private:

      PtrWrprChkr<NativeObjType> nativeObj_;

      friend class RFSdkBasicLib;
      friend class Curve;

    };

  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _NL_RFSDK_KEY_H...





