//
//  SkDrawRangeResult.h
//  SDK开发版本
//
//  Created by 北京国泰北斗科技有限公司 on 16/9/1.
//  Copyright © 2016年 北京国泰北斗科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UCDrawRangeResult : NSObject

/**
 *  类型polygon\circle
 */
@property(nonatomic,copy,readonly)NSString *type;
/**
 *  圆心
 */
@property(nonatomic,copy,readonly)NSString *center;
/**
 *  半径
 */
@property(nonatomic,copy,readonly)NSString *radius;
/**
 *  多边形区域坐标
 */
@property(nonatomic,copy,readonly)NSString *coord;
/**
 *  用户输入的原始坐标串
 */
@property(nonatomic,copy,readonly)NSString *originalCoord;
/**
 *  飞行范围描述
 */
@property(nonatomic,copy,readonly)NSString *areaRemark;

- (instancetype)initWithType:(NSString *)type
                  withCenter:(NSString *)center
                  withRadius:(NSString *)radius
                   withCoord:(NSString *)coord
           withOriginalCoord:(NSString *)originalCoord
              withAreaRemark:(NSString *)areaRemark;
@end
