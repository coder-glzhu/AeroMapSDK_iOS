//
//  UCPolygon.h
//  SDK开发版本
//
//  Created by 北京国泰北斗科技有限公司 on 2016/11/15.
//  Copyright © 2016年 北京国泰北斗科技有限公司. All rights reserved.
//

#import "UCOverlayer.h"
#import <UIKit/UIKit.h>
@class UCPath;

NS_ASSUME_NONNULL_BEGIN

@protocol UCPolygonDelegate <NSObject>
@optional
- (UIImage *)showPolygonMiddleLabelWithLabelContent:(NSString *)content;

@end

/*!
 *  \~chinese
 *  UCPolygon定义一个多边形在地图上。多边形（像折线）定义了一系列的有序连接坐标序
 *  列；此外，多边形形成一个封闭的循环，并定义一个填充区域。
 *
 *  \~english
 *  GMSPolygon defines a polygon that appears on the map. A polygon (like
 *  polyline) defines a series of connected coordinates in an ordered 
 *  sequence; additionally,polygons form a closed loop and define a filled region.
 */
@interface UCPolygon : UCOverlayer

/*!
 *  \~chinese
 *  控制是否在每一条边的中间部位显示长度 默认是NO
 *
 *  \~english
 *  Controls whether the length is displayed at the middle of each side (Default : NO)
 */
@property(nonatomic,assign)BOOL showLabel;

/*!
 *  \~chinese
 *  UCPolygonDelegate
 *
 *  \~english
 *  UCPolygonDelegate
 */
@property(nonatomic,weak)id<UCPolygonDelegate>delegate;

/*!
 *  \~chinese
 *  多边形路径,组合路径de坐标必须是有效的
 *
 *  \~english
 *  The path that describes this polygon. The coordinates composing the path must be valid.
 */
@property(nonatomic, copy) UCPath *path;

/*!
 *  \~chinese
 *  多边形轮廓的宽度，默认值为1。
 *
 *  \~english
 *  The width of the polygon outline in screen points. Defaults to 1.
 */
@property(nonatomic, assign) CGFloat strokeWidth;

/*!
 *  \~chinese
 *  多边形轮廓的颜色。默认值nil
 *
 *  \~english
 *  The color of the polygon outline. Defaults to nil
 */
@property(nonatomic, strong) UIColor *strokeColor;

/*!
 *  \~chinese
 *  填充色，默认是蓝色
 *
 *  \~english
 *  The fill color. Defaults to blueColor.
 */
@property(nonatomic, strong) UIColor *fillColor;

/*!
 *  \~chinese
 *  多边形是否允许几何校正
 *
 *  \~english
 *  Whether this polygon should be rendered with geodesic correction.
 */
@property(nonatomic, assign) BOOL geodesic;

/*!
 *  \~chinese
 *  工厂方法，构造UCPoline实例
 *
 *  \~english
 *  Convenience constructor for UCPolygon for a particular path. Other
 *  properties will have default values.
 */

+ (instancetype)polygonWithPath:(UCPath *)path;
@end

NS_ASSUME_NONNULL_END
