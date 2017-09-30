//
//  UCUISettings.h
//  AeroMapSDK
//
//  Created by 北京国泰北斗科技有限公司 on 2017/3/13.
//  Copyright © 2017年 北京国泰北斗科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UCUISettings : NSObject

/*!
 *  \~chinese
 *  设置是否启用所有手势（默认）或禁用。这不会限制用户点击屏幕上的任何按钮去
 *  移动相机（例如，罗盘或缩放控件），也不限制程序化运动和动画。
 *
 *  \~english
 *  Sets the preference for whether all gestures should be enabled (default) or
 *  disabled. This doesn't restrict users from tapping any on screen buttons to
 *  move the camera (e.g., compass or zoom controls), nor does it restrict
 *  programmatic movements and animation.
 */
- (void)setAllGesturesEnabled:(BOOL)enabled;

/*!
 *  \~chinese
 *  控制是启用（默认）还是禁用滚动手势。如果启用后，用户可以拖动以平移相机。这不限制程序化
 *  相机的运动。
 *
 *  \~english
 *  Controls whether scroll gestures are enabled (default) or disabled. If
 *  enabled, users may drag to pan the camera. This does not limit programmatic
 *  movement of the camera.
 */
@property(nonatomic, assign) BOOL scrollGestures;

/*!
 *  \~chinese
 *  控制是启用缩放手势（默认）还是禁用缩放手势。如果启用时，用户可以双击/两指点击或双指缩放相机
 *  这不限制相机的编程移动。
 *
 *  \~english
 *  Controls whether zoom gestures are enabled (default) or disabled. If
 *  enabled, users may double tap/two-finger tap or pinch to zoom the camera
 *  This does not limit programmatic movement of the camera.
 */
@property(nonatomic, assign) BOOL zoomGestures;

/*!
 *  \~chinese
 *  控制倾斜手势是启用（默认）还是禁用。如果启用，用户可以使用双指垂直向下或向上滑动来倾斜相机。这个
 *  不限制通过程序化设置相机的视图角度。
 *
 *  \~english
 *  Controls whether tilt gestures are enabled (default) or disabled. If enabled,
 *  users may use a two-finger vertical down or up swipe to tilt the camera. This
 *  does not limit programmatic control of the camera's viewingAngle.
 */
@property(nonatomic, assign) BOOL tiltGestures;

/*!
 *  \~chinese
 *  控制旋转手势是启用（默认）还是禁用。如果启用时，用户可以使用两指旋转手势来旋转相机。这个
 *  不限制相机轴承的程序控制。
 *
 *  \~english
 *  Controls whether rotate gestures are enabled (default) or disabled. If
 *  enabled, users may use a two-finger rotate gesture to rotate the camera. This
 *  does not limit programmatic control of the camera's bearing.
 */
@property(nonatomic, assign) BOOL rotateGestures;

/*!
 *  \~chinese
 *  控制是否启用用户作用在UCMapView上的自定义手势（默认为YES）。这防止这些手势被父视图接收。
 *  当UCMapView包含一个UIScrollView(或其他可滚动区域)，这意味着地图上的手势将不会作用于scroll的手势
 *  但是，禁用此选项（设置为NO）可能有助于支持复杂视图层次结构或需求
 *
 *  \~english
 *  Controls whether gestures by users are completely consumed by the UCMapView
 *  when gestures are enabled (default YES).  This prevents these gestures from
 *  being received by parent views.
 *  When the UCMapView is contained by a UIScrollView (or other scrollable area),
 *  this means that gestures on the map will not be additional consumed as scroll
 *  gestures.  However, disabling this (set to NO) may be useful to support
 *  complex view hierarchies or requirements.
 */
@property(nonatomic, assign) BOOL consumesGesturesInView;

/*!
 *  \~chinese
 *  启用或禁用指南针。指南针是地图上的一个图标表示地图上的北方向。
 *  如果启用，则仅当相机旋转离开其默认值时才会显示方位（方位为0）。当用户点击指南针时，相机会定向
 *  本身到其默认方向，并在不久之后消失。如果禁用，指南针将永远不会显示。
 *
 *  \~english
 *  Enables or disables the compass. The compass is an icon on the map that
 *  indicates the direction of north on the map.
 *  If enabled, it is only shown when the camera is rotated away from its default
 *  orientation (bearing of 0). When a user taps the compass, the camera orients
 *  itself to its default orientation and fades away shortly after. If disabled,
 *  the compass will never be displayed.
 */
@property(nonatomic, assign) BOOL compassButton;

/*!
 *  \~chinese
 *  启用（默认）或禁用室内地面选择器。如果启用，它只是当视图集中在具有室内地板数据的建筑物时可见。
 *  如果禁用，则仍可以通过编程方式控制所选楼层indoorDisplay的mapView属性。
 *
 *  \~english
 *  Enables (default) or disables the indoor floor picker. If enabled, it is only
 *  visible when the view is focused on a building with indoor floor data.
 *  If disabled, the selected floor can still be controlled programmatically via
 *  the indoorDisplay mapView property.
 */
@property(nonatomic, assign) BOOL indoorPicker;

/*!
 *  \~chinese
 *  控制旋转和缩放手势是否可以偏心移动和滚动(默认为YES)。
 *
 *  \~english
 *  Controls whether rotate and zoom gestures can be performed off-center and scrolled around
 *  (default YES).
 */
@property(nonatomic, assign) BOOL allowScrollGesturesDuringRotateOrZoom;

@end
