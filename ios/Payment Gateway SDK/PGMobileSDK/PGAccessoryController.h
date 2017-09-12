#ifndef IDYNAMO_DISABLED

#import <Foundation/Foundation.h>
#import <ExternalAccessory/ExternalAccessory.h>

@interface PGAccessoryController : NSObject <EAAccessoryDelegate, NSStreamDelegate>
{
    EAAccessory *_accessory;
    EASession *_session;
    NSString *_protocolString;
    BOOL testDataSent;
    NSMutableData *_writeData;
}

@property (nonatomic, readonly) EAAccessory *accessory;
@property (nonatomic, readonly) NSString *protocolString;

+ (PGAccessoryController *)sharedController;

- (void)setupControllerForAccessory:(EAAccessory *)accessory withProtocolString:(NSString *)protocolString;

- (BOOL)openSession;
- (void)closeSession;

- (void)writeData:(NSData *)data;

- (void)accessoryDidDisconnect:(EAAccessory *)accessory;

@end

#endif //#ifndef IDYNAMO_DISABLED