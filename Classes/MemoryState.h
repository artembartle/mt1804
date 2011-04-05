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
	IBOutlet UILabel *tetr0;
	IBOutlet UILabel *tetr1;
	IBOutlet UILabel *tetr2;
	IBOutlet UILabel *tetr3;
	IBOutlet UILabel *tetr4;
	IBOutlet UILabel *tetr5;
	IBOutlet UILabel *tetr6;
	IBOutlet UILabel *tetr7;
	
	Register *microComand;
}

@property(nonatomic) Register *microComand;

-(NSString*)labelForTetrade:(int)numTetrade;
-(IBAction)onBack;

@end
