#import "PGMobileSDK/PGMobileSDK.h"
#import "RCTNMIBridge.h"

@implementation NMIBridge

RCT_EXPORT_MODULE();

RCT_EXPORT_METHOD(encryptCardData
                  :(NSString *)key
                  :(NSString *)cardNumber
                  :(NSString *)expirationData
                  :(NSString *)cvv
                  resolver:(RCTPromiseResolveBlock)resolve
                  rejecter:(RCTPromiseRejectBlock)reject)
{
    PGEncrypt *encryption = [[PGEncrypt alloc] init];
    [encryption setKey:key];
    PGCard *cardData = [[PGKeyedCard alloc] initWithCardNumber:cardNumber
                                                expirationDate:expirationData
                                                           cvv:cvv];
    NSString *encryptedCardData = [encryption encrypt:cardData includeCVV:YES];
    resolve(encryptedCardData);
}

@end
