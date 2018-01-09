//
//  AMNetworkTool.h
//  AeroMapSDK
//
//  Created by 朱国良 on 2017/9/14.
//  Copyright © 2017年 北京国泰北斗科技有限公司. All rights reserved.
//

#import <XMNetworking/AFNetworking.h>

@interface AMNetworkTool : AFHTTPSessionManager

+ (instancetype)shareIntance;

@end
