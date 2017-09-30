//
//  UCCircle.h
//  SDK开发版本
//
//  Created by 北京国泰北斗科技有限公司 on 2016/11/16.
//  Copyright © 2016年 北京国泰北斗科技有限公司. All rights reserved.
//

#import "UCOverlayer.h"
#import <CoreLocation/CoreLocation.h>
#import <UIKit/UIKit.h>
@class UCMapView;

NS_ASSUME_NONNULL_BEGIN

@interface UCCircle : UCOverlayer
/** Position on Earth of circle center. */
@property(nonatomic, assign) CLLocationCoordinate2D position;

/** Radius of the circle in meters; must be positive. */
@property(nonatomic, assign) CLLocationDistance radius;

/**
 * The width of the circle's outline in screen points. Defaults to 1. As per
 * UCPolygon, the width does not scale when the map is zoomed.
 * Setting strokeWidth to 0 results in no stroke.
 */
@property(nonatomic, assign) CGFloat strokeWidth;

/** The color of this circle's outline. The default value is black. */
@property(nonatomic, strong) UIColor *strokeColor;

/**
 * The interior of the circle is painted with fillColor.
 * The default value is nil, resulting in no fill.
 */
@property(nonatomic, strong) UIColor *fillColor;

/**
 * If this overlay should cause tap notifications. Some overlays, such as
 * markers, will default to being tappable.
 */
@property(nonatomic, assign, getter=isTappable) BOOL tappable;


/**
 * Convenience constructor for UCCircle for a particular position and radius.
 * Other properties will have default values.
 */
+ (instancetype)circleWithPosition:(CLLocationCoordinate2D)position
                            radius:(CLLocationDistance)radius;
@end

NS_ASSUME_NONNULL_END
