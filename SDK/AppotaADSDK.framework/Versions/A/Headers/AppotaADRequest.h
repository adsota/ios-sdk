//
//  AppotaADRequest.h
//  AppotaADSDK
//
//  Created by Tue Nguyen on 6/11/15.
//
//

#import <Foundation/Foundation.h>

@interface AppotaADRequest : NSObject<NSCopying>
@property (nonatomic, strong) NSString *state;
@property (nonatomic, strong) NSString *target;

/// Returns a default request.
+ (instancetype)request;

#pragma mark Collecting SDK Information

/// Returns the version of the SDK.
+ (NSString *)sdkVersion;

@end
