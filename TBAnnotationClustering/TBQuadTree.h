//
//  TBQuadTree.h
//  TBQuadTree
//
//  Created by Theodore Calmes on 9/19/13.
//  Copyright (c) 2013 Theodore Calmes. All rights reserved.
//

#import <Foundation/Foundation.h>
/**
 *  数据节点
 *  x 存放维度 latitude
 *  y 存放经度 longitude
 *  data 存放TBHotelInfo结构体指针
 */
typedef struct TBQuadTreeNodeData {
    double x;
    double y;
    void* data;
} TBQuadTreeNodeData;
TBQuadTreeNodeData TBQuadTreeNodeDataMake(double x, double y, void* data);

/**
 *  TBBoundingBox表示一个范围 存放两个对角点(左上角和右下角)
 *  x0 xf 表示维度
 *  y0 yf 表示经度
 */
typedef struct TBBoundingBox {
    double x0; double y0;
    double xf; double yf;
} TBBoundingBox;
TBBoundingBox TBBoundingBoxMake(double x0, double y0, double xf, double yf);

/**
 *  四叉树节点
 *  northWest。。。四个子节点
 *  boundingBox 范围
 *  bucketCapacity 可存储的数据节点个数 数据优先存储在本节点 当容量满时存放到子节点
 *  points 数据节点数组 大小为sizeof(TBQuadTreeNodeData) * bucketCapacity
 *  count 当前points数据节点个数
 */
typedef struct quadTreeNode {
    struct quadTreeNode* northWest;
    struct quadTreeNode* northEast;
    struct quadTreeNode* southWest;
    struct quadTreeNode* southEast;
    TBBoundingBox boundingBox;
    int bucketCapacity;
    TBQuadTreeNodeData *points;
    int count;
} TBQuadTreeNode;
TBQuadTreeNode* TBQuadTreeNodeMake(TBBoundingBox boundary, int bucketCapacity);

void TBFreeQuadTreeNode(TBQuadTreeNode* node);

bool TBBoundingBoxContainsData(TBBoundingBox box, TBQuadTreeNodeData data);
bool TBBoundingBoxIntersectsBoundingBox(TBBoundingBox b1, TBBoundingBox b2);

typedef void(^TBQuadTreeTraverseBlock)(TBQuadTreeNode* currentNode);
void TBQuadTreeTraverse(TBQuadTreeNode* node, TBQuadTreeTraverseBlock block);

typedef void(^TBDataReturnBlock)(TBQuadTreeNodeData data);
void TBQuadTreeGatherDataInRange(TBQuadTreeNode* node, TBBoundingBox range, TBDataReturnBlock block);

bool TBQuadTreeNodeInsertData(TBQuadTreeNode* node, TBQuadTreeNodeData data);
TBQuadTreeNode* TBQuadTreeBuildWithData(TBQuadTreeNodeData *data, int count, TBBoundingBox boundingBox, int capacity);
