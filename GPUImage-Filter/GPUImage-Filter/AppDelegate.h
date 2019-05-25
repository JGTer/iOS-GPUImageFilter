//
//  AppDelegate.h
//  GPUImage-Filter
//
//  Created by jgt on 2019/5/25.
//  Copyright © 2019 jgt. All rights reserved.
//

#import <UIKit/UIKit.h>
@class ShowcaseFilterListController;
@interface AppDelegate : UIResponder <UIApplicationDelegate>
{
    UINavigationController *filterNavigationController;
    
    ShowcaseFilterListController *filterListController;
}
@property (strong, nonatomic) UIWindow *window;


@end

