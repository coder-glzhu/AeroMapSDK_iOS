//
//  AeroMapView.h
//  AeroMapView
//
//  Created by 朱国良 on 2018/1/9.
//

#import <UIKit/UIKit.h>
@class GMSMapView;

typedef NS_ENUM(NSUInteger, AeroMapViewMapType) {
    AeroMapViewMapTypeNormal,
    AeroMapViewMapTypeTerrain,
    AeroMapViewMapTypeSatellite,
};

@interface AeroMapView : UIView

@property(nonatomic,strong,readonly)GMSMapView *mapView;
@property(nonatomic,assign)AeroMapViewMapType mapViewType;


@end
