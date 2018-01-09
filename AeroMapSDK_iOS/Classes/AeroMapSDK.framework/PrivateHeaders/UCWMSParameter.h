//
//  UCWMSParameter.h
//  6789
//
//  Created by 北京国泰北斗科技有限公司 on 16/7/5.
//  Copyright © 2016年 北京国泰北斗科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UCWMSParameter : NSObject

@property(nonatomic,copy)NSString *url;
@property(nonatomic,copy)NSString *name;
@property(nonatomic,assign)NSInteger buffer;
@property(nonatomic,copy)NSString *featureID;
@property(nonatomic,copy)NSString *filter;

/**地图类型*/
@property(nonatomic,copy)NSString *mapType;

/**
 *  图层的唯一标识符
 */
@property(nonatomic,copy)NSString *layerKey;

- (NSString *)stringUTF8:(NSString *)string;
@end
