//
//  MemoryState.mm
//  mt1804
//
//  Created by bartle on 4/5/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "MemoryState.h"


@implementation MemoryState
@synthesize microComand;

-(NSString*)labelForTetrade:(int)numTetrade
{
	int n = (*microComand).getFromRegister(numTetrade);
	return [NSString stringWithFormat:@"%d%d%d%d", (n/8)%2, (n/4)%2, (n/2)%2, n%2];
}

-(IBAction)onBack
{
	[self dismissModalViewControllerAnimated:YES];
}

// Implement viewDidLoad to do additional setup after loading the view, typically from a nib.
- (void)viewDidLoad {
    [super viewDidLoad];
	tetr0.text = [self labelForTetrade:0];
	tetr1.text = [self labelForTetrade:1];
	tetr2.text = [self labelForTetrade:2];
	tetr3.text = [self labelForTetrade:3];
	tetr4.text = [self labelForTetrade:4];
	tetr5.text = [self labelForTetrade:5];
	tetr6.text = [self labelForTetrade:6];
	tetr7.text = [self labelForTetrade:7];
}



// Override to allow orientations other than the default portrait orientation.
- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation {
    // Return YES for supported orientations
    return UIInterfaceOrientationIsLandscape(interfaceOrientation);
}


- (void)didReceiveMemoryWarning {
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
    // Release any cached data, images, etc. that aren't in use.
}

- (void)viewDidUnload {
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}


- (void)dealloc {
    [super dealloc];
}


@end
