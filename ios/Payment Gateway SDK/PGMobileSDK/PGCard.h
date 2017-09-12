
#import <Foundation/Foundation.h>

/**
 @brief The base class for credit cards.
 @details This class is not intended for direct instantiation.  Use one of the concrete subclasses instead.
 */
@interface PGCard : NSObject

/**
 @brief Gets or sets the CVV number of the credit card.  May be nil.
 */
@property (nonatomic, retain) NSString * cvv;

/**
 @brief Gets a string containing the name-value pairs associated with the credit card data.
 @param cvvIncluded Indicates if the CVV should be returned in the string.  PCI rules prevent storing the CVV, even encrypted, so only set this to YES if the returned string will be purged after usage.
 @return A string similar to "ccnumber=1111111111111111&ccexp=0101", ready for sending to the Gateway DirectPost API.
 */
-(NSString *) getDirectPostStringWithCVVIncluded:(BOOL)cvvIncluded;

@end




