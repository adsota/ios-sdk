//
//  AppotaADInterstitial.h
//  AppotaAdsFramework
//
//  Created by Tue Nguyen on 6/4/15.
//  Copyright (c) 2015 DB-Interactive. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "AppotaADConstants.h"
#import "AppotaADInterstitialDelegate.h"
#import "AppotaADOfferWallDelegate.h"

@class AppotaADRequest;

@interface AppotaADInterstitial : NSObject

/// Initializes an interstitial with an ad unit created on the Appota website. Create a new ad unit
/// for every unique placement of an ad in your application. Set this to the ID assigned for this
/// placement. Ad units are important for targeting and statistics.
/// Root view controller is required for interstitial ads
- (instancetype)initWithAdUnitID:(NSString *)adUnitID withRootViewController:(UIViewController*) rootViewController;;

#pragma mark Pre-Request

/// Required value passed in with initWithAdUnitID:.
@property(nonatomic, readonly, copy) NSString *adUnitID;
@property (readwrite) AppotaADType adType;

/// Optional delegate object that receives state change notifications from this GADInterstitalAd.
/// Remember to nil this property before deallocating the delegate.
@property(nonatomic, weak) id<AppotaADInterstitialDelegate, AppotaADOfferWallDelegate> delegate;

#pragma mark Making an Ad Request

/// Makes an interstitial ad request. Additional targeting options can be supplied with a request
/// object. Only one interstitial request is allowed at a time.
///
/// This is best to do several seconds before the interstitial is needed to preload its content.

- (void)loadRequest:(AppotaADRequest *) request;

- (BOOL) isReady;
#pragma mark Post-Request

/// Returns YES if the interstitial is ready to be displayed. The delegate's
/// interstitialAdDidReceiveAd: will be called after this property switches from NO to YES.
@property(nonatomic, readonly, assign) BOOL isReady;

/// Returns YES if this object has already been presented. Interstitial objects can only be used
/// once even with different requests.
@property(nonatomic, readonly, assign) BOOL hasBeenUsed;

/// Returns the ad network class name that fetched the current ad. Returns nil while the latest ad
/// request is in progress or if the latest ad request failed. For both standard and mediated Google
/// AdMob ads, this method returns @"GADMAdapterGoogleAdMobAds". For ads fetched via mediation
/// custom events, this method returns @"GADMAdapterCustomEvents".
@property(nonatomic, readonly, copy) NSString *adNetworkClassName;

@property(nonatomic, weak) IBOutlet UIViewController *rootViewController;

/// Presents the interstitial ad which takes over the entire screen until the user dismisses it.
/// This has no effect unless isReady returns YES and/or the delegate's interstitialDidReceiveAd:
/// has been received.
///
/// Set rootViewController to the current view controller at the time this method is called. If your
/// application does not use view controllers pass in nil and your views will be removed from the
/// window to show the interstitial and restored when done. After the interstitial has been removed,
/// the delegate's interstitialDidDismissScreen: will be called.
//- (void)presentFromRootViewController:(UIViewController *)rootViewController;

@end
