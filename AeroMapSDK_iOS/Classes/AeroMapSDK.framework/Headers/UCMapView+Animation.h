//
//  UCMapView+Animation.h
//  AeroMapSDK
//
//  Created by 北京国泰北斗科技有限公司 on 2017/3/22.
//  Copyright © 2017年 北京国泰北斗科技有限公司. All rights reserved.
//

#import <AeroMapSDK/AeroMapSDK.h>
@class UCCoordinateBounds;

@interface UCMapView (Animation)

- (void)animationToBounds:(UCCoordinateBounds *)bounds;

- (void)animationToZoom:(float)zoom;
@end
