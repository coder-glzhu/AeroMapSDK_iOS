//
//  UCCoordinateBounds.h
//  AeroMapSDK
//
//  Created by 北京国泰北斗科技有限公司 on 2017/3/22.
//  Copyright © 2017年 北京国泰北斗科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
@class UCPath,UCMapView;

@interface UCCoordinateBounds : NSObject

@property(nonatomic, readonly) CLLocationCoordinate2D northEast;

@property(nonatomic, readonly) CLLocationCoordinate2D southWest;

@property(readonly, getter=isValid) BOOL valid;

- (instancetype)initWithPath:(UCPath *)path;

- (instancetype)initWithCoordinate:(CLLocationCoordinate2D)coord1
              coordinate:(CLLocationCoordinate2D)coord2;

- (UCCoordinateBounds *)includingCoordinate:(CLLocationCoordinate2D)coordinate;


- (UCCoordinateBounds *)includingBounds:(UCCoordinateBounds *)other;

- (UCCoordinateBounds *)initWithVisibleBoundsWithMap:(UCMapView *)mapView;

- (BOOL)containsCoordinate:(CLLocationCoordinate2D)coordinate;


- (BOOL)intersectsBounds:(UCCoordinateBounds *)other;


@end
