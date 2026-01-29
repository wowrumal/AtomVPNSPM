//
//  NSError+Helper.h
//  CityQuest
//
//  Created by Hrachya Stepanyan on 3/23/16.
//  Copyright © 2016 Hrachya Stepanyan. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSError (Helper)

+ (NSError *)errorWithResponseParams:(NSDictionary *)responseParams;
+ (NSError *)unknownResponseError;
+ (NSError *)errorWithCode:(NSUInteger)code message:(NSString *)message;
+ (NSError *)errorWithCode:(NSUInteger)code andFailureMessage:(NSString *)failureMessage;
+ (NSError *)mappingSeverErrorCodeToAtomErrorException:(NSUInteger)code andFailureMessage:(NSString *)failureMessage;
@end
