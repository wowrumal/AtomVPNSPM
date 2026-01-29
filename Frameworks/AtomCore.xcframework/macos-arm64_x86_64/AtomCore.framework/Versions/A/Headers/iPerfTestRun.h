//
//  iPerfTestRun.h
//  AtomCore
//
//  Created by AtomCore on 05/11/2020.
//  Copyright © 2020 AtomCore By Secure. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "iPerfConfiguration.h"
#import "iPerfTestResponse.h"

NS_ASSUME_NONNULL_BEGIN

@interface iPerfTestRun : NSObject

- (void) runiPerfTestWithConfiguration: (iPerfConfiguration *) configuration onSuccess: (void(^)(iPerfTestResponse * response))successBlock onFailure: (void(^)(NSError * error))errorBlock;
- (void) stopTest;

@end

NS_ASSUME_NONNULL_END
