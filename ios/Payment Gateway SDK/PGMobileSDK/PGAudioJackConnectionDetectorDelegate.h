

/**
 @brief This protocol must be implemented for classes to be notified when an object is connected to the audio jack.
 */
@protocol PGAudioJackConnectionDetectorDelegate <NSObject>

@optional

/**
 @brief This event is generated when iOS reports that an object has been plugged into the audio jack.
 */
-(void) audioJackObjectAttached;

/**
 @brief This event is generated when iOS reports that an object has been removed from the audio jack.
 */
-(void) audioJackObjectDetached;

@end
