//
//  mt1804AppDelegate.h
//  mt1804
//
//  Created by bartle on 3/20/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@class mt1804ViewController;

@interface mt1804AppDelegate : NSObject <UIApplicationDelegate> {
    UIWindow *window;
    mt1804ViewController *viewController;
}

@property (nonatomic, retain) IBOutlet UIWindow *window;
@property (nonatomic, retain) IBOutlet mt1804ViewController *viewController;

@end

