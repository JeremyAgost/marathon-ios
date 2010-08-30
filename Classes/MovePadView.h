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
  CGFloat deadSpaceRadius;
  CGFloat runRadius;
  SDLKey forwardKey;
  SDLKey backwardKey;
  SDLKey leftKey;
  SDLKey rightKey;
  SDLKey runKey;
  
}
- (void)setup;

@end