//
//  UCLine.h
//  SDK开发版本
//
//  Created by 北京国泰北斗科技有限公司 on 2016/11/15.
//  Copyright © 2016年 北京国泰北斗科技有限公司. All rights reserved.
//

#import "UCOverlayer.h"
#import <UIKit/UIKit.h>
@class UCPath,UCPath,UCMarker;

NS_ASSUME_NONNULL_BEGIN
/*!
 *  \~chinese
 *  描述实体（例如折线）的绘制样式
 *
 *  \~english
 *  Describes the drawing style for one-dimensional entities such as polylines.
 */
@interface UCStrokeStyle : NSObject

/*!
 *  \~chinese
 *  创建纯色笔画样式。
 *
 *  \~english
 *  Creates a solid color stroke style.
 */
+ (instancetype)solidColor:(UIColor *)color;

/*!
 *  \~chinese
 *  从| fromColor |创建一个渐变笔画样式插值到| toColor |。
 *
 *  \~english
 *  Creates a gradient stroke style interpolating from |fromColor| to |toColor|.
 */
+ (instancetype)gradientFromColor:(UIColor *)fromColor toColor:(UIColor *)toColor;

@end





/*!
 *  \~chinese
 *  描述折线的某些区域的样式
 *
 *  \~english
 *  Describes the style for some region of a polyline
 */
@interface UCStyleSpan : NSObject

/*!
 *  \~chinese
 *  工厂返回长度为一段的纯色跨度。相当于
    [UCStyleSpan spanWithStyle：[UCStrokeStyle solidColor：| color |] segments：1]
 *
 *  \~english
 *  Factory returning a solid color span of length one segment. Equivalent to
 *  [UCStyleSpan spanWithStyle:[UCStrokeStyle solidColor:|color|] segments:1].
 */
+ (instancetype)spanWithColor:(UIColor *)color;

/*!
 *  \~chinese
 *  工厂返回具有给定数量段的纯色跨度。相当于
 *  [UCStyleSpan spanWithStyle：[UCStrokeStyle solidColor：| color |] segments：| segments |]。
 *
 *  \~english
 *  Factory returning a solid color span with a given number of segments. Equivalent to
 *  [UCStyleSpan spanWithStyle:[UCStrokeStyle solidColor:|color|] segments:|segments|].
 */
+ (instancetype)spanWithColor:(UIColor *)color segments:(double)segments;

/*!
 *  \~chinese
 *  工厂返回给定| style |的span的长度一段。相当于
 *  [UCStyleSpan spanWithStyle：| style |段：1]。
 *
 *  \~english
 *  Factory returning a span with the given |style| of length one segment. Equivalent to
 *  [UCStyleSpan spanWithStyle:|style| segments:1].
 */
+ (instancetype)spanWithStyle:(UCStrokeStyle *)style;

/*!
 *  \~chinese
 *  工厂返回给定| style |的span和段数的长度。| segments |必须大于0（即不能为0）。
 *
 *  \~english
 *  Factory returning a span with the given |style| and length in number of segments.
 *  |segments| must be greater than 0 (i.e. can't be 0).
 */
+ (instancetype)spanWithStyle:(UCStrokeStyle *)style segments:(double)segments;

/*!
 *  \~chinese
 *  这个跨度的风格
 *
 *  \~english
 *  The style of this span
 */
@property(nonatomic, readonly) UCStrokeStyle *style;

/*!
 *  \~chinese
 *  段的长度（以段数表示）。
 *
 *  \~english
 *  The length of this span in number of segments.
 */
@property(nonatomic, readonly) double segments;

@end


@protocol UCPolineDelegate <NSObject>
@optional
- (UIImage *)showPolineMiddleLabelWithLabelContent:(NSString *)content;

@end


/*!
 *  \~chinese
 *  UCPolyline指定存在于地球表面的折线的可用选项。它被绘制为| path |中指定的点之间的物理线。
 *
 *  \~english
 *  UCPolyline specifies the available options for a polyline that exists on the Earth's surface.
 *  It is drawn as a physical line between the points specified in |path|.
 */
@interface UCPolyline : UCOverlayer

/*!
 *  \~chinese
 *  控制是否显示path中间的标签 默认是NO
 *
 *  \~english
 *  Control whether the path in the middle of the label (Default : NO)
 */
@property(nonatomic,assign)BOOL showLabel;

/*!
 *  \~chinese
 *  控制path中间标签的显示样式代理
 *
 *  \~english
 *  Control path between tag display agent
 */
@property(nonatomic,weak)id<UCPolineDelegate> delegate;

/*!
 *  \~chinese
 *  描述此折线的路径。
 *
 *  \~english
 *  The path that describes this polyline.
 */
@property(nonatomic, copy) UCPath *path;

/*!
 *  \~chinese
 *  屏幕点中线的宽度。默认值为1。
 *
 *  \~english
 *  The width of the line in screen points. Defaults to 1.
 */
@property(nonatomic, assign) CGFloat strokeWidth;

/*!
 *  \~chinese
 *  UIColor用于渲染折线。默认为[UIColor blueColor]。
 *
 *  \~english
 *  The UIColor used to render the polyline. Defaults to [UIColor blueColor].
 */
@property(nonatomic, strong) UIColor *strokeColor;

/*!
 *  \~chinese
 *  是否应该使用测地校正来渲染此线。
 *
 *  \~english
 *  Whether this line should be rendered with geodesic correction.
 */
@property(nonatomic, assign) BOOL geodesic;

/*!
 *  \~chinese
 *  包含UCStyleSpan的数组，用于渲染此折线的跨度。
 *  如果此数组包含的段数少于折线本身，则将应用最终段在剩余长度。如果此数组未设置或为空，则| strokeColor |用于
 *  整行代替。
 *
 *  \~english
 *  An array containing UCStyleSpan, the spans used to render this polyline.
 *  If this array contains fewer segments than the polyline itself, the final segment will be applied
 *  over the remaining length. If this array is unset or empty, then |strokeColor| is used for the
 *  entire line instead.
 */
@property(nonatomic, copy) NSArray<UCStyleSpan *> *spans;

/*!
 *  \~chinese
 *  UCPath的特殊路径的方便构造函数。其他属性会有默认值。
 *
 *  \~english
 *  Convenience constructor for UCPath for a particular path. Other properties will have
 *  default values.
 */
+ (instancetype)polylineWithPath:(UCPath *)path;

/*!
 *  \~chinese
 *  编辑UCPoline会弹出一下可以拖曳的点，如果不想使用默认的样式，可以自己根据需求设计样式
 *
 *  \~english
 *  Edit UCPoline will be able to pop up the point can be dragged, if you do not want to use the default style,
 *  you can design their own style
 */
- (void)compilePolyline;

/*!
 *  \~chinese
 *  结束编辑，将恢复之前的样式
 *
 *  \~english
 *  End editing will restore the previous style
 */
- (void)closeEiditPoline;

/*!
 *  \~chinese
 *  如果拖拽marker时候想修改path上对应位置的marker，可以调用此方法快速的返回一个修改后的path
 *
 *  \~english
 *  If you drag the marker when you want to modify the corresponding location on the path of the marker, you can
 *  call this method quickly return to a modified path.
 */
- (UCPath *)compilePolylineWithMarker:(UCMarker *)marker;

@end

NS_ASSUME_NONNULL_END
