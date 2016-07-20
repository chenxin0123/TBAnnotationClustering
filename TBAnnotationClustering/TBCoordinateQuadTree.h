//
//  TBCoordinateQuadTree.h
//  TBAnnotationClustering
//
//  Created by Theodore Calmes on 9/27/13.
//  Copyright (c) 2013 Theodore Calmes. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBQuadTree.h"

/**
 *  旅馆信息
 */
typedef struct TBHotelInfo {
    char* hotelName;
    char* hotelPhoneNumber;
} TBHotelInfo;


@interface TBCoordinateQuadTree : NSObject
///四叉树
@property (assign, nonatomic) TBQuadTreeNode* root;

@property (strong, nonatomic) MKMapView *mapView;

- (void)buildTree;
- (NSArray *)clusteredAnnotationsWithinMapRect:(MKMapRect)rect withZoomScale:(double)zoomScale;

@end
