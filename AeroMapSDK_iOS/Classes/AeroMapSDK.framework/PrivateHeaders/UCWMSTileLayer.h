//
//  GTWMSTileLayer.h
//  MyMap
//
//  Created by 朱国良 on 16/6/29.
//  Copyright © 2016年 朱国良. All rights reserved.
//

#import <GoogleMaps/GMSTileLayer.h>

@class UCWMSParameter;

// range of map or layer
typedef struct bbox{
    double  left;
    double  bottom;
    double  right;
    double  top;
} bbox;

typedef NS_ENUM(NSInteger,WMSTitleLayerType){
    WMSTitleLayerMap = 1,   //地图图层
    WMSTitleLayerOverlay,   //叠加图层
};

@interface UCWMSTileLayer : GMSTileLayer

@property(nonatomic,strong)UCWMSParameter *parameter;

@property(nonatomic,assign)BOOL openCache;
/**
 *  图层的唯一标示符
 */
@property(nonatomic,copy)NSString *layerName;

- (instancetype)initWithLayerParameter:(UCWMSParameter *)parameter;

@property(nonatomic,assign)WMSTitleLayerType titleLayerType;

@end
