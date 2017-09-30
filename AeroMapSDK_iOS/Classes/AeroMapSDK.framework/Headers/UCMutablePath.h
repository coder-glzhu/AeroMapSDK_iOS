//
//  UCMutablePath.h
//  AeroMapSDK
//
//  Created by 北京国泰北斗科技有限公司 on 2017/3/10.
//  Copyright © 2017年 北京国泰北斗科技有限公司. All rights reserved.
//

#import "UCPath.h"

NS_ASSUME_NONNULL_BEGIN

@interface UCMutablePath : UCPath

/*!
 *  \~chinese
 *  添加| coord |在路径的结尾。
 *
 *  \~english
 *  Adds |coord| at the end of the path.
 */
- (void)addCoordinate:(CLLocationCoordinate2D)coord;

/*!
 *  \~chinese
 *  添加给定经纬度返回新CLLocationCoordinate2D实例
 *
 *  \~english
 *  Adds a new CLLocationCoordinate2D instance with the given lat/lng
 */
- (void)addLatitude:(CLLocationDegrees)latitude longitude:(CLLocationDegrees)longitude;

/*!
 *  \~chinese
 *  插入| coord | at | index |。如果它小于路径的大小，则将所有坐标向前移动一个。除此以外，
 *  表示为replaceCoordinateAtIndex：withCoordinate :.
 *
 *  \~english
 *  Inserts |coord| at |index|.
 *  If this is smaller than the size of the path, shifts all coordinates forward by one. Otherwise,
 *  behaves as replaceCoordinateAtIndex:withCoordinate:.
 */
- (void)insertCoordinate:(CLLocationCoordinate2D)coord atIndex:(NSUInteger)index;

/*!
 *  \~chinese
 *  替换| index |上的坐标与| coord |。如果| index |是数组长度之后的值，生成数组
 *  没有意义的坐标。
 *
 *  \~english
 *  Replace the coordinate at |index| with |coord|. If |index| is after the end, grows the array with
 *  an undefined coordinate.
 */
- (void)replaceCoordinateAtIndex:(NSUInteger)index withCoordinate:(CLLocationCoordinate2D)coord;

/*!
 *  \~chinese
 *  删除指点点的坐标
 *
 *  \~english
 *  Remove entry at |index|.
 *  If |index| < count decrements size. If |index| >= count this is a silent
 *  no-op.
 */
- (void)removeCoordinateAtIndex:(NSUInteger)index;

/*!
 *  \~chinese
 *  删除最后一个点
 *
 *  \~english
 *  Removes the last coordinate of the path.
 *  If the array is non-empty decrements size. If the array is empty, this is a silent no-op.
 */
- (void)removeLastCoordinate;

/*!
 *  \~chinese
 *  删除这个path上所有的点
 *
 *  \~english
 *  Removes all coordinates in this path
 */
- (void)removeAllCoordinates;

@end

NS_ASSUME_NONNULL_END
