//
//  AeroMapServices.h
//  SDK开发版本
//
//  Created by 北京国泰北斗科技有限公司 on 2016/11/17.
//  Copyright © 2016年 北京国泰北斗科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AeroMapServices : NSObject

/**
 * Provides the shared instance of AeroMapServices for the AeroMap SDK for iOS,
 * creating it if necessary. Classes such as UCMapView will hold this instance to 
 * provide their connection AeroMapService.
 *
 * This is an opaque object. If your application often creates and destroys view
 * or service classes provided by the AeroMap SDK for iOS, it may be useful
 * to hold onto this object directly, as otherwise your connection to AeroMapService
 * may be restarted on a regular basis. It also may be useful to take this
 * object in advance of the first map creation, to reduce initial map creation
 * performance cost.
 *
 * This method will throw an exception if provideAPIKey: has not been called.
 */
+ (id<NSObject>)shareServices;

/**
 * Provides your API key to the AreoMap SDK for iOS.  This key is generated
 * for your application via the AeroMap APIs Console, and is paired with your
 * application's bundle ID to identify it.  This must be called exactly once
 * by your application before any iOS Maps SDK object is initialized.
 *
 * @return YES if the APIKey was successfully provided
 */
+ (BOOL)provideAPIKey:(NSString *)APIKey;

@end
