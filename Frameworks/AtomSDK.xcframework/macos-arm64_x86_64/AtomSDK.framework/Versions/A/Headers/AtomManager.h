//
//  AtomManager.h
//  AtomSDK
//
//  Copyright © 2017 Atom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AtomStatus.h"
#import "AtomProperties.h"
#import "AtomConnectionDetails.h"
#import "AtomOnDemandConfiguration.h"
#import "AtomCredential.h"
#import "AtomCore/AtomCore-Swift.h"
#import "AtomManager.h"

@class AtomManager;

@protocol AtomShieldManagerDelegate;

// This protocol represents the Atom Manager delegates. As such, it supplies information about connection and disconnection of the VPN tunnel.
@protocol AtomManagerDelegate <NSObject>

/*!
 * @method atomManagerDidInitialized:
 * @discussion Invokes when a AtomManager sharedInstance is successfully initialized.
 * @param sharedInstance Provides the initialzed sharedInstance of AtomManager.
 */
@required
- (void)atomManagerDidInitialized:(AtomManager * _Nonnull)sharedInstance;

/*!
 * @method atomManagerDidConnecting:
 * @discussion Invokes when a successful VPN Connection is made.
 * @param atomConnectionDetails Provides the details of the connection attempt.
 */

- (void)atomManagerDidConnecting:(AtomConnectionDetails * _Nullable)atomConnectionDetails;

/*!
 * @method atomManagerDidConnect:
 * @discussion Invokes when a successful VPN Connection is made.
 * @param atomConnectionDetails Provides the details of the connection attempt.
 */

- (void)atomManagerDidConnect:(AtomConnectionDetails * _Nullable)atomConnectionDetails;

/*!
 * @method atomManagerDidPaused:
 * @discussion Invokes when a VPN is Paused.
 * @param atomConnectionDetails Provides the details of the connection attempt.
 */
- (void)atomManagerDidPaused:(AtomConnectionDetails * _Nullable)atomConnectionDetails;

/**
 Invokes when a VPN Connection is successfully disconnected.
 Note :
 @param atomConnectionDetails Provides the details of the connection attempt.
 */

- (void)atomManagerDidDisconnect:(AtomConnectionDetails * _Nullable)atomConnectionDetails;


/*!
 * @method atomManagerDidDisconnect:withConnectionDetails:
 * @discussion Invokes when a VPN Connection is successfully disconnected.
 * @param manuallyDisconnected Identifying if the connection has been cancelled manually. The return value will be YES when using -cancelVPN otherwise the default value will be NO.
 * @param atomConnectionDetails Provides the details of the connection attempt.
 */

- (void)atomManagerDidDisconnect:(BOOL)manuallyDisconnected withConnectionDetails:(AtomConnectionDetails * _Nullable) atomConnectionDetails __attribute__ ((unavailable("Don't use this method, instead use atomManagerDidDisconnect:")));

/*!
 * @method atomManagerOnRedialing:withError:
 * @discussion Invokes whenever ATOM SDK tries to redial automatically in case of a failed connection attempt.
 * @param atomConnectionDetails Provides the details of the connection attempt.
 * @param error Contains the exception occured during the dialing process.
 */
- (void)atomManagerOnRedialing:(AtomConnectionDetails * _Nullable)atomConnectionDetails withError:(NSError *_Nullable)error;

/*!
* @method atomManagerDialErrorReceived:withConnectionDetails:
* @discussion Invokes when the ATOM SDK is unable to connect with the provided VPNProperties.
* @param atomConnectionDetails Provides the details of the connection attempt.
* @param error Contains the error occured during dialing.
*/

- (void)atomManagerDialErrorReceived:(NSError * _Nullable)error withConnectionDetails:(AtomConnectionDetails * _Nullable)atomConnectionDetails;

/*!
 * @method atomManagerOnUnableToAccessInternet:withConnectionDetails:
 * @discussion Invokes when the VPN server is unable to access internet.
 * @param atomConnectionDetails Provides the details of the connection attempt.
 * @param error Contains the error occured during dialing.
 */
@optional 
- (void) atomManagerOnUnableToAccessInternet: (NSError * _Nullable) error withConnectionDetails: (AtomConnectionDetails * _Nullable) atomConnectionDetails;

/*!
 * @method atomManagerDidReceivedConnectedLocation:withError:
 * @discussion Invokes when the VPN is connected with location.
 * @param location Provides the details of the connected country, connected city and connected ip in AtomLocation
 * @param error Contains the error, if unable to fetch connected details.
*/
@optional
- (void) atomManagerDidReceivedConnectedLocation: (AtomLocation * _Nullable) location withError: (NSError * _Nullable) error;

@optional

/*!
 * @method atomManagerDidConnect
 * @discussion Invokes when a successful VPN Connection is made.
 */
- (void)atomManagerDidConnect __deprecated_msg("Use atomManagerDidConnect: instead. This method will not be available from next version.");

/*!
 * @method disconnectVPN:
 * @discussion This function is used to stop the VPN tunnel. The VPN tunnel disconnect process is started and this function returns immediately.
 */
//- (void)VPNConnected:(id _Nullable )sender __deprecated_msg("Use atomManagerDidConnect instead. This method will not be available from next version.");

/* -VPNDisconnected:isCancelled
 * @optional
 * @discussion This delegate method will fire when VPN connection is Disconnected. At this point, you can have the VPN disconnected state.
 * @param isCancelled Identifying if the connection has been cancelled manually. The return value will be YES when using -cancelVPNConnection otherwise the default value will be NO.
 */
//- (void)VPNDisconnected:(BOOL)isCancelled __deprecated_msg("Use atomManagerDidDisconnect: instead. This method will not be available from next version.");

/* -VPNRedialingConnectionDetails:withError
 * @optional
 * @discussion This delegate method will fire when VPN connection is Redialing after unsuccessful connection try. At this point, you can have the VPN Redialing state.
 */
//- (void)VPNRedialingConnectionDetails:(AtomConnectionDetails * _Nullable)atomConnectionDetails withError:(NSError * _Nullable)error __deprecated_msg("Use atomManagerOnRedialing:withError: instead. This method will not be available from next version.");

/* -VPNDialedError:withConnectionDetails
 * @optional
 * @discussion This delegate method will fire when VPN is failed to establish connection. At this point, you can have the VPN connection failed state.
 */
//- (void)VPNDialedError:(NSError * _Nullable)error withConnectionDetails:(AtomConnectionDetails * _Nullable)atomConnectionDetails __deprecated_msg("Use atomManagerDialErrorReceived:withError: instead. This method will not be available from next version.");

@end

/*!
 * @interface AtomManager
 * @discussion The main class used to connect and maintain VPN Connections.
 *
 * Instances of this class are thread safe.
 */


@interface AtomManager : NSObject

/*!
 * @property delegate
 * @discussion A property delegate. Set this property to receive the connection delegates.
 */

@property (nonatomic, weak) id <AtomManagerDelegate> _Nullable delegate;

/*!
 * @property atomShieldDelegate
 * @discussion A property atomShieldDelegate. Set this property to receive the AtomShield delegates.
 */
@property (nonatomic, weak) id <AtomShieldManagerDelegate> _Nullable atomShieldDelegate;

/*!
 * @property stateDidChangedHandler
 * @discussion Invokes when the VPNState changed during dialing.
 */
@property (nonatomic, copy) StateDidChangedHandler _Nullable stateDidChangedHandler;

/*!
 * @property onPacketsTransmitted
 * @discussion Invokes when network packets starts transmitting after VPN connection is made.
 */
@property (nonatomic, copy) OnPacketsTransmitted _Nonnull onPacketsTransmitted;

/*!
 * @property atomCredential
 * @discussion Gets and Sets the VPN Credentials object to be used in a VPN Connection. It must be provided before calling Connect method or provide UUID alternatively.
 */
@property (nonatomic, strong) AtomCredential * _Nullable atomCredential;

/*!
 * @property atomProperties
 * @discussion Gets or sets the AtomProperties which are used for the connection, or return last properties, if persistVPNDetails in AtomConfiguration set to true and return null if no connection has been made yet..
 */
@property (nonatomic, strong) AtomProperties * _Nonnull atomProperties;


/*!
 * @property onDemandConfiguration
 * @discussion Get or set AtomOnDemandConfigurtion to enable onDemandRules

 */
@property (nonatomic, strong) AtomOnDemandConfiguration * _Nullable onDemandConfiguration;


/*!
 * @property onDemandConfiguration
 * @discussion Get or set AtomOnDemandConfigurtion to enable onDemandRules

 */
@property (nonatomic, strong) NSArray<AtomProtocol *> * _Nullable excludeProtocols;


/*!
 * @property UUID
 * @discussion Gets or Sets a Unique User identifier used to connect to a vpn server if Credentials object is not provided. ATOM SDK will generate VPN Credentials itself when this property is provided. This value will be ignored if Credentials are provided.
 */
@property (nonatomic, strong) NSString * _Nullable UUID __deprecated_msg("Deprecated in v6.2.0. This property will not be available from next version.");

/*!
 * @property lastDialedHost
 * @discussion The VPN server. Depending on the protocol, may be an IP address or host name. This value will be set to nil if no prior connection has been made.
 */
@property (nonatomic, strong) NSString * _Nullable lastDialedHost __deprecated_msg("Use atomConnectionDetails instead. This property will not be available from next version.");

/*!
 * @property lastDialedHostMethod
 * @discussion The VPN server method. Depending on the protocol, server method through which @lastDialedHost was fetched. This value will be set to nil if no prior connection has been made.
 */
@property (nonatomic, strong) NSString *_Nullable lastDialedHostMethod __deprecated_msg("Use atomConnectionDetails instead. This property will not be available from next version.");

/*!
 * @property lastDialedHostMethod
 * @discussion The VPN server type. Depending on the protocol, server type through which @lastDialedHost was fetched. This value will be set to nil if no prior connection has been made.
 */
@property (nonatomic, strong) NSString * _Nullable lastDialedHostServerType __deprecated_msg("Use atomConnectionDetails instead. This property will not be available from next version.");

/*!
 * @property atomConnectionDetails
 * @discussion Gets the details of the last connection attempt or return details of last connection made, if persistVPNDetails set to true.
 */
@property (nonatomic, strong) AtomConnectionDetails * _Nullable atomConnectionDetails;

/*!
 * @property isAlwaysOnEnabled
 * @discussion Toggles VPN Always On feature. 
 */
@property (nonatomic) BOOL vpnAlwaysOn;

/*!
 * @property domainsArray
 * @discussion An array of web domain objects. e.g: www.<domain_name>.com
 */
@property (nonatomic, strong) NSArray * _Nullable vpnOnDemandWithDomains;

/*!
 * @property doCheckInternetConnectivity
 * @discussion When set to True, ATOM SDK will  check  internet connectivity.
 */
@property (nonatomic) BOOL doCheckInternetConnectivity;


/*!
 * @method sharedInstanceWithSecretKey:
 * @discussion Initializes a new instance of the ATOM SDK using a secret key. If the ATOM SDK was initialized previously the same object is returned.
 * @param secretKey The Secret Key provided by ATOM at the time of subscription.
 */
+ (AtomManager *_Nonnull)sharedInstanceWithSecretKey:(NSString *_Nonnull)secretKey;

/*!
 * @method sharedInstanceWithAtomConfiguration:
 * @discussion Initializes a new instance of the ATOM SDK using AtomConfiguration. If the SDK was initialized previously the same object is returned.
 * @param atomConfiguration An AtomConfiguration object which enables the developer to provide the custom configuration. SecretKey is mandatory in any case.
 */
+ (AtomManager *_Nonnull)sharedInstanceWithAtomConfiguration:(AtomConfiguration *_Nonnull)atomConfiguration;

/*!
 @method
 
 @abstract
 Returns the previously instantiated singleton instance of the API.
 
 @discussion
 The API must be initialized with <code>sharedInstanceWithSecretKey:</code> before
 calling this class method.
 */
+ (AtomManager * _Nullable)sharedInstance;

/*!
 * @method pauseWithTimer:
 * @discussion Pauses existing VPN Connection.
 */
- (void)pauseWithTimer:(PauseVPNTimer)timer WithCompletion:(void(^_Nullable)(NSError * _Nullable error))completion;

/*!
 * @method resumeWithCompletion:
 * @discussion Resumes existing VPN Connection.
 */
- (void)resumeWithCompletion:(void(^_Nullable)(NSError * _Nullable error))completion;

/*!
 * @method connectWithProperties:completion:errorBlock
 * @discussion Creates a VPN connection.This function is used to start the VPN tunnel using the current VPN configuration after validation of AtomProperties.
 * @param propertiesObject The AtomProperties object used by the ATOM SDK to establish a VPN connection.
 */
- (void)connectWithProperties:(AtomProperties *_Nonnull)propertiesObject completion:(void(^_Nonnull)(NSString* _Nullable success))successBlock errorBlock:(void(^_Nonnull)(NSError * _Nullable error))errorBlock;

/*!
 * @method disconnectVPN:
 * @discussion Disconnects existing VPN Connection. If AtomStatus is CONNECTING then use cancelVPN method.
 */
- (void)disconnectVPN;

/*!
 * @method reconnectVPN:
 * @discussion Reconnect to the last connected server. This will cause a dial error if no connection has been made yet.
 */
- (void)reconnectVPN;

/*!
 * @method cancelVPNConnection:
 * @discussion Cancels a VPN connection process if a connection process is already started and not reached to Connected state.
 */
- (void)cancelVPNConnection __deprecated_msg("Use cancelVPN instead. This method will not be available from next version.");

/*!
 * @method cancelVPN:
 * @discussion Cancels a VPN connection process if a connection process is already started and not reached to Connected state.
 */
- (void)cancelVPN;

/*!
 * @property getCurrentVPNStatus
 * @discussion Gets the current status of the VPN SDK. Please refer to AtomVPNStatus Enum for the possible values.
 */
- (AtomVPNStatus) getCurrentVPNStatus;

/*!
 * @property getConnectedIP
 * @discussion Gets the VPN IP of the current connected session. Returns empty string in case of disconnected state.
 */
- (NSString* _Nonnull) getConnectedIP __deprecated_msg("Use getConnectedLocation: instead. This method will not be available from next version.");

/*!
 * @property getConnectedTime
 * @discussion Gets the time at which the current VPN connection was established.
 */
- (NSDate* _Nullable) getConnectedTime;

/// Gets the public key for dialing the wireguard connection.
- (NSString * _Nonnull) getWireguardConnectionPublicKey;

/// Gets the private key for dialing the wireguard connection.
- (NSString * _Nonnull) getWireguardConnectionPrivateKey;


#pragma mark - Request Inventory Methods

/*!
 * @method getProtocolsWithSuccess:errorBlock
 * @discussion Gets all the Protocols allowed to the reseller by Atom.
 * @param errorBlock If the array of AtomProtocol object is returned, this parameter is set to nil. Otherwise this parameter is set to the error that occurred.
 * @param success Will be called with array of AtomProtocol
 */
- (void)getProtocolsWithSuccess:(void (^_Nonnull)(NSArray <AtomProtocol *> * _Nullable protocolsList))success
                     errorBlock:(void (^_Nonnull)(NSError * _Nullable error))errorBlock;

/*!
 * @method getCountriesWithSuccess:errorBlock
 * @discussion Gets all the Countries allowed to the reseller by Atom.
 * @param errorBlock  If the array of AtomCountry object is returned, this parameter is set to nil. Otherwise this parameter is set to the error that occurred.
 * @param success Will be called with array of AtomCountry
 */
- (void)getCountriesWithSuccess:(void (^_Nonnull)(NSArray <AtomCountry *> * _Nullable countriesList))success
                     errorBlock:(void (^_Nonnull)(NSError * _Nullable error))errorBlock;


/*!
 * @method getCountriesForSmartDialing:errorBlock
 * @discussion Get all the Countries those support advanced mechanism of VPN Dialing on our network. This advanced mechanism of dialing will help in establishing a VPN Tunnel, quicker than the conventional (and recommended) method.
 * @param errorBlock If the array of AtomCountry object is returned, this parameter is set to nil. Otherwise this parameter is set to the error that occurred.
 */
- (void)getCountriesForSmartDialing:(void (^_Nonnull)(NSArray <AtomCountry *> * _Nullable countriesList))success
                         errorBlock:(void (^_Nonnull)(NSError * _Nullable error))errorBlock;

/*!
 * @method getOptimizedCountriesWithSuccess:errorBlock
 * @discussion Gets all the Countries optimized and sorted on the basis of realtime latency w.r.t. user's network conditions allowed to the reseller by Atom.
 * @param errorBlock If the array of AtomCountry object is returned, this parameter is set to nil. Otherwise this parameter is set to the error that occurred.
 * @param success Will be called with array of AtomCountry
 */
- (void)getOptimizedCountriesWithSuccess:(void (^_Nonnull)(NSArray <AtomCountry *> * _Nullable optimizedCountriesList))success
                              errorBlock:(void (^_Nonnull)(NSError * _Nullable error))errorBlock;

/*!
 * @method isSmartConnectAvailableOnProtocol:protocol:tags
 * @discussion Returns true if SmartConnect is available on Protocol and SmartConnectTag .
 * @param protocol  Supported protocol otherwise throw validation exception
 * @param tags Valid tags that might support the supported protocol
 * @warning Throw validation exception
 */
- (BOOL) isSmartConnectAvailableOnProtocol: (AtomProtocol *_Nonnull) protocol andTags: (NSArray *_Nonnull) tags;

/*!
* @method getCitiesWithSuccess:errorBlock
* @discussion Gets all the Cities allowed to the reseller by Atom.
* @param errorBlock  If the array of AtomCity object is returned, this parameter is set to nil. Otherwise this parameter is set to the error that occurred.
* @param success Will be called with array of AtomCity
*/
- (void)getCitiesWithSuccess:(void (^_Nonnull)(NSArray <AtomCity *> * _Nullable citiesList))success
                  errorBlock:(void (^_Nonnull)(NSError * _Nullable error))errorBlock;

/*!
 * @method getChannelsWithSuccess:errorBlock
 * @discussion Gets all the Channels allowed to the reseller by Atom.
 * @param errorBlock  If the array of AtomChannel object is returned, this parameter is set to nil. Otherwise this parameter is set to the error that occurred.
 * @param success Will be called with array of AtomChannel
 */
- (void)getChannelsWithSuccess:(void (^_Nonnull)(NSArray <AtomChannel *> * _Nullable channelsList))success
                    errorBlock:(void (^_Nonnull)(NSError * _Nullable error))errorBlock;

/*!
 * @method getConnectionDetailsWithSuccess:errorBlock
 * @discussion This function can be used to return the last connected VPN interface details of the current session. AtomConnectionDetails includes the necessary details about the connection information.
 * @param errorBlock If the connectionDetails object is returned, this parameter is set to nil. Otherwise this parameter is set to the error that occurred.
 */
- (void)getConnectionDetailsWithSuccess:(void (^_Nonnull)(AtomConnectionDetails * _Nullable connectionDetails))success
                             errorBlock:(void (^_Nonnull)(NSError * _Nullable error))errorBlock __deprecated_msg("Use getLastConnectionDetailsWithSuccess instead. This method will not be available from next version.");

/*!
 * @method getLastConnectionDetailsWithSuccess:errorBlock
 * @discussion Gets the connection details of the last successful connection made using the provided Credentials or UUID.
 * @param errorBlock when no connection details found for this session or invalid credentials/UUID are provided.
 */
- (void)getLastConnectionDetailsWithSuccess:(void (^_Nonnull)(AtomConnectionDetails * _Nullable connectionDetails))success
                                 errorBlock:(void (^_Nonnull)(NSError * _Nullable error))errorBlock;

/*!
* @method getRecommendedCountry:errorBlock
* @discussion Get the recommended country based on USER's location when VPN is in disconnected state.
* @param errorBlock when no recommended country found.
*/
- (void) getRecommendedCountry: (void (^_Nonnull)(AtomCountry * _Nullable country)) success errorBlock:(void (^_Nonnull)(NSError * _Nullable error)) errorBlock  __deprecated_msg("Use getRecommendedLocation instead. This method will not be available from next version.");

/*!
* @method getRecommendedLocation:errorBlock
* @discussion Get the recommended location based on USER's location when VPN is in disconnected state.
* @param errorBlock when no recommended country found.
*/
- (void) getRecommendedLocation:(void (^_Nonnull)(AtomLocation * _Nullable location))success errorBlock:(void (^_Nonnull)(NSError * _Nullable error))errorBlock;


#pragma mark - Install VPN Profile

/*!
 * @method installVPNProfileWithCompletion:errorBlock
 * @discussion This function is used to install the VPN profile. VPN profile is used to establish the VPN connections.
 * @param errorBlock If the successBlock is returned, this parameter is set to nil. Otherwise this parameter is set to the error that occurred.
 */
- (void)installVPNProfileWithCompletion:(void(^_Nonnull)(NSString* _Nullable success))successBlock errorBlock:(void(^_Nonnull)(NSError * _Nullable error))errorBlock;

#pragma mark - On Demand VPN Method
/*!
 * @method updateOnDemandVpnStatusWithCompletion:errorBlock
 * @discussion This function is used to update and apply the On Demand VPN status of the VPN profile. On Demand VPN is used to establish the VPN connections based on the rules specified through @isOnDemandVpnEnabled, @isAlwaysOnEnabled, @isDomainEnabled, or @domainsArray properties.
 * @param errorBlock If the successBlock is returned, this parameter is set to nil. Otherwise this parameter is set to the error that occurred.
 */
- (void)updateOnDemandVpnStatusWithCompletion:(void(^_Nullable)(NSString* _Nullable success))successBlock errorBlock:(void(^_Nullable)(NSError * _Nullable error))errorBlock;

/*!
 * @method removeVPNProfileWithCompletion:
 * @discussion This function is used to remove VPN Profile
 * @param completionBlock will return true, if profile successfully deleted.
 */
- (void) removeVPNProfileWithCompletion: (void(^_Nullable)(BOOL isSuccess)) completionBlock;

/*!
* @method getConnectedLocation:
* @discussion This function is used to get connected location after VPN connection establishes
* @param success will return AtomLocation object that contains AtomCountry, AtomCity and IP address of VPN.
* @param errorBlock will return NSError object that contains error object, if no connected location is fetched
*/
- (void) getConnectedLocation: (void (^_Nonnull)(AtomLocation * _Nullable location)) success errorBlock:(void (^_Nonnull)(NSError * _Nullable error)) errorBlock;

/*!
* @method getVirtualCountries:
* @discussion This function is used to get list of virtual countries based on isVirtual property in AtomCountry
* @param successBlock will return list of AtomCountry that are virtually avaiable.
* @param errorBlock will return NSError object that contains error object, if no virtual countries fetched.
*/
- (void) getVirtualCountries: (void (^_Nonnull)(NSArray<AtomCountry *> * _Nullable virtualCountries)) successBlock errorBlock:(void (^_Nonnull)(NSError * _Nullable error)) errorBlock;

/*!
* @method getPhysicalCountries:
* @discussion This function is used to get list of physical countries based on isVirtual property in AtomCountry
* @param successBlock will return list of AtomCountry that are physically avaiable.
* @param errorBlock will return NSError object that contains error object, if no virtual countries fetched.
*/
- (void) getPhysicalCountries: (void (^_Nonnull)(NSArray<AtomCountry *> * _Nullable physicalCountries)) successBlock errorBlock:(void (^_Nonnull)(NSError * _Nullable error)) errorBlock;

/*!
* @method pingDedicatedIPServer:
* @discussion This function is used to get list of physical countries based on isVirtual property in AtomCountry
* @param successBlock will return list of AtomCountry that are physically avaiable.
* @param errorBlock will return NSError object that contains error object, if no virtual countries fetched.
*/
- (void) pingDedicatedIPServer: (AtomDedicatedIPServerPing *_Nonnull) dedicatedServer successBlock: (void (^_Nonnull)(AtomDedicatedIPServerPing * _Nullable pingedDedicatedServer)) successBlock errorBlock:(void (^_Nonnull)(NSError * _Nullable error)) errorBlock;

/**
 * this method will identify whether the user is eligible to get obfuscated server,
 * it will also update the connection detail properties for vpn obfuscation
 *
 * @return true if user is eligible for obfuscated server otherwise false
 */
- (BOOL) isObfuscatedServerRequired;

- (void) setCustomDomainNames:( NSArray<NSString*> *_Nullable)customDomainNames;
@end
