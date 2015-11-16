//
//  AdsOTAInterstitialDelegate.h
//  Google Mobile Ads SDK
//
//  Copyright 2011 Google Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AdsOTAInterstitial;
@class AdsOTARequestError;

/// Delegate for receiving state change messages from a AdsOTAInterstitial such as interstitial ad
/// requests succeeding/failing.
@protocol AdsOTAInterstitialDelegate<NSObject>

@optional

#pragma mark Ad Request Lifecycle Notifications

/// Called when an interstitial ad request succeeded. Show it at the next transition point in your
/// application such as when transitioning between view controllers.
- (void)adsotaInterstitialDidReceiveAd:(AdsOTAInterstitial *)ad;

/// Called when an interstitial ad request completed without an interstitial to
/// show. This is common since interstitials are shown sparingly to users.
- (void)adsotaInterstitial:(AdsOTAInterstitial *)ad didFailToReceiveAdWithError:(AdsOTARequestError *)error;

#pragma mark Display-Time Lifecycle Notifications

// Ad did click
- (void)adsotaInterstitialDidClick:(AdsOTAInterstitial *)ad;

/// Called just after dismissing an interstitial and it has animated off the screen.
- (void)adsotaInterstitialDidDismissScreen:(AdsOTAInterstitial *)ad;

@end
