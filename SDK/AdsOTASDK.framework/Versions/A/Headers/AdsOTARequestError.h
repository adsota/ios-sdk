//
//  AdsOTARequestError.h
//  AdsOTASDK
//
//  Created by Tue Nguyen on 6/12/15.
//
//

#import <Foundation/Foundation.h>

/// Google AdMob Ads error domain.
extern NSString *const kAdsOTAErrorDomain;

/// NSError codes for AdsOTA error domain.
typedef NS_ENUM(NSInteger, AdsOTAErrorCode) {
    /// The ad request is invalid
    kAdsOTAErrorInvalidRequest,
    
    // The ad request session's not created
    kAdsOTAErrorNoSession,
    
    /// The ad request was successful, but no ad was returned.
    kAdsOTAErrorNoAD,
    
    // Interstitial will not be shown without rootViewController
    kAdsOTAErrorNoRootViewController,
    
    // Ad type not match
    kAdsOTAErrorAdTypeNotMatch,
    
    /// There was an error loading data from the network.
    kAdsOTAErrorNetworkError,
    
    /// The ad server experienced a failure processing the request.
    kAdsOTAErrorServerError,
    
    /// The current device's OS is below the minimum required version.
    kAdsOTAErrorOSVersionTooLow,
    
    /// The request was unable to be loaded before being timed out.
    kAdsOTAErrorTimeout,
    
    /// Will not send request because the interstitial object has already been used.
    kAdsOTAErrorInterstitialAlreadyUsed,
    
    /// Internal error.
    kAdsOTAErrorInternalError,
    
    /// Invalid argument error.
    kAdsOTAErrorInvalidArgument,
    
    /// Received invalid response.
    kAdsOTAErrorReceivedInvalidResponse
};

@interface AdsOTARequestError : NSError
+ (AdsOTARequestError*) errorWithCode:(AdsOTAErrorCode) errorCode;
+ (AdsOTARequestError*) errorWithCode:(AdsOTAErrorCode) errorCode withUserInfo:(NSDictionary*) info;
@end
