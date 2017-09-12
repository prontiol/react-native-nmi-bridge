
#import <Foundation/Foundation.h>
#import "PGCard.h"

/**
 @brief Represents card data received from a swipe reader.
 @details This class is not intended for direct instantiation.  Use one of the concrete subclasses instead.
 */
@interface PGSwipedCard : PGCard

/**
 @brief Gets or sets card Track 1.  This data is normally encrypted.
 */
@property (nonatomic, retain) NSString *track1;

/**
 @brief Gets or sets crack 2.  This data is normally encrypted.
 */
@property (nonatomic, retain) NSString *track2;

/**
 @brief Gets or sets crack 3.  This data is normally encrypted.
 */
@property (nonatomic, retain) NSString *track3;

/**
 @brief Gets or sets the card number, masked with 0's.
 @details This value is returned by swipe readers but is not returned in getDirectPostStringWithCVVIncluded: and does not need to be sent to the Payment Gateway to process a swiped card.
 */
@property (nonatomic, retain) NSString *maskedCardNumber;

/**
 @brief Gets or sets the card expiration date as a string in MMYY format.
 @details This value is returned by swipe readers but is not returned in getDirectPostStringWithCVVIncluded: and does not need to be sent to the Payment Gateway to process a swiped card.
 */
@property (nonatomic, retain) NSString *expirationDate;

/**
 @brief Gets or sets the cardholder name.
 @details This value is returned by swipe readers but is not returned in getDirectPostStringWithCVVIncluded: and does not need to be sent to the Payment Gateway to process a swiped card.
 */
@property (nonatomic, retain) NSString *cardholderName;

-(id) initWithTrack1:(NSString *)track1 track2:(NSString *)track2 track3:(NSString *)track3 cvv:(NSString *)cvv;

/**
 @brief Gets a string containing the name-value pairs associated with the credit card data.
 @param cvvIncluded Indicates if the CVV should be returned in the string.  PCI rules prevent storing the CVV, even encrypted, so only set this to YES if the returned string will be purged after usage.
 @return A string similar to "ccnumber=1111111111111111&ccexp=0101", ready for sending to the Gateway DirectPost API.
 */
-(NSString *) getDirectPostStringWithCVVIncluded:(BOOL)cvvIncluded;

@end
