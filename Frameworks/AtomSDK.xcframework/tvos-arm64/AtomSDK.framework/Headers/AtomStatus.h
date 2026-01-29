//
//  AtomStatus.h
//  AtomSDK
//
//  Copyright © 2017 Atom. All rights reserved.
//

#ifndef AtomStatus_h
#define AtomStatus_h

/*!
 * @typedef AtomVPNStatus
 * @abstract AtomVPN status codes
 */

typedef NS_ENUM (NSInteger, AtomVPNState) {
    
    /// The VPN is not configured.
    AtomStatusInvalid,
    
    /// The VPN is disconnected.
    AtomStatusDisconnected,
    
    /// The VPN is connecting.
    AtomStatusConnecting,
    
    /// The VPN is connected.
    AtomStatusConnected,
    
    /// The VPN is reconnecting following a loss of underlying network connectivity.
    AtomStatusReasserting,
    
    /// The VPN is disconnecting.
    AtomStatusDisconnecting,
    
    /// The VPN is validating.
    AtomStatusValidating,
    
    /// The VPN is generating credentials.
    AtomStatusGeneratingCredentials,
    
    /// The VPN is getting the fastest server.
    AtomStatusGettingFastestServer,
    
    /// The VPN is optimizing the connection.
    AtomStatusOptimizingConnection,
    
    /// The VPN is verifying the host name.
    AtomStatusVerifyingHostName,
    
    /// The VPN is authenticating.
    AtomStatusAuthenticating,
    
    /// The VPN is checking internet connectivity.
    AtomStatusInternetChecking,
    
    /// The VPN is pausing.
    AtomStatusPausing,
    
    /// The VPN is paused.
    AtomStatusPaused
};
typedef void (^StateDidChangedHandler)(AtomVPNState status);

typedef NS_ENUM (NSInteger, AtomVPNStatus) {
    /// The VPN is disconnected.
    DISCONNECTED,
    
    /// The VPN is disconnecting.
    DISCONNECTING,
    
    /// The VPN is connecting.
    CONNECTING,
    
    /// The VPN is connected.
    CONNECTED,
    
    /// The VPN is pausing.
    PAUSING,
    
    /// The VPN is paused.
    PAUSED
};

typedef void (^OnPacketsTransmitted)(NSNumber *bytesReceived , NSNumber *bytesSent);

#endif /* AtomStatus_h */
