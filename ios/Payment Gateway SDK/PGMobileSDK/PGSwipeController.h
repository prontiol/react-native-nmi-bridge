
#import <Foundation/Foundation.h>
#import "PGSwipeDelegate.h"
#import "PGSwipeIDynamo.h"
#import "PGSwipeUnimag.h"
#import "PGSwipeIps.h"
#import "PGSwipeIpsEnterprise.h"
#import "PGAudioJackConnectionDetector.h"
#import "AudioJackReaderType.h"

/**
 @brief The class to instantiate to enable swipe reader functionality.
 */
@interface PGSwipeController : NSObject<PGAudioJackConnectionDetectorDelegate>

/**
 @brief Gets or sets the delegate that will receive swipe reader events.
 @note You should avoid setting the delegate this way.  Events can be sent during initialization, so you should use the initWithDelegate: function instead to ensure receipt of all events.
 
 @note This passes through to the individual reader control classes, so setting this delegate allows receipt of events from any of the swipe reader types.
 */
@property (nonatomic, assign, setter = setDelegate:) id<PGSwipeDelegate> delegate;

/**
 @brief Gets or sets the audio jack reader type that the library should expect.
 @details The default is AudioJackReaderTypeUnimag, which allows Shuttle readers to connect if this is not set otherwise.  This setting only applies to audio readers.  The iDynamo is automatically supported no matter what this is set to.
 @note This can be set to autodetect the reader type, but that function should be used only when necessary.  See -(void)beginAutodetectAudioJackCardReader for more information.
 */
@property (nonatomic, assign, setter = setAudioJackReaderType:) AudioJackReaderType audioJackReaderType;

#ifndef IDYNAMO_DISABLED
/**
 @brief The controller class for iDynamo readers.
 */
@property (nonatomic, retain, readonly) PGSwipeIDynamo *iDynamoReader;
#endif

/**
 @brief The controller class for IDTECH Shuttle readers.
 */
@property (nonatomic, retain, readonly) PGSwipeUniMag *uniMagReader;

/**
 @brief The controller class for IPS readers
 */
@property (nonatomic, retain, readonly) PGSwipeIps *ipsReader;

/**
 @brief The controller class for IpsEnterprise readers
 */
@property (nonatomic, retain, readonly) PGSwipeIpsEnterprise *ipsEnterpriseReader;


-(id)initWithDelegate:(id<PGSwipeDelegate>)delegate;

-(id)initWithDelegate:(id<PGSwipeDelegate>)delegate audioReader:(AudioJackReaderType)audioJackReaderType;

-(void)setAudioJackReaderType:(AudioJackReaderType)audioJackReaderType;

-(void)setAudioJackReaderType:(AudioJackReaderType)audioJackReaderType messageOptions:(PGSwipeUniMagMessageOptions*)messageOptions;

/**
 @brief Asynchronously attempts to detect the card reader type currently attached to the audio jack.
 @details A communication test is first attempted for an IPS reader then IpsEnterprise reader.  If that fails, an attempt is made to power up a UniMag (Shuttle) card reader.  If either test succeeds, the audioJackReaderType is set to the correct value, and the device will be made ready for use.  The result of the autodetect is reported to the delegate through deviceAutodetectComplete:.
 @note All devices produce very loud tones through the audio jack during this step.  If speakers or headphones are attached, the tones would be unpleasant to the user.  It is recommended that the user be warned and allowed to remove headphones before calling this function.  This library suppresses notifications from the UniMag reader during autodetect.
 Because the device is powered up in order to test it, you will not receive connection / activation / ready for swipe events during detection.  When your delegate receives its deviceAutodetectComplete message, check the isConnected, isActive, and isReadyForSwipe properties for its current state and to complete any initialization.
 In order to detect the devices, all of the underlying card reader libraries must be loaded.  Under some circumstances, these libraries may not unload cleanly, resulting in unreliable use of the card reader.  Autodetect is also a very slow process.  For these reasons, you should not rely on autodetection for each use of the app.
 Because communication through the audio jack is not always perfect, autodetect does not always return a correct result.  The most common failure type is returning CardReaderAutodetectResultFail even though a supported device is connected.
 If it is known in advance which card reader type will be used, that type should be specified when initializing the PGSwipeController.  If multiple devices must be supported, it is strongly recommended that the result of the autodetect be saved (e.g. in NSUserDefaults) and re-used on app startup.
 */
-(void)beginAutodetectAudioJackCardReader;


@end