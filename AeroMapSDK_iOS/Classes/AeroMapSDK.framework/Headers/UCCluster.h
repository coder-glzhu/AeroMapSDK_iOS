//
//  UCCluster.h
//  AeroMapSDK
//
//  Created by 北京国泰北斗科技有限公司 on 2017/3/22.
//  Copyright © 2017年 北京国泰北斗科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UCClusterItem.h"

@protocol UCCluster <NSObject>

@property(nonatomic, readonly) CLLocationCoordinate2D position;


@property(nonatomic, readonly) NSUInteger count;


@property(nonatomic, readonly) NSArray<id<UCClusterItem>> *items;

@end
