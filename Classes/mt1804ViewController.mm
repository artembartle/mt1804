//
//  mt1804ViewController.m
//  mt1804
//
//  Created by bartle on 3/20/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "mt1804ViewController.h"
#import "MemoryState.h"
#include "MicrocommandsMemory.h"

@implementation mt1804ViewController

#pragma mark -
#pragma mark IB methods

-(void)changeBtnState:(UIButton*)button;
{
	if (button.selected)
		button.selected = NO;
	else button.selected = YES;
}

-(IBAction)muxChanged: (id)sender
{
	UIButton *muxBtn;
	muxBtn = sender;
	[self changeBtnState:muxBtn];
	mux.setBool(muxBtn.tag, muxBtn.selected);
	[self changeMemoryState:pmk.getDataFromTetradAtRegister(address.getNumber(), mux.getNumber())];
}

-(IBAction)dataChanged: (id)sender
{
	UIButton *dataBtn;
	dataBtn = sender;
	[self changeBtnState:dataBtn];
	data.setBool(dataBtn.tag, dataBtn.selected);
	[self changeMicroCommandState:data.getNumber()];
}

-(IBAction)addressChanged: (id)sender
{
	UIButton *addressBtn;
	addressBtn = sender;
	[self changeBtnState:addressBtn];
	address.setBool(addressBtn.tag, addressBtn.selected);
	[self changeMemoryState:pmk.getDataFromTetradAtRegister(address.getNumber(), mux.getNumber())];
}

-(IBAction)load
{
	microCommand.loadToRegister(mux.getNumber(), data.getNumber());
	pmk.loadMicroCommandToAddress(microCommand, address.getNumber());
	[self changeMemoryState:pmk.getDataFromTetradAtRegister(address.getNumber(), mux.getNumber())];
}

-(void)changeMemoryState:(int)number
{
	VD5.highlighted = number % 2;
	number /= 2;
	VD6.highlighted = number % 2;
	number /= 2;
	VD7.highlighted = number % 2;
	number /= 2;
	VD8.highlighted = number % 2;
	number /= 2;
}

-(void)changeMicroCommandState:(int)number
{
	VD1.highlighted = number % 2;
	number /= 2;
	VD2.highlighted = number % 2;
	number /= 2;
	VD3.highlighted = number % 2;
	number /= 2;
	VD4.highlighted = number % 2;
	number /= 2;	
}

-(IBAction)viewMemoryState
{
	MemoryState *memState = [[MemoryState alloc] init];
	[self presentModalViewController:memState animated:YES];
	[memState release];
}

#pragma mark -
/*
// The designated initializer. Override to perform setup that is required before the view is loaded.
- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}
*/

/*
// Implement loadView to create a view hierarchy programmatically, without using a nib.
- (void)loadView {
}
*/


/*
// Implement viewDidLoad to do additional setup after loading the view, typically from a nib.
- (void)viewDidLoad {
    [super viewDidLoad];
}
*/



// Override to allow orientations other than the default portrait orientation.
- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation {
    // Return YES for supported orientations
    return UIInterfaceOrientationIsLandscape(interfaceOrientation);
}


- (void)didReceiveMemoryWarning {
	// Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
	
	// Release any cached data, images, etc that aren't in use.
}

- (void)viewDidUnload {
	// Release any retained subviews of the main view.
	// e.g. self.myOutlet = nil;
}


- (void)dealloc {
    [super dealloc];
}

@end
