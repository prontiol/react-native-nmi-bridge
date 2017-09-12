#import <Foundation/Foundation.h>
#import "PGSwipeDevice.h"
#import "PGSwipeDelegate.h"
#import "PGAudioJackConnectionDetector.h"

@protocol IpsEnterpriseCommunicationTestDelegate <NSObject>

-(void)ipsEnterpriseCommunicationTestCompleteWithResult:(BOOL)success;

@end

/**
 @brief The controller class for Ips Enterprise readers.
 @note This class should not be instantiated directly.  Create a PGSwipeController instead and use its ipsEnterpriseReader property.
 */
@interface PGSwipeIpsEnterprise : PGSwipeDevice<PGAudioJackConnectionDetectorDelegate> {
    @protected id<IpsEnterpriseCommunicationTestDelegate> testDelegate;
}

-(id)initWithDelegate:(id<PGSwipeDelegate>)delegate;

/**
 @brief Closes the reader and unsubscribes from events.  Must be called before releasing.
 */
-(void)shutdown;

-(void)beginTestCommunication:(id<IpsEnterpriseCommunicationTestDelegate>)delegate;

@end
