//
//  AtomConnectionDetails.h
//  AtomSDK
//
//  Copyright © 2017 Atom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AtomEnum.h"

/*!
 * @interface AtomConnectionDetails
 * @discussion The AtomConnectionDetails class manages the connection specific details of the last connection vpn configuration of the session.This class will also be handy in resolving details related to recently dialed connection.
 */
@interface AtomConnectionDetails : NSObject <NSCoding>

/*!
 * @property username
 * @discussion The username with which last connection was made.
 */
@property (nonatomic, strong) NSString * _Nullable username;

/*!
 * @property bandwidth
 * @discussion The bandwidth consumed in the last session.
 */
@property (nonatomic, strong)  NSString * _Nullable bandwidth;

/*!
 * @property sessionDuration
 * @discussion The duration of last session in minutes.
 */
@property (nonatomic, strong)  NSString * _Nullable sessionDuration;

/*!
 * @property country
 * @discussion The name of the country to which the last connection was made.
 */
@property (nonatomic, strong) NSString  * _Nullable country;

/*!
 * @property ipAddress
 * @discussion The IP address assigned in last VPN connection.
 */
@property (nonatomic, strong)  NSString * _Nullable ipAddress;

/*!
 * @property deviceType
 * @discussion The device type is used to represent the device/platform on which the last connected VPN connection was made.
 */
@property (nonatomic, strong) NSString * _Nullable deviceType;

/*!
 * @property serverAddress
 * @discussion The host address at which the VPN connection was established.
 */
@property (nonatomic, strong) NSString * _Nullable serverAddress;

/*!
 * @property fastestServerFindingMethod
 * @discussion The method used to find servers for the last VPN connection.
 */
@property (nonatomic, strong) NSString * _Nullable fastestServerFindingMethod;

/*!
 * @property serverType
 * @discussion Representing the type of server host with which the VPN connection was made.
 */
@property (nonatomic, strong) NSString * _Nullable serverType;

/*!
 * @property protocol
 * @discussion The Protocol of the VPN configuration with which last VPN connection was made.
 */
@property (nonatomic, strong) AtomProtocol * _Nullable protocol;

/*!
 * @property timeTakenToFindFastestServer
 * @discussion The time taken to find fastest server before starting connection to a server.
 */
@property (nonatomic) double timeTakenToFindFastestServer;

/*!
 * @property totalTimeTakenToConnect
 * @discussion The total time taken to connect successfully in seconds.
 */
@property (nonatomic) double totalTimeTakenToConnect;

/*!
 * @property timeTakenToConnectServer
 * @discussion The  time taken to connect successfully in seconds.
 */
@property (nonatomic) double timeTakenToConnectServer;

/*!
 * @property timeElapsedSinceConnect
 * @discussion The  time elapsed since initiating the connection.
 */
@property (nonatomic) double timeElapsedSinceConnect;

/*!
 * @property fastestServerFindingApiResponse
 * @discussion The response of Fastest Server API.
 */
@property (nonatomic, strong) NSMutableDictionary * _Nullable fastestServerFindingApiResponse;

/*!
 * @property connectionMethod
 * @discussion The connection method type used to dialed VPN using ATOM SDK (Params, PSK, Manual)
 */
@property (nonatomic, strong) NSString * _Nullable connectionMethod;

/*!
 * @property connectionType
 * @discussion The connection type define the type of VPN connection using ATOM SDK (Country, City, Channel, Smart Connect, PSK, Manual, Manual With Config)
 */
@property (nonatomic) ConnectionType connectionType;

/*!
 * @property serverIp
 * @discussion The IP address of the server with which VPN Connection is establish.
 */
@property (nonatomic, strong) NSString * _Nullable serverIp;

/*!
 * @property sessionId
 * @discussion The sessionId of the VPN Connection established.
 */
@property (nonatomic, strong) NSString * _Nullable sessionId;

/*!
 * @property clientPublicKey
 * @discussion The clientPublicKey of the VPN Connection established with Wireguard.
 */
@property (nonatomic, strong) NSString * _Nullable clientPublicKey;

/*!
 * @property isDisconnectedManually
 * @discussion Returns true if VPN Connection was disconnected by user otherwise false.
 */
@property (nonatomic) BOOL isDisconnectedManually;

/*!
 * @property disconnectionType
 * @discussion Returns disconnection type (Auto, Manual, Cancelled, CoC).
 */
@property (nonatomic) AtomDisconnectionType disconnectionType;


/*!
 * @property connectionAttempts
 * @discussion The connection attempt tried to establish VPN Connection.
 */
@property (nonatomic) int connectionAttempts;

/*!
 * @property isCancelled
 * @discussion Returns true if VPN Connection was cancelled before Connection is made successfully otherwise false.
 */
@property (nonatomic) BOOL isCancelled;

/*!
 * @property isDialedWithSmartDialing
 * @discussion Returns true if VPN Connection was dialed with Smart Dialing otherwise false.
 */
@property (nonatomic) BOOL isDialedWithSmartDialing;

/*!
 * @property isDialedWithOptimization
 * @discussion Returns true if VPN Connection was dialed with Optimization otherwise false
 */
@property (nonatomic) BOOL isDialedWithOptimization;

/*!
 * @property isLastConnectionWasUTB
 * @discussion Returns true if VPN Connection was dialed but no internet availablilty
 */
@property (nonatomic) BOOL isLastConnectionWasUTB;

/*!
 * @property city
 * @discussion The city to which the last connection was made. The city will be null if not dialed.
 */
@property (nonatomic ,strong) AtomCity * _Nullable city;

/*!
 * @property channel
 * @discussion The channel to which the last connection was made. The channel will be null if not dialed.
 */
@property (nonatomic ,strong) AtomChannel *_Nullable channel;

/*!
 * @property serverFilters
 * @discussion The Server Filters provided by developer.
 */
@property (nonatomic, strong) NSArray<ServerFilter*> * _Nullable serverFilters;

/*!
 * @property nasIdentifier
 * @discussion The nasIdentifier of the connected VPN Server.
 */
@property (nonatomic, strong) NSString * _Nullable nasIdentifier;

/*!
 * @property isFiltered
 * @discussion The isFiltered defines if the filter type is applied from speedtest.
 */
@property (nonatomic) BOOL isFiltered;

/*!
 * @property isUseFailoverEnabled
 * @discussion Returns false if last connection was not dialed with failover server(s)
 */
@property (nonatomic) BOOL isUseFailoverEnabled;

/*!
 * @property isDialedWithQuantumResistantServer
 * @discussion Returns false if last connection was not dialed with QR server
 */
@property (nonatomic) BOOL isDialedWithQuantumResistantServer;

/*!
 * @property IsDialedWithOVPNObfuscatedServer
 * @discussion Returns false if last connection was not dialed with OVPNObfuscatedServer
 */
@property (nonatomic) BOOL IsDialedWithOVPNObfuscatedServer;

/*!
 * @property IsOVPNObfuscatedSupported
 * @discussion Returns true if TAG_OVPN_OBF supported on the specific location
 */
@property (nonatomic) BOOL IsOVPNObfuscatedSupported;

/*!
 * @property experimentProperties
 * @discussion The experimentProperties of the session provided in AtomProperties
 */
@property (nonatomic, strong) AtomExperimentProperties * _Nullable experimentProperties;

/*!
 * @property isExperimentedServer
 * @discussion The isExperimentedServer is true if server is from Experimented server
 */
@property (nonatomic) BOOL isExperimentedServer;

/*!
 * @property ip_translation
 * @discussion The ipTranslation is 0 in case of Non_natted server and 1 in case of Natted
 */
@property (nonatomic) int ipTranslation;

/*!
 * @property isDialedWithNonNatted
 * @discussion The isDialedWithNonNatted is true in case of Non_natted server else false in case of Natted
 */
@property (nonatomic) BOOL isDialedWithNonNatted;

/**
 * Tells if the Tracker Blocker has been requested by the user.
 * - Returns: `true` if the user has requested Tracker Blocker, `false` otherwise.
 */
@property (nonatomic) BOOL isTrackerBlockerRequested;

/**
 * Tells if the Ad Blocker has been requested by the user.
 * - Returns: `true` if the user has requested Ad Blocker, `false` otherwise.
 */
@property (nonatomic) BOOL isAdBlockerRequested;

/**
 * Tells if the VPN is resumed automatically.
 * - Returns: `true` if the VPN is resumed automatically, `false` otherwise.
 */
@property (nonatomic) BOOL isVPNAutoResumed;

/**
 * Controls the timer for pausing the VPN connection.
 * - Returns: The `PauseVPNTimer` object managing the pause duration for the VPN.
 */
@property (nonatomic) PauseVPNTimer pauseVPNTimer;

/**
 * Tells if the Local Network Traffic has been requested by the user.
 * - Returns: `true` if the user has requested Local Network Traffic, `false` otherwise.
 */
@property (nonatomic) BOOL isAllowLocalNetworkTrafficRequested;

@end
