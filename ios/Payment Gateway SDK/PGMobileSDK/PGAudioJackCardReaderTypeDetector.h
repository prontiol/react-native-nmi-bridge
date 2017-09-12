
#import <Foundation/Foundation.h>
#import "PGIpsReader.h"
#import "PGSwipeUnimag.h"
#import "PGAudioJackConnectionDetector.h"
#import "PGSwipeIpsEnterprise.h"

/**
 @brief Detects what is attached to the audio jack.
 */
@interface PGAudioJackCardReaderTypeDetector : NSObject<IpsDelegate, PGSwipeDelegate, PGAudioJackConnectionDetectorDelegate, IpsCommunicationTestDelegate, IpsEnterpriseCommunicationTestDelegate>

@property (nonatomic, readonly) bool detectedIpsReader;
@property (nonatomic, readonly) bool detectedUniMagReader;
@property (nonatomic, readonly) bool detectedIpsEnterpriseReader;
@property (nonatomic, retain) PGSwipeDevice *detectedSwipeDevice;

/**
 @brief Asynchronously attempts to detect the card reader type currently attached to the audio jack.
 @details A communication test is first attempted for an IPS reader then IpsEnterprise Audio reader.  If that fails, an attempt is made to power up a UniMag (Shuttle) card reader.  If either test succeeds, the audioJackReaderType is set to the correct value, and the device will be made ready for use.  The result of the autodetect is reported to the delegate through deviceAutodetectComplete:.
 @note All devices produce very loud tones through the audio jack during this step.  If speakers or headphones are attached, the tones would be unpleasant to the user.  It is recommended that the user be warned and allowed to remove headphones before calling this function.  This library suppresses notifications from the UniMag reader during autodetect.
 Because the device is powered up in order to test it, you will not receive connection / activation / ready for swipe events during detection.  When your delegate receives its deviceAutodetectComplete message, check the isConnected, isActive, and isReadyForSwipe properties for its current state and to complete any initialization.
 In order to detect the devices, all of the underlying card reader libraries must be loaded.  Under some circumstances, these libraries may not unload cleanly, resulting in unreliable use of the card reader.  Autodetect is also a very slow process.  For these reasons, you should not rely on autodetection for each use of the app.
 Because communication through the audio jack is not always perfect, autodetect does not always return a correct result.  The most common failure type is returning CardReaderAutodetectResultFail even though a supported device is connected.
 If it is known in advance which card reader type will be used, that type should be specified when initializing the PGSwipeController.  If multiple devices must be supported, it is strongly recommended that the result of the autodetect be saved (e.g. in NSUserDefaults) and re-used on app startup.
 */
-(void)beginAutodetectCardReader;

@end
