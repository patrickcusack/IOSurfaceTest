
//
//  Created by patrick cusack on 4/15/2015.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@protocol PCProxyProtocol

- (oneway void)openMovieURL:(NSURL*)movieURL;

#pragma mark - setters for movie properties
- (oneway void) setMovieIsPlaying:(BOOL)flag;
//- (oneway void) setMovieRate:(float)rate;
//- (oneway void) setMovieTime:(float)time;

#pragma mark - getters for movie properties
-(BOOL)hasMovie;
-(BOOL)isMoviePlaying;
-(void)back;
-(void)forward;
//- (float) movieRate;
//- (double) movieTime;
//- (float) movieNormalizedTime;
//- (double) movieDuration;

#pragma mark - throttling
//- (BOOL) hasNewFrame;

#pragma mark - IOSurface
//- (IOSurfaceID) surfaceID;
//- (mach_port_t) surfaceMachPort;


#pragma mark - cleanup
- (oneway void) quitHelperTool;

@optional
//- (oneway void) setMovieVolume:(float)volume;
//- (oneway void) setMovieVolumes:(in NSArray*)volumes;	// for multichannel/multitrack
//- (oneway void) setMovieBalance:(float)balance;
//- (oneway void) setMovieBalances:(in NSArray*)balances;	// for multichannel/multitrack
//- (oneway void) setMovieLoop:(NSUInteger)loopMode;
//- (oneway void) setMovieDeinterlaceHint:(BOOL)hint;
//- (oneway void) setMovieHighQualityHint:(BOOL)hint;
//- (oneway void) setMovieSingleFieldHint:(BOOL)hint;
//- (oneway void) setMovieAperture:(NSUInteger)aperture;
//- (oneway void) setMovieDecodeQuality:(float)quality;
//- (oneway void) setMovieAudioDevice:(NSString*)audioDeviceUID;

//- (NSString*) movieTitle;
//- (BOOL) hasNewInfo; // Currently only movieTitle
//- (BOOL) movieDidEnd;

#pragma mark - features
//- (oneway void) enableWaveformOutput:(BOOL)waveform;
//- (oneway void) setWaveformOutputMode:(v002WaveformOutputMode)mode;
//- (oneway void) setWaveformNumberOfBands:(NSUInteger)num;
//- (NSArray*) waveForm;


@end
