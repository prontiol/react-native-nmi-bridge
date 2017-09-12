#import <Foundation/Foundation.h>

@class PGCard;

/**
 @brief Encrypts payment info before sending to the Payment Gateway.
 @details Payment info (e.g. a credit card) is encrypted with a public key.  The card may only be decrypted by the Gateway when submitted by the Merchant whose key encrypted it.
 */
@interface PGEncrypt : NSObject

/**
 @brief Sets the public key that will be used to encrypt payment data.
 @note This key can be obtained through an API query or by logging into the Gateway and navigating to the Settings -> Security Keys section.
 @param key The merchant's public key.
 */
-(void)setKey:(NSString *)key;

/**
 @brief Encrypts a credit card.
 @param card The card to encrypt.  This should usually be a PGKeyedCard created from user-entered data, but for convenience this can also be a swiped card returned in a didReceiveSwipe event from the swipe library.
 @param includeCVV Indicates whether the CVV should be included in the encrypted data.  PCI rules disallow storing CVV data, even encrypted, so if this encrypted data  will be stored, you should set this to NO.
 */
-(NSString *)encrypt:(PGCard *)card includeCVV:(BOOL)includeCVV;

/**
 @brief Encrypts arbitrary data.
 @param str The data to encrypt.
 @note This is not intended for normal use.  Instead, use the version that takes a PGCard, which guarantees that the Gateway will accept the encrypted data.  Only certain name-value pairs are accepted by the Gateway, so only use this if directed to by the documentation.
 */
-(NSString *)encrypt:(NSString *)str;

/**
 @brief Encodes a UTF8 string in Base64.
 @param str A string to be encoded.  Must be in UTF8 format.
 */
+(NSString *)encodeBase64WithString:(NSString *)str;

/**
 @brief Encodes data in Base64.
 @param objData Data to be encoded.
 */
+(NSString *)encodeBase64WithData:(NSData *)objData;

/**
 @brief Decodes a Base64 string into a UTF8 string.
 @param strBase64 A Base64 string to decode.
 */
+(NSString *)decodeBase64ToStringWithString:(NSString *)strBase64;

/**
 @brief Decodes a Base64 string.
 @param strBase64 A Base64 string to decode.
 */
+(NSData *)decodeBase64WithString:(NSString *)strBase64;

@end
