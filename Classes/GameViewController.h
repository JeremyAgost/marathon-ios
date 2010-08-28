//
//  GameViewController.h
//  AlephOne
//
//  Created by Daniel Blezek on 6/29/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "SDL_uikitopenglview.h"
#include "SDL_keyboard.h"
#import "MovePadView.h"
#import "ButtonView.h"
#import "LookView.h"


// Useful functions
extern bool save_game(void);

typedef enum {
  MenuMode,
  GameMode,
  AutoMapMode
} HUDMode;

@interface GameViewController : UIViewController {
  IBOutlet SDL_uikitopenglview *viewGL;
  IBOutlet UIView *hud;
  IBOutlet UIView *menuView;
  IBOutlet UIView *newGameView;
  IBOutlet UIView *saveGameView;
  IBOutlet UIButton *pause;
  IBOutlet ButtonView *mapView;
  IBOutlet ButtonView *actionView;
  IBOutlet LookView *lookView;
  IBOutlet MovePadView *moveView;
  IBOutlet ButtonView *leftFireView;
  IBOutlet ButtonView *rightFireView;
  IBOutlet ButtonView *previousWeaponView;
  IBOutlet ButtonView *nextWeaponView;
  IBOutlet ButtonView *inventoryToggleView;

  HUDMode mode;
  
  bool haveNewGamePreferencesBeenSet;
  CGPoint lastMenuTap;
  
  SDLKey leftFireKey;
  SDLKey rightFireKey;
  
  
  UISwipeGestureRecognizer *leftWeaponSwipe;
  UISwipeGestureRecognizer *rightWeaponSwipe;
  UIPanGestureRecognizer *panGesture;
  
  UIPanGestureRecognizer *moveGesture;
  UITapGestureRecognizer *menuTapGesture;
  CGPoint lastPanPoint;
}

+(GameViewController*)sharedInstance;
+(GameViewController*)createNewSharedInstance;

- (IBAction)pause:(id)from;
- (IBAction)newGame;
- (IBAction)beginGame;
- (IBAction)cancelNewGame;

- (void)bringUpHUD;
- (void)setOpenGLView:(SDL_uikitopenglview*)oglView;

- (void)handleSwipeFrom:(UISwipeGestureRecognizer *)recognizer;
- (void)handleLookGesture:(UIPanGestureRecognizer *)recognizer;
- (void)handleMoveGesture:(UIPanGestureRecognizer *)recognizer;
- (void)handleTapFrom:(UITapGestureRecognizer *)recognizer;

- (CGPoint) transformTouchLocation:(CGPoint)location;
- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event;
- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event;
- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event;
  
@property (nonatomic, retain) SDL_uikitopenglview *viewGL;
@property (nonatomic, retain) IBOutlet UIView *hud;
@property (nonatomic, retain) IBOutlet UIView *newGameView;
@property (nonatomic, retain) IBOutlet UIView *saveGameView;
@property (nonatomic, retain) IBOutlet UIView *menuView;
@property (nonatomic, retain) IBOutlet ButtonView *mapView;
@property (nonatomic, retain) IBOutlet ButtonView *actionView;
@property (nonatomic, retain) IBOutlet LookView *lookView;
@property (nonatomic, retain) IBOutlet MovePadView *moveView;
@property (nonatomic, retain) IBOutlet ButtonView *leftFireView;
@property (nonatomic, retain) IBOutlet ButtonView *rightFireView;
@property (nonatomic, retain) IBOutlet ButtonView *previousWeaponView;
@property (nonatomic, retain) IBOutlet ButtonView *nextWeaponView;
@property (nonatomic, retain) IBOutlet ButtonView *inventoryToggleView;
@property (nonatomic, retain) IBOutlet UIButton *pause;
@property (nonatomic, retain) UISwipeGestureRecognizer *leftWeaponSwipe;
@property (nonatomic, retain) UISwipeGestureRecognizer *rightWeaponSwipe;
@property (nonatomic, retain) UIPanGestureRecognizer *panGesture;
@property (nonatomic, retain) UIPanGestureRecognizer *moveGesture;
@property (nonatomic, retain) UITapGestureRecognizer *menuTapGesture;
@end
