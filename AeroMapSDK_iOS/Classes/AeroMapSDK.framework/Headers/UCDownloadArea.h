//
//  UCDownloadArea.h
//  SDK开发版本
//
//  Created by 北京国泰北斗科技有限公司 on 2016/12/15.
//  Copyright © 2016年 北京国泰北斗科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
@class UCPath;

extern NSString * const kStartX;
extern NSString * const kStartY;
extern NSString * const kEndX;
extern NSString * const kEndY;

typedef enum : NSUInteger {
    UCDownloading,          //downloading
    UCDownloadCompletion,   //Download completed
    UCDownloadPause,        //Pause the download
} UCDownProgress;

@interface UCDownloadArea : NSObject<NSCoding>

- (instancetype)initGetDownloadAreaWith:(UCPath *)path withLevelsSet:(NSArray *)levelsSet;
- (void)getDownloadProgressWith:(int64_t)totalBytesWritten;



///The total number of downloads required
@property(nonatomic,assign,readonly)long long sumCount;
///Estimated memory for downloading data
@property(nonatomic,assign,readonly)double sumMemory;
///The amount of data that has been written
@property(nonatomic,assign,readonly)int64_t sumTotalBytesWritten;
///Download progress
@property(nonatomic,assign)float progress;
///The number has been downloaded
@property(nonatomic,assign)NSUInteger downloadCount;
///Download the map type
@property(nonatomic,copy)NSString *mapType;
///Download status
@property(nonatomic,assign)UCDownProgress progressState;
///The unique identifier for the cache
@property(nonatomic,copy)NSString *cacheName;
///All the data needed to download the hierarchy
@property(nonatomic,strong,readonly)NSMutableArray *levelArray;
///Save user-defined data
@property(nonatomic)id data;


///Record breakpoint download the last download xyz, used to restore the download
@property(nonatomic,assign,readonly)NSInteger x;
@property(nonatomic,assign,readonly)NSInteger y;
@property(nonatomic,assign,readonly)NSInteger z;

@end
