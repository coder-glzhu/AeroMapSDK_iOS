//
//  UCDownloadOfflineMap.h
//  SDK开发版本
//
//  Created by 北京国泰北斗科技有限公司 on 2016/12/12.
//  Copyright © 2016年 北京国泰北斗科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
@class UCMapView,UCDownloadArea,UCPath;

///Normal Map
extern NSString * const kAeroMapNormal;
///Terrain Map
extern NSString * const kAeroMapTerrain;
///Satellite Map
extern NSString * const kAeroMapSatellite;

@interface UCDownloadOfflineMap : NSObject

///Obtain download area data based on the desired download hierarchy and the name of the download area.mapType(kAeroMapChinaMap/kAeroMapChinaTerrainMap/kAeroMapChinaHybridMap)
- (UCDownloadArea *)downloadAreaWithMapType:(NSString *)mapType
                                 withPath:(UCPath *)path
                                 withLevels:(NSArray *)levelsSet
                               withAreaName:(NSString *)areaName;

///The number of map tiles and the estimated cache size are obtained based on the selection of different tiers
- (void)getMapTitleCounWithSumMemory:(NSArray *)levels
                          withPath:(UCPath *)path
                                with:(void(^)(long long sumCount,double sumMemory))block;
@end
