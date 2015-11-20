//
//  AdsOTAConstants.h
//  AdsOTADK
//
//  Created by Tue Nguyen on 6/12/15.
//
//

#import <Foundation/Foundation.h>

/*
 * Banner type (4 types: list (show ads in tableview), side (show ads in side view), screen (show ads in fullscreen view), random (random 1 of 3 other types)
 */
typedef enum
{
    AdsOTATypeView = 0,
    AdsOTATypeInterstitial = 1,
    AdsOTATypeOfferWall = 2,
    AdsOTATypeNone = 3,
} AdsOTAType;

typedef void (^AdsOTAStringBlock)(NSString *xmlString);
typedef void (^AdsOTAArrayBlock)(NSArray *list);
typedef void (^AdsOTADictionaryBlock) (NSDictionary *dict);
typedef void (^AdsOTABOOLBlock)(BOOL b);
typedef void (^AdsOTAObjectBlock)(id object);
typedef void (^AdsOTAErrorBlock) (NSError *error);

// Sizing constants.
extern CGSize const ADSOTA_BANNER_SIZE;
extern CGFloat const ADSOTA_BANNER_SIZE_HEIGHT;
#define ADSOTA_SMART_BANNER_SIZE getSmartBannerSize()
#define ADSOTA_IS_SANDBOX 1
//#define ADSOTA_ADS_IS_DEBUG_DEVICE 1

//#define ADSOTA_ADS_IS_DEBUG 1
//#define ADSOTA_DEBUG_LOG 1
//#define ADSOTA_INSTALL_ALL_DEBUG 1


CGSize getSmartBannerSize();