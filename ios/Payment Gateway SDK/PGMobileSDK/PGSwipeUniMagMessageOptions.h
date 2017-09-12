#import <Foundation/Foundation.h>

/**
 @brief A set of options to control the automatically-displayed messages for a Shuttle swipe reader.
 */
@interface PGSwipeUniMagMessageOptions : NSObject

/**
 @brief Gets or sets whether to ask the user to confirm that the device should be activated upon inserting the device.
 @note The attached device may be any audio-connected device, and attempting to activate a non-swipe attachment will have unintended results (e.g. a loud, sharp tone through headphones or speakers).
 */
@property (nonatomic) BOOL activateReaderWithoutPromptingUser;

/**
 @brief Gets or sets whether to show "Initializing Card Reader" during device power-up.
 */
@property (nonatomic) BOOL showInitializingReaderMessage;

/**
 @brief Gets or sets a string to use to ask the user to confirm device activation, including a warning that the volume will be set to maximum.
 @note For this message to be displayed, set: automaticallySetVolumeToMaxOnActivate = YES; activateReaderWithoutPromptingUser = NO
 */
@property (nonatomic, retain) NSString *cardReaderActivationPrompt;

/**
 @brief Gets or sets a string to use to ask the user to confirm device activation.  This is used if volume is already at max or if automaticallySetVolumeToMaxOnActivate is NO.
 @note For this message to be displayed, set: activateReaderWithoutPromptingUser = NO; and either volume to maximum or automaticallySetVolumeToMaxOnActivate = NO.
*/
@property (nonatomic, retain) NSString *cardReaderActivationAtMaxVolumePrompt;

/**
 @brief Gets or sets the message to display if the card reader does not respond to an activation request within the timeout period.  Set to nil if no message should be displayed.
 */
@property (nonatomic, retain) NSString *cardReaderTimeoutMessage;

/**
 @brief Gets or sets the message to display when powering up fails due to insufficient device volume.  Set to nil if no message should be displayed.
 */
@property (nonatomic, retain) NSString *volumeTooLowMessage;


//Sets all properties back to their default values.
-(void)resetToDefaults;

@end
