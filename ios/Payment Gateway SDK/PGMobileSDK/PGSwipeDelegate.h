
#import <Foundation/Foundation.h>

#import "SwipeActivationResult.h"
#import "SwipeReasonUnreadyForSwipe.h"
#import "CardReaderAutodetectResult.h"

@class PGSwipeDevice;
@class PGSwipedCard;

/**
 @brief This protocol must be implemented by classes intending to receive swipe reader events.
 */
@protocol PGSwipeDelegate<NSObject>

@optional

/**
 @brief This event is received when a card is swiped.
 @details The event occurs whether the swipe successfully received data or not, unless the underlying card reader does not send data for failed swipes (e.g. the IPS reader does not send notification of bad reads)
 @param card The card that was swiped. This will contain either a PGEncryptedSwipedCard (for audioreaders) or a PGMagnesafeSwipedCard (for iDynamo readers).  The card may be nil if there was a swipe but data was not received.
 @param sender The originating swipe device controller.
 */
-(void)didSwipeCard:(PGSwipedCard *)card device:(PGSwipeDevice *)sender;

/**
 @brief This event is received when the reader begins accepting swipes.
 @details This may occur when the device is connected, when it powers up, or when a swipe is requested, depending on the device and settings.
 @param sender The originating swipe device controller.
 */
-(void)deviceBecameReadyForSwipe:(PGSwipeDevice *)sender;

/**
 @brief This event is received when the reader stops accepting swipes.
 @param reason The reason the device is no longer ready to receive a swipe.
 @param sender The originating swipe device controller.
 */
-(void)deviceBecameUnreadyForSwipe:(PGSwipeDevice *)sender reason:(SwipeReasonUnreadyForSwipe)reason;

/**
 @brief This event is received when the reader is attached to the mobile device.
 @param sender The originating swipe device controller.
 @note The underlying SDK for Shuttle readers will read a headphone attachment as a device connection and you will receive this event.  Be sure to verify with the user that a reader device was attached, not headphones.
 */
-(void)deviceConnected:(PGSwipeDevice *)sender;

/**
 @brief This event is received when the reader is detached from the mobile device.
 @param sender The originating swipe device controller.
 */
-(void)deviceDisconnected:(PGSwipeDevice *)sender;


/**
 @brief This event is received when an attempt to power the reader finishes.
 @param sender The originating swipe device controller.
 @param result The result of the power-up attempt.
 @note This does not necessarily mean that the device was activated.  Check the value of result to verify success or failure.
 */
-(void)deviceActivationFinished:(PGSwipeDevice *)sender result:(SwipeActivationResult)result;

/**
 @brief This event is received when the reader has powered down.
 @param sender The originating swipe device controller.
 */
-(void)deviceDeactivated:(PGSwipeDevice *)sender;


/**
 @brief This event is received when the controller begins attempting to detect the type of reader attached to the audio jack.
 */
-(void)deviceAutodetectStarted;

/**
 @brief This event is received when detecting the audio-jack card reader device type completes.
 @details The result will be CardReaderAutodetectResultFail if the device did not respond to any detection method, or one of the device types.
 @note Autodetect does not check for an iDynamo reader, since the iDynamo identifies itself upon connection and does not conflict with other readers.  This is only useful for audio readers.
 @param result Detected device type
 */
-(void)deviceAutodetectComplete:(CardReaderAutodetectResult)result;


@end
