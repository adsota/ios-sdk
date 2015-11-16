//
//  AdsOTASDK.h
//  AdsOTASDK
//
//  Created by Anh Toan on 1/24/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "AdsOTAConstants.h"
#import "AdsOTABannerView.h"
#import "AdsOTARequest.h"
#import "AdsOTARequestError.h"
#import "AdsOTAInterstitial.h"
#import "AdsOTAOfferWall.h"
#import "AdsOTANative.h"


@interface AdsOTASDK : NSObject

/**
 * Call in application:didFinishLaunchingWithOptions
 */
+ (void) init;
+ (id) sharedInstance;
@end