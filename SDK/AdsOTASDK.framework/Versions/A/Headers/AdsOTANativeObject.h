//
//  AdsOTANativeObject.h
//  AdsOTASDK
//
//  Created by Tue Nguyen on 7/27/15.
//
//

#import <Foundation/Foundation.h>

@interface AdsOTANativeObject : NSObject
// Get adID
- (NSString*) getID;

- (NSString*) getName;

- (NSString*) getImageURL;

- (NSString*) getIconURL;

// Return display type icon or screen
- (NSString*) getType;

- (NSString*) getAction;

- (NSString*) getDescription ;

@end
