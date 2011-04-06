//
//  LoadSaveVC.h
//  mt1804
//
//  Created by bartle on 4/6/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface LoadSaveVC : UIViewController<UITableViewDelegate, UITableViewDataSource>
{
	NSMutableArray *savedMemory;
	IBOutlet UITableView *mainTable;
}

-(void)saveMemoryArea;
-(void)loadMemoryAreaFromSlot:(NSString*)slotName;
-(IBAction)onBack;
-(IBAction)onSave;
@end
