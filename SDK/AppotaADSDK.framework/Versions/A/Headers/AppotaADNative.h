//
//  AppotaADNative.h
//  AppotaADSDK
//
//  Created by Tue Nguyen on 7/27/15.
//
//

#import <Foundation/Foundation.h>
#import "AppotaADConstants.h"

@class AppotaADRequest;
@class AppotaADNativeObject;

@interface AppotaADNative : NSObject
+ (void) loadRequest:(AppotaADRequest*) request
 withCompletionBlock:(AppotaADArrayBlock) completionBlock
      withErrorBlock:(AppotaADErrorBlock) errorBlock;

+ (void) click:(AppotaADNativeObject*) adNativeObject withRootViewController:(UIViewController*) rootViewController;
@end
