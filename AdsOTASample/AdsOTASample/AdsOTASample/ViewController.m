//
//  ViewController.m
//  AdsOTASample
//
//  Created by Tue Nguyen on 7/20/15.
//  Copyright (c) 2015 ADSOTA. All rights reserved.
//

#import "ViewController.h"
#import <AdsOTASDK/AdsOTASDK.h>

@interface ViewController () <AdsOTABannerViewDelegate, AdsOTAInterstitialDelegate, AdsOTAOfferWallDelegate>
{
    AdsOTAOfferWall *offerWall;
    AdsOTAInterstitial* interstitial;
}

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    [self setupBannerView];
    // Cannot show interstitial and offerwall all at once
//    [self setupInterstitital];
    [self setupOfferWall];
}

- (void) setupBannerView {
    AdsOTABannerView* bannerView = [[AdsOTABannerView alloc] initWithAdSize:ADSOTA_SMART_BANNER_SIZE origin:CGPointMake(0, 0)];
    bannerView.adUnitID = @"71";
    AdsOTARequest *request = [AdsOTARequest request];
    request.state = @"state";
    request.target = @"target";
    bannerView.delegate = self;
    bannerView.rootViewController = self;
    [bannerView loadRequest:request];
    [self.view addSubview:bannerView];
}

- (void) setupInterstitital {
    interstitial = [[AdsOTAInterstitial alloc] initWithAdUnitID:@"72" withRootViewController:self];
    interstitial.delegate = self;
    [interstitial loadRequest:[AdsOTARequest request]];
}

- (void) setupOfferWall  {
    offerWall = [[AdsOTAOfferWall alloc] initWithAdUnitID:@"73" withRootViewController:self];
    offerWall.delegate = self;
    AdsOTARequest *request = [AdsOTARequest request];
    request.state = @"TestState";
    [offerWall loadRequest:[AdsOTARequest request]];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


#pragma mark - ADSOTA AD delegate

# pragma mark Banner
- (void) adsotaViewDidReceiveAd:(AdsOTABannerView *)view {
    
}

- (void) adsotaView:(AdsOTABannerView *)view didFailToReceiveAdWithError:(AdsOTARequestError *)error {
    
}

- (void) adsotaViewDidClick:(AdsOTABannerView *)adView {
    
}

#pragma mark Interstitial
- (void) adsotaInterstitialDidReceiveAd:(AdsOTAInterstitial *)ad {
    
}

- (void) adsotaInterstitial:(AdsOTAInterstitial *)ad didFailToReceiveAdWithError:(AdsOTARequestError *)error {
    // Fail interstitial then show offerwall
    [self setupOfferWall];
}

- (void) adsotaInterstitialDidClick:(AdsOTAInterstitial *)ad {
    
}

- (void) adsotaInterstitialDidDismissScreen:(AdsOTAInterstitial *)ad {
    
}

#pragma mark Offerwall
- (void) adsotaOfferWallDidReceiveAd:(AdsOTAOfferWall *)ad {
    
}

- (void) adsotaOfferWall:(AdsOTAOfferWall *)ad didFailToReceiveAdWithError:(AdsOTARequestError *)error {
    
}

- (void) adsotaOfferWallDidClick:(AdsOTAOfferWall *)ad {
    
}

- (void) adsotaOfferWallDidDismissScreen:(AdsOTAOfferWall *)ad {
    
}
@end
