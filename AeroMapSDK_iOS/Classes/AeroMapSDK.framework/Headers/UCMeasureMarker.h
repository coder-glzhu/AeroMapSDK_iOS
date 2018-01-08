//
//  UCMeasureMarker.h
//  SDK开发版本
//
//  Created by 北京国泰北斗科技有限公司 on 2017/3/7.
//  Copyright © 2017年 北京国泰北斗科技有限公司. All rights reserved.
//

#import <GoogleMaps/GoogleMaps.h>

NS_ASSUME_NONNULL_BEGIN

@interface UCMeasureMarker : GMSMarker

/**
 根据两个坐标点计算得出一个测量数据显示的标签

 @param coord1 坐标1
 @param coord2 坐标2
 @param dataString 需要显示的数据
 @return 返回一个显示数据的标签
 */
+ (instancetype)measureMarkerWithLocation1:(CLLocationCoordinate2D)coord1
                                 location2:(CLLocationCoordinate2D)coord2
                                    string:(NSString *)dataString;


/**
 显示中心区域测量数据的标签

 @param center 中心区域的坐标
 @param dataString 需要显示的数据
 @return 返回一个中心区域显示数据的标签
 */
+ (instancetype)measureMarkerCenterLocation:(CLLocationCoordinate2D)center string:(NSString *)dataString;


/**
 改变两个点的位置是需要改变两点之间显示数据点的位置

 @param coord1 坐标1
 @param coord2 坐标2
 @param dataString 需要显示的数据
 */
- (void)changeLocationWithLocation1:(CLLocationCoordinate2D)coord1
                          location2:(CLLocationCoordinate2D)coord2
                             string:(NSString *)dataString;



/**
 设置两点之间标签的样式

 @param configDic 样式Dic
 */
- (void)setContentLabelCongfig:(NSDictionary<NSString *,id> *)configDic;


/**
 根据需要显示的数据修改标签上显示的内容

 @param text 需要显示的内容
 */
- (void)iconForText:(NSString *)text;


@end

NS_ASSUME_NONNULL_END
