
#import <Foundation/Foundation.h>
#import "PGSwipeDevice.h"
#import "PGIpsReader.h"
#import "PGAudioJackConnectionDetector.h"

/**
 @brief The controller class for IPS swipe readers.
 @note This class should not be instantiated directly.  Create a PGSwipeController instead and use its ipsReader property.
 */
@interface PGSwipeIps : PGSwipeDevice<IpsDelegate, PGAudioJackConnectionDetectorDelegate>


-(id) initWithDelegate:(id<PGSwipeDelegate>)delegate;

/**
 @brief Closes the reader and unsubscribes from events.  Must be called before releasing.
 */
-(void)shutdown;

-(void)beginTestCommunication:(id<IpsCommunicationTestDelegate>)communicationTestDelegate;

@end
