//
//  GBVersionTracking.h
//  GBVersionTracking
//
//  Created by Luka Mirosevic on 28/01/2013.
//  Copyright (c) 2015 Goonbee. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^GBVersionTrackingHandlerBlock)(void);

@interface GBVersionTracking : NSObject

/**
 Call this as the VERY FIRST THING in application:didFinishLaunching:withOptions:
 */
+ (void)track;

/**
 Check if this is the first time ever that the app is launched.
 */
+ (BOOL)isFirstLaunchEver;

/**
 Check if this is the first time that this particular version is being launched.
 */
+ (BOOL)isFirstLaunchForVersion;

/**
 Check if this is the first time that this particular build is being launched.
 */
+ (BOOL)isFirstLaunchForBuild;

/**
 Check if this is the first launch, for a particular version number. Useful if you want to execute some code for first time launches of a particular version (like db migrations?).
 */
+ (BOOL)isFirstLaunchForVersion:(NSString *)version;

/**
 Check if this is the first launch, for a particular build number. Useful if you want to execute some code for first time launches of a particular version (like db migrations?).
 */
+ (BOOL)isFirstLaunchForBuild:(NSString *)build;

/**
 Calls block if the condition is satisfied that the current version matches `version`, and this is the first time this app version is being launched.
 */
+ (void)callBlockOnFirstLaunchOfVersion:(NSString *)version block:(GBVersionTrackingHandlerBlock)block;

/**
 Calls block if the condition is satisfied that the current build matches `build`, and this is the first time this app build is being launched.
 */
+ (void)callBlockOnFirstLaunchOfBuild:(NSString *)build block:(GBVersionTrackingHandlerBlock)block;

/**
 Returns the current version of the app, as defined in the PList, e.g. "4.3".
 */
+ (NSString *)currentVersion;

/**
 Returns the previous version of the app, as defined in the PList, e.g. "4.3".
 */
+ (NSString *)previousVersion;

/**
 Returns the version which the user first installed the app at.
 */
+ (NSString *)firstInstalledVersion;

/**
 Returns a sorted array of versions which the user has had installed, e.g. ["3.5", "4.0", "4.1"]. In terms of ordering, more recent versions are appended at the back of the array. The array includes the current version as the last element.
 */
+ (NSArray *)versionHistory;

/**
 Returns the current build of the app, as defined in the PList, e.g. "4300".
 */
+ (NSString *)currentBuild;

/**
 Returns the previous build of the app, as defined in the PList, e.g. "4300".
 */
+ (NSString *)previousBuild;

/**
 Returns the version which the user first installed the app at.
 */
+ (NSString *)firstInstalledBuild;

/**
 Returns a sorted array of builds which the user has had installed, e.g. ["3500", "4000", "4100"]. In terms of ordering, more recent builds are appended at the back of the array.  The array includes the current build as the last element.
 */
+ (NSArray *)buildHistory;

@end
