//
//  UseYourSelfTitleViewController.m
//  QCPullRefreshDemo
//
//  Created by QC.L on 16/6/29.
//  Copyright © 2016年 QC.L. All rights reserved.
//

#import "UseYourSelfTitleViewController.h"

@interface UseYourSelfTitleViewController ()

@end

@implementation UseYourSelfTitleViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.tableView.qc_header = [QCPullRefreshAnimationHeader headerPullingTitle:@"Use Your Self Title" refreshingTitle:@"Your Self Title Refreshing" headerWithRefreshingBlock:^{
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(3 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            [self.tableView reloadData];
            [self.tableView.qc_header endRefreshing];
        });
    }];
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
