//
//  GBVersionTracking.m
//  GBVersionTracking
//
//  Created by Luka Mirosevic on 28/01/2013.
//  Copyright (c) 2013 Goonbee. All rights reserved.
//

#import "GBVersionTracking.h"

// Allows making public interface a little simpler by wrapping all singleton instance methods inside class methods
#define _controller [GBVersionTracking sharedController]

static NSString * const kGBVersionTrail = @"kGBVersionTrail";
static NSString * const kGBVersion = @"kGBVersion";
static NSString * const kGBBuild = @"kGBBuild";


@interface GBVersionTracking ()

@property (strong, nonatomic) NSDictionary          *versionTrail;
@property (assign, nonatomic) BOOL                  isFirstLaunchEver;
@property (assign, nonatomic) BOOL                  isFirstLaunchForVersion;
@property (assign, nonatomic) BOOL                  isFirstLaunchForBuild;

@end


@implementation GBVersionTracking

#pragma mark - Storage

+(GBVersionTracking *)sharedController {
    static GBVersionTracking *sharedController;
    @synchronized(self) {
        if (!sharedController) {
            sharedController = [GBVersionTracking new];
        }
        return sharedController;
    }
}

#pragma mark - Public API

//store a version crumb tail in NSUserDefaults
+(void)track {
    BOOL needsSync = NO;
    
    //load history
    NSDictionary *oldVersionTrail = [[NSUserDefaults standardUserDefaults] objectForKey:kGBVersionTrail];
    
    //check if its the first ever launch
    if (oldVersionTrail == nil) {
        _controller.isFirstLaunchEver = YES;
        
        _controller.versionTrail = @{kGBVersion: [NSMutableArray new], kGBBuild: [NSMutableArray new]};
    }
    else {
        _controller.isFirstLaunchEver = NO;
        
        //read the old datastructure out but make a deeply mutable copy of it first
        _controller.versionTrail = @{kGBVersion: [oldVersionTrail[kGBVersion] mutableCopy], kGBBuild: [oldVersionTrail[kGBBuild] mutableCopy]};
        
        needsSync = YES;
    }
    
    //check if this version was previously launched
    if ([_controller.versionTrail[kGBVersion] containsObject:[self currentVersion]]) {
        _controller.isFirstLaunchForVersion = NO;
    }
    else {
        _controller.isFirstLaunchForVersion = YES;
        
        [_controller.versionTrail[kGBVersion] addObject:[self currentVersion]];
        
        needsSync = YES;
    }
    
    //check if this build was previously launched
    if ([_controller.versionTrail[kGBBuild] containsObject:[self currentBuild]]) {
        _controller.isFirstLaunchForBuild = NO;
    }
    else {
        _controller.isFirstLaunchForBuild = YES;
        
        [_controller.versionTrail[kGBBuild] addObject:[self currentBuild]];
        
        needsSync = YES;
    }
    
    //store the new version stuff
    if (needsSync) {
        [[NSUserDefaults standardUserDefaults] setObject:_controller.versionTrail forKey:kGBVersionTrail];
        [[NSUserDefaults standardUserDefaults] synchronize];
    }
}

+(BOOL)isFirstLaunchEver {
    return _controller.isFirstLaunchEver;
}

+(BOOL)isFirstLaunchForVersion {
    return _controller.isFirstLaunchForVersion;
}

+(BOOL)isFirstLaunchForBuild {
    return _controller.isFirstLaunchForBuild;
}

+(BOOL)isFirstLaunchForVersion:(NSString *)version {
    if ([[self currentVersion] isEqualToString:version]) {
        return [self isFirstLaunchForVersion];
    }
    else {
        return NO;
    }
}

+(BOOL)isFirstLaunchForBuild:(NSString *)build {
    if ([[self currentBuild] isEqualToString:build]) {
        return [self isFirstLaunchForBuild];
    }
    else {
        return NO;
    }
}

+(void)callBlockOnFirstLaunchOfVersion:(NSString *)version block:(GBVersionTrackingHandlerBlock)block {
    if ([self isFirstLaunchForVersion:version] && block) {
        block();
    }
}

+(void)callBlockOnFirstLaunchOfBuild:(NSString *)build block:(GBVersionTrackingHandlerBlock)block {
    if ([self isFirstLaunchForBuild:build] && block) {
        block();
    }
}

#pragma mark - Version

+(NSString *)currentVersion {
    return [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleShortVersionString"];
}

+(NSString *)previousVersion {
    NSUInteger count = [_controller.versionTrail[kGBVersion] count];
    if (count >= 2) {
        return _controller.versionTrail[kGBVersion][count-2];
    }
    else return nil;
}

+(NSArray *)versionHistory {
    return _controller.versionTrail[kGBVersion];
}

#pragma mark - Build

+(NSString *)currentBuild {
    return [[NSBundle mainBundle] objectForInfoDictionaryKey:(NSString *)kCFBundleVersionKey];
}

+(NSString *)previousBuild {
    NSUInteger count = [_controller.versionTrail[kGBBuild] count];
    if (count >= 2) {
        return _controller.versionTrail[kGBBuild][count-2];
    }
    else return nil;
}

+(NSArray *)buildHistory {
    return _controller.versionTrail[kGBBuild];
}

@end
