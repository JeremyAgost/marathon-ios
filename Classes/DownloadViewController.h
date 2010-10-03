//
//  DownloadViewController.h
//  AlephOne
//
//  Created by Daniel Blezek on 9/8/10.
//  Copyright 2010 SDG Productions. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ASIHTTPRequest.h"
#import "PDColoredProgressView.h"

@interface DownloadViewController : UIViewController {
  PDColoredProgressView *progressView;
  NSString *downloadPath;
}

@property (nonatomic, retain) IBOutlet PDColoredProgressView *progressView;

- (void)downloadFinished:(ASIHTTPRequest*)request;
- (void)downloadOrchooseGame;
- (bool)isDownloadOrChooseGameNeeded;
- (void)downloadFailed:(ASIHTTPRequest*)request;
@end