//
//  ViewController.m
//  AppotaADSample
//
//  Created by Tue Nguyen on 7/20/15.
//  Copyright (c) 2015 appota. All rights reserved.
//

#import "ViewController.h"
#import <AppotaADSDK/AppotaADSDK.h>

@interface ViewController () <AppotaADBannerViewDelegate, AppotaADInterstitialDelegate, AppotaADOfferWallDelegate>
{
}

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    [self setupBannerView];
    // Cannot show interstitial and offerwall all at once
    [self setupInterstitital];
//    [self setupOfferWall];
}

- (void) setupBannerView {
    AppotaADBannerView* bannerView = [[AppotaADBannerView alloc] initWithAdSize:APPOTA_SMART_BANNER_SIZE origin:CGPointMake(0, 0)];
    bannerView.adUnitID = @"43";
    AppotaADRequest *request = [AppotaADRequest request];
    request.state = @"state";
    request.target = @"target";
    bannerView.delegate = self;
    bannerView.rootViewController = self;
    [bannerView loadRequest:request];
    [self.view addSubview:bannerView];
}

- (void) setupInterstitital {
    AppotaADInterstitial* interstitial = [[AppotaADInterstitial alloc] initWithAdUnitID:@"44" withRootViewController:self];
    interstitial.delegate = self;
    [interstitial loadRequest:[AppotaADRequest request]];
}

- (void) setupOfferWall  {
    AppotaADOfferWall *offerWall = [[AppotaADOfferWall alloc] initWithAdUnitID:@"45" withRootViewController:self];
    offerWall.delegate = self;
    AppotaADRequest *request = [AppotaADRequest request];
    request.state = @"TestState";
    [offerWall loadRequest:[AppotaADRequest request]];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


#pragma mark - Appota AD delegate

# pragma mark Banner
- (void) adViewDidReceiveAd:(AppotaADBannerView *)view {
    
}

- (void) adView:(AppotaADBannerView *)view didFailToReceiveAdWithError:(AppotaADRequestError *)error {
    
}

- (void) adViewDidClick:(AppotaADBannerView *)adView {
    
}

#pragma mark Interstitial
- (void) interstitialDidReceiveAd:(AppotaADInterstitial *)ad {
    
}

- (void) interstitial:(AppotaADInterstitial *)ad didFailToReceiveAdWithError:(AppotaADRequestError *)error {
    // Fail interstitial then show offerwall
    [self setupOfferWall];
}

- (void) interstitialDidClick:(AppotaADInterstitial *)ad {
    
}

- (void) interstitialDidDismissScreen:(AppotaADInterstitial *)ad {
    
}

#pragma mark Offerwall
- (void) offerWallDidReceiveAd:(AppotaADOfferWall *)ad {
    
}

- (void) offerWall:(AppotaADOfferWall *)ad didFailToReceiveAdWithError:(AppotaADRequestError *)error {
    
}

- (void) offerWallDidClick:(AppotaADOfferWall *)ad {
    
}

- (void) offerWallDidDismissScreen:(AppotaADOfferWall *)ad {
    
}
@end
