
#ifndef _NL_SDK_CURVE_H
#define _NL_SDK_CURVE_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// STANDARD INCLUDES
#include NL_BEGIN_DISABLE_WARNINGS
#include <string>
#include <vector>
#include NL_END_DISABLE_WARNINGS

// LOCAL INCLUDES
  //  BASIC PROJ
#include "rf_sdk/rf_sdkdefs.h"
  //  REST"
#include <rf_sdk/util/ptrwrprchkr.h>
#include "rf_sdk/sdk/key.h"

// FORWARD DECLARATIONS
class ANIFloatBase;

// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{

  namespace rf_sdk
  {

    //-----------------------------------------------------------------------------------
    //
    // Curve:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL Curve
    {

      typedef ANIFloatBase NativeObjType ;
      
      // Curve behaviour
      static const int CURVE_BEHAVIOUR_ZERO;
      static const int CURVE_BEHAVIOUR_CONSTANT;
      static const int CURVE_BEHAVIOUR_LOOP;
      static const int CURVE_BEHAVIOUR_LOOPOFFSET;
      static const int CURVE_BEHAVIOUR_FOLLOWTANGENT;
      
      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    private:

      /// Constructor
      Curve( NativeObjType* nativeObj ):nativeObj_( nativeObj ) {};

    public:
      /// Destructor
      virtual ~Curve( void ) {};


      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      /// getExpression:
      /// Get the curve's expression string
      /// @return THIS Curve's expression string
      std::string getExpression();

      /// setExpression:
      /// Set THIS curve's expression string
      /// @param [in] exp / Curve's expression string
      void setExpression( std::string exp  );

      /// getKeys:
      /// Get THIS Curve's keys. Please note that the order of the returned keys is 
      /// the order used at creation and not the order of keys in the time line.
      /// @param [out] keys / Curve's keys
      void getKeys( std::vector< Key >& keys );

      /// addKey:
      /// Add a key to THIS Curve
      /// @param [in] key / Key to be added
      void addKey( Key& key );

      /// removeKey:
      /// Remove a key from THIS Curve. The key passed as parameter has to be the key 
      /// got from the list of keys returned by the addKey function. 
      /// This means that we can't create a new key and set that key as the parameter to 
      /// this function with the hope that the key at that time position is going to be removed
      /// @param [in] key / Key to be removed. Has to be part of the list of keys returned by the addKey function
      void removeKey( Key& key );

      /// getPreBehaviour:
      /// Get the curve's pre-Behaviour
      /// @return THIS Curve's pre-Behaviour
      int getPreBehaviour( void );

      /// setPreBehaviour:
      /// Set THIS Curve's pre-behaviour. Valid values are CURVE_BEHAVIOUR_ZERO and CURVE_BEHAVIOUR_CONSTANT. 
      /// @param [in] preBehaviour / Curve's pre-behaviour
      void setPreBehaviour( int preBehaviour );

      /// getPostBehaviour:
      /// Get the curve's post-Behaviour
      /// @return THIS Curve's post-Behaviour
      int getPostBehaviour( void );

      /// setPostBehaviour:
      /// Set the curve's post-behaviour. Valid values are CURVE_BEHAVIOUR_ZERO, 
      ///                                                  CURVE_BEHAVIOUR_CONSTANT, 
      ///                                                  CURVE_BEHAVIOUR_LOOP, 
      ///                                                  CURVE_BEHAVIOUR_LOOPOFFSET and 
      ///                                                  CURVE_BEHAVIOUR_FOLLOWTANGENT.
      /// @param [in] postBehaviour / Curve's post-behaviour   
      void setPostBehaviour( int postBehaviour );

      /// evaluate:
      /// Evaluate THIS curve at specific time. 
      /// @param [in] time / Time, in seconds
      /// @return Value of THIS Curve at the specific time
      double evaluate( double time );

      /// eulerFilter:
      /// Assuming THIS curve represents euler angles this function process THIS 
      /// entire Curve searching and fixing for angle discontinuities, 
      /// i.e. always taking the least angle difference between the last and the current key
      void eulerFilter( void );
       
      /// removeAllKeys:
      /// Remove all keys from THIS Curve  
      void removeAllKeys( void );
      
      /// isSplineAndExpression:
      /// Returns true if value for THIS Curveis the result of adding the expression
      /// and spline values.  
      /// @return : true if adds spline and expression for evaluation
      bool isSplineAndExpression( void );
      
      /// setSplineAndExpression:
      /// Set the value of the curve to be evaluated by adding expression and spline values.
      /// @param [in] enable / True for adding expression and spline value.
      /// False for using expression if exists. Otherwise spline is used.
      void setSplineAndExpression( const bool& enable );
      
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

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @ friend Classes:
      //  @{ 
    private:

      friend class RFSdkBasicLib;
      friend class SdkSplineControlPointUtil;
      friend class Daemon;
      friend class Spline;
      friend class Scene;
      friend class PB_Emitter;
    };

  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _NL_SDK_CURVE_H...





