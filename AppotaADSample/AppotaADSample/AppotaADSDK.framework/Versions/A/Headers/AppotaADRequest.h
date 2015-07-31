//
//  AppotaADRequest.h
//  AppotaADSDK
//
//  Created by Tue Nguyen on 6/11/15.
//
//

#import <Foundation/Foundation.h>
#import "AppotaADConstants.h"

@interface AppotaADRequest : NSObject<NSCopying>
@property (nonatomic, strong) NSString *state;
@property (nonatomic, strong) NSString *target;
@property (nonatomic, strong) NSString *adUnitID;
@property (readwrite) AppotaADType adType;
@property (readwrite) BOOL isDevelopmentMode;

/// Returns a default request.
+ (instancetype)request;

#pragma mark Collecting SDK Information

/// Returns the version of the SDK.
+ (NSString *)sdkVersion;

@end
