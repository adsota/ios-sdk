//
//  AppotaADRequestError.h
//  AppotaADSDK
//
//  Created by Tue Nguyen on 6/12/15.
//
//

#import <Foundation/Foundation.h>

/// Google AdMob Ads error domain.
extern NSString *const kAppotaADErrorDomain;

/// NSError codes for AppotaAD error domain.
typedef NS_ENUM(NSInteger, AppotaADErrorCode) {
    /// The ad request is invalid
    kAppotaADErrorInvalidRequest,
    
    // The ad request session's not created
    kAppotaADErrorNoSession,
    
    /// The ad request was successful, but no ad was returned.
    kAppotaADErrorNoAD,
    
    // Interstitial will not be shown without rootViewController
    kAppotaADErrorNoRootViewController,
    
    // Ad type not match
    kAppotaErrorAdTypeNotMatch,
    
    /// There was an error loading data from the network.
    kAppotaADErrorNetworkError,
    
    /// The ad server experienced a failure processing the request.
    kAppotaADErrorServerError,
    
    /// The current device's OS is below the minimum required version.
    kAppotaADErrorOSVersionTooLow,
    
    /// The request was unable to be loaded before being timed out.
    kAppotaADErrorTimeout,
    
    /// Will not send request because the interstitial object has already been used.
    kAppotaADErrorInterstitialAlreadyUsed,
    
    /// Internal error.
    kAppotaADErrorInternalError,
    
    /// Invalid argument error.
    kAppotaADErrorInvalidArgument,
    
    /// Received invalid response.
    kAppotaADErrorReceivedInvalidResponse
};

@interface AppotaADRequestError : NSError
+ (AppotaADRequestError*) errorWithCode:(AppotaADErrorCode) errorCode;
+ (AppotaADRequestError*) errorWithCode:(AppotaADErrorCode) errorCode withUserInfo:(NSDictionary*) info;
@end
