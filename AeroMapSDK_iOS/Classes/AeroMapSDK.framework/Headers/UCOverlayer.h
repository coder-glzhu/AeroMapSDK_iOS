//
//  UCOverlayer.h
//  AeroMapSDK
//
//  Created by 北京国泰北斗科技有限公司 on 2017/3/27.
//  Copyright © 2017年 北京国泰北斗科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
@class UCMapView;


@interface UCOverlayer : NSObject

/*!
 *  \~chinese
 *  高| zIndex |值覆盖将绘制在低| zIndex |之上。相等的值将部分次序绘制。标记是一个例外，它始终会在图块层和其他非标记叠加上绘制;它
 *  被有效地认为是在一个单独的z指数组相比其他覆盖层来说。
 *
 *  \~english
 *  Higher |zIndex| value overlays will be drawn on top of lower |zIndex|
 *  value tile layers and overlays.  Equal values result in undefined draw
 *  ordering.  Markers are an exception that regardless of |zIndex|, they will
 *  always be drawn above tile layers and other non-marker overlays; they
 *  are effectively considered to be in a separate z-index group compared to
 *  other overlays.
 */
@property(nonatomic, assign) int zIndex;

/**
 *  The map this overlay is on. Setting this property will add the overlay to the
 *  map. Setting it to nil removes this overlay from the map. An overlay may be
 *  active on at most one map at any given time.
 */
@property(nonatomic,weak)UCMapView *mapView;


@end
