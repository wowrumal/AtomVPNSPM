//
//  AtomSDKErrorHeader.h
//  AtomSDK
//
//  Created by Atom on 03/05/2017.
//  Copyright © 2017 Atom By Secure. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef AtomSDKErrorHeader_h
#define AtomSDKErrorHeader_h

typedef NS_ENUM(NSInteger, AtomSDKErrorCode) {
    AtomSDKErrorValidateUUIDorCredentialMissing             = 5006,     // Username and Password must not be null or empty
    AtomSDKErrorValidateUUIDEmptyAndCredentialMissing       = 5008,     // UUID empty and credentials missing
    AtomSDKErrorValidateSourceMissing                       = 5009,     // PSK cityId and protocolId not provided
    AtomSDKErrorValidateAtomPropertiesInvalid               = 5010,     // Invalid VPNProperties
    AtomSDKErrorGetFastestUnableToGetSpeedTest              = 5012,     // Unable to get speedtest response (General speedtest error)
    AtomSDKErrorGetFastestUnableToParseSpeedTest            = 5013,     // Unable to parse speedtest response
    AtomSDKErrorGetFastestEmptyServers                      = 5014,     // Unable to establish connection. No server available for dialing
    AtomSDKErrorGetFastestRequestFailed                     = 5015,     // Request to get fastest server failed
    AtomSDKErrorSomethingWentWrong                          = 5029,     // Something went wrong
    AtomSDKErrorGetFastestUserAccountIsExpired              = 5059,     // User account has expired
    AtomSDKErrorGetFastestUserAccountIsDisabled             = 5060,     // User account is disabled
    AtomSDKErrorGetFastestUserNotFound                      = 5066,     // User not found
    AtomSDKErrorGetCountriesFailed                          = 5056,     // Unable to get countries
    AtomSDKErrorDedicatedIpNotAllowedForUser                = 5030,     // Dedicated IP not allowed to user
    AtomSDKErrorUnableToGenerateCredentials                 = 5034,     // Unable to generate vpn credentials
    AtomSDKErrorEmptyCountry                                = 5035,     // Country is null or invalid
    AtomSDKErrorEmptyProtocol                               = 5036,     // Protocol is null or invalid
    AtomSDKErrorVPNAuthenticationFailed                     = 5038,     // VPN Authentication failed
    AtomSDKErrorInternetConnectionFailed                    = 5041,     // No Internet Connection
    AtomSDKErrorProtocolNotSupported                        = 5042,     // Protocol Not Supported
    AtomSDKErrorVPNAlreadyConnected                         = 5043,     // Vpn Connection already established
    AtomSDKErrorConnectionDetailsNotFound                   = 5044,     // No connection details found for this session.
    AtomSDKErrorUnableToGetOptimizedCountries               = 5069,     // Unable to get Optimized countries
    AtomSDKErrorUnableToGetProtocols                        = 5068,     // Unable to get protocols
    AtomSDKErrorProtocolNotAllowedToReseller                = 5061,     // Protocol not allowed to reseller
    AtomSDKErrorVPNGeneralError                             = 5040,     // VPN general error
    AtomSDKErrorUnableToGetCities                           = 5055,     // Unable to get Cities
    AtomSDKErrorUnableToGetChannels                         = 5093,     // Unable to get Channels
    AtomSDKErrorAtomConfigurationIsNil                      = 5067,     // Atom Configuration is empty
    AtomSDKErrorAtomInvalidPSK                              = 5071,     // Invalid or empty PSK
    AtomSDKErrorReconnectFailedDueToNoPriorConnection       = 5062,     // Reconnection failed because of no prior connection made
    AtomSDKErrorAtomConfigurationIsNull                     = 5067,     // AtomConfiguration is null
    AtomSDKErrorInvalidDedicatedHostname                    = 5070,     // Dedicated host name is not valid
    AtomSDKErrorJsonParsingError                            = 5074,     // Json parsing error
    AtomSDKErrorCountryNotAllowed                           = 5075,     // Provided country not allowed from given country list.
    AtomSDKErrorCityNotAllowed                              = 5092,     // Provided country not allowed from given city list
    
    AtomSDKErrorChannelNotAllowed                           = 5094,     // Provided channel not allowed from given city list
    
    AtomSDKErrorSmartDNSAgainstProtocol                     = 5076,      // No Smart DNS available against the Protocol
    AtomSDKErrorLoginLimitForSessionExceeded                = 5077,      // Login Limit Exceed
    AtomSDKErrorSessionLimitForSessionExceeded              = 5078,      // Session Limit Exceed
    AtomSDKErrorUnableToGetDataCenters                      = 5054,
    AtomSDKErrorConfigurationIsNil                          = 5084,      //Configuration is missing
    AtomSDKErrorUnableToValidateDedicatedHost               = 5085,      //Unable to get Configuration for Dedicated Host
    AtomSDKErrorProvidedDNSMismatchingConfiguration         = 5086,      //DNS and Provided configuration are mismatching
    AtomSDKErrorFailToParseOVPNConfiguration                = 5087,      //Failed to parse OVPN configuration
    AtomSDKErrorChannelisNull                               = 5088,      // Invalid Channel
    AtomSDKErrorCityisNull                                  = 5089,      // Invalid City
    AtomSDKErrorInvalidSmartConnectTag                      = 5095,      // Invalid Smart Connect Tag
    AtomSDKErrorNoSmartConnectDNS                           = 5096,      // No Smart Connect DNS found for dailing
    AtomSDKErrorUnableToBrowse                              = 5097,       // Unable to Browse
    AtomSDKErrorNoQRServerAvailable                         = 5098,       // No Quantam Resistant Servers available at this moment
    AtomSDKErrorVPNNotConnectedToGetConnectedCountry        = 5102,       // VPN is not connected for connected country
    AtomSDKErrorUnableToGetConnectedLocation                = 5103,       // Unable to get Connected Country
    AtomSDKErrorVPNProfilePermissionDenied                  = 5028,        //Unable to install VPN Profile due to permission denied
    
    AtomSDKErrorVPNAlreadyConnecting                        = 5104,     // Vpn connection is in connecting state

    AtomSDKErrorRecommendedCountryDueToVPNState             = 5113,     // VPN is not in disconnected state.
    AtomSDKErrorUnableToGetRecommendedCountry               = 5114,     // Unable to get recommended country.
    
    AtomSDKErrorInvalidNASIdentifier                        = 5115,     // Invalid NAS Identifier.

    AtomSDKErrorUnableToGetVirtualCountries                 = 5116,     // Unable to Get Virtual Countries
    AtomSDKErrorUnableToGetPhysicalCountries                = 5117,     // Unable to Get Physical Countries
    AtomSDKErrorUnableToFindRecommendedProtocol             = 5118,     // Unable to Recommended Protocol
    AtomSDKErrorProtocolNotAvailableOrNotAllowed            = 5124,     // Protocol not allowed or not available
    AtomSDKErrorInvalidDedicatedIPServer                    = 5126,        // Invalid Dedicated IP Server
    AtomSDKErrorUnbableToPingDedicatedIPServer              = 5127,        // Invalid Dedicated IP Server
    AtomSDKErrorConnectionOverConnectionInProgress          = 5129,     // Connection is already in progress
    AtomSDKErrorSystemExtensionIsNotInstalled               = 5136,     // System Extension is not Installed
    AtomSDKErrorWireguardConfigurationNotFound              = 5130,     // Wireguard Configuration not found
    AtomSDKErrorWireGuardKeyPairGenerationFailed            = 5125,     // Failed to create keypair for wireguard
    
    /// Dedicated DNS collection should not be empty
    AtomSDKErrorDedicatedDNSCollectionNullOrEmpty = 5138,
    
    /// Invalid Dedicated DNS
    AtomSDKErrorDedicatedDNSNullOrEmpty = 5139,
    
    /// Selected protocol is invalid
    AtomSDKErrorDedicatedIPSelectedProtocolIsInvalid = 5202,
    
    /// Invalid Dedicated IP
    AtomSDKErrorDedicatedIPNullOrEmpty = 5203,
    
    /// Unable to establish connection. Password is invalid
    AtomSDKErrorInvalidPasswordProvided = 5173,
    
    // MARK: - Tracker Blocker Errors START
    
    /// AtomShield feature can not be null or empty
    AtomSDKErrorAtomShieldNullOrEmpty = 5177,
    
    /// Connection type does not support tracker blocker
    AtomSDKErrorAtomShieldConnectionTypeNotSupported = 5179,
    
    /// Unable to establish tracker blocker connection, please see inner exception
    AtomSDKErrorAtomShieldUnableToEstablishTrackerBlockerConnection = 5180,
    
    /// Unable to make request to tracker blocker server, please see inner exception
    AtomSDKErrorAtomShieldUnableToMakeRequestToTrackerBlockerServer = 5181,
    
    /// Unable to enable tracker blocker connection
    AtomSDKErrorAtomShieldUnableToEnableTrackerBlockerConnection = 5182,
    
    /// Unable to get the tracker blocker stats
    AtomSDKErrorAtomShieldUnableToGetTheTrackerBlockerStats = 5183,
    
    // MARK: - Tracker Blocker Errors END
    
    
    /// Private Key or Public Key not found in configuration
    AtomSDKErrorWireGuardKeyPairNotFound = 5189,
    
    
    // MARK: - Pause VPN Errors START
    
    /// Unable to resume, the VPN connection is not in a paused state
    AtomSDKErrorUnableToResumeVPNIsNotPaused = 5194,
    
    /// Unable to pause, the VPN connection is not in a connected state
    AtomSDKErrorUnableToPauseVPNIsNotConnected = 5195,
    
    /// Unable to pause, connected protocol is not supported
    AtomSDKErrorUnableToPauseProtocolNotSupported = 5197,
    
    /// Unable to pause, the VPN connection is not in a connected state
    AtomSDKErrorVPNisAlreadyPaused = 5198,
    
    /// Exception occured when trying to Pause/Resume connection while tunnel connection is not valid.
    AtomSDKErrorTunnelInvalidTunnelConnection = 5199,
    
    /// Exception occured when trying to Pause/Resume connection while no response occurred.
    AtomSDKErrorTunnelNoResponse = 5200,
    
    /// Exception occured when trying to Pause/Resume connection while invalid response occurred.
    AtomSDKErrorTunnelInvalidResponse = 5201
    
    // MARK: - Pause VPN Errors END
};


#define kAtom_Error_Message_VPN_Connection_Failed               @"VPN Connection failed."

#endif /* AtomSDKErrorHeader_h */
