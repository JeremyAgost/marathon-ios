//
//  MovePadView.h
//  AlephOne
//
//  Created by Daniel Blezek on 8/12/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SDL_uikitopenglview.h"
#include "SDL_keyboard.h"


@interface MovePadView : UIView {
  CGPoint moveCenterPoint;
  CGFloat moveRadius;
  CGFloat moveRadius2;
  CGFloat deadSpaceRadius;
  CGFloat runRadius;
  SDL_Keycode forwardKey;
  SDL_Keycode backwardKey;
  SDL_Keycode leftKey;
  SDL_Keycode rightKey;
  SDL_Keycode runKey;
	
		//DCW
	SDL_Keycode secondaryFireKey;
	SDL_Keycode actionKey;
	bool	 useForceTouch;

  UIImageView *knobView;
	
	UIImpactFeedbackGenerator *feedbackSecondary; //DCW
}

@property (nonatomic, retain) IBOutlet UIImageView *knobView;
@property (nonatomic,retain) IBOutlet UIButton* actionKeyImageView; //DCW

- (void)setup;
- (void) actionKeyUp; //DCW

@end
