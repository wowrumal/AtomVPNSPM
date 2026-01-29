//
//  AtomOnDemandConfiguration.h
//  AtomSDK
//
//  Created by Atom By Secure on 26/02/2019.
//

#import <Foundation/Foundation.h>

@interface AtomOnDemandConfiguration : NSObject

/*!
 @abstract
 If set to YES, alwaysOnEnable or connectOnDemandMatchDomains rules will be applied. Default value is NO.
 */
@property (nonatomic, assign) BOOL onDemandRulesEnabled;

/*!
@abstract
 Toggles VPN Always On feature. If true VPN connection establishes automatically when connected with stable internet. Default is NO.
 */
@property (nonatomic, assign) BOOL alwaysOnEnable;

/*!
 * @property alwaysOnType
 * @discussion AlwaysOn is enabled if alwaysOnEnable is set to true with default value of alwaysOnType to AlwaysOnAny
*/
@property (nonatomic, assign) AtomOnDemandRuleInterfaceType alwaysOnType;

/*!
 * @property connectOnDemandMatchDomains
 * @discussion An array of web domain objects. e.g: www.domainname.com
 */
@property (nonatomic, strong) NSArray *connectOnDemandMatchDomains;


/*!
 * @property unTrustedWifi
 * @discussion Connect VPN when WiFi is connected to list of provided SSID(s)
 */
@property (nonatomic, strong) NSArray *unTrustedWifi;

/*!
 * @property trustedWifi
 * @discussion Disconnect VPN when WiFi is connected to list of provided SSID(s)
 */
@property (nonatomic, strong) NSArray *trustedWifi;

/*!
 * @property isOnDemandCustomRulesEnabled
 * @discussion A boolean flag that enables or disables the use of custom On-Demand VPN rules.
 * When set to YES, the SDK will apply the rules provided in `OnDemandCustomRules`.
 */
@property (nonatomic, assign) BOOL isOnDemandCustomRulesEnabled;

/*!
 * @property OnDemandCustomRules
 * @discussion An array of AtomOnDemandRule objects representing custom On-Demand VPN rules.
 * These rules are applied automatically by the SDK when `isOnDemandCustomRulesEnabled` is set to YES.
 */
@property (nonatomic, strong) NSArray *OnDemandCustomRules;


@end
