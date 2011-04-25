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
	
	BOOL isWork;
	
	IBOutlet UIImageView *VD1;
	IBOutlet UIImageView *VD2;
	IBOutlet UIImageView *VD3;
	IBOutlet UIImageView *VD4;
	
	IBOutlet UIImageView *VD5;
	IBOutlet UIImageView *VD6;
	IBOutlet UIImageView *VD7;
	IBOutlet UIImageView *VD8;
	
	IBOutlet UIImageView *VD9;
	IBOutlet UIImageView *VD10;
	IBOutlet UIImageView *VD11;
	IBOutlet UIImageView *VD12;
}

-(void)changeBtnState:(UIButton*)button;
-(IBAction)muxChanged: (id)sender;
-(IBAction)dataChanged: (id)sender;
-(IBAction)addressChanged: (id)sender;
-(IBAction)load;
-(IBAction)viewMemoryState;
-(IBAction)viewLoadSave;
-(IBAction)onStart;
-(IBAction)onStep;
-(IBAction)onWorkLoad:(id)sender;
-(void)changeMemoryState:(int)number;
-(void)changeMicroCommandState:(int)number;
-(void)changeDataState:(int)number;
@end

