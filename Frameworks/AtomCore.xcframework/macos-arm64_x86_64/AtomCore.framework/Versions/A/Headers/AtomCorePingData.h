//
//  InventoryData.h
//  AtomSDK
//
//  Created by AtomBPC By Secure on 5/22/17.
//  Copyright © 2017 AtomBPC By Secure. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AtomCorePingData : NSObject

typedef void(^PingCompletionBlock)(NSArray* dataCenter);

@property (nonatomic, strong) NSArray *dataCentersArray;

- (void)getOptimizedDataCentersWithcompletion:(void(^)(NSArray *dataArray))successBlock errorBlock:(void(^)(NSError *error))errorBlock;

- (void) pingAllDataCentersDataCenter:(NSArray *)datacenters withCompletion:(PingCompletionBlock) pingCompletion;


@end
