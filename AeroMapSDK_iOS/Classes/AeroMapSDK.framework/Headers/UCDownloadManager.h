//
//  UCDownloadManager.h
//  SDK开发版本
//
//  Created by 北京国泰北斗科技有限公司 on 2016/12/30.
//  Copyright © 2016年 北京国泰北斗科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
@class UCDownloadArea;

typedef void(^DownloadBlock)(float progress);
typedef void(^CompletionBlock)(void);


@interface UCDownloadManager : NSObject

+ (instancetype)defaultManager;

///Start download
- (void)beginDownloadWith:(UCDownloadArea *)download
                WithBlcok:(DownloadBlock)block
           withCompletion:(CompletionBlock)completionBlock;

///Pause the download
- (void)pauseDownload;

///Restore the download
- (void)recoverDownloadWithName:(NSString *)name
                      withBlcok:(DownloadBlock)block
                 withCompletion:(CompletionBlock)completionBlock;

///Remove the cache
- (void)removeCache:(NSString *)cacheName;

///An object that contains data for the currently downloaded information
@property(nonatomic,strong,readonly)UCDownloadArea *download;
@end
