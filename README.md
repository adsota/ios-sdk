AppotaADSDK for iOS
====
This is version 1.01 of AppotaADSDK for iOS

## 1. Configuration
- Add `AppotaADSDK.framework` and `AppotaADBundle.bundle` to your project
- Add other frameworks that the SDK requires

	- AdSupport
	- AudioToolbox
	- AVFoundation
	- CoreGraphics
	- CoreMedia
	- CoreTelephony
	- StoreKit
	- SystemConfiguration
- Configure project `.plist` add key `AppotaAPIKey` using key from developer page
- In `AppDelegate`:
	- import SDK: `#import <AppotaADSDK/AppotaADSDK.h>`
	- Init SDK in `application:didFinishLaunchingWithOptions:`
	
	```
	[AppotaADSDK init];
	```
	
	- in `applicationWillResignActive:`
		
	```
	[AppotaADSDK resignActive];

	```
	
	- in `applicationDidBecomeActive:`
	
	```
	[AppotaADSDK becomeActive];
	```

## 2. Banner
Now that you have a project with the SDK referenced, let's put banner ads into it. There are 2 ways to add banner by interface builder or programmatically. 
- Add `AppotaADBannerView` to interface builder and add constraint
![AD Constraint](adview_constraint.png)
- Or init `AppotaADBannerView` and add to view programmatically

```
bannerView = [[AppotaADBannerView alloc] initWithAdSize:APPOTA_SMART_BANNER_SIZE origin:CGPointMake(0, 0)];
[self.view addSubview:bannerView];

```
There are 2 options for banner size `APPOTA_BANNER_SIZE` which is fixed and `APPOTA_SMART_BANNER_SIZE` which is adaptively fit your side screen

### 2.1 Setup ad banner
Use `adUnitID` from ad CMS to make ad request, pass any value `state` to send to Appota server to identify the ad. Set `rootViewControlelr` and `delegate` for ad banner

```
    bannerView.adUnitID = @"YOUR_AD_UNIT";
    AppotaADRequest *request = [AppotaADRequest request];
    request.state = @"state";
    bannerView.delegate = self;
    bannerView.rootViewController = self;    
    [bannerView loadRequest:request];    
```
### 2.2 Delegate
There are 2 delegate call :

- `adViewDidReceiveAd:` called when delegate received ad and will display it

```
- (void) adViewDidReceiveAd:(AppotaADBannerView *)view;

```

- `adView:didFailToReceiveAdWithError:` called when fail to receive ad, print the error information to get the reason

```
- (void) adView:(AppotaADBannerView *)view didFailToReceiveAdWithError:(AppotaADRequestError *)error
```

- `adViewDidClick:` called when user did click on banner

```
- (void) adViewDidClick:(AppotaADBannerView *)adView;
```

## 3. Interstitial Ad
Interstitial will display a full banner in your app. 
### 3.1 Setup interstitial banner
Call `initWithAdUnitID:` and set `delegate`, `rootViewController`

```
interstitial = [[AppotaADInterstitial alloc] initWithAdUnitID:@"YOUR_AD_UNIT_ID"];
interstitial.delegate = self;
interstitial.rootViewController = self;
    
```

Then call `loadRequest:` when you want to display your interstitital ad

```
AppotaADRequest *request = [AppotaADRequest request];
request.state = @"YOUR_STATE";
[interstitial loadRequest:request];    

```

### 3.2 Delegate

- Called when an interstitial ad request succeeded.

```

- (void)interstitialDidReceiveAd:(AppotaADInterstitial *)ad;

```

- Called when an interstitial ad request completed without an interstitial to
show, print the error for more information

```
- (void)interstitial:(AppotaADInterstitial *)ad didFailToReceiveAdWithError:(AppotaADRequestError *)error;

```


- Called when ad did click

```
- (void)interstitialDidClick:(AppotaADInterstitial *)ad;

```

- Called just after dismissing an interstitial and it has animated off the screen.

```
- (void)interstitialDidDismissScreen:(AppotaADInterstitial *)ad;

```

##4. Offerwall Ad
Offerwill will display fullscreen ad with list of offer and reward
### 4.1 Setup offerwall ad

Call `initWithAdUnitID:` and set `delegate`, `rootViewController`

```
offerWall = [[AppotaADOfferWall alloc] initWithAdUnitID:@"YOUR_AD_UNIT_ID"];
offerWall.delegate = self;
offerWall.rootViewController = self;
    
```

Then call `loadRequest:` when you want to display your offerwall ad, pass `state` to your request, it'll be used to identify user and reward them after install ad by IPN

```
AppotaADRequest *request = [AppotaADRequest request];
request.state = @"YOUR_STATE";
[offerWall loadRequest:request];    

```

### 4.2 Delegate
- Called when an offerwall ad request succeeded.

```

- (void)offerWallDidReceiveAd:(AppotaADOfferWall *)ad;

```

- Called when an offerwall ad request completed without an offerwall to
show, print the error for more information

```
- (void)offerWall:(AppotaADOfferWall *)ad didFailToReceiveAdWithError:(AppotaADRequestError *)error;

```


- Called when ad did click

```
- (void)offerWallDidClick:(AppotaADOfferWall *)ad;

```

- Called just after dismissing an offerwall and it has animated off the screen.

```
- (void)offerWallDidDismissScreen:(AppotaADOfferWall *)ad;

```
### 4.3 IPN reward
Please visit our ad site to study IPN mechanism 
