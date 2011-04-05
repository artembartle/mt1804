//
//  MemoryState.mm
//  mt1804
//
//  Created by bartle on 4/5/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "MemoryState.h"
#include "MicrocommandsMemory.h"


@implementation MemoryState

-(NSString*)labelForTetrade:(int)numTetrade atRegister:(int)numRegister
{
	int n = pmk.getDataFromTetradAtRegister(numRegister, numTetrade);
	return [NSString stringWithFormat:@"%d%d%d%d", (n/8)%2, (n/4)%2, (n/2)%2, n%2];
}

-(IBAction)onBack
{
	[self dismissModalViewControllerAnimated:YES];
}

// Implement viewDidLoad to do additional setup after loading the view, typically from a nib.
- (void)viewDidLoad {
    [super viewDidLoad];
	
	for (int i = 0; i < 16; i++) 
	{
		for (int j = 0; j < 8; j++) 
		{
			UILabel *label = [[UILabel alloc] initWithFrame:CGRectMake(43+j*50, 58+i*20, 42, 21)];
			label.font = [UIFont fontWithName:@"Helvetica" size:17];
			label.textColor = [UIColor blackColor];
			label.text = [self labelForTetrade:j atRegister:i];
			[scrollView addSubview:label];
			[label release];
		}
	}
	[scrollView setContentSize:CGSizeMake(480, 400)];
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
