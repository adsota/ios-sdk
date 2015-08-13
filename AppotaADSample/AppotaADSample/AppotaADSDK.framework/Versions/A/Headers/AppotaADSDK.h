//
//  AppotaSDK.h
//  AppotaSDK
//
//  Created by Anh Toan on 1/24/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "AppotaADConstants.h"
#import "AppotaADBannerView.h"
#import "AppotaADRequest.h"
#import "AppotaADRequestError.h"
#import "AppotaADInterstitial.h"
#import "AppotaADOfferWall.h"
#import "AppotaADNative.h"


@interface AppotaADSDK : NSObject

/**
 * Call in application:didFinishLaunchingWithOptions
 */
+ (void) init;

@end