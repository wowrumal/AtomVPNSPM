//
//  AtomProperties.h
//  AtomSDKFramework
//
//  Copyright © 2017 Atom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AtomCore/AtomCore-Swift.h>
#import "ServerFilter.h"
#import "AtomMultipleDNS.h"

typedef NS_ENUM(NSUInteger, IPTranslation) {
    AUTO = 0,
    NON_NAT = 1,
    NAT = 2,
};

/*!
 * @interface AtomProperties
 * @discussion Contains all the properties required by the ATOM SDK to establish VPN connection.
 */
@interface AtomProperties : NSObject <NSCoding>

/*!
 * @property preSharedKey
 * @discussion Gets the PSK property if provided by the developer for the instance of AtomProperties.
 */
@property (nonatomic, strong) NSString * _Nullable preSharedKey;

/*!
 * @property country
 * @discussion Gets the Country object if provided by the developer for the instance of AtomProperties.
 */
@property (nonatomic, strong, readonly) AtomCountry * _Nullable country;

/*!
 * @property channel
 * @discussion Gets the Channel object if provided by the developer for the instance of AtomProperties.
 */
@property (nonatomic, strong, readonly) AtomChannel * _Nullable channel;

/*!
 * @property city
 * @discussion Gets the City object if provided by the developer for the instance of AtomProperties.
 */
@property (nonatomic, strong, readonly) AtomCity * _Nullable city;

/*!
 * @property protocol
 * @discussion Gets the Protocol object if provided by the developer for the instance of AtomProperties.
 */
@property (nonatomic, strong) AtomProtocol * _Nullable protocol;

/*!
 * @property secondaryProtocol
 * @discussion Set this property to make ATOM SDK dial automatically to this protocol if Primary Protocol fails to connect.
 */
@property (nonatomic, strong) AtomProtocol * _Nullable secondaryProtocol;

/*!
 * @property tertiaryProtocol
 * @discussion Set this property to make ATOM SDK dial automatically to this protocol if Primary and Secondary Protocol fails to connect.
 */
@property (nonatomic, strong) AtomProtocol * _Nullable tertiaryProtocol;

/*!
 *
 * @property experimentProperties
 * @discussion This method can be used to identify SDK whether the user is allowed to park in any specific app experiment.
 */
@property (nonatomic, strong) AtomExperimentProperties * _Nullable experimentProperties;

/*!
 * @property useAutomaticPort
 * @discussion Set this property to True to make ATOM SDK use Multiport Dialing mechanism (For TCP and UDP Protocols only).
 */
@property (nonatomic) BOOL useAutomaticPort;

/*!
 * @property manualPort
 * @discussion Set this property to make ATOM SDK use Multiport Dialing mechanism (For TCP and UDP Protocols only) on a specific port.Port range is dependant on the protocol. Setting this will ignore automaticPort
 */
@property (nonatomic) int manualPort;

/*!
 * @property serverFilters
 * @discussion Gets the ServerFilter object if provided by the developer for the instance of AtomProperties.
 */
@property (nonatomic, strong, readonly) NSArray<ServerFilter *> * _Nullable serverFilters;
/*!
* @property tags
* @discussion Gets the tags array if provided by the developer from the list of enum AtomSmartConnectTag for the instance of AtomProperties.
*/
@property (nonatomic, strong, readonly) NSArray * _Nullable smartConnectTags;

/*!
 * @property dedicatedHostName
 * @discussion Gets the DedicatedHostName property if provided by the developer for the instance of AtomProperties.
 */
@property (nonatomic, strong) NSString * _Nullable dedicatedHostName;

/*!
 * @property dedicatedHosts
 * @discussion Gets the DedicatedHosts property if provided by the developer for the instance of AtomProperties.
 */
@property (nonatomic, strong) NSArray<AtomMultipleDNS *> * _Nullable dedicatedHosts;

/*!
 * @property dedicatedHostProtocols
 * @discussion Gets the dedicatedHostProtocols property if provided by the developer for the instance of AtomProperties.
 */
@property (nonatomic, strong) NSArray<AtomProtocol *> * _Nullable dedicatedHostProtocols;

/*!
 * @property customConfiguration
 * @discussion Gets the configuration property if provided by the developer for the instance of AtomProperties. For TCP/UDP protocol only.
 */
@property (nonatomic, strong) NSString * _Nullable configuration;

/*!
 * @property useOptimization
 * @discussion When set to True, ATOM SDK will use real-time optimization mechanism to connect to your desired Country.
 */
@property (nonatomic) BOOL useOptimization;

/*!
 * @property enableProtocolSwitch
 * @discussion When set to TRUE, ATOM SDK will apply protocol switch automatically else SDK will not apply protocol switch. Default is TRUE
 */
@property (nonatomic) BOOL enableProtocolSwitch;


/*!
 * @property useSmartDialing
 * @discussion Set this property to TRUE for countries that supports advanced mechanism of VPN Dialing on our network. This method of dialing will help in establishing a VPN Tunnel, quicker than the conventional (and recommended) method.
 
 How to get countries those support advanced mechanism of VPN Dialing?
 To get the list of countries those support advanced dialing mechanism use SDK method getCountriesForSmartDialing.
 
 Important:
 1. Setting this Parameter to TRUE, will override useOptimization (if used). This means that useOptimization and UseSmartDialing cannot work together and overrides each other properties.
 
 2. This mechanism only works with countries those supports advanced dialing mechanism, this means, this property can only be used when VPNProperties is being initialized with Country and Protocol.
 */
@property (nonatomic) BOOL useSmartDialing;

/*!
* @property useFailover
* @discussion When set to FALSE, AtomSDK will ignore dialing from failover servers.
*/
@property (nonatomic) BOOL useFailover;

/*!
* @property ipTranslation
* @discussion When set to Auto, AtomSDK can consider NAT & NON_NATTED server whichever is available. Default value is AUTO.
*/
@property (nonatomic) enum IPTranslation ipTranslation;

/*!
* @property preferredLFO
* @discussion When set to Auto, AtomSDK will consider NAT & NON_NATTED server whichever is available in LFO. Default value is AUTO.
*/
@property (nonatomic) enum IPTranslation preferredLFO;

/*!
 * @property dialWithQuantumResistantServer
 * @brief A Boolean value that indicates whether to dial with Quantum Resistant Server or not.
 * @discussion If this property is YES, then ATOM will add the TAG_QR in the speed test request.
 *
 * The default value for this property is NO.
 */
@property (nonatomic, assign) BOOL dialWithQuantumResistantServer;

/*!
 * @property featureFlagAllowLocalNetworkTraffic
 * @brief A Boolean value that indicates whether the SDK will check allowLocalNetworkTraffic or not.
 * @discussion If this property is YES, the SDK will check for allowLocalNetworkTraffic value, if NO then the SDK will dial with old logic without considering allowLocalNetworkTraffic property.
 *
 * The default value for this property is NO.
 */
@property (nonatomic, assign) BOOL featureFlagAllowLocalNetworkTraffic
API_AVAILABLE(macos(10.15), ios(14.2))
API_UNAVAILABLE(watchos, tvos) __WATCHOS_PROHIBITED __TVOS_PROHIBITED;

/*!
 * @property allowLocalNetworkTraffic
 * @brief A Boolean value that indicates whether the system excludes all traffic destined for local networks from the tunnel.
 * @discussion If this property is YES, the system excludes network connections to hosts on the local network — such as AirPlay, AirDrop, and CarPlay.
 *
 * The default value for this property is NO.
 */
@property (nonatomic, assign) BOOL allowLocalNetworkTraffic
API_AVAILABLE(macos(10.15), ios(14.2))
API_UNAVAILABLE(watchos, tvos) __WATCHOS_PROHIBITED __TVOS_PROHIBITED;

/*!
* @property useLastSuccessfulDialedProtocol
* @discussion When set to True, AtomSDK will use last dialed protocol instead of Recommended Protocol in case when Protocol is not provided in AtomProperties.
*/
@property (nonatomic) BOOL useLastSuccessfulDialedProtocol;

/**
 A string identifying the remote IPSec endpoint for authentication purposes.
    # Property
    vpnRemoteIdentifier

*/
@property (nonatomic, strong) NSString * _Nonnull vpnRemoteIdentifier;

/*!
 * @property shouldPerformSpeedTest
 * @discussion When set to True, AtomSDK will use shouldPerformSpeedTest in AtomProperties.
 */
@property (nonatomic) BOOL shouldPerformSpeedTest;

/*!
 * @property atomShieldFeatureList
 * @discussion The list of AtomShield features.
 */
@property (nonatomic, strong) NSArray<NSNumber *>* _Nullable atomShieldFeatureList;

/**
 Initializes a new instance of AtomProperties object with the PSK provided by your backend server. All other properties of this class are ignored by the ATOM SDK when PSK is provided.

 @param  psk : The Pre-shared Key provided by your backend server.
 */
- (instancetype _Nonnull )initWithPreSharedKey:(NSString *_Nonnull)psk __deprecated_msg("Deprecated in v6.2.0. This method will not be available from next version.");
/**
 Initializes a new instance of AtomProperties with a AtomCountry and AtomProtocol object obtained from -getCountriesWithSuccess:errorBlock and -getProtocolsWithSuccess:errorBlock methods of AtomManager.

 @param country The Country to which you need to make the connection on. Countries list can be obtained from -getCountriesWithSuccess:errorBlock method of AtomManager.
 @param protocol The Protocol with which you need to make the connection. Protocols list can be obtained from -getProtocolsWithSuccess:errorBlock method of AtomManager.
 */
- (instancetype _Nonnull )initWithCountry:(AtomCountry * _Nonnull)country protocol:(AtomProtocol * _Nullable)protocol;

/**
 Initializes a new instance of AtomProperties with a AtomChannel and AtomProtocol object obtained from -getProtocolsWithSuccess:errorBlock methods of AtomManager.
 
 @param channel The Channel to which you need to make the connection on.
 @param protocol The Protocol with which you need to make the connection. Protocols list can be obtained from -getProtocolsWithSuccess:errorBlock method of AtomManager.
 */
- (instancetype _Nonnull)initWithChannel:(AtomChannel *_Nonnull)channel protocol:(AtomProtocol * _Nullable)protocol;

/**
 Initializes a new instance of AtomProperties with a AtomCity and AtomProtocol object obtained from -getProtocolsWithSuccess:errorBlock methods of AtomManager.
 
 @param city The city to which you need to make the connection on.
 @param protocol The Protocol with which you need to make the connection. Protocols list can be obtained from -getProtocolsWithSuccess:errorBlock method of AtomManager.
 */
- (instancetype _Nonnull)initWithCity:(AtomCity * _Nonnull)city protocol:(AtomProtocol * _Nullable)protocol;

/**
 Initializes a new instance of AtomProperties with a AtomProtocol and array of AtomSmartConnectTag provided in form of @(<Tag>).
 
 @param protocol The Protocol with which you need to make the connection. Protocols list can be obtained from -getProtocolsWithSuccess:errorBlock method of AtomManager.
 @param tags The Tags to which you need to make the connection on provided from AtomSmartConnectTag.
 */
- (instancetype _Nonnull ) initWithProtocol: (AtomProtocol *_Nonnull) protocol andTags: (NSArray *_Nonnull) tags __deprecated_msg("Deprecated in v6.2.0. This method will not be available from next version.");


/**
 Initializes a new instance of AtomProperties with a dedicatedHostName and the AtomProtocol object obtained from -getProtocolsWithSuccess:errorBlock method of AtomManager.

 @param dedicatedHostName The Dedicated Host Name with which you want to make the connection.This should be a valid hostname or IP Address, Dial error with a validation exception will be thrown otherwise.
 @param protocol The Protocol with which you need to make the connection. Protocols list can be obtained from -getProtocolsWithSuccess:errorBlock method of AtomManager.
 */
- (instancetype _Nonnull)initWithDedicatedHostName:(NSString * _Nonnull)dedicatedHostName protocol:(AtomProtocol * _Nonnull)protocol;

/**
 Initializes a new instance of AtomProperties with a dedicatedHostName and the AtomProtocol object obtained from -getProtocolsWithSuccess:errorBlock method of AtomManager.
 
 @param dedicatedHostName The Dedicated Host Name with which you want to make the connection.This should be a valid hostname or IP Address, Dial error with a validation exception will be thrown otherwise.
 @param protocol The Protocol with which you need to make the connection. Protocols list can be obtained from -getProtocolsWithSuccess:errorBlock method of AtomManager.
 @param configuration Specify configuration while dialing using (For TCP & UDP Protocols only).
 
 */
- (instancetype _Nonnull)initWithDedicatedHostName:(NSString * _Nonnull)dedicatedHostName protocol:(AtomProtocol *_Nonnull)protocol customConfig:(NSString * _Nonnull)configuration;


/**
 Initializes a new instance of AtomProperties with a dedicatedHostName and the AtomProtocol object obtained from -getProtocolsWithSuccess:errorBlock method of AtomManager.
 @param dedicatedHosts The Dedicated Host Name with which you want to make the connection.This should be a valid hostname or IP Address, Dial error with a validation exception will be thrown otherwise.
 @param protocol The Protocol with which you need to make the connection. Protocols list can be obtained from -getProtocolsWithSuccess:errorBlock method of AtomManager.
 */
- (instancetype _Nonnull)initWithMultipleDedicatedHost:(NSArray<AtomMultipleDNS *> * _Nonnull)dedicatedHosts protocol:(AtomProtocol * _Nullable)protocol;

/**
 Use this method to dial using the virtual private server. Use of this method requires special permission from Atom.
 
 Initializes a new instance of AtomProperties with a dedicatedHostName and the AtomProtocol object obtained from -getProtocolsWithSuccess:errorBlock method of AtomManager.

 @param dedicatedHostName The Dedicated Host Name with which you want to make the connection.This should be a valid hostname or IP Address, Dial error with a validation exception will be thrown otherwise.
 @param protocol The Protocol with which you need to make the connection. Protocols list can be obtained from -getProtocolsWithSuccess:errorBlock method of AtomManager.
 */
- (instancetype _Nonnull)initWithDedicatedVPS:(NSString * _Nonnull)dedicatedHostName protocol:(AtomProtocol * _Nonnull)protocol;


/**
 Use this method to dial using the virtual private server. Use of this method requires special permission from Atom.
 
 Initializes a new instance of AtomProperties with a dedicatedHostName and the AtomProtocol object obtained from -getProtocolsWithSuccess:errorBlock method of AtomManager.
 
 @param dedicatedHostName The Dedicated Host Name with which you want to make the connection.This should be a valid hostname or IP Address, Dial error with a validation exception will be thrown otherwise.
 @param protocol The Protocol with which you need to make the connection. Protocols list can be obtained from -getProtocolsWithSuccess:errorBlock method of AtomManager.
 @param configuration Specify configuration while dialing using (For TCP & UDP Protocols only).
 
 */
- (instancetype _Nonnull)initWithDedicatedVPS:(NSString * _Nonnull)dedicatedHostName protocol:(AtomProtocol *_Nonnull)protocol customConfig:(NSString * _Nonnull)configuration;


- (void) setServerFilters: (NSArray<ServerFilter *> *_Nullable) filters;

@end
