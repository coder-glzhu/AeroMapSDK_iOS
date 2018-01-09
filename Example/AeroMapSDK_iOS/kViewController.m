//
//  kViewController.m
//  AeroMapSDK_iOS
//
//  Created by GL-ZHU on 09/30/2017.
//  Copyright (c) 2017 GL-ZHU. All rights reserved.
//

#import "kViewController.h"
#import <AeroMapSDK/AeroMapSDK.h>

@interface kViewController ()

@end

@implementation kViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	
    AeroMapView *mapView = [[AeroMapView alloc] init];
    mapView.frame = CGRectMake(0, 0, self.view.bounds.size.width, self.view.bounds.size.height);
    [self.view addSubview:mapView];
    
    AirspaceOverLayer *lay = [AirspaceOverLayer overLayerWithMapView:mapView.mapView];
    [lay addOverLayerWithlayerName:(AirspaceOverLayerNameFreeZone|AirspaceOverLayerNameDangerous)];
    
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
