
#ifndef IDYNAMO_DISABLED

#import <Foundation/Foundation.h>
#import "PGSwipeDevice.h"

/**
 @brief The controller class for Magnetek iDynamo swipe readers.
 @note This class should not be instantiated directly.  Create a PGSwipeController instead and use its iDynamoReader property.
 */
@interface PGSwipeIDynamo : PGSwipeDevice

-(id) initWithDelegate:(id<PGSwipeDelegate>)delegate;

@end

#endif
