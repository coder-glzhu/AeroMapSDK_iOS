//
//  UCDrawToolsDelegate.h
//  SDK开发版本
//
//  Created by 朱国良 on 16/9/4.
//  Copyright © 2016年 北京国泰北斗科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol UCDrawToolsDelegate <NSObject>

@optional
/**
 *  点击地图时返回点击的经纬度
 *
 *  @param coordinate 经纬度
 */
- (void)tapMapViewAtCoordinate:(CLLocationCoordinate2D)coordinate;

/**
 *  画圆时，实时的更新坐标及其半径
 *
 *  @param coordinate 中心点
 *  @param radius     半径
 */
- (void)drawCircleAtCoordinate:(CLLocationCoordinate2D)coordinate withRadius:(CLLocationDistance)radius;

/**
 *  拖拽修改多边形时调用的方法
 *
 *  @param coordinate 当前的拖拽到哪一个位置
 *  @param index      拖拽的是第几个点
 */
- (void)drawRectTapCoordinate:(CLLocationCoordinate2D)coordinate withIndex:(NSInteger)index;

@end
