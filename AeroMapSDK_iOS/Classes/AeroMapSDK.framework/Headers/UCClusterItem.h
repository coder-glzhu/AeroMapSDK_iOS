//
//  UCClusterItem.h
//  SDK开发版本
//
//  Created by 北京国泰北斗科技有限公司 on 2017/3/21.
//  Copyright © 2017年 北京国泰北斗科技有限公司. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>
#import <UIKit/UIKit.h>

@protocol UCClusterItem <NSObject>

@property(nonatomic, readonly) CLLocationCoordinate2D position;
@property(nonatomic,strong,readonly)NSString *itemKey;

@end
