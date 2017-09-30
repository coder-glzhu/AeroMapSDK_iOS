//
//  UCGeometryUtils.hpp
//  AeroMapSDK
//
//  Created by 北京国泰北斗科技有限公司 on 2017/3/10.
//  Copyright © 2017年 北京国泰北斗科技有限公司. All rights reserved.
//


#define UC_NSArrayOf(value) NSArray<value>

#import "UCPath.h"

@class UCStyleSpan;
@class UCStrokeStyle;

NS_ASSUME_NONNULL_BEGIN


/*!
 *  \~chinese
 *  设计线条的复杂的样式，需要绘制线条的路径，样式的数组，每个样式的长度，以及整体绘制的类型。
 *
 *  \~english
 *  The complex style of the design lines, the lines of the lines to be drawn, the array of styles, the length of
 *  each style, and the type of the whole drawing
 */
FOUNDATION_EXPORT
UC_NSArrayOf(UCStyleSpan *) *UCSStyleSpans(UCPath *path,
                                             UC_NSArrayOf(UCStrokeStyle *) *styles,
                                             UC_NSArrayOf(NSNumber *) *lengths,
                                             UCLengthKind lengthKind);


/*!
 *  \~chinese
 *  获取path的距离长度
 *
 *  \~english
 *  get path disstance
 */
FOUNDATION_EXPORT
CLLocationDistance CalculateTheDistanceOfTheLine(UCPath *path);

/*!
 *  \~chinese
 *  获取path构成的区域面积
 *
 *  \~english
 *  get area
 */
FOUNDATION_EXPORT
double CalculatePolygonArea(UCPath *path);

NS_ASSUME_NONNULL_END

