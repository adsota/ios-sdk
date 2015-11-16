//
//  AdsOTARequest.h
//  AdsOTASDK
//
//  Created by Tue Nguyen on 6/11/15.
//
//

#import <Foundation/Foundation.h>
#import "AdsOTAConstants.h"

@interface AdsOTARequest : NSObject<NSCopying>
@property (nonatomic, strong) NSString *state;
@property (nonatomic, strong) NSString *target;
@property (nonatomic, strong) NSString *adUnitID;
@property (readwrite) AdsOTAType adType;
@property (readwrite) BOOL isDevelopmentMode;

/// Returns a default request.
+ (instancetype)request;

#pragma mark Collecting SDK Information

/// Returns the version of the SDK.
+ (NSString *)sdkVersion;

@end
