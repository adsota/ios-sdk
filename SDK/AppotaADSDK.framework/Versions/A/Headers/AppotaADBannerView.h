//
//  AppotaAdView.h
//  AppotaAdsFramework
//
//  Created by Tue Nguyen on 6/2/15.
//  Copyright (c) 2015 DB-Interactive. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AppotaADRequest.h"
#import "AppotaADBannerViewDelegate.h"

@interface AppotaADBannerView : UIView
#pragma mark Initialization

/// Initializes a AppotaADBannerView and sets it to the specified size, and specifies its placement
/// within its superview bounds. Returns nil if |adSize| is an invalid ad size.
- (instancetype)initWithAdSize:(CGSize)adSize origin:(CGPoint)origin;

/// Initializes a AppotaADBannerView and sets it to the specified size, and specifies its placement at
/// the top left of its superview. Returns nil if |adSize| is an invalid ad size.
- (instancetype)initWithAdSize:(CGSize) adSize;

#pragma mark Pre-Request

/// Required value created on the AdsOTA website. Create a new ad campaign. Ad campaign are
/// important for targeting and statistics.
///
@property(nonatomic, copy) IBInspectable NSString *adUnitID;

/// Required reference to the current root view controller. For example the root view controller in
/// tab-based application would be the UITabViewController. Remember to nil or update this property
/// before deallocating the view controller.
@property(nonatomic, weak) IBOutlet UIViewController *rootViewController;

/// Required to set this banner view to a proper size. Never create your own AppotaADAdSize directly. Use
/// one of the predefined standard ad sizes (such as kAppotaADAdSizeBanner), or create one using the
/// AppotaADAdSizeFromCGSize method. If not using mediation, then changing the adSize after an ad has
/// been shown will cause a new request (for an ad of the new size) to be sent. If using mediation,
/// then a new request may not be sent.
@property(nonatomic, assign) CGSize adSize;

/// Optional delegate object that receives state change notifications from this AppotaADBannerView.
/// Typically this is a UIViewController. Remember to nil this property before deallocating the
/// delegate.
@property(nonatomic, weak) IBOutlet id<AppotaADBannerViewDelegate> delegate;

#pragma mark Making an Ad Request

/// Makes an ad request. The request object supplies targeting information.
- (void)loadRequest:(AppotaADRequest *)request;

@end
