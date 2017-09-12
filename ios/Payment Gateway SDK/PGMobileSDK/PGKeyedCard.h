
#import <Foundation/Foundation.h>
#import "PGCard.h"

/**
 @brief Represents a credit card manually entered by the user.
 */
@interface PGKeyedCard : PGCard

/**
 @brief Gets or sets the card number.
 */
@property (nonatomic, retain) NSString * cardNumber;

/**
 @brief Gets or sets the card expiration date as a string in the format MMYY.
 */
@property (nonatomic, retain) NSString * expirationDate;

/**
 @brief Gets or sets the card start date.  This is specific to Maestro cards.  May be nil.
 */
@property (nonatomic, retain) NSString * cardStartDate;

/**
 @brief Gets or sets the card issue number.  This is specific to Maestro cards.  May be nil.
 */
@property (nonatomic, retain) NSString * cardIssueNumber;

-(id) initWithCardNumber:(NSString *)cardNumber expirationDate:(NSString *)expirationDate cvv:(NSString *)cvv;

-(id) initWithCardNumber:(NSString *)cardNumber expirationDate:(NSString *)expirationDate cardStartDate:(NSString *)cardStartDate cardIssueNumber:(NSString *)cardIssueNumber cvv:(NSString *)cvv;

/**
 @brief Gets a string containing the name-value pairs associated with the credit card data.
 @param cvvIncluded Indicates if the CVV should be returned in the string.  PCI rules prevent storing the CVV, even encrypted, so only set this to YES if the returned string will be purged after usage.
 @return A string similar to "ccnumber=1111111111111111&ccexp=0101", ready for sending to the Gateway DirectPost API.
 */
-(NSString *) getDirectPostStringWithCVVIncluded:(BOOL)cvvIncluded;

@end
