
//
//  Created by patrick cusack on 4/15/2015.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@protocol PCProxyProtocol

- (oneway void)addMovieURL:(NSURL*)movieURL;
- (oneway void)openMovieURL:(NSURL*)movieURL;

#pragma mark - setters for movie properties
- (void)playMovie;
- (void)stopMovie;
- (oneway void)setMovieIsPlaying:(BOOL)flag;
- (void)goToBeginning;
- (void)goToEnd;
- (oneway void)goToTimeValue:(long)timeValue;
- (oneway void)setMovieRate:(float)nRate;

#pragma mark - getters for movie properties
-(BOOL)hasMovie;
-(BOOL)isMoviePlaying;
-(void)back;
-(void)forward;
-(long long)currentTimeValue;
-(long long)maxTimeValue;
-(long)timeScale;
-(NSValue*)movieSize;

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
