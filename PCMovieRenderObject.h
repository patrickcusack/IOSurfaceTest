//
//  PCMovieRenderObject.h
//  IOSurfaceTest
//
//  Edited by Patrick Cusack on 5/7/15.
//  Copyright (c) 2015 Paolo Manna. All rights reserved.
//

#import <QTKit/QTKit.h>
#import <QuickTime/QuickTime.h>
#import <CoreAudio/CoreAudio.h>
#import <CoreVideo/CoreVideo.h>

// For OSAtomic operations
#import <libkern/OSAtomic.h>

#if defined(DISABLE_IOSURFACE) && defined(COREVIDEO_SUPPORTS_IOSURFACE)
#undef COREVIDEO_SUPPORTS_IOSURFACE
#define COREVIDEO_SUPPORTS_IOSURFACE	0
#endif

#define	FRAME_QUEUE_SIZE	100

typedef struct _QueueItem {
    CVImageBufferRef	frameBuffer;
    NSTimeInterval		frameTime;
} QueueItem;


@interface PCMovieRenderObject : NSObject{
    QTMovie								*qtMovie;
    NSString							*moviePath;
    
    QTVisualContextRef					vContext;
    
    OSSpinLock							_movieLock;
    
    NSInteger							maxQueueSize;
    NSInteger							currentQueueIdx;
    NSTimeInterval						refHostTime;
    NSTimeInterval						_frameStep;
    
    QueueItem							frameQueue[FRAME_QUEUE_SIZE];
    
    id                                  _currentFrame;
    
    BOOL                                isMoviePlaying;
}



- (void)loadMovieURL:(NSURL*)movieURL;
- (void)playMovie;
- (void)stopMovie;
- (void)setMovieIsPlaying:(BOOL)flag;
- (void)goToBeginning;
- (void)goToEnd;
- (oneway void)goToTimeValue:(long)timeValue;
- (void)setMovieRate:(float)nRate;
- (float)movieRate;
- (void)stepForward;
- (void)stepBackward;
- (long long)currentTimeValue;
- (long long)maxTimeValue;
- (long)timeScale;
- (NSTimeInterval)movieDuration;
- (NSTimeInterval)frameStep;
- (NSTimeInterval)queuedMovieTime;

- (NSTimeInterval)movieTime;
- (void)setMovieTime:(NSTimeInterval)aDouble;

- (NSValue*)movieSize;

- (id)getFrameAtTime: (NSTimeInterval)aTime;
- (IOSurfaceID)hasNewFrameAtTime:(NSTimeInterval)time;
- (IOSurfaceID)currentSurfaceID;



@property (nonatomic, retain, readwrite) QTMovie *qtMovie;
@property (nonatomic, retain, readwrite) NSString *moviePath;
@property (nonatomic, assign, readwrite) NSTimeInterval refHostTime;
@property (nonatomic, assign, readwrite) BOOL isMoviePlaying;


@end
