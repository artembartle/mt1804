//
//  MemoryState.h
//  mt1804
//
//  Created by bartle on 4/5/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#include "Register.h"


@interface MemoryState : UIViewController 
{
	IBOutlet UIScrollView *scrollView;
}

-(NSString*)labelForTetrade:(int)numTetrade atRegister:(int)numRegister;
-(IBAction)onBack;

@end
