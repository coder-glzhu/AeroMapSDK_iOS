//
//  AirspaceOverLayer.h
//  SDK开发版本
//
//  Created by 北京国泰北斗科技有限公司 on 2016/11/14.
//  Copyright © 2016年 北京国泰北斗科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
@class UCMapView;
typedef enum : NSUInteger {
    AirspaceOverLayerNameRestricted = 0,    //限制区
    AirspaceOverLayerNameNoFly,             //禁飞区
    AirspaceOverLayerNameDangerous,         //危险区
    AirspaceOverLayerNameForbidden,         //净空区
    AirspaceOverLayerNameAirportMH,         //民航机场
    AirspaceOverLayerNameAirportHL,         //护林机场
    AirspaceOverLayerNameAirportNH,         //农化机场
    AirspaceOverLayerNameAirportTH,         //通航机场
    AirspaceOverLayerNameAirportJY,         //军用机场
    AirspaceOverLayerNameAirportJM,         //军民机场
    AirspaceOverLayerNameAirportZSJ,        //直升机
    AirspaceOverLayerNameAirportJB          //军备机场
} AirspaceOverLayerName;


@interface AirspaceOverLayer : NSObject

/**
 * 图层初始化方法

 @param mapView 地图对象
 @return 图层实例
 */
+ (instancetype)overLayerWithMapView:(UCMapView *)mapView;


/**
 * 调用此方法根据传入的枚举类型添加不同的图层

 @param layerName 图层名称
 */
- (void)addOverLayerWithlayerName:(AirspaceOverLayerName)layerName;


/**
 * 调用此方法根据枚举类型删除不同的图层

 @param layerName 图层名称
 */
- (void)deleteOverLayerWithLayerName:(AirspaceOverLayerName)layerName;
@end
