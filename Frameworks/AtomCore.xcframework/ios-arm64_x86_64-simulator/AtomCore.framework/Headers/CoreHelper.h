//
//  AtomHelper.h
//  AtomSDK
//
//  Created by Ajay Sagar Parwani on 23/01/2020.
//  Copyright © 2020 Atom. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CoreHelper : NSObject

+ (NSArray<NSString *> *) tokenizeString: (NSString *) string by: (NSString *) seperator;
+ (NSValue *) getRange: (NSString *) ports;

@end
