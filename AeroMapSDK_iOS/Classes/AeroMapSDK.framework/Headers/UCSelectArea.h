//
//  UCSelectArea.h
//  SDK开发版本
//
//  Created by 北京国泰北斗科技有限公司 on 2017/2/13.
//  Copyright © 2017年 北京国泰北斗科技有限公司. All rights reserved.
//

#import "UCCustomComponent.h"

NS_ASSUME_NONNULL_BEGIN


@interface UCSelectArea : UCCustomComponent

@property(nonatomic,assign)BOOL openContentLabel;

/*!
 *  \~chinese
 *  设置选择区域数据标签的样式
 *
 *  \~english
 *  Sets the style of the selection area data label
 */
- (void)setContentLabelAttributes:(NSDictionary<NSString *,id> *)configDic;


/*!
 *  \~chinese
 *  点击marker弹出修改信息的视图，如果调用此方法会默认的弹出一个UI视图，暂不支持修改样式，如果不能满足需要，可以根据开发的需求自定义样式
 *
 *  \~english
 *  Pop view when tap marker
 */
- (void)popViewWhenTapMarker:(UCMarker *)marker;


@end

NS_ASSUME_NONNULL_END
