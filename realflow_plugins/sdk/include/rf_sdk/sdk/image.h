
#ifndef _NL_SDK_IMAGE_H
#define _NL_SDK_IMAGE_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// EXTERNAL INCLUDES

// LOCAL INCLUDES
#include "rf_sdk/rf_sdkdefs.h"
#include "rf_sdk/sdk/rfnodetype.h"

//FORWARD DECLARATIONS
class SceneCamera;
namespace nextlimit
{
  class NL_Image;
};

// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{

  namespace rf_sdk
  {
    //-----------------------------------------------------------------------------------
    //
    // Image:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL_STATIC Image 
    {

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    public:

      /// Constructor:
      ///
      /// Create a new empty image 
      Image();

    public:
      /// Destructor
      ~Image( void ) {}


      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      /// open:  
      ///
      /// Open the file and load the image into THIS Image. The image format is taken from the file extension. 
      ///
      /// @param [in] imageFilePath / file path of image to load
      /// 
      /// @return : - True if the image was opened 
      ///           - False otherwise
      bool open( const std::string& imageFilePath ); 
      
      /// save:  
      ///
      /// Save THIS Image to a file. The image format is taken from the file extension. 
      ///
      /// @param [in] imageFilePath / file path of image to save
      /// 
      /// @return : - True if the image was saved 
      ///           - False otherwise
      bool save( const std::string& imageFilePath ); 
      /// close:  
      ///
      /// Close the image freeing memory resources
      void close( ); 

      /// getSize:  
      ///
      /// Gets the size of the image [Width, Height]
      ///
      /// @return : Vector of 2 ints = [Width, Height]
      std::vector< int > getSize(); 

      /// getPixel:  
      ///
      /// Get the RGB values for the pixel at specified location [ R, G, B ]
      /// 
      /// @param [in] px / Pixel 's X position starting from the left.
      /// @param [in] py / Pixel 's Y position starting from the bottom.
      ///
      /// @return : Vector of 3 unsigned ints = [ R, G, B ]
      std::vector< unsigned int > getPixel( int px, int py );

      /// getPixelAsFloat:
      ///
      /// Get the RGB values in float for the pixel at specified location [ R, G, B ]
      /// 
      /// @param [in] px / Pixel 's X position starting from the left.
      /// @param [in] py / Pixel 's Y position starting from the bottom.
      ///
      /// @return : Vector of 3 floats = [ R, G, B ]
      std::vector< float > getPixelAsFloat( int px, int py );


      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Helper methods
      //  @{ 
    public:

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Data Members:
      //  @{ 
    private:
      
      nl::NL_Image* nativeObj_;

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @ friend Classes:
      //  @{ 
    private:
      
      friend class HY_Mesh;
      friend class HY_Mesh_VDB;
      friend class Scene;
      
    };

  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _NL_SDK_IMAGE_H...





