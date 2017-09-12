

#import <Foundation/Foundation.h>

@class PGIpsPacket;
@class SwiperReader;

@protocol IpsDelegate

-(void)gotIpsSwipe:(PGIpsPacket *)swipePacket;

@end

@protocol IpsCommunicationTestDelegate

-(void)ipsCommunicationTestCompleteWithResult:(BOOL)success;

@end

#if !(TARGET_IPHONE_SIMULATOR)
@interface PGIpsReader : NSObject {
}

@property (nonatomic, retain) id<IpsDelegate> delegate;

-(void) initReader;
-(void) stopListeningForSwipe;
-(void) startListeningForSwipe;
-(void) willTerminate:(NSNotification *)notification;
-(void) readerCardInfo;
-(void) deviceUnavailable;
-(void) readerIsDecoding;
-(void) readerErrorDisplay:(NSString*)errorCode;
-(void) openReader;
//-(void) remoteControlReceivedWithEvent:(UIEvent *)theEvent;
-(void) setMaxVolume;
-(void) closeReader;
-(void) setBackRound:(BOOL)backGround;
-(void) testCommunication:(id<IpsCommunicationTestDelegate>)resultListener;
@end
#endif