//
//  UCDrawToolsClass.h
//  SDK开发版本
//
//  Created by 朱国良 on 16/9/4.
//  Copyright © 2016年 北京国泰北斗科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "UCDrawToolsDelegate.h"
@class UCMapView;

@interface UCDrawToolsClass : NSObject

@property(nonatomic,weak)id<UCDrawToolsDelegate> delegate;

/**
 *  初始化方法
 *
 *  @param mapView 地图对象
 *
 */
- (instancetype)initWithMapView:(UCMapView *)mapView;

/** (多边形)
 *  根据传入的坐标画线（如果此方法只调用一次，默认就是一个点,此方法用来画多边形）
 *
 *  @param coordinate 经纬度
 */
- (void)drawAreaWithCoordinates:(CLLocationCoordinate2D)coordinate;

/** （多边形）
 *  修改多边形的index位置的坐标
 *
 *  @param position 位置坐标
 *  @param index    第几个位置
 */
- (void)changeRcetPositionWith:(CLLocationCoordinate2D)position withIdex:(NSInteger)index;

/** （圆）
 *  (默认画圆方式)在地图上画圆
 *
 *  @param center 圆的中心坐标
 *  @param radius 半径
 */
- (void)drawCircleWithCenter:(CLLocationCoordinate2D)center withRadius:(CLLocationDistance)radius;

/** （圆）
 *  通过手动添加圆心来画圆
 *
 *  @param center 圆心
 */
- (void)drawCircleWithCenter:(CLLocationCoordinate2D)center;

/** （圆）
 *  通过手动添加半径来画圆
 *
 *  @param radius 半径
 */
- (void)drawCircleWithRadius:(CLLocationDistance)radius;

/**
 *  编辑坐标（此方法仅用于选择无人机飞行区域时，进行编辑）
 */
- (void)editingCoordinte;

/**
 *  完成编辑（此方法仅用于选择无人机飞行区域时，完成编辑）
 */
- (void)commitEdittingCoordinte;

/**
 *  擦除所有的点
 */
- (void)wipeAllCoordintes;
@end
