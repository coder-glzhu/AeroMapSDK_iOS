//
//  UCMapView.h
//
//  Created by 朱国良 on 16/7/1.
//  Copyright © 2016年 北京国泰北斗科技有限公司. All rights reserved.

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
@class UCMarker,UCMapView,UAVModel,UCDrawRangeResult,UCUISettings;

NS_ASSUME_NONNULL_BEGIN

//最大层级
FOUNDATION_EXTERN const float kAMMaxZoomLevel;

//最小层级
FOUNDATION_EXTERN const float kAMMinZoomLevel;

/*!
 *  \~chinese
 *  mapView缓存的key
 *
 *  \~english
 *  This is a identifier of mapCache
 */
extern NSString * const AreoMapCache;

/*!
 *  \~chinese
 *  mapView的代理方法
 *
 *  \~english
 *  MapViewDelegate
 */
@protocol UCMapViewDelegate <NSObject>
@optional

/*!
 *  \~chinese
 *  改变地图位置或者是缩放地图时候调用
 *
 *  \~english
 *  Called after change mapView camera
 */
- (void)mapView:(UCMapView *)mapView didChangeCameraPosition:(CLLocationCoordinate2D)position;

/*!
 *  \~chinese
 *  当地图处于闲置时被调用(在任何手势，或者是动画结束之后调用)
 *
 *  \~english
 *  Called when the map becomes idle, after any outstanding gestures or
 *  animations have completed (or after the camera has been explicitly set)
 */
- (void)mapView:(UCMapView *)mapView idleAtCameraPosition:(CLLocationCoordinate2D)position;
/*!
 *  \~chinese
 *  点击地图特定的位置时调用。
 *
 *  \~english
 *  Called after a tap gesture at a particular coordinate, but only if a marker
 *  was not tapped.  This is called before deselecting any currently selected
 *  marker (the implicit action for tapping on the map).
 */
- (void)mapView:(UCMapView *)mapView didTapAtCoordinate:(CLLocationCoordinate2D)coordinate;

/*!
 *  \~chinese
 *   在地图上的摄像机调用之前调用，由于手势，动画（例如，通过用户点击“我的位置”按钮）或通过存在
 *  通过摄像机明确地更新或在层上零长度的动画。gesture如果是，则由于用户手势而发生。
 *
 *  \~english
 *  Called before the camera on the map changes, either due to a gesture,
 *  animation (e.g., by a user tapping on the "My Location" button) or by being
 *  updated explicitly via the camera or a zero-length animation on layer.
 *  gesture If YES, this is occuring due to a user gesture.
 */
- (void)mapView:(UCMapView *)mapView willMove:(BOOL)gesture;

/*!
 *  \~chinese
 *  在特定坐标长按手势后调用
 *
 *  \~english
 *  Called after a long-press gesture at a particular coordinate.
 */
- (void)mapView:(UCMapView *)mapView didLongPressAtCoordinate:(CLLocationCoordinate2D)coordinate;

/*!
 *  \~chinese
 *  点击marker调用
 *  如果返回YES，代理将处理了点击事件，则会阻止该地图从执行其默认选择行为，否则地图
 *  应继续其默认选择行为。
 *
 *  \~english
 *  在轻击标记后调用。
 *  YES if this delegate handled the tap event, which prevents the map
 *  from performing its default selection behavior, and NO if the map
 *  should continue with its default selection behavior.
 */
- (BOOL)mapView:(UCMapView *)mapView didTapMarker:(UCMarker *)marker;

/*!
 *  \~chinese
 *  在轻按标记的信息窗口后调用。
 *
 *  \~english
 *  Called after a marker's info window has been tapped.
 */
- (void)mapView:(UCMapView *)mapView didTapInfoWindowOfMarker:(UCMarker *)marker;

/*!
 *  \~chinese
 *  在长按标记的信息窗口后调用。
 *
 *  \~english
 *  Called after a marker's info window has been long pressed.
 */
- (void)mapView:(UCMapView *)mapView didLongPressInfoWindowOfMarker:(UCMarker *)marker;

/*!
 *  \~chinese
 *  当标记即将被选中时调用，如果此方法返回一个UIView，就为marker提供了自定义信息窗口。
 *  如果在此方法执行之后改变这个视图，将不会更改已经呈现出来的视图信息。
 *  返回的UIView不能有大于500像素的边界。由于在任何时间只显示一个信息窗口，所以返回
 *  视图可以在其他信息窗口之间重复使用。
 *  在地图中移除标记或在地图中更改地图的所选标记，此方法不触发。返回指定标记的自定义信息窗口，或默认值nil
 *
 *  \~english
 *  Called when a marker is about to become selected, and provides an optional
 *  custom info window to use for that marker if this method returns a UIView.
 *  If you change this view after this method is called, those changes will not
 *  necessarily be reflected in the rendered version.
 *  The returned UIView must not have bounds greater than 500 points on either
 *  dimension.  As there is only one info window shown at any time, the returned
 *  view may be reused between other info windows.
 *  Removing the marker from the map or changing the map's selected marker during
 *  this call results in undefined behavior.
 *  @return The custom info window for the specified marker, or nil for default
 */
- (UIView *)mapView:(UCMapView *)mapView markerInfoWindow:(UCMarker *)marker;

/*!
 *  \~chinese
 *  当调用mapView：markerInfoWindow：返回nil时调用。如果此方法返回一个视图，它将被放置在默认信息窗口框架内。如果这个方法
 *  返回nil，那么将使用默认方式渲染。
 *
 *  \~english
 *  Called when mapView:markerInfoWindow: returns nil. If this method returns a
 *  view, it will be placed within the default info window frame. If this method
 *  returns nil, then the default rendering will be used instead.
 */
- (UIView *)mapView:(UCMapView *)mapView markerInfoContents:(UCMarker *)marker;

/*!
 *  \~chinese
 *  标记的信息窗口关闭时调用。
 *
 *  \~english
 *  Called when the marker's info window is closed.
 */
- (void)mapView:(UCMapView *)mapView didCloseInfoWindowOfMarker:(UCMarker *)marker;

/*!
 *  \~chinese
 *  标记开始拖拽前调用
 *
 *  \~english
 *  Called when dragging has been initiated on a marker.
 */
- (void)mapView:(UCMapView *)mapView didBeginDraggingMarker:(UCMarker *)marker;

/*!
 *  \~chinese
 *  标记拖拽结束时候调用
 *
 *  \~english
 *  Called after dragging of a marker ended.
 */
- (void)mapView:(UCMapView *)mapView didEndDraggingMarker:(UCMarker *)marker;

/*!
 *  \~chinese
 *  标记被拖拽的时候调用
 *
 *  \~english
 *  Called while a marker is dragged.
 */
- (void)mapView:(UCMapView *)mapView didDragMarker:(UCMarker *)marker;
@end

typedef enum {
    UCMapViewSTypeNormal = 1,
    UCMapViewTypeTerrain,
    UCMapViewTypeSatellite,
} UCMapType;

@interface UCMapView : UIView

/*!
 *  \~chinese
 *  设置最大的缓存值（默认是200兆）
 *
 *  \~english
 *  MaxCache（Default 200MB)
 */
@property(nonatomic,assign)NSInteger maxCache;

/*!
 *  \~chinese
 *  获取缓存的当前状态，此属性在受限空域中使用。如果要控制是否打开缓存，请在初始化方法中设置。
 *
 *  \~english
 *  Gets the current status of the cache, this property is used in the restricted airspace.
 *  If you want to control whether open cache,please set in the initialization method.
 */
@property(nonatomic,assign,readonly)BOOL openCache;

/*!
 *  \~chinese
 *  MapView代理
 *
 *  \~english
 *  This property is the mapView of proxy object
 */
@property(nonatomic,weak)id<UCMapViewDelegate>delegate;

/*!
 *  \~chinese
 *  开启定位，默认是NO
 *
 *  \~english
 *  Open the position function Default NO.
 */
@property(nonatomic,assign)BOOL myLocationEnabled;

/*!
 *  \~chinese
 *  获取UCUISettings对象，该对象控制地图的用户界面设置。
 *
 *  \~english
 *  Gets the UCUISettings object, which controls user interface settings for the map.
 */
@property(nonatomic, strong, readonly) UCUISettings *settings;

/*!
 *  \~chinese
 *  如果启用了“我的位置”，则会显示正在绘制用户位置点的位置。
 *  如果已禁用或已启用，但没有位置数据可用，则此值将为零。此属性可使用KVO观察
 *
 *  \~english
 *  If My Location is enabled, reveals where the user location dot is being drawn.
 *  If it is disabled, or it is enabled but no location data is available,this will be nil. This property is observable using KVO
 */
@property(nonatomic, strong, readonly) CLLocation *myLocation;

/*!
 *  \~chinese
 *  构造一个mapView对象，zoom是初始化时候缩放到什么层级（3-18）
 *
 *  \~english
 *  Builds and returns a UCMapView,with position,zoom and cache.
 Zoom ratio between 3 to 18
 */
+ (instancetype)creatMapViewWithLatitude:(CLLocationDegrees)latitude
                           withLongitude:(CLLocationDegrees)longitude
                                withZoom:(float)zoom
                        withOpenMapCache:(BOOL)cache;

/*!
 *  \~chinese
 *  根据一个区域初始化地图 Default Area POLYGON((longitude latitude,longitude latitude......))
 *
 *  \~english
 *  Builds and returns a UCmapView according to to the area by default bounds
 *  Default Area POLYGON((longitude latitude,longitude latitude......))
 */
+ (instancetype)creatMapViewWithLocationBounds:(NSString *)bounds
                              withOpenMapCache:(BOOL)cache;


/*!
 *  \~chinese
 *  清除所有的瓦片后，会重新请求一次瓦片
 *
 *  \~english
 *  Clears the cache so that all tiles will be requested again
 */
- (void)clearTileCache;

/*!
 *  \~chinese
 *  坐标转换
 *
 *  \~english
 *  Coordinate transformation
 */
- (CLLocationCoordinate2D)wgs84ToGcj02WithPosition:(CLLocationCoordinate2D)position;

/*!
 *  \~chinese
 *  将屏幕坐标转换为经纬度坐标
 *
 *  \~english
 *  Converts the screen coordinates to latitude and longitude coordinates
 */
- (CLLocationCoordinate2D)screenCoordinatesToGeographicCoordinates:(double)screenX with:(double)screenY;


/*!
 *  \~chinese
 *  将经纬度坐标转换为屏幕坐标
 *
 *  \~english
 *  Converts latitude and longitude coordinates to screen coordinates
 */
- (CGPoint)geographicCoordinatesTurnScreenCoordinates:(CLLocationCoordinate2D)position;

/*!
 *  \~chinese
 *  将屏幕坐标转换为经纬度
 *
 *  \~english
 *  Maps a point coordinate in the map's view to an Earth coordinate.
 */
- (CLLocationCoordinate2D)coordinateForPoint:(CGPoint)point;

/*!
 *  \~chinese
 *  改变地图的显示类型
 *
 *  \~english
 *  Controls the type of map tiles that should be displayed. Defaults to
 *  UCMapViewSTypeNormal.
 */
- (void)changeMapView:(UCMapType)mapViewType;

/*!
 *  \~chinese
 *  放大
 *
 *  \~english
 *  As animateToCameraPosition:, but amplified only the zoom level of the camera.
 */
- (void)zoomIn;

/*!
 *  \~chinese
 *  缩小
 *
 *  \~english
 *  As animateToCameraPosition:, but narrow only the zoom level of the camera.
 */
- (void)zoomOut;

/*!
 *  \~chinese
 *  清除缓存
 *
 *  \~english
 *  Clear map cache
 */
- (void)clearMapCache;




/***************************************************************************************/
/**
 以下是在绘制无人机以及显示绘制区域的接口
 */


/**
 移动无人机到地图中心
 position 无人机位置
 */
- (void)toMapCenter:(CLLocationCoordinate2D)position;

/**
 根据绘制的结果预览图形
 drawRangeResult 绘制结果对象
 */
- (void)previewGraphicsWithDrawDrangeResult:(UCDrawRangeResult *)drawRangeResult;
@end

NS_ASSUME_NONNULL_END
