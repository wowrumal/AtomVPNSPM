//
//  AtomMultipleDNS.h
//  AtomSDK
//
//  Created by Syed Faizan Ahmed on 02/09/2022.
//  Copyright © 2022 AtomSDK. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 * @interface AtomMultipleDNS
 * @discussion Represents a Dedicated DNS with which you want to dial connection with Dedicated DNS dialing.
 */
@interface AtomMultipleDNS : NSObject

/*!
 * @property dedicatedHostName
 * @discussion Gets or sets the dedicatedHostName.
 */
@property (nonatomic, strong) NSString *dedicatedHostName;

/*!
 * @property dedicatedHostIP
 * @discussion Gets or sets the dedicatedHostIP.
 */
@property (nonatomic, strong) NSString *dedicatedHostIP;

/*!
 * @property protocol
 * @discussion Gets or sets the protocol.
 */
@property (nonatomic, strong) AtomProtocol *protocol;

/*!
 * @method initWithDedicatedHostName:andDedicatedHostIP:andProtocol:
 * @discussion Creates a AtomMultipleDNS object with a dedicatedHostName and a protocol.
 * @param dedicatedHostName The host name of the VPN server.
 * @param dedicatedHostIP The host IP Address of the VPN server.
 * @param protocol The preferred protocol to dial VPN server.
 */
- (instancetype)initWithDedicatedHostName:(NSString *)dedicatedHostName andDedicatedHostIP:(NSString *)dedicatedHostIP andProtocol:(AtomProtocol *)protocol;

-(NSDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END
