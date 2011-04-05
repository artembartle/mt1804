//
//  mt1804ViewController.h
//  mt1804
//
//  Created by bartle on 3/20/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#include "Register.h"
#include "Multiplexer.h"

@interface mt1804ViewController : UIViewController 
{
	Register microCommand;
	Multiplexer mux;
	Tetrad data;
	Tetrad address;
	
	IBOutlet UIImageView *VD1;
	IBOutlet UIImageView *VD2;
	IBOutlet UIImageView *VD3;
	IBOutlet UIImageView *VD4;
	
	IBOutlet UIImageView *VD5;
	IBOutlet UIImageView *VD6;
	IBOutlet UIImageView *VD7;
	IBOutlet UIImageView *VD8;
}

-(void)changeBtnState:(UIButton*)button;
-(IBAction)muxChanged: (id)sender;
-(IBAction)dataChanged: (id)sender;
-(IBAction)addressChanged: (id)sender;
-(IBAction)load;
-(IBAction)viewMemoryState;
-(void)changeMemoryState:(int)number;
-(void)changeMicroCommandState:(int)number;
@end

