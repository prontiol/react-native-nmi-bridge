
#import <Foundation/Foundation.h>
#import "PGSwipeDelegate.h"


/**
 @brief The base class for swipe reader devices.
 @note This class should not be instantiated directly.  Use the concrete sub-classes instead.
 */
@interface PGSwipeDevice : NSObject
{
@protected bool _isConnected;
@protected bool _isActivated;
@protected bool _isReadyForSwipe;
@protected id<PGSwipeDelegate> _delegate;
}

/**
 @brief Gets whether a reader is attached.
 @note Since with audio reader's type can not be determined until activation is attempted, this may be set to YES even if the user has only attached headphones or another audio-port connected device.
 */
@property (nonatomic, readonly) bool isConnected;

/**
 @brief Gets whether the reader is powered up / initialized.
 @note The reader is not necessarily ready to accept swipes when activated.  Check the value of isReadyForSwipe.
 */
@property (nonatomic, readonly) bool isActivated;

/**
 @brief Gets whether a user swiping a card will result in a didSwipeCard event.
 */
@property (nonatomic, readonly) bool isReadyForSwipe;

/**
 @brief Gets or sets the delegate that will receive swipe events.
 @note This should not be set directly.  Setting the delegate on the owning PGSwipeController will also set this.
 */
@property (nonatomic,assign) id<PGSwipeDelegate> delegate;


-(id)initWithDelegate:(id<PGSwipeDelegate>) delegate;

@end
