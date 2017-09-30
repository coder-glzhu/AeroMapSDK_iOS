//
//  UCCustomComponent.h
//  SDK开发版本
//
//  Created by 北京国泰北斗科技有限公司 on 2017/2/7.
//  Copyright © 2017年 北京国泰北斗科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN

@class UCMapView,UCMutablePath,UCMarker;


@interface UCCustomComponent : NSObject

/*!
 *  \~chinese
 *  实例化组件对象
 *
 *  \~english
 *  Instantiate a custom component object
 */
+ (instancetype)componentWithMapView:(UCMapView *)mapView;

/*!
 *  \~chinese
 *  添加一个选择的坐标到自定义的组件上
 *
 *  \~english
 *  Obtain an area based on the incoming point
 */
- (void)addCoordToComponent:(CLLocationCoordinate2D)position;

/*!
 *  \~chinese
 *  当拖拽marker的时候，改变选择的位置
 *
 *  \~english
 *  When the marker is dragged, change the selected position
 */
- (void)changeCoordWhenDragMarker:(UCMarker *)marker;

/*!
 *  \~chinese
 *  重置选择区域
 *
 *  \~english
 *  Reset the selection area
 */
- (void)resetChoseArea;

/*!
 *  \~chinese
 *  GMSMutablePath是CLLocationCoordinate2D的动态（可调整大小）数组，所有坐标必须是有效的。
 *
 *  \~english
 *  Variable path, save all coordinates
 */
@property(nonatomic,strong)UCMutablePath *mutablePath;

/*!
 *  \~chinese
 *  当前UI组件上所有标注的集合
 *
 *  \~english
 *  A collection of all the labels
 */
@property(nonatomic,strong)NSMutableArray *markers;

/*!
 *  \~chinese
 *  UI组件的线条颜色
 *
 *  \~english
 *  Line color
 */
@property(nonatomic,strong)UIColor *componentLineColor;

/*!
 *  \~chinese
 *  UI组件的线宽
 *
 *  \~english
 *  Line width
 */
@property(nonatomic,assign)CGFloat componentLineWidth;

/*!
 *  \~chinese
 *  UI组件的填充颜色
 *
 *  \~english
 *  Fill color
 */
@property(nonatomic,strong)UIColor *componentFillColor;

/*!
 *  \~chinese
 *  UCMapView地图
 *
 *  \~english
 *  UCMapView
 */
@property(nonatomic,strong,readonly)UCMapView *mapView;

@end

NS_ASSUME_NONNULL_END
