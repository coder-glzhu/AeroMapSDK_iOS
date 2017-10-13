//
//  AirspaceOverLayer.h
//  SDK开发版本
//
//  Created by 北京国泰北斗科技有限公司 on 2016/11/14.
//  Copyright © 2016年 北京国泰北斗科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
@class UCMapView;
typedef NS_ENUM(NSUInteger, AirspaceOverLayerName) {
    AirspaceOverLayerNameNone = 0,
    AirspaceOverLayerNameRestricted = 1 << 0,        //限制区
    AirspaceOverLayerNameNoFly = 1 << 1,             //禁飞区
    AirspaceOverLayerNameDangerous = 1 << 2,         //危险区
    AirspaceOverLayerNameForbidden = 1 << 3,         //净空区
    AirspaceOverLayerNameFreeZone = 1 << 4,          //自由飞行区
    AirspaceOverLayerNameAirportMH = 1 << 5,         //民航机场
    AirspaceOverLayerNameAirportHL = 1 << 6,         //护林机场
    AirspaceOverLayerNameAirportNH = 1 << 7,         //农化机场
    AirspaceOverLayerNameAirportTH = 1 << 8,         //通航机场
    AirspaceOverLayerNameAirportJY = 1 << 9,         //军用机场
    AirspaceOverLayerNameAirportJM = 1 << 10,         //军民机场
    AirspaceOverLayerNameAirportZSJ = 1 << 11,        //直升机
    AirspaceOverLayerNameAirportJB = 1 << 12         //军备机场
};

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
