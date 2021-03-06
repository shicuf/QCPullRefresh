//
//  QCPullRefreshControl.h
//  QCPullRefresh
//
//  Created by QC.L on 16/6/24.
//  Copyright © 2016年 QC.L. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UIView+QCAttribute.h"
#import "UIScrollView+QCAttribute.h"
#import "QCPullRefreshConst.h"

typedef NS_ENUM(NSUInteger, QCRefreshState) {
    // 普通状态
    QCRefreshStateNormal = 1,
    // 松开就可以刷新的状态
    QCRefreshStatePulling,
    // 正在刷新状态
    QCRefreshStateRefreshing,
    // 将要刷新的状态
    QCRefreshStateWillRefresh,
    // 没有更多数据的状态
    QCRefreshStateNoMoreData
};

/** 进入刷新状态回调 */
typedef void(^QCRefreshBaseControlRefreshingBlock)();
/** 开始刷新后的回调(进入刷新状态后的回调) */
typedef void(^QCRefreshBaseControlBeginRefreshingCompletionBlock)();
/** 结束刷新后回调 */
typedef void(^QCRefreshBaseControlEndRefreshingCompletionBlock)();

@interface QCPullRefreshBaseControl : UIView {
    // 存储下拉偏移
    UIEdgeInsets _scrollViewOriginalInset;
    // 父控件
    __weak UIScrollView *_scrollView;
}

#pragma mark - refresh callback
/** 正在刷新回调 */
@property (nonatomic, copy) QCRefreshBaseControlRefreshingBlock refreshingBlock;
/** 开始刷新回调 */
@property (nonatomic, copy) QCRefreshBaseControlBeginRefreshingCompletionBlock beginRefreshingCompletionBlock;
/** 结束刷新回调 */
@property (nonatomic, copy) QCRefreshBaseControlEndRefreshingCompletionBlock endRefreshingCompletionBlock;
/** 回调的target action */
- (void)setRefreshingTarget:(id)refreshingTarget refreshingAction:(SEL)refreshingAction;
@property (nonatomic, weak) id refreshingTarget;
@property (nonatomic, assign) SEL refreshingAction;

- (void)executeRefreshingCallback;

#pragma mark - refresh state control
@property (nonatomic, assign) BOOL isHaveAnimationEndRefresh;
/** 进入刷新状态 */
- (void)beginRefreshing;
/** 结束刷新状态 */
- (void)endRefreshing;
/** 结束刷新状态 是否包含动画 */
- (void)endRefreshingAnimation:(BOOL)isAnimation;
/**
 *  结束刷新状态
 *
 *  @param isAnimation 是否包含动画
 *  @param completion  结束刷新时回调
 */
- (void)endRefreshingAnimation:(BOOL)isAnimation
                    completion:(QCRefreshBaseControlEndRefreshingCompletionBlock)completion;

/** 判断是否正在刷新 */
- (BOOL)isRefreshing;
/** 刷新状态 */
@property (nonatomic, assign) QCRefreshState state;

@property (nonatomic, assign, readonly) UIEdgeInsets scrollViewOriginalInset;
@property (nonatomic, weak, readonly) UIScrollView *scrollView;

- (void)prepare NS_REQUIRES_SUPER;
- (void)placeSubviews NS_REQUIRES_SUPER;
- (void)scrollViewContentOffsetDidChange:(NSDictionary *)change NS_REQUIRES_SUPER;
- (void)scrollViewContentSizeDidChange:(NSDictionary *)change NS_REQUIRES_SUPER;
- (void)scrollViewPanStateDidChange:(NSDictionary *)change NS_REQUIRES_SUPER;

@property (assign, nonatomic) CGFloat pullingPercent;
@property (assign, nonatomic, getter=isAutomaticallyChangeAlpha) BOOL automaticallyChangeAlpha;
@end

@interface UILabel (QCPullRefresh)
+ (instancetype)qc_label;
- (CGFloat)qc_textWidth;
@end
