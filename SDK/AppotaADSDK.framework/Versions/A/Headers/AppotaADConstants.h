//
//  AppotaADConstants.h
//  AppotaADDK
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
    AppotaADTypeView = 0,
    AppotaADTypeInterstitial = 1,
    AppotaADTypeOfferWall = 2,
    AppotaADTypeNone = 3,
} AppotaADType;

typedef void (^AppotaADStringBlock)(NSString *xmlString);
typedef void (^AppotaADArrayBlock)(NSArray *list);
typedef void (^AppotaADDictionaryBlock) (NSDictionary *dict);
typedef void (^AppotaADBOOLBlock)(BOOL b);
typedef void (^AppotaADObjectBlock)(id object);
typedef void (^AppotaADErrorBlock) (NSError *error);

// Sizing constants.
extern CGSize const APPOTA_BANNER_SIZE;
extern CGFloat const APPOTA_BANNER_SIZE_HEIGHT;
#define APPOTA_SMART_BANNER_SIZE getSmartBannerSize()
#define APPOTA_IS_SANDBOX 1
//#define APPOTA_ADS_IS_DEBUG_DEVICE 1

//#define APPOTA_ADS_IS_DEBUG 1
//#define APPOTA_DEBUG_LOG 1
//#define APPOTA_INSTALL_ALL_DEBUG 1


CGSize getSmartBannerSize();