//
//  UCMarker.h
//  SDK开发版本
//
//  Created by 朱国良 on 16/9/4.
//  Copyright © 2016年 北京国泰北斗科技有限公司. All rights reserved.
//

#import "UCOverlayer.h"
#import <CoreLocation/CoreLocation.h>
#import <UIKit/UIKit.h>
@class UCMapView;

NS_ASSUME_NONNULL_BEGIN

typedef enum {
    /** No animation (default). */
    kUCSMarkerAnimationNone = 0,
    kUCSMarkerAnimationPop,
} UCSMarkerAnimation;

@interface UCMarker : UCOverlayer

/**
 * marker的经纬度，此经纬度需要设置Gcj02的坐标系的坐标。如果设置84坐标会出现偏移问题
 * 如果需要将84坐标转换成Gcj02坐标@see UCMapView
 */
@property(nonatomic, assign) CLLocationCoordinate2D coordinate;

/**
 * Marker icon to render. If left nil, uses a default SDK place marker.
 *
 * Supports animated images, but each frame must be the same size or the
 * behavior is undefined.
 *
 * Supports the use of alignmentRectInsets to specify a reduced tap area.  This
 * also redefines how anchors are specified.  For an animated image the
 * value for the animation is used, not the individual frames.
 */
@property(nonatomic, strong) UIImage *icon;

/**
 * Controls the animation used when this marker is placed on a UCMapView
 * (default kUCSMarkerAnimationNone, no animation).
 */
@property(nonatomic, assign) UCSMarkerAnimation appearAnimation;

/**
 * Sets the rotation of the marker in degrees clockwise about the marker's
 * anchor point. The axis of rotation is perpendicular to the marker. A rotation
 * of 0 corresponds to the default position of the marker. Animated.
 *
 * When the marker is flat on the map, the default position is north aligned and
 * the rotation is such that the marker always remains flat on the map. When the
 * marker is a billboard, the default position is pointing up and the rotation
 * is such that the marker is always facing the camera.
 */
@property(nonatomic, assign) CLLocationDegrees rotation;


/**
 * Marker view to render. If left nil, falls back to the |icon| property instead.
 *
 * Supports animation of all animatable properties of UIView, except |frame| and |center|. Changing
 * these properties or their corresponding CALayer version, including |position|, is not supported.
 *
 * Note that the view behaves as if |clipsToBounds| is set to YES, regardless of its actual
 * value.
 */
@property(nonatomic, strong) UIView *iconView;

/**
 * Controls whether the icon for this marker should be redrawn every frame.
 *
 * Note that when this changes from NO to YES, the icon is guaranteed to be redrawn next frame.
 *
 * Defaults to YES.
 * Has no effect if |iconView| is nil.
 */
@property(nonatomic, assign) BOOL tracksViewChanges;

/**
 * Controls whether the info window for this marker should be redrawn every frame.
 *
 * Note that when this changes from NO to YES, the info window is guaranteed to be redrawn next
 * frame.
 *
 * Defaults to NO.
 */
@property(nonatomic, assign) BOOL tracksInfoWindowChanges;

/**
 * The ground anchor specifies the point in the icon image that is anchored to
 * the marker's position on the Earth's surface. This point is specified within
 * the continuous space [0.0, 1.0] x [0.0, 1.0], where (0,0) is the top-left
 * corner of the image, and (1,1) is the bottom-right corner.
 *
 * If the image has non-zero alignmentRectInsets, the top-left and bottom-right
 * mentioned above refer to the inset section of the image.
 */
@property(nonatomic, assign) CGPoint groundAnchor;

/**
 * The info window anchor specifies the point in the icon image at which to
 * anchor the info window, which will be displayed directly above this point.
 * This point is specified within the same space as groundAnchor.
 */
@property(nonatomic, assign) CGPoint infoWindowAnchor;


/**
 * Controls whether this marker can be dragged interactively (default NO).
 */
@property(nonatomic, assign, getter=isDraggable) BOOL draggable;

/*!
 *  \~chinese
 *  标题、覆盖的一个简短的描述。一些覆盖,如标记,将显示在地图上。
 *
 *  \~english
 *  Title, a short description of the overlay. Some overlays, such as markers,
 *  will display the title on the map. The title is also the default
 *  accessibility text.
 */
@property(nonatomic, copy) NSString *title;

/*!
 *  \~chinese
 *  控制标记是否允许点击
 *
 *  \~english
 *  If this overlay should cause tap notifications. Some overlays, such as
 *  markers, will default to being tappable.
 */
@property(nonatomic, assign, getter=isTappable) BOOL tappable;

/*!
 *  \~chinese
 *  控制此标记是否应与地球表面相平行（是）
 *  或面向相机的广告牌（否，默认）。
 *
 *  \~english
 *  Controls whether this marker should be flat against the Earth's surface (YES)
 *  or a billboard facing the camera (NO, default).
 */
@property(nonatomic, assign, getter=isFlat) BOOL flat;

/*!
 *  \~chinese
 *  透明度（0-1）
 *
 *  \~english
 *  Sets the opacity of the marker, between 0 (completely transparent) and 1
 *  (default) inclusive.
 */
@property(nonatomic, assign) float opacity;

/*!
 *  \~chinese
 *  标记数据。您可以使用此属性将任意对象与这个标记进行绑定。iOS的AeroMap SDK既不读取也不写入此属性。
 *  请注意，userData不应该持有对任何地图的任何强引用对象，否则可能会创建一个循环（防止ARC释放对象）。
 *
 *  \~english
 *  Marker data. You can use this property to associate an arbitrary object with
 *  this marker. AeroMap SDK for iOS neither reads nor writes this property.
 *  Note that userData should not hold any strong references to any Maps
 *  objects, otherwise a loop may be created (preventing ARC from releasing
 *  objects).
 */
@property(nonatomic, strong) id userData;


/*!
 *  \~chinese
 *  创建一个默认的marker标注
 *
 *  \~english
 *  Create a default marker
 */
+ (instancetype)markerWithPosition:(CLLocationCoordinate2D)position;

/*!
 *  \~chinese
 *  判断是否与另一个marker是同一个对象。
 *  如果直接用(marker1 == marker2)会出错。想判断marker是都是同一个请务必用此方法
 *
 *  \~english
 *  Determine whether the same object is the same object as another marker.
 *  If the direct use (marker1 == marker2) will be a error. Want to judge the marker is the same one must use
 *  this method.
 */
- (BOOL)isEqualToOther:(UCMarker *)marker;
@end

NS_ASSUME_NONNULL_END
