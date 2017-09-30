//
//  UCPath.h
//  AeroMapSDK
//
//  Created by 北京国泰北斗科技有限公司 on 2017/3/10.
//  Copyright © 2017年 北京国泰北斗科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UCPath : NSObject

/*!
 *  \~chinese
 *  空路径的构造方法
 *
 *  \~english
 *  Convenience constructor for an empty path
 */
+ (instancetype)path;

/*!
 *  \~chinese
 *  使用另一个UCPath的内容初始化新分配的路径
 *
 *  \~english
 *  Initializes a newly allocated path with the contents of another UCPath
 */
- (id)initWithPath:(UCPath *)path;

/*!
 *  \~chinese
 *  获取path的长度
 *
 *  \~english
 *  Get size of path
 */
- (NSUInteger)count;

/*!
 *  \~chinese
 *  翻译path上对应位置的坐标
 *
 *  \~english
 *  Returns kCLLocationCoordinate2DInvalid if |index| >= count
 */
- (CLLocationCoordinate2D)coordinateAtIndex:(NSUInteger)index;

/*!
 *  \~chinese
 *  初始化来自| encodedPath |的新分配的路径。此格式在
    https://developers.google.com/maps/documentation/utilities/polylinealgorithm
 *
 *  \~english
 *  Initializes a newly allocated path from |encodedPath|. This format is described at
 *  https://developers.google.com/maps/documentation/utilities/polylinealgorithm
 */
+ (instancetype)pathFromEncodedPath:(NSString *)encodedPath;

/*!
 *  \~chinese
 *  以上述格式返回路径的编码字符串。
 *
 *  \~english
 *  Returns an encoded string of the path in the format described above.
 */
- (NSString *)encodedPath;

/*!
 *  \~chinese
 *  通过添加| deltaLatitude |获得的新路径| deltaLongitude |返回每个坐标的路径。不修改当前路径。
 *
 *  \~english
 *  Returns a new path obtained by adding |deltaLatitude| and |deltaLongitude| to each coordinate
 *  of the current path. Does not modify the current path.
 */
- (instancetype)pathOffsetByLatitude:(CLLocationDegrees)deltaLatitude
                           longitude:(CLLocationDegrees)deltaLongitude;

@end


/*!
 *  \~chinese
 *  UCLengthKind指示长度值的类型，可以是测地线（以米为单位），rhumb长度（以米为单位）和投影长度
 *
 *  \~english
 *  UCLengthKind indicates the type of a length value, which can be geodesic (in meters), rhumb
 *  length (in meters) and projected length.
 */
typedef enum {
    /*!
     *  \~chinese
     *  测地长度，以米为单位，沿测地线段。例如，指定沿着飞机或船的轨迹的长度。
     *
     *  \~english
     *  Geodesic length, in meters, along geodesic segments. May be useful, for example, to specify
     lengths along the the trajectory of airplanes or ships.
     */
    UCLengthGeodesic,
    
    /*!
     *  \~chinese
     *  垂直长度，以米为单位，沿垂直（直线）段。例如，在地图上绘制比例尺。给定长度的段的视觉尺寸取决于纬度。
     *
     *  \~english
     *  Rhumb length, in meters, along rhumb (straight line) segments. May be useful, for example, to
     draw a scale bar on a map. The visual size of a segment of a given length depens on the
     latitude.
     */
    UCLengthRhumb,
    
    /*!
     *  \~chinese
     *  投影空间中的长度，沿着线段。投影长度使用相同的单位。地球赤道圆周长度为2.可以指定投影长度以相应于赤道1米的单位乘以
     *  kGMSEquatorProjectedMeter，等于1 /（pi * EarthRadius）。投影长度可能有用，例如，指定具有相同视觉长度的段
     *  不管纬度。
     *
     *  \~english
     *  Length in projected space, along rhumb segments. Projected length uses the same units as
     *  GMSMapPoint - the Earth equator circumference has length 2. It is possible to specify projected
     *  length in units corresponding to 1 meter at the equator by multiplying with
     *  kGMSEquatorProjectedMeter, equal to 1/(pi * EarthRadius).
     *  Projected length may be useful, for example, to specify segments with the same visual length
     *  regardless of latitude.
     */
    UCLengthProjected
} UCLengthKind;

@interface UCPath (UCPathLength)

/*!
 *  \~chinese
 *  返回沿着| length |对应的路径的分段数，根据| kind |解释。请参阅UCLengthKind。
 *
 *  \~english
 *  Returns the fractional number of segments along the path that correspond to |length|,
 *  interpreted according to |kind|. See GMSLengthKind.
 */
- (double)segmentsForLength:(CLLocationDistance)length kind:(UCLengthKind)kind;

/*!
 *  \~chinese
 *  根据| kind |返回路径的长度。请参阅UCLengthKind。
 *
 *  \~english
 *  Returns the length of the path, according to |kind|. See UCLengthKind.
 */
- (CLLocationDistance)lengthOfKind:(UCLengthKind)kind;

@end

NS_ASSUME_NONNULL_END
