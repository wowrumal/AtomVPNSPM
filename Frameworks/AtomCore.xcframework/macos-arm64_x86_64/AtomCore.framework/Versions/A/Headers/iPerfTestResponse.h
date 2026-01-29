//
//  iPerfTestResponse.h
//  AtomCore
//
//  Created by AtomCore on 05/11/2020.
//  Copyright © 2020 AtomCore By Secure. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface iPerfTestResponse : NSObject

@property(strong, nonatomic) NSString *hostname;
@property (strong, nonatomic) NSNumber *bandwidth;
@property (strong, nonatomic) NSNumber *averageBandwidth;
@property (strong, nonatomic) NSString *unit;
@property (nonatomic) int port;
@property (nonatomic) BOOL isActive;
@property (nonatomic) double totalTimeTakenToFindConnectedSpeed;

@end

NS_ASSUME_NONNULL_END
