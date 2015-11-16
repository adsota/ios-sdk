//
//  AdsOTAInterstitialDelegate.h
//  Google Mobile Ads SDK
//
//  Copyright 2011 Google Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AdsOTAOfferWall;
@class AdsOTARequestError;

/// Delegate for receiving state change messages from a AdsOTAInterstitial such as interstitial ad
/// requests succeeding/failing.
@protocol AdsOTAOfferWallDelegate <NSObject>

@optional

#pragma mark Ad Request Lifecycle Notifications

/// Called when an interstitial ad request succeeded. Show it at the next transition point in your
/// application such as when transitioning between view controllers.
- (void)adsotaOfferWallDidReceiveAd:(AdsOTAOfferWall *)ad;

/// Called when an interstitial ad request completed without an interstitial to
/// show. This is common since interstitials are shown sparingly to users.
- (void)adsotaOfferWall:(AdsOTAOfferWall *)ad didFailToReceiveAdWithError:(AdsOTARequestError *) error;

#pragma mark Display-Time Lifecycle Notifications

// Ad did click
- (void)adsotaOfferWallDidClick:(AdsOTAOfferWall *)ad;

/// Called just after dismissing an interstitial and it has animated off the screen.
- (void)adsotaOfferWallDidDismissScreen:(AdsOTAOfferWall *)ad;

- (void) adsotaOfferWallDidInstall:(NSArray*) listOffer;
@end
