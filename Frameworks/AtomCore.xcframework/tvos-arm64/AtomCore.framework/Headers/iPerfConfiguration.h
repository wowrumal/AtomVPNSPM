//
//  iPerfConfiguration.h
//  AtomCore
//
//  Created by AtomCore on 05/11/2020.
//  Copyright © 2020 AtomCore By Secure. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface iPerfConfiguration : NSObject

- (instancetype) initWithHostname: (NSString *) hostname withPortRange: (NSString *) portRange withStream: (int) stream withDuration: (int) duration inUnit: (NSString *) units;

- (NSString *) getHostname;
- (NSString *) getPortRange;
- (int) getStream;
- (int) getDuration;
- (NSString *) getUnits;

@end

NS_ASSUME_NONNULL_END
