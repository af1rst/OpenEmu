//
//  MyDocument.h
//  OpenEmu
//
//  Created by Josh Weinberg on 9/1/08.
//  Copyright __MyCompanyName__ 2008 . All rights reserved.
//


#import <Cocoa/Cocoa.h>
#import <QuartzCore/CoreAnimation.h>

@class GameCore;
@class GameInput;
@class GameAudio;
@class GameLayer;
@class GameBuffer;
@class GameQTRecorder;

@interface GameDocument : NSDocument
{
	NSTimer* frameTimer;
	CALayer *rootLayer;
	GameLayer *gameLayer;
	GameBuffer *gameBuffer;
	GameQTRecorder *recorder;
	BOOL keyedOnce;
	GameCore * gameCore;
	GameAudio * audio;
	IBOutlet NSWindow *gameWindow;
	IBOutlet NSView *view;
}

- (BOOL) isFullScreen;
- (void) switchFullscreen;
- (void) refresh;
- (void) refreshAudio;
- (void) saveState: (NSString *) fileName;
- (void) loadState: (NSString *) fileName;

- (NSBitmapImageRep*) getRawScreenshot;

- (void) setVolume: (float) volume;

- (void) resetFilter;

@property(readonly) GameCore* gameCore;
@end
