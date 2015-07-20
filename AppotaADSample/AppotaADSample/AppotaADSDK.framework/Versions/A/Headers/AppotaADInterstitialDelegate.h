//
//  AppotaADInterstitialDelegate.h
//  Google Mobile Ads SDK
//
//  Copyright 2011 Google Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AppotaADInterstitial;
@class AppotaADRequestError;

/// Delegate for receiving state change messages from a AppotaADInterstitial such as interstitial ad
/// requests succeeding/failing.
@protocol AppotaADInterstitialDelegate<NSObject>

@optional

#pragma mark Ad Request Lifecycle Notifications

/// Called when an interstitial ad request succeeded. Show it at the next transition point in your
/// application such as when transitioning between view controllers.
- (void)interstitialDidReceiveAd:(AppotaADInterstitial *)ad;

/// Called when an interstitial ad request completed without an interstitial to
/// show. This is common since interstitials are shown sparingly to users.
- (void)interstitial:(AppotaADInterstitial *)ad didFailToReceiveAdWithError:(AppotaADRequestError *)error;

#pragma mark Display-Time Lifecycle Notifications

// Ad did click
- (void)interstitialDidClick:(AppotaADInterstitial *)ad;

/// Called just after dismissing an interstitial and it has animated off the screen.
- (void)interstitialDidDismissScreen:(AppotaADInterstitial *)ad;

@end
