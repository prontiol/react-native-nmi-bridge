
#import <Foundation/Foundation.h>
#import "PGSwipedCard.h"

/**
 @brief Represents a card swiped with an audio reader.
 */
@interface PGEncryptedSwipedCard : PGSwipedCard

/**
 @brief Gets or sets the KSN received from the swipe reader.
 */
@property (nonatomic, retain) NSString * ksn;

-(id) initWithTrack1:(NSString *)track1 track2:(NSString *)track2 track3:(NSString *)track3 ksn:(NSString *)ksn cvv:(NSString *)cvv;

/**
 @brief Gets a string containing the name-value pairs associated with the credit card data.
 @param cvvIncluded Indicates if the CVV should be returned in the string.  PCI rules prevent storing the CVV, even encrypted, so only set this to YES if the returned string will be purged after usage.
 @return A string similar to "ccnumber=1111111111111111&ccexp=0101", ready for sending to the Gateway DirectPost API.
 */
-(NSString *) getDirectPostStringWithCVVIncluded:(BOOL)cvvIncluded;

@end

