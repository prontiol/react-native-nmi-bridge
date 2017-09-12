
#import <Foundation/Foundation.h>
#import "PGSwipeDelegate.h"
#import "PGSwipeDevice.h"

@class PGSwipeUniMagMessageOptions;

/**
 @brief The controller class for IDTECH Shuttle swipe readers.
 @note This class should not be instantiated directly.  Create a PGSwipeController instead and use its uniMagReader property.
 */
@interface PGSwipeUniMag : PGSwipeDevice


/**
 @brief Gets a set of options describing how messages are displayed to the user.
 */
@property (nonatomic, retain, readonly) PGSwipeUniMagMessageOptions *messageOptions;

/**
 @brief Gets or sets whether the swipe device is activated automatically upon device attachment.
 @note If you set this to NO, you must call powerUpDevice:YES after (or during) the deviceConnected event to continue powering up the device or call powerUpDevice:NO to cancel powering up.  If this is yes, powerUpDevice:YES is automatically called after the deviceConnected event.
 */
@property (nonatomic) BOOL activateReaderOnAttach;

/**
 @brief Gets or sets whether to set the volume to maximum when activating the the device.  The device will not operate with low volume.
 */
@property (nonatomic) BOOL automaticallySetVolumeToMaxOnActivate;

/**
 @brief Gets or sets whether the device should always be be ready for a user swipe.
 @note The underlying SDK requires the swipe device to timeout at a maximum of 20 seconds, but if this is YES a new request is issued after each timeout to keep the device constantly ready for a swipe.  This may drain the iPhone / iPad / iPod battery more quickly than only requesting a swipe when ready to swipe.
 */
@property (nonatomic, setter = setAlwaysAcceptSwipe:) BOOL alwaysAcceptSwipe;



-(id) initWithDelegate:(id<PGSwipeDelegate>)delegate;

-(id) initWithDelegate:(id<PGSwipeDelegate>)delegate messageOptions:(PGSwipeUniMagMessageOptions *)options;

/**
 @brief Either continues or cancels powering up the card reader after an audio connection is detected.
 @param powerUp Set to true if the device should be powered up, or false if the powerup should be canceled.
 @note This should be called on or after the deviceConnected event only if activateReaderOnAttach is NO. If activateReaderOnAttach is YES (the default), this is called automatically.
 @note If you call powerDown, you may call powerUpDevice:YES at any time after that to re-power the device.
 */
- (void)powerUpDevice:(BOOL)powerUp;

/**
 @brief Deactivate / power down the device.
 @note This will send a disconnect and reconnect event, at which time the SDK will attempt to reactivate the device if activateReaderOnAttach is enabled.  Be sure to disable activateReaderOnAttach before powering down to prevent this.
 */
- (void)powerDown;

/**
 @brief Readies the device to receive a swipe.  Swipe events can be received from the time requestSwipe is called until the request times out.
 @note This should not be used if alwaysAcceptSwipe is YES.
 */
-(void)requestSwipe;

/**
 @brief Cancels a swipe request.
 @note To prevent alwaysAcceptSwipe from immediately re-requesting a swipe, be sure to set alwaysAcceptSwipe to NO before calling.
 */
-(void)cancelSwipeRequest;

/**
 @brief Sets the amount of time the device will wait for a swipe after a call to
requestSwipe before timing out.  The minimum is 3 seconds, and the max is 20 seconds.
 @param seconds The number of seconds to wait for a swipe before canceling.
 */
-(void)setSwipeTimeout:(int)seconds;


@end

