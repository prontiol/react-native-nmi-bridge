
#import <Foundation/Foundation.h>
#import "PGSwipedCard.h"


/**
 @brief Represents a card swiped with an iDynamo swipe reader.
 */
@interface PGMagnesafeSwipedCard : PGSwipedCard

/**
 @brief Gets or sets the KSN returned by the swipe reader.
 */
@property (nonatomic, retain) NSString * magnesafeKsn;

/**
 @brief Gets or sets the MagnesafePrint returned by the swipe reader.
 */
@property (nonatomic, retain) NSString * magnesafePrint;

/**
 @brief Gets or sets the MagnesafePrintStatus returned by the swipe reader.
 */
@property (nonatomic, retain) NSString * magnesafePrintStatus;

-(id) initWithTrack1:(NSString *)track1 track2:(NSString *)track2 track3:(NSString *)track3 magnesafeKsn:(NSString *)ksn magnesafePrint:(NSString *)magnesafePrint magnesafePrintStatus:(NSString *)magnesafePrintStatus cvv:(NSString *)cvv;

/**
 @brief Gets a string containing the name-value pairs associated with the credit card data.
 @param cvvIncluded Indicates if the CVV should be returned in the string.  PCI rules prevent storing the CVV, even encrypted, so only set this to YES if the returned string will be purged after usage.
 @return A string similar to "ccnumber=1111111111111111&ccexp=0101", ready for sending to the Gateway DirectPost API.
 */
-(NSString *) getDirectPostStringWithCVVIncluded:(BOOL)cvvIncluded;

@end
