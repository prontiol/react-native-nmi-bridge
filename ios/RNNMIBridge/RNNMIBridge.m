#import "PGMobileSDK/PGMobileSDK.h"
#import "RNNMIBridge.h"

@implementation NMIBridge

RCT_EXPORT_MODULE();

RCT_EXPORT_METHOD(encryptCardData
                  :(NSString *)key
                  :(NSString *)cardNumber
                  :(NSString *)expirationDate
                  :(NSString *)cvv
                  resolver:(RCTPromiseResolveBlock)resolve
                  rejecter:(RCTPromiseRejectBlock)reject)
{
    PGEncrypt *encryption = [[PGEncrypt alloc] init];
    [encryption setKey:key];
    PGCard *cardData = [[PGKeyedCard alloc] initWithCardNumber:cardNumber
                                                expirationDate:expirationDate
                                                           cvv:cvv];
    NSString *encryptedCardData = [encryption encrypt:cardData includeCVV:YES];
    resolve(encryptedCardData);
}

@end
