//
//  AdsOTANative.h
//  AdsOTASDK
//
//  Created by Tue Nguyen on 7/27/15.
//
//

#import <Foundation/Foundation.h>
#import "AdsOTAConstants.h"
#import "AdsOTANativeObject.h"
#import "AdsOTANativeViewObject.h"
#import "AdsOTANativeInterstitialObject.h"
#import "AdsOTANativeOfferWallObject.h"

@class AdsOTARequest;
@class AdsOTANativeObject;

@interface AdsOTANative : NSObject
+ (void) loadRequest:(AdsOTARequest*) request
 withCompletionBlock:(AdsOTAArrayBlock) completionBlock
      withErrorBlock:(AdsOTAErrorBlock) errorBlock;

+ (void) click:(AdsOTANativeObject*) adNativeObject withRootViewController:(UIViewController*) rootViewController;
@end
