//
//  AtomEnum.h
//  AtomSDK
//
//  Created by Atom on 11/06/2020.
//  Copyright © 2020 AtomSDK. All rights reserved.
//

#ifndef AtomEnum_h
#define AtomEnum_h


typedef NS_ENUM(NSInteger, ConnectionType) {
    /*! @const None */
    Undefined API_AVAILABLE(macos(10.11), ios(11.0), tvos(17.0)) API_UNAVAILABLE(watchos) = 0,
    /*! @const None */
    Reconnect API_AVAILABLE(macos(10.11), ios(11.0), tvos(17.0)) API_UNAVAILABLE(watchos) = 1,
    /*! @const PSK */
    PSK API_AVAILABLE(macos(10.11), ios(11.0), tvos(17.0)) API_UNAVAILABLE(watchos) = 2,
    /*! @const Country */
    Country API_AVAILABLE(macos(10.11), ios(11.0), tvos(17.0)) API_UNAVAILABLE(watchos) = 3,
    /*! @const City */
    City API_AVAILABLE(macos(10.11), ios(11.0), tvos(17.0)) API_UNAVAILABLE(watchos) = 4,
    /*! @const Channel */
    Channel API_AVAILABLE(macos(10.11), ios(11.0), tvos(17.0)) API_UNAVAILABLE(watchos) = 5,
    /*! @const SmartConnects */
    SmartConnects API_AVAILABLE(macos(10.11), ios(11.0), tvos(17.0)) API_UNAVAILABLE(watchos) = 6,
    /*! @const Manual */
    Manual API_AVAILABLE(macos(10.11), ios(11.0), tvos(17.0)) API_UNAVAILABLE(watchos) = 7,
    /*! @const ManualWithConfig */
    ManualWithConfig API_AVAILABLE(macos(10.11), ios(11.0), tvos(17.0)) API_UNAVAILABLE(watchos) = 8,
} API_AVAILABLE(macos(10.11), ios(11.0), tvos(17.0)) API_UNAVAILABLE(watchos);


typedef NS_ENUM(NSInteger, FilterType) {
    /*! @const INCLUDE */
    INCLUDE API_AVAILABLE(macos(10.11), ios(11.0), tvos(17.0)) API_UNAVAILABLE(watchos) = 0,
    /*! @const EXCLUDE */
    EXCLUDE API_AVAILABLE(macos(10.11), ios(11.0), tvos(17.0)) API_UNAVAILABLE(watchos) = 1
} API_AVAILABLE(macos(10.11), ios(11.0), tvos(17.0)) API_UNAVAILABLE(watchos);
    
/*!
 * @typedef AtomOnDemandRuleInterfaceType
 * @abstract On Demand rule network interface types
 */
typedef NS_ENUM(NSInteger, AtomOnDemandRuleInterfaceType) {
    /*! @const AtomOnDemandRuleInterfaceTypeAny */
    Any API_AVAILABLE(macos(10.11), ios(11.0), tvos(17.0)) API_UNAVAILABLE(watchos) = 0,
    /*! @const AtomOnDemandRuleInterfaceTypeEthernet Wired Ethernet */
    Ethernet API_AVAILABLE(macos(10.11), tvos(17.0)) API_UNAVAILABLE(ios, watchos) = 1,
    /*! @const AtomOnDemandRuleInterfaceTypeWiFi WiFi */
    WiFi API_AVAILABLE(macos(10.11), ios(11.0), tvos(17.0)) API_UNAVAILABLE(watchos) = 2,
    /*! @const AtomOnDemandRuleInterfaceTypeCellular Cellular */
    Cellular API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(macos, watchos, tvos) = 3,
} API_AVAILABLE(macos(10.11), ios(11.0), tvos(17.0)) API_UNAVAILABLE(watchos);

/*!
 * @typedef AtomDisconnectionType
 * @abstract VPN Disconnection type
 */
typedef NS_ENUM(NSInteger, AtomDisconnectionType) {
    /*! @const None */
    None API_AVAILABLE(macos(10.11), ios(11.0), tvos(17.0)) API_UNAVAILABLE(watchos) = 0,
    /*! @const ManualDisconnect */
    ManualDisconnect API_AVAILABLE(macos(10.11), ios(11.0), tvos(17.0)) API_UNAVAILABLE(watchos) = 1,
    /*! @const CoCDisconnected */
    CoCDisconnect API_AVAILABLE(macos(10.11), ios(11.0), tvos(17.0)) API_UNAVAILABLE(watchos) = 2,
    /*! @const AutoDisconnect */
    AutoDisconnect API_AVAILABLE(macos(10.11), ios(11.0), tvos(17.0)) API_UNAVAILABLE(watchos) = 3,
    /*! @const Cancelled */
    Cancel API_AVAILABLE(macos(10.11), ios(11.0), tvos(17.0)) API_UNAVAILABLE(watchos) = 4
} API_AVAILABLE(macos(10.11), ios(11.0), tvos(17.0)) API_UNAVAILABLE(watchos);

/*!
 * @abstract Enum representing features supported by AtomShield.
 */
typedef NS_ENUM(NSUInteger, AtomShieldFeature) {
    
    /*!
     * @const `TRACKER`
     * @field Provide user privacy by blocking or restricting the functionality of tracking techniques, such as cookies, scripts, or pixels, employed by websites and online advertisers.
     */
    TRACKER API_AVAILABLE(macos(10.11), ios(11.0), tvos(17.0)) API_UNAVAILABLE(watchos) = 0,
    
    /*!
     * @const `AD_BLOCKER`
     * @field Enables ad blocker functionality to prevent advertisements from being displayed or loaded on web pages and applications.
     */
    AD_BLOCKER API_AVAILABLE(macos(10.11), ios(11.0), tvos(17.0)) API_UNAVAILABLE(watchos) = 1
} API_AVAILABLE(macos(10.11), ios(11.0), tvos(17.0)) API_UNAVAILABLE(watchos);

/*!
 * @abstract Enum defining various statuses for AtomShield.
 */
typedef NS_ENUM(NSUInteger, AtomShieldStatus) {
    
    /*!
     * @const AtomShieldEstablishing
     * @field Indicating that AtomShield is in the process of establishing.
     */
    AtomShieldEstablishing API_AVAILABLE(macos(10.11), ios(11.0), tvos(17.0)) API_UNAVAILABLE(watchos) = 0,
    
    /*!
     * @const AtomShieldEstablished
     * @field Indicating that AtomShield has been successfully established.
     */
    AtomShieldEstablished API_AVAILABLE(macos(10.11), ios(11.0), tvos(17.0)) API_UNAVAILABLE(watchos) = 1,
    
    /*!
     * @const AtomShieldError
     * @field Indicating an error in AtomShield.
     */
    AtomShieldError API_AVAILABLE(macos(10.11), ios(11.0), tvos(17.0)) API_UNAVAILABLE(watchos) = 2,
    
    /*!
     * @const AtomShieldDisconnected
     * @field Indicating that AtomShield is disconnected.
     */
    AtomShieldDisconnected API_AVAILABLE(macos(10.11), ios(11.0), tvos(17.0)) API_UNAVAILABLE(watchos) = 3
} API_AVAILABLE(macos(10.11), ios(11.0), tvos(17.0)) API_UNAVAILABLE(watchos);

/*!
 * @abstract Enum defining various timers for PauseVPNTimer.
 */
typedef NS_ENUM(NSUInteger, PauseVPNTimer) {
    
    /*!
     * @const `MANUAL`
     * @field Pauses VPN, resume manually.
     */
    //MANUAL API_AVAILABLE(macos(10.11), ios(11.0), tvos(17.0)) API_UNAVAILABLE(watchos) = 0,
    
    /*!
     * @const `MINUTES_5`
     * @field Pauses VPN for 5 minutes.
     */
    MINUTES_5 API_AVAILABLE(macos(10.11), ios(11.0), tvos(17.0)) API_UNAVAILABLE(watchos) = 1,
    
    /*!
     * @const `MINUTES_10`
     * @field Pauses VPN for 10 minutes.
     */
    MINUTES_10 API_AVAILABLE(macos(10.11), ios(11.0), tvos(17.0)) API_UNAVAILABLE(watchos) = 2,
    
    /*!
     * @const `MINUTES_15`
     * @field Pauses VPN for 15 minutes.
     */
    MINUTES_15 API_AVAILABLE(macos(10.11), ios(11.0), tvos(17.0)) API_UNAVAILABLE(watchos) = 3,
    
    /*!
     * @const `MINUTES_20`
     * @field Pauses VPN for 20 minutes.
     */
    MINUTES_20 API_AVAILABLE(macos(10.11), ios(11.0), tvos(17.0)) API_UNAVAILABLE(watchos) = 4
} API_AVAILABLE(macos(10.11), ios(11.0), tvos(17.0)) API_UNAVAILABLE(watchos);

#endif /* AtomEnum_h */
