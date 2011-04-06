//
//  LoadSaveVC.m
//  mt1804
//
//  Created by bartle on 4/6/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "LoadSaveVC.h"
#include "MicrocommandsMemory.h"

@implementation LoadSaveVC

#pragma mark -

-(IBAction)onBack
{
	[self dismissModalViewControllerAnimated:YES];
}

-(IBAction)onSave
{
	[self saveMemoryArea];
	[mainTable reloadData];
}

-(void)saveMemoryArea
{
	NSMutableArray *memory = [[NSMutableArray alloc] initWithCapacity:16];
	for (int i = 0; i < 16; i++) 
	{
		NSMutableArray *command = [[NSMutableArray alloc] initWithCapacity:8];
		for (int j = 0; j < 8; j++) 
		{
			NSNumber *number = [NSNumber numberWithInt:pmk.getDataFromTetradAtRegister(i, j)];
			[command addObject:number];
		}
		[memory addObject:command];
		[command release];
	}
	NSDate *date = [NSDate date];
	NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);  
    NSString *path = [NSString stringWithFormat:@"%@/%@.plist",[paths objectAtIndex:0], [date description]];
	[memory writeToFile:path atomically:YES];
	[savedMemory addObject:[date description]];
	[savedMemory writeToFile:[NSString stringWithFormat:@"%@/saved.plist", [paths objectAtIndex:0]] atomically:YES];
}

-(void)loadMemoryAreaFromSlot:(NSString*)slotName
{
	NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);  
	NSString *path = [NSString stringWithFormat:@"%@/%@.plist", [paths objectAtIndex:0], slotName];
	NSMutableArray *memory = [[NSMutableArray alloc] initWithContentsOfFile:path];
	if (memory) 
	{
		for (int i = 0; i < 16; i++)
		{
			NSMutableArray *command = [NSMutableArray arrayWithArray:[memory objectAtIndex:i]];
			Register regCommand;
			for (int j = 0; j < 8; j++)
				regCommand.loadToRegister(j, [[command objectAtIndex:j] intValue]);
			pmk.loadMicroCommandToAddress(regCommand, i);
		}
	}
	[memory release];
}

#pragma mark -
// The designated initializer.  Override if you create the controller programmatically and want to perform customization that is not appropriate for viewDidLoad.
/*
- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization.
    }
    return self;
}
*/


// Implement viewDidLoad to do additional setup after loading the view, typically from a nib.
- (void)viewDidLoad {
    [super viewDidLoad];
	NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);  
    NSString *path = [paths objectAtIndex:0];
	savedMemory = [[NSMutableArray alloc] initWithContentsOfFile:[NSString stringWithFormat:@"%@/saved.plist", path]];
	if (savedMemory == nil) 
	{
		savedMemory = [[NSMutableArray alloc] init];
	}
}



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
	[savedMemory release];
    [super dealloc];
}

#pragma mark -
#pragma mark UITableViewDelegate & DataSource

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
		return [savedMemory count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
	UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"ident"];
    if (cell == nil)
	{
        cell = [[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"ident"] autorelease];
    }
	cell.textLabel.text = [savedMemory objectAtIndex:indexPath.row];
	return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
	[self loadMemoryAreaFromSlot:[savedMemory objectAtIndex:indexPath.row]];
	[self dismissModalViewControllerAnimated:YES];
}
@end
