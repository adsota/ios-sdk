//
//  AdsOTABannerViewDelegate.h
//  AdsOTASDK
//
//  Created by Tue Nguyen on 6/12/15.
//
//

#import <Foundation/Foundation.h>

@class AdsOTABannerView;
@class AdsOTARequestError;

/// Delegate for receiving state change messages from a AdsOTAView such as ad requests
/// succeeding/failing or when an ad has been clicked.
@protocol AdsOTABannerViewDelegate<NSObject>

@optional

#pragma mark Ad Request Lifecycle Notifications


/// Called when an ad request loaded an ad. This is a good opportunity to add this view to the
/// hierarchy if it has not been added yet. If the ad was received as a part of the server-side auto
/// refreshing, you can examine the hasAutoRefreshed property of the view.
- (void)adsotaAdViewDidReceiveAd:(AdsOTABannerView *) view;

/// Called when an ad request failed. Normally this is because no network connection was available
/// or no ads were available (i.e. no fill). If the error was received as a part of the server-side
/// auto refreshing, you can examine the hasAutoRefreshed property of the view.
- (void)adsotaAdView:(AdsOTABannerView *)view didFailToReceiveAdWithError:(AdsOTARequestError *)error;

#pragma mark Click-Time Lifecycle Notifications

/// Called just before presenting the user a full screen view, such as a browser, in response to
/// clicking on an ad. Use this opportunity to stop animations, time sensitive interactions, etc.
///
/// Normally the user looks at the ad, dismisses it, and control returns to your application by
/// calling adViewDidDismissScreen:. However if the user hits the Home button or clicks on an App
/// Store link your application will end. On iOS 4.0+ the next method called will be
/// applicationWillResignActive: of your UIViewController
/// (UIApplicationWillResignActiveNotification). Immediately after that adViewWillLeaveApplication:
/// is called.
- (void)adsotaAdViewDidClick:(AdsOTABannerView *)adView;

@end
