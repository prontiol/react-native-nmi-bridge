
#import <Foundation/Foundation.h>
#import "PGAudioJackConnectionDetectorDelegate.h"


/**
 @brief Provides notification when objects are attached or removed from the audio port.
 @details The attached device may or may not be a card reader.  Headphones and speakers will also trigger these events.
 */
@interface PGAudioJackConnectionDetector : NSObject {
    @protected bool notificationPropagating;
}

@property (nonatomic, retain) NSMutableArray *delegates;

/**
 @brief A singleton that should normally be used to access a detector.  Use addDelegate and removeDelegate to subscribe and unsubscribe from events.
 */
+(PGAudioJackConnectionDetector *)defaultDetector;


/**
 @brief Initializes a detector.
 @details This should normally not be used.  Instead, use the PGAudioJackConnectionDetector's defaultDetector object.
 */
-(id)initWithDelegate:(id<PGAudioJackConnectionDetectorDelegate>) delegate;


/**
 @brief Adds to the list of objects that will be notified when objects are attached or removed from the audio jack.
 */
-(void)addDelegate:(id<PGAudioJackConnectionDetectorDelegate>) delegate;


/**
 @brief Removes an item from the list of delegates that are notified when object is attached or removed from the audio jack.
 */
-(void)removeDelegate:(id<PGAudioJackConnectionDetectorDelegate>) delegate;


/**
 @brief Gets whether an object is currently attached to the audio jack.
 @return Returns YES if the audio route is HeadsetInOut or Headphone.  Otherwise returns NO.
 */
-(BOOL)isObjectPluggedIn;



@end
