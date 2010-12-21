    //
//  HelpViewController.m
//  AlephOne
//
//  Created by Daniel Blezek on 11/19/10.
//  Copyright 2010 SDG Productions. All rights reserved.
//

#import "HelpViewController.h"
#import "AlephOneAppDelegate.h"
#import "GameViewController.h"

@implementation HelpViewController
@synthesize scrollView, pageControl;
- (IBAction)done {
  [self cleanupUI];
  [[AlephOneAppDelegate sharedAppDelegate].game closeHelp:self];
}
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
  pageControlUsed = YES;
  [super viewDidLoad];
}

- (void)setupUI {
  int kNumImages = 11;
  CGFloat kScrollObjHeight = scrollView.bounds.size.height;
  CGFloat kScrollObjWidth = scrollView.bounds.size.width;
  
  // load all the images from our bundle and add them to the scroll view
  NSUInteger i;
  for (i = 1; i <= kNumImages; i++) {
    NSString *imageName = [NSString stringWithFormat:@"help%d.png", i];
    UIImage *image = [UIImage imageNamed:imageName];
    UIImageView *imageView = [[UIImageView alloc] initWithImage:image];
    
    // setup each frame to a default height and width, it will be properly placed when we call "updateScrollList"
    CGRect rect = imageView.frame;
    rect.size.height = kScrollObjHeight;
    rect.size.width = kScrollObjWidth;
    imageView.frame = rect;
    imageView.tag = i;  // tag our images for later use when we place them in serial fashion
    [scrollView addSubview:imageView];
    [imageView release];
  }
  UIImageView *view = nil;
  NSArray *subviews = [scrollView subviews];
  
  // reposition all image subviews in a horizontal serial fashion
  CGFloat curXLoc = 0;
  for (view in subviews) {
    if ([view isKindOfClass:[UIImageView class]] && view.tag > 0) {
      CGRect frame = view.frame;
      frame.origin = CGPointMake(curXLoc, 0);
      view.frame = frame;
      
      curXLoc += (kScrollObjWidth);
    }
  }
  
  // set the content size so it can be scrollable
  [scrollView setContentSize:CGSizeMake((kNumImages * kScrollObjWidth), [scrollView bounds].size.height)];
  
}

- (void)cleanupUI {
  for ( UIView *v in [scrollView subviews] ) {
    [v removeFromSuperview];
  }
}

- (void)scrollViewDidScroll:(UIScrollView *)sender
{
  // We don't want a "feedback loop" between the UIPageControl and the scroll delegate in
  // which a scroll event generated from the user hitting the page control triggers updates from
  // the delegate method. We use a boolean to disable the delegate logic when the page control is used.
  if (pageControlUsed)
  {
    // do nothing - the scroll was initiated from the page control, not the user dragging
    return;
  }
	
  // Switch the indicator when more than 50% of the previous/next page is visible
  CGFloat pageWidth = scrollView.frame.size.width;
  int page = floor((scrollView.contentOffset.x - pageWidth / 2) / pageWidth) + 1;
  pageControl.currentPage = page;
}

// At the begin of scroll dragging, reset the boolean used when scrolls originate from the UIPageControl
- (void)scrollViewWillBeginDragging:(UIScrollView *)scrollView
{
  pageControlUsed = NO;
}

// At the end of scroll animation, reset the boolean used when scrolls originate from the UIPageControl
- (void)scrollViewDidEndDecelerating:(UIScrollView *)scrollView
{
  pageControlUsed = NO;
}

- (IBAction)changePage:(id)sender
{
  int page = pageControl.currentPage;
	  
	// update the scroll view to the appropriate page
  CGRect frame = scrollView.frame;
  frame.origin.x = frame.size.width * page;
  frame.origin.y = 0;
  [scrollView scrollRectToVisible:frame animated:YES];
  
	// Set the boolean used when scrolls originate from the UIPageControl. See scrollViewDidScroll: above.
  pageControlUsed = YES;
}


- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation {
    // Overriden to allow any orientation.
    return YES;
}


- (void)didReceiveMemoryWarning {
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
    // Release any cached data, images, etc. that aren't in use.
}


- (void)viewDidUnload {
  [super viewDidUnload];
  self.scrollView = nil;
  self.pageControl = nil;
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}


- (void)dealloc {
    [super dealloc];
}


@end
