//
//  UCCusterManager.h
//  SDK开发版本
//
//  Created by 北京国泰北斗科技有限公司 on 2017/3/21.
//  Copyright © 2017年 北京国泰北斗科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UCMapView.h"
#import "UCCluster.h"
#import "UCClusterItem.h"
@class UCClusterManager;

/*!
 *  \~chinese
 *  聚合管理者Delegate
 *
 *  \~english
 *  ClusterManagerDelegate
 */
@protocol UCClusterManagerDelegate<NSObject>
@optional

/*!
 *  \~chinese
 *  点击聚合点的回调
 *
 *  \~english
 *  Called when the user taps on a cluster marker.
 */
- (BOOL)clusterManager:(UCClusterManager *)clusterManager didTapCluster:(id<UCCluster>)cluster;

/*!
 *  \~chinese
 *  点击展开点的回调
 *
 *  \~english
 *  Called when the user taps on a cluster item marker
 */
- (BOOL)clusterManager:(UCClusterManager *)clusterManager didTapClusterItem:(id<UCClusterItem>)clusterItem;

/*!
 *  \~chinese
 *  当聚合点将要展开时候显示的图片
 */
- (UIImage *)clusterManager:(UCClusterManager *)clusterManager willExpansion:(id<UCClusterItem>)clusterItem;

- (void)clusterManager:(UCClusterManager *)clusterManager willExpansion:(id<UCClusterItem>)clusterItem block:(void (^)(UIImage *, CGPoint))block;
@end


/*!
 *  \~chinese
 *  聚合管理者
 *
 *  \~english
 *  UCClusterManager
 */
@interface UCClusterManager : NSObject<UCMapViewDelegate>

/*!
 *  \~chinese
 *  聚合管理者代理
 *
 *  \~english
 *  ClusterManagerDelegate
 */
@property(nonatomic,readonly,weak) id<UCClusterManagerDelegate> delegate;

/*!
 *  \~chinese
 *  地图代理
 *
 *  \~english
 *  MapDelegate
 */
@property(nonatomic,readonly,weak) id<UCMapViewDelegate> mapDelegate;

/*!
 *  \~chinese
 *  聚合管理者的初始化方法
 *  @param buckets  要严格递增 例如:@[@(20),@(50),@(500),@(1000)]
 *  @param backgroundImages buckets和backgroundImages 必须要一一对应，buckets的图片不能对应一个空的数据
 *
 *  \~english
 *  Initializes the class with a list of buckets and the corresponding background images.
 *  The backgroundImages array should ideally be big enough to hold the cluster label.
 *  Notes:
 *  - |buckets| should be strictly increasing. For example: @[@10, @20, @100, @1000].
 *  - |buckets| and |backgroundImages| must have equal non zero lengths.
 */
- (instancetype)initWithMap:(UCMapView *)mapView
            initWithBuckets:(NSArray<NSNumber *> *)buckets
           backgroundImages:(NSArray<UIImage *> *)backgroundImages;

/*!
 *  \~chinese
 *  设置聚合和地图的代理
 *
 *  \~english
 *  set clusterDelegate and mapDelegate
 */
- (void)setDelegate:(id <UCClusterManagerDelegate>)delegate
        mapDelegate:(id <UCMapViewDelegate>)mapDelegate;

/**
 改变展开item的图标和信息标签
 */
- (void)changeItemIcon:(id<UCClusterItem>)item icon:(UIImage *)icon groundAnchor:(CGPoint)groundAnchor;
/*!
 *  \~chinese
 *  添加聚合点
 *
 *  \~english
 *  add clusteritem
 */
- (void)addItem:(id <UCClusterItem>)item;
/*!
 *  \~chinese
 *  更新聚合点
 *
 *  \~english
 *  update clusteritem
 */
- (void)updateItem:(id <UCClusterItem>)item;

/*!
 *  \~chinese
 *  添加一组聚合点
 *
 *  \~english
 *  add clusterItems
 */
- (void)addItems:(NSArray<id<UCClusterItem>> *)items;

/*!
 *  \~chinese
 *  删除一个clusterItem
 *
 *  \~english
 *  delegate a clusterItem
 */
- (void)removeItem:(id <UCClusterItem>)item;

/*!
 *  \~chinese
 *  删除所有的聚合点
 *
 *  \~english
 *  delegate all clusterItems
 */
- (void)clearItems;

/*!
 *  \~chinese
 *  绘制
 *
 *  \~english
 *  draw ClusterItem
 */
- (void)cluster;
@end
