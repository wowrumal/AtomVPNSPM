//
//  ServerFilter.h
//  AtomSDK
//
//  Created by Atom on 12/06/2020.
//  Copyright © 2020 AtomSDK. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AtomEnum.h"

@interface ServerFilter: NSObject

@property(strong, nonatomic, readonly) NSString *nasIdentifier;
@property(nonatomic, readonly) FilterType filter;

- (instancetype) initWithNasIdentifier:(NSString *) nasIdentifier andFilter: (FilterType) filter;

@end
